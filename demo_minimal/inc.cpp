
#include "SDL2/SDL.h"
#include <iostream>
#include <sstream>

using namespace std ;

SDL_Window *window1 ;
SDL_Renderer *renderer1 ;

#include "functions.cpp"

int main( int argc , char* argv[ ] ) {

    if( SDL_Init( SDL_INIT_EVERYTHING ) != 0 ) {

        cout << "SDL_Init Error: " << SDL_GetError( ) << endl ;
        return( 1 ) ;

    }

    ///////////////////////////////////////////////////////////////////////////

    window1 = SDL_CreateWindow( "Hello World!" , 100 , 100 , 640 , 480 , SDL_WINDOW_SHOWN ) ;

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

    gfx_window_clear( ) ;
    gfx_present( ) ;

    srand( time( NULL ) ) ;

    SDL_bool done = SDL_FALSE ;
    SDL_Event event;

    extern int demo_setup( ) ;
    extern int demo_loop( ) ;
    extern int demo_event_keydown( int ) ;

    if( demo_setup( ) == 0 ) {

        while( !done ) {

            if( demo_loop( ) != 0 ) {

                done = SDL_TRUE ;
                continue ;

            }

            while( SDL_PollEvent( &event ) ) {

                if( event.type == SDL_QUIT ) {

                    done = SDL_TRUE ;

                }

                switch( event.type ) {

                    case SDL_KEYDOWN :

                        switch( event.key.keysym.sym ) {

                            case SDLK_ESCAPE : 
                                done = SDL_TRUE ;
                                break ;

                            default :

                                demo_event_keydown( event.key.keysym.sym ) ;

                                break ;

                        }

                        break;

                }

            }

            SDL_Delay( 42 ) ;

        }

    }
    
    ///////////////////////////////////////////////////////////////////////////

    SDL_DestroyRenderer( renderer1 ) ;
    SDL_DestroyWindow( window1 ) ;

    SDL_Quit( ) ;

    return( 0 ) ;

}
