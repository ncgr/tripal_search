<?php

function tripal_search_blat_form($form, &$form_state){
    $form=array();
     $form['para']=array(
      '#markup' => '<h3> Enter the species and parameters below for alignment of sequences using a Client to a local BLAT Server: </h3>
                    <p>BLAT is a tool for aligning gene/transcript sequences, or highly-similar DNA sequences, to a genome.<br> BLAT performs spliced alignment, allowing an alignm                     ent to span introns.<br><br> Alignments will be displayed in the genome browser of the selected species.</p>');
    $form['blat'] = array(
    '#type' => 'fieldset',
    '#title' => t('BLAT'),
    '#collapsible'=> TRUE,
    );
     $form['blat']['dropdown1']=array(
     '#type'=> 'select',
     '#title'=>t('Sequence type'),
     '#options'=> array(
          'dna' => 'DNA',
          'rna' => 'RNA',
      ),
      '#required' => TRUE, // Added
    );

    $form['blat']['string'] = array(
    '#type' => 'textarea',
    '#title' => t('Only a single input sequence (20 bp or longer), raw seq or FASTA is acceptable.'),
    '#description'=>t('click to load example'),
    '#required' => TRUE, // Added

 );
    $form['blat']['dropdown2']=array(
         '#type' => 'select',
         '#title' => t('Species to align against:'),
         '#required'=>TRUE,
          '#options'=>array(
             '/gb2/gbrowse/Pv1.0/?plugin=Blat;plugin_action=Go"'=>'Phaseolus vulgaris (v1.0)',
             '/gb2/gbrowse/Cc1.0/?plugin=Blat;plugin_action=Go"' => 'Cajanus cajun (v1.0)',
             '/gb2/gbrowse/Ca1.0/?plugin=Blat;plugin_action=Go"' =>'Cicer arietinum (v1.0)',
             '/gb2/gbrowse/Mt4.0/?plugin=Blat;plugin_action=Go"'=> 'Medicago truncatula (v4.0)',
             '/gb2/gbrowse/Lj2.5/?plugin=Blat;plugin_action=Go"' => 'Lotus japonicus (v2.5)',
              'http://peanutbase.org/gb2/gbrowse/Aradu1.0/?plugin=Blat;plugin_action=Go"' => 'A. duranensis (v1.0 at PeanutBase)',
              'http://peanutbase.org/gb2/gbrowse/Araip1.0/?plugin=Blat;plugin_action=Go"'=>'A. ipaensis (v1.0 at PeanutBase)',
              'http://soybase.org/gb2/gbrowse/gmax2.0/?plugin=Blat;plugin_action=Go"'=>'Glycine max (Wm82.a2 at SoyBase)',
         ),
    );

 $form['blat']['text1']=array(
       '#type'=>'textfield',
       '#title'=>t('Number of Hits to Return'),
       '#size'=>5,
       '#default_value' => 50,
       '#prefix' => '<table><tr><td>',
       '#suffix' => '</td>',
    );

    $form['blat']['text2']=array(
      '#type'=>'textfield',
      '#title'=>t('Minimum Percent Identity'),
      '#size'=>5,
      '#default_value' => 70,
      '#prefix' => '<td>',
      '#suffix' => '</td></tr></table>',
    );

     $form['blat']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#name'=> 'submit',
   );

  $form['blat']['reset'] = array (
     '#type' => 'submit',
     '#value' => t('Reset'),
     '#name' => 'reset',
  );

  return $form;
}


function tripal_search_blat_form_submit($form, &$form_state){
    switch ($form_state['triggering_element']['#name']) {
    case 'submit':
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

