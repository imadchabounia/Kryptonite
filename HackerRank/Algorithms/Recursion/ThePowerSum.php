<?php
// additional basic algorithm (compute power of number with for loop) :


function power_n($X, $N){
  
  $p = 1;
  
  for($i = 1; $i <= $N; $i++){
    $p = $p*$X;
  }
  
  return $p;
}


function powerSumHelper($X, $N, $l){
  $counter = 0;
  if($X == 0){ // base case/Condition
    return 1;
  }else{
    for($i = $l + 1; power_n($i, $N) <= $X; $i++){
       $x = $X - power_n($i, $N);
       $counter += powerSumHelper($x, $N, $i);
    }
  }
  return $counter;
}
