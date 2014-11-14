<?php
function tripal_search_form($form, &$form_state){
   $form=array();
   $form['search'] = array(
    '#type' => 'fieldset',
    '#title' => t('Search'),
    '#collapsible'=> TRUE,
    '#description'=>t('Enter terms to search for features (gene or marker names, functional descriptions, etc.) on the indicated genome. You will see the results displayed on a karyotpe view of chromosomes and in a list report. You can go from there to a detailed view of the features on the genome browser.'),
  );
  $form['search']['string'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter term'),
    '#description'=>t('Examples: lipoxygenase, Medtr3g108450.1.')
  );
  $form['search']['dropdown']=array(
     '#type'=> 'select',
     '#title'=>t('Select Organism'),
     '#options'=> array(
          'Pv1.0' => 'Phaseolus vulgaris 1.0',
          'Mt4.0' => 'Medicago truncatula 4.0',
          'Lj2.5' => 'Lotus japonicus 2.5',
          'Ca1.0' =>'Cicer arietinum 1.0',
          'Cc1.0' =>'Cajanus cajan 1.0',
      )
   );
  $form['search']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#name'=> 'submit',
  );

   $form['search']['reset'] = array (
  '#type' => 'submit',
  '#value' => t('Reset'),
  '#name' => 'reset',
  );

   return $form;
}

function tripal_search_form_validate($form, $form_state){
  if(empty($form_state['input']['string'])){
     form_error($form, t('Search field cannot be empty'));
   }

}

function tripal_search_form_submit($form, &$form_state) {
    //debug($form_state);
    switch ($form_state['triggering_element']['#name']) {
    case 'submit':
      $string=$form_state['input']['string'];
      $organism=$form_state['input']['dropdown'];
      $url="http://legumeinfo.org/gb2/gbrowse/$organism/?q=$string";
      $form_state['redirect'] = $url;
      break;

    case 'reset':
    $form['items']['name'] = array(
    '#type' => 'markup',
    '#value' => '<input class="form-button" "Reset" type="reset">',
    '#weight' => 2000,
    );
    break;
  }
}

