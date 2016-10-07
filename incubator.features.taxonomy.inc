<?php
/**
 * @file
 * incubator.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function incubator_taxonomy_default_vocabularies() {
  return array(
    'incubator_locations' => array(
      'name' => 'Incubator Locations',
      'machine_name' => 'incubator_locations',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'incubator',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'incubator_strategic_plan' => array(
      'name' => 'Incubator Strategic Plan',
      'machine_name' => 'incubator_strategic_plan',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'incubator',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'incubator_target_audience' => array(
      'name' => 'Incubator Target Audience',
      'machine_name' => 'incubator_target_audience',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'incubator',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
