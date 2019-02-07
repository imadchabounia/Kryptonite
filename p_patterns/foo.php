<?php
print("\033[1;31");
print("
/**************************************************
[ + ]      Coded by Imad ^________-
***************************************************/
");

function triangle1($string){

  $begin = 0;
  $end = strlen($string);

  if(strlen($string) == 1){
    print("\t \n".$string);
    return;
  }

  triangle1(control($string, $begin+1, $end-1));
  print("\t \n".$string);

}

function control($string, $start, $end){
  $result = "";
  for($i = $start; $i <= $end; $i++){

    $result = $result.$string[$i];
  }

  return $result;
}

function triangle2($string){
  $begin = 0;
  $end = strlen($string)-1;
  $i = 0;
  $str = $string;
  while(strlen($str) != 1){
      $str = control($string, $begin+$i, $end);
      $i++;
      print("\n");
      print("\t\t\t".$str);
  }

}
$string = "***********************";

triangle1($string);
triangle2($string);
