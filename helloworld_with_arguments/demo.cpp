#include <iostream>
#include <string>
using namespace std ;
     
int main( int argc , char **argv ) {

  cout << "Hello, World!" << endl ;

  string val ;

  for( int i = 1 ; i < argc ; i++ ) {

    val = argv[ i ] ;
    cout << "Argument " << i << " -->" << val << "<--" << endl ;
  
  }
  
  return( 0 ) ;

}
