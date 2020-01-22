
#include <iostream>
#include <fstream>

using namespace std ;

int main( ) {

    ofstream outfile ;
    outfile.open( "output.txt" ) ;

    int a , b , c ;

    a = 1 ;
    b = 2 ;
    c = 3 ;

    outfile << a ;
    outfile << " " ;
    outfile << b ;
    outfile << " " ;
    outfile << c ;

    outfile << endl ;

    outfile.close( ) ;

    return( 0 ) ;

}
