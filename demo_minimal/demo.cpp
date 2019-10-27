
#include "inc.cpp"

int demo_setup( ) {

    //cout << "SETUP" << endl ;

    return( 0 ) ;

}

int demo_loop( ) {

    //cout << "LOOP " << endl ;

    gfx_color_set( 255 , 255 , 255 , 2) ;
    gfx_line_draw( 0 , 0 , 640 , 480 ) ;
    
    gfx_color_set( 255 , 255 , 255) ;
    gfx_line_draw( 640 , 0 , 0 , 480 ) ;

    gfx_present( ) ;

    return( 0 ) ;

}

int demo_event_keydown( int key ) {

    if( key == SDLK_RIGHT ) {

        cout << "RIGHT" << endl ;
    
    }

    cout << dice_get( 20 ) << endl ;

    return( 0 ) ;

}
