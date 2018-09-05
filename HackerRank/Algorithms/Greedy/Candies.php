<?php


function candies($n, $arr){
  
  $total = 0;
  $candies = [];
  $base = 1;
  
  if($n == count($arr)){
     
    for($i = 0; $i < $n; $i++){
      $candies[$i] = $base;
    }
    
    for($i = 1; $i < $n; $i++){ // asc
      if($arr[$i] > $arr[$i-1]){
        $candies[$i] += $candies[$i-1];
      }
    }
    
    for($i = $n-2; $i >= 0; $i--){ // desc
      if($arr[$i] > $arr[$i+1] && $candies[$i] < $candies[$i+1]+1){
        $candies[$i] = $candies[$i+1]+1;
      }
    }
    
    for($i = 0; $i < $n; $i++){
      $total += $candies[$i];
    }
    
    return $total;
  }
}
