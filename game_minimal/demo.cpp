
#include "inc.cpp"

int game_setup( ) {

    return( 0 ) ;

}

int game_loop( ) {

    return( 0 ) ;

}

int game_event_keydown( int key ) {

    // SDLK_RIGHT, SDLK_LEFT etc.

    return( 0 ) ;

}

int game_event_mousebuttondown( int mouse_button ) {

    //SDL_BUTTON_LEFT,SDL_BUTTON_RIGHT, or something else like middle button

    if( mouse_button == SDL_BUTTON_RIGHT) {

        gfx_pixels_clear( ) ;
    
    }

    return( 0 ) ;

}

int game_event_mousemotion( int mouse_x , int mouse_y ) {

    int ox = WINDOW_WIDTH / 2 ;
    int oy = WINDOW_HEIGHT / 2 ;

    int x = mouse_x ;
    int y = mouse_y ;

    gfx_pixel_set( x , y , 255 , 255 , 255 );
    gfx_pixel_set( ox + ( ox - x )  , y , 255 , 255 , 255 ) ;
    gfx_pixel_set( x , oy + ( oy - y ) , 255 , 255 , 255 ) ;
    gfx_pixel_set( ox + ( ox - x ) , oy + ( oy - y ) , 255 , 255 , 255 ) ;

    return( 0 ) ;

}

