

void gfx_window_clear( ) {

    SDL_SetRenderDrawColor( renderer1 , 0 , 0 , 0 , SDL_ALPHA_OPAQUE ) ;
    SDL_RenderClear( renderer1 ) ;

}

void gfx_line_draw( int x1 , int y1, int x2, int y2 ) {

    SDL_RenderDrawLine( renderer1 , x1 , y1 , x2 , y2 ) ;

}


void gfx_color_set( int r , int g , int b ) {

    SDL_SetRenderDrawColor( renderer1 , r , g , b , SDL_ALPHA_OPAQUE ) ;

}

void gfx_color_set( int r , int g , int b , int a ) {

    SDL_SetRenderDrawColor( renderer1 , r , g , b , a ) ;

}

void gfx_present( ) {

    SDL_RenderPresent( renderer1 ) ;

}

int dice_get( int n ) {
    return((rand()%n)+1);
}