<?php
//interval length = 4
function toys($w){
  
  //we need to sort arra first
  
  sort($w);
  $start_e = $w[0]; 
  $end_e   = $start_e+4;
  $counter = 1; // at anycase there's a one container
  
  for($i = 1; $i < count($w); $i++){
    // so if an element $w[$i] is greater than a start_point+4 so he should be inside a new container
    if($w[$i] > $end){
      $start_e = $w[$i];
      $end_e   = $start_e+4;
      $counter++;
    }
  }
 
  
  return $counter;
    
}
