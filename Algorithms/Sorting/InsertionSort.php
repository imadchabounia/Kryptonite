<?php

function InsertionSort($array, $n): array { // $n => size of the array
  
  if(!(empty($array))){
    
    // main Algorithm: 
    
    for($i = 1; $i < $n; $i++){
      $shot = $array[$i];
      $j = $i-1;
      
      while($j >= 0 && $array[$j] > $shot){
        $array[$j+1] = $array[$j];
        $j = $j - 1;
      }
      
      $array[$j+1] = $shot;
        
    }
    
    return $array;
  
  }

}
