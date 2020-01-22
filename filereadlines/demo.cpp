
#include <iostream>
#include <fstream>

using namespace std ;

int main( ) {

    ifstream infile ;
    infile.open( "input.txt" ) ;

    int universities_total , students_total ;

    infile >> universities_total ;
    cout << "universities_total = " << universities_total << endl ;

    infile >> students_total ;
    cout << "students_total = " << students_total << endl ;

    int university_places ;

    for( int i = 0 ; i < universities_total ; i++ ) {

        infile >> university_places ;
        cout << "(" << i << ") " ;
        cout << university_places << " university_places" << endl ;

    }

    int student_score ;
    int student_preferences ;

    for( int i = 0 ; i < students_total ; i++ ) {

        infile >> student_score ;
        cout << "(" << i << ") " ;
        cout << "student_score = " ;
        cout << student_score ;

        infile >> student_preferences ;
        cout << " student_preferences = " ;
        cout << student_preferences ;

        int student_preference ;

        for( int j = 0 ; j < student_preferences ; j++ ) {

            infile >> student_preference ;
            cout << " student_preference = " ;
            cout << student_preference ;

        }

        cout << endl ;

    }

    infile.close( ) ;

    return( 0 ) ;

}
