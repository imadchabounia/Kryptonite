<?php

function migratoryBirds($arr){

  $freq = [0, 0, 0, 0, 0];
  $max = 0;
  $selected_id = 1;
  
  for($i = 0; $i < count($arr); $i++){
    $freq[$arr[$i]-1] += 1;
    
    if($freq[$arr[$i]-1] > $max){
    $max = $freq[$arr[$i]-1];
      $selected_id = $arr[$i];
    }
    
    
  }
  
  return $selected_id;
}
