<?php

function stockmax($prices){

    $gained = 0;
    $max = 0;

    for($i = count($prices)-1; $i > -1; $i--){
        
        if($prices[$i] > $max){

            $max = $prices[$i];
        }

        $gained += ($max - $prices[$i]);
    }

    return $gained;
}
