<?php

function swap(&$a, &$b){
  $temp = $a;
  $a    = $b;
  $b    = $temp;
}

function SelectionSort($array, $n): array {
  
  for($i = 0; $i < $n-1; $i++){
   
    $min_i = $i;
    
    for($j = $i + 1; $j < $n; $j++){
     
      if($array[$j] < $array[$min_i]){
        $min_i = $j;
      
      }
    }
     
      swap($array[$i], $array[$min_i]);
  
  }
  
  return $array;
}
