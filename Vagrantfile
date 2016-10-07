# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
  config.vm.box = "ubuntu/trusty64"

  config.vm.network "forwarded_port", guest: 80, host: 80

  config.vm.network "private_network", ip: "192.168.33.10"

  config.vm.provider "virtualbox" do |v|
    v.customize ["setextradata", :id, "VBoxInternal2/SharedFoldersEnableSymlinksCreate/v-root", "1"]
  end

  config.vm.provision "shell", inline: <<-SHELL

    MYSQL_ROOT_PASS=vagrant
    TEST_DB_NAME=local_db
    TEST_DB_USER=vagrant
    TEST_DB_PASS=vagrant

    apt-get update
    apt-get install -y debconf git

    # LAMP Stack install
    ##
    echo "mysql-server-5.5 mysql-server/root_password_again password $MYSQL_ROOT_PASS" | debconf-set-selections
    echo "mysql-server-5.5 mysql-server/root_password password $MYSQL_ROOT_PASS" | debconf-set-selections
    apt-get install -y lamp-server^
    apt-get install -y mysql-client php5-dev php5-gd php5-curl php5-json ruby-compass default-jre-headless

    # LAMP Configurations
    ##
    pecl install uploadprogress
    if ! grep -Fxq "extension=uploadprogress.so" /etc/php5/apache2/php.ini; then
      echo "extension=uploadprogress.so" >> /etc/php5/apache2/php.ini
    fi
    a2enmod rewrite
    a2enmod headers
    sed -i "s/AllowOverride None/AllowOverride All/" /etc/apache2/apache2.conf

    sed -i "s/memory_limit = 128M/memory_limit = 512M/" /etc/php5/apache2/php.ini
    sed -i "s/post_max_size = 8M/post_max_size = 256M/" /etc/php5/apache2/php.ini
    sed -i "s/upload_max_filesize = 2M/upload_max_filesize = 256M/" /etc/php5/apache2/php.ini
    apt-get install -y apache2 mysql php5

    # Test database creation
    ##
    if [ ! -d "/var/lib/mysql/$TEST_DB_NAME" ]; then
      mysql -u root -p$MYSQL_ROOT_PASS -e "create database $TEST_DB_NAME"
    fi
    mysql -u root -p$MYSQL_ROOT_PASS -e "grant usage on $TEST_DB_NAME.* to $TEST_DB_USER@localhost identified by '$TEST_DB_PASS'"
    mysql -u root -p$MYSQL_ROOT_PASS -e "grant all privileges on $TEST_DB_NAME.* to $TEST_DB_USER@localhost"
    mysql -u root -p$MYSQL_ROOT_PASS -e "flush privileges"

    # Drush setup
    #
    if [ ! -f "/usr/local/bin/composer" ]; then
      curl -sS https://getcomposer.org/installer | php
      mv composer.phar /usr/local/bin/composer
    fi
    if [ ! -f "/usr/local/bin/drush" ]; then
      curl -sSO http://files.drush.org/drush.phar
      chmod 755 drush.phar
      mv drush.phar /usr/local/bin/drush
      su - vagrant -c "drush init -y"
    fi

    curl https://github.com/pantheon-systems/terminus/releases/download/0.12.0/terminus.phar -L -o /usr/local/bin/terminus && chmod +x /usr/local/bin/terminus

    # Drupal Install
    rm -r /var/www/html
    cd /var/www/ && drush dl drupal-7 && mv drupal* html && cd -
    cp /var/www/html/sites/default/default.settings.php /var/www/html/sites/default/settings.php

    # Settings file setup
    SETTINGS_FILE=/var/www/html/sites/default/settings.php
    if [ -f "$SETTINGS_FILE" ]; then
      rm $SETTINGS_FILE
    fi
    touch $SETTINGS_FILE
    echo "<?php" >> $SETTINGS_FILE
    echo "\\$databases['default']['default'] = array(" >> $SETTINGS_FILE
    echo " 'driver' => 'mysql'," >> $SETTINGS_FILE
    echo " 'database' => '$TEST_DB_NAME'," >> $SETTINGS_FILE
    echo " 'username' => '$TEST_DB_USER'," >> $SETTINGS_FILE
    echo " 'password' => '$TEST_DB_PASS'," >> $SETTINGS_FILE
    echo " 'host' => 'localhost'," >> $SETTINGS_FILE
    echo " 'prefix' => ''," >> $SETTINGS_FILE
    echo ");" >> $SETTINGS_FILE
    echo "\\$preprocess_js = 0;" >> $SETTINGS_FILE
    echo "\\$preprocess_css = 0;" >> $SETTINGS_FILE
    chown vagrant:vagrant $SETTINGS_FILE

    mkdir /var/www/html/sites/default/files
    chown -R vagrant:vagrant /var/www/html
    chown -R www-data:www-data /var/www/html/sites/default/files

    # Local drush alias setup
    DRUSH_LOCAL_FILE="/home/vagrant/.drush/local.aliases.drushrc.php"
    if [ -f $DRUSH_LOCAL_FILE ]; then
      rm $DRUSH_LOCAL_FILE
    fi
    touch $DRUSH_LOCAL_FILE
    echo '<?php ' >> $DRUSH_LOCAL_FILE
    cd /var/www/html/sites/default && drush sa @self --full --with-optional >> $DRUSH_LOCAL_FILE && cd -
    sed -i 's/self/local/' $DRUSH_LOCAL_FILE

    cd /var/www/html/sites/default && sudo drush si -y && sudo -u vagrant drush en incubator -y && cd -

    ln -s /vagrant /var/www/html/sites/all/modules/incubator

    # Updates for onlogin
    ##
    if ! grep -q "drush site-set" /home/vagrant/.bashrc
    then
      echo "drush site-set @local && cd /vagrant" >> /home/vagrant/.bashrc
    fi

    chown -R vagrant:vagrant /home/vagrant/.drush
  SHELL
end
