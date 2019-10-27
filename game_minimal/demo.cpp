
#include "inc.cpp"

int game_setup( ) {

    //cout << "SETUP" << endl ;

    return( 0 ) ;

}

int game_loop( ) {

    //cout << "LOOP " << endl 

    gfx_window_clear( ) ;

    gfx_color_set( 255 , 255 , 255 , 64) ;
    gfx_line_draw( 0 , 0 , 640 , 480 ) ;
    
    gfx_color_set( 255 , 255 , 255) ;
    gfx_line_draw( 640 , 0 , 0 , 480 ) ;

    return( 0 ) ;

}

int game_event_keydown( int key ) {

    if( key == SDLK_RIGHT ) {

        cout << "YOU PRESS THE RIGHT KEY" << endl ;
    
    }

    cout << dice_get( 20 ) << endl ;

    return( 0 ) ;

}

int game_event_mousebuttondown( int but ) {

    if( but == SDL_BUTTON_LEFT ) {

        cout << "You clicked LEFT mouse button!" << endl ;
        return( 0 ) ;
    
    }

    if( but == SDL_BUTTON_RIGHT) {
    
        cout << "You clicked RIGHT mouse button!" << endl ;
        return( 0 ) ;
    
    }

    cout << "You clicked SOME mouse button!" << endl ;
    

    return( 0 ) ;

}

int game_event_mousemotion( int x , int y ) {

    gfx_pixel_set( x , y , 255,255,255 );
    gfx_pixel_set( x+1 , y , 255,255,255 );
    gfx_pixel_set( x , y+1 , 255,255,255 );
    gfx_pixel_set( x , y-1 , 255,255,255 );
    gfx_pixel_set( x-1 , y , 255,255,255 );

    return( 0 ) ;

}

