

#include <iostream>
#include "csv.h"

using namespace std ;

int main( ) {

    io::CSVReader<3> in( "input.csv" ) ;

    in.read_header( io::ignore_extra_column , "identifier" , "height" , "weight" ) ;

    std::string name ;
    double height ;
    double weight ;

    while( in.read_row( name , height , weight ) ) {

        cout << name << " is " << height << "m tall and weighs " << weight << "Kg" << endl ;

    }

    return( 0 ) ;

}
