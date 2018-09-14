<?php

function gradingStudents($grades) {

for($i = 0; $i < count($grades); $i++){
    if((((($grades[$i]-$grades[$i]%5)+5)-$grades[$i]) < 3) && (($grades[$i]-$grades[$i]%5)+5) >= 40){
        $grades[$i] = (($grades[$i]-$grades[$i]%5)+5);
    }
}

return $grades;

}
