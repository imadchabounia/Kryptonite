<?php

// this algorithm follow devide and conquer startegy, unlike quick sort in merge sort we need auci

function merge($L, $R, &$M){ // calling by refrence
 
  $x = 0; 
  $y = 0;
  $z = 0;
  
  while($x < count($L) && $y < count($R)){
    
    if($L[$x] <= $R[$y]){
      
      $M[$z] = $L[$x];
      $x++;
      
    }else{
      
      $M[$z] = $R[$y];
      $y++;
      
    }
    
    $z++;    
    
  }
        
  while($x < count($L)){
    
    $M[$z] = $L[$x];
    $x++; $z++;
    
  }
  
  while($y < count($L)){
    
    $M[$z] = $R[$y];
    $y++; $z++;
    
  }
  
}

function mergeSort(&$array){ // calling by refrence
 
  $median = ceil(count($array)/2)-1;
  for($i = 0; $i < $median; $i++){
    
    $L[$i] = $array[$i];
  
  }
  
  for($i = $median; $i < count($array); $i++){
    
    $R[$i-$median] = $array[$i];
    
  }
  
  mergeSort($L); 
  mergeSort($R);
  merge($L, $R, $array);
}
