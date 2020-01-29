<?php

/*


3 5
1 2 3
1 2 1 2
2 3
3
4
5


*/



//$universities = mt_rand( 10 , 3 ) ;
//$students = mt_rand( 1 , 3 ) ;

$universities = 100 ;
$students = 10000 ;

print("$universities $students\n");


for($i=0;$i<$universities;$i++){

    print(mt_rand(1,intval($students/$universities))." ");

}

print("\n");

$parr=array();
for($j=0;$j<$students;$j++){
    $parr[]=$j+1;
}
shuffle($parr);
$student_scores=$parr;
//print_r($student_scores);

for($i=0;$i<$students;$i++){

    //$score=mt_rand(1,99);

    $score=$student_scores[$i];

    $preferences = mt_rand( 1 , $universities ) ;

    $parr=array();
    for($j=0;$j<$preferences;$j++){
        $parr[]=$j+1;
    }
    shuffle($parr);

    $t1=implode(" ",$parr);

    print("$score $preferences $t1\n") ;


}

