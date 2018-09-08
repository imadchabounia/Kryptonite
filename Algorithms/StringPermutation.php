<?php

// it works also with arrays

function swap($string, $left, $right){
  $temp = $string[$left];
  $string[$left] = $string[$right];
  $string[$right] = $temp;
  
  return $string;
}

//This problem will be solved Recursivly

function permute($string, $left, $right){
  if($left == $right){
    print($string."\n");
  }else{
    for($i = $left; $i < $right; $i++){
      $string = swap($string, $left, $i);
      permute($string, $left+1, $right);
      }
  }
}

