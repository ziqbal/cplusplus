
#include "SDL2/SDL.h"
#include <iostream>
#include <sstream>

using namespace std ;

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

SDL_Window *window1 ;
SDL_Renderer *renderer1 ;
SDL_Texture *texture_pixels ;
Uint32 *pixels ;

SDL_bool gfx_pixels_dirty = SDL_TRUE ;

const Uint8 *state_keyboard ;

#include "functions.cpp"

int main( int argc , char* argv[ ] ) {

    if( SDL_Init( SDL_INIT_EVERYTHING ) != 0 ) {

        cout << "SDL_Init Error: " << SDL_GetError( ) << endl ;
        return( 1 ) ;

    }

    ///////////////////////////////////////////////////////////////////////////

    window1 = SDL_CreateWindow( "Hello World!" , 100 , 100 , WINDOW_WIDTH , WINDOW_HEIGHT , SDL_WINDOW_SHOWN ) ;

    if( window1 == nullptr ) {

        cout << "SDL_CreateWindow Error: " << SDL_GetError( ) << endl;
        SDL_Quit( ) ;
        return( 1 ) ;

    }

    ///////////////////////////////////////////////////////////////////////////

    renderer1 = SDL_CreateRenderer( window1 , -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ) ;

    if( renderer1 == nullptr ) {

        cout << "SDL_CreateRenderer Error: " << SDL_GetError( ) << endl ;
        SDL_DestroyWindow( window1 ) ;
        SDL_Quit( ) ;
        return( 1 ) ;

    }

    ///////////////////////////////////////////////////////////////////////////

    SDL_SetRenderDrawBlendMode( renderer1 , SDL_BLENDMODE_BLEND ) ;

    texture_pixels = SDL_CreateTexture( renderer1 , SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC , WINDOW_WIDTH , WINDOW_HEIGHT ) ;

    SDL_SetTextureBlendMode(texture_pixels, SDL_BLENDMODE_BLEND);

    pixels = new Uint32[ WINDOW_WIDTH * WINDOW_HEIGHT ] ;
    memset( pixels , 0 , WINDOW_WIDTH * WINDOW_HEIGHT * sizeof( Uint32 ) ) ;

    ///////////////////////////////////////////////////////////////////////////

    //gfx_window_clear( ) ;
    //gfx_present( ) ;

    srand( time( NULL ) ) ;

    SDL_bool done = SDL_FALSE ;
    SDL_Event event ;

    state_keyboard = SDL_GetKeyboardState( NULL ) ;

    extern int game_setup( ) ;
    extern int game_loop( ) ;
    extern int game_event_keydown( int ) ;
    extern int game_event_keyup( int ) ;
    extern int game_event_mousebuttondown( int , int , int ) ;
    extern int game_event_mousebuttonup( int , int , int ) ;
    extern int game_event_mousemotion( int , int ) ;

    if( game_setup( ) == 0 ) {

        while( ! done ) {

            while( SDL_PollEvent( &event ) ) {

                if( event.type == SDL_QUIT ) {

                    done = SDL_TRUE ;

                }

                switch( event.type ) {

                    //////////////////////////////////////////////////////////

                    case SDL_KEYDOWN :

                        switch( event.key.keysym.sym ) {

                            case SDLK_ESCAPE :

                                done = SDL_TRUE ;
                                break ;

                            default :

                                if(event.key.repeat == 0) {

                                    game_event_keydown( event.key.keysym.sym );
                                }

                                break ;

                        }

                        break;

                    case SDL_KEYUP:

                        switch( event.key.keysym.sym ) {

                            default :

                                game_event_keyup( event.key.keysym.sym ) ;

                                break ;

                        }

                        break;

                    //////////////////////////////////////////////////////////

                    case SDL_MOUSEBUTTONDOWN :

                        game_event_mousebuttondown( event.button.button , event.motion.x , event.motion.y ) ;
                        break ;

                    case SDL_MOUSEBUTTONUP :

                        game_event_mousebuttonup( event.button.button , event.motion.x , event.motion.y ) ;
                        break ;

                    case SDL_MOUSEMOTION :

                        game_event_mousemotion( event.motion.x , event.motion.y ) ;
                        break ;


                    //////////////////////////////////////////////////////////

                }

            }

            gfx_window_clear( ) ;

            if( game_loop( ) != 0 ) {

                done = SDL_TRUE ;
                continue ;

            }

            gfx_present( ) ;

            SDL_Delay( 42 ) ;

        }

    }

    ///////////////////////////////////////////////////////////////////////////

    delete[ ] pixels ;

    SDL_DestroyTexture( texture_pixels ) ;

    SDL_DestroyRenderer( renderer1 ) ;
    SDL_DestroyWindow( window1 ) ;

    SDL_Quit( ) ;

    return( 0 ) ;

}
