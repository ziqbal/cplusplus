
#include <iostream>
#include <vector>
using namespace std ;

int main( ) {

    vector<string> my_strings ;

    my_strings.push_back( "hello" ) ;
    my_strings.push_back( "world!" ) ;
    my_strings.push_back( "my name is aran" ) ;

    cout << my_strings[ 1 ] << endl ;

    int my_strings_size = my_strings.size( ) ;

    cout << my_strings_size << endl ;

    int last_string_size = my_strings[ my_strings_size - 1  ].size( ) ;

    cout << last_string_size << endl ;

    return( 0 ) ;

}
