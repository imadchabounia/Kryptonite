<?php 

function swap(&$a, &$b){
  
  $temp = $a;
 
  $a = $b;
  
  $b = $temp;

}


function BubbleSort($array, $n): array  {
  
  while(true){
  
    $swapped = 0;
    
    for($i = 0; $i < $n-1; $i++){
     
      if($array[$i+1] < $array[$i]){
        
        swap($array[$i], $array[$i+1]);
        $swapped = 1;
     
      }
    }
    
    if($swapped == 0){
      
      break;
   
    }else{
     
      continue;
   
    }
  
  }
  
  return $array;
  
 }
