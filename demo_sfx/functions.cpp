

void gfx_window_clear( ) {

    SDL_SetRenderDrawColor( renderer1 , 0 , 0 , 0 , SDL_ALPHA_OPAQUE ) ;
    SDL_RenderClear( renderer1 ) ;

}

void gfx_line_draw( int x1 , int y1, int x2, int y2 ) {

    SDL_RenderDrawLine( renderer1 , x1 , y1 , x2 , y2 ) ;
    gfx_pixels_dirty = SDL_TRUE ;

}


void gfx_color_set( int r , int g , int b ) {

    SDL_SetRenderDrawColor( renderer1 , r , g , b , SDL_ALPHA_OPAQUE ) ;

}

void gfx_color_set( int r , int g , int b , int a ) {

    SDL_SetRenderDrawColor( renderer1 , r , g , b , a ) ;

}

void gfx_pixel_set( int x , int y , int r , int g , int b , int a ) {

    pixels[ ( y * WINDOW_WIDTH ) + x ] = (a<<24) + (r<<16)+ (g<<8)+b;
    gfx_pixels_dirty = SDL_TRUE ;

}

void gfx_pixel_set( int x , int y , int r , int g , int b ) {

    pixels[ ( y * WINDOW_WIDTH ) + x ] = (SDL_ALPHA_OPAQUE<<24) + (r<<16)+ (g<<8)+b;
    gfx_pixels_dirty = SDL_TRUE ;

}

void gfx_pixels_clear( ) {

    memset( pixels , 0 , WINDOW_WIDTH * WINDOW_HEIGHT * sizeof( Uint32 ) ) ;

}

void gfx_present( ) {

    if( gfx_pixels_dirty ) {

        SDL_UpdateTexture( texture_pixels , NULL , pixels , WINDOW_WIDTH * sizeof( Uint32 ) ) ;
        gfx_pixels_dirty = SDL_FALSE ;

    }

    SDL_RenderCopy( renderer1 , texture_pixels , NULL , NULL ) ;

    SDL_RenderPresent( renderer1 ) ;

}

int dice_get( int n ) {

    return( ( rand( ) %n ) + 1 ) ;

}
