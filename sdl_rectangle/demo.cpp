
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <sstream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main( int argc , char* argv[ ] ) {


    SDL_Rect r1;
    r1.x = 50;
    r1.y = 50;
    r1.w = 50;
    r1.h = 50;
    SDL_Rect rectangle2;
    rectangle2.x = 200;
    rectangle2.y = 200;
    rectangle2.w = 50;
    rectangle2.h = 100;

    if( SDL_Init( SDL_INIT_EVERYTHING ) != 0 ) {

        std::cout << "SDL_Init Error: " << SDL_GetError( ) << std::endl ;
        return( 1 ) ;

    }

    ///////////////////////////////////////////////////////////////////////////

    SDL_Window *window1 = SDL_CreateWindow( "Hello World!" , 100 , 100 , WINDOW_WIDTH , WINDOW_HEIGHT , SDL_WINDOW_SHOWN ) ;

    if( window1 == nullptr ) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit( ) ;
        return( 1 ) ;
    }

    ///////////////////////////////////////////////////////////////////////////

    SDL_Renderer *renderer1 = SDL_CreateRenderer( window1 , -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ) ;

    if( renderer1 == nullptr ) {

        SDL_DestroyWindow( window1 ) ;
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError( ) << std::endl ;
        SDL_Quit( ) ;
        return( 1 ) ;

    }

    ///////////////////////////////////////////////////////////////////////////

    SDL_SetRenderDrawBlendMode(renderer1, SDL_BLENDMODE_BLEND);


    SDL_Texture* tex = IMG_LoadTexture( renderer1, "test.png" );
    if (tex == nullptr){
        SDL_DestroyRenderer(renderer1);
        SDL_DestroyWindow(window1);
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }


    int tex_w, tex_h; // texture width & height

    SDL_QueryTexture(tex, NULL, NULL, &tex_w, &tex_h);

    std::cout << tex_w << "," << tex_h << "\n" ;

    ///////////////////////////////////////////////////////////////////////////

    for (int i = 0; i < 3; ++i){
        std::cout << "Z\n";
                SDL_SetRenderDrawColor(renderer1, 0, 128, 0, SDL_ALPHA_OPAQUE);
        //First clear the renderer
        SDL_RenderClear(renderer1);
                SDL_SetRenderDrawColor(renderer1, 255, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawLine(renderer1, 0, 0, 300, 240);
        //Draw the texture
        //SDL_RenderCopy(renderer1, tex, &r1, &rectangle2);
        SDL_RenderCopy(renderer1, tex,NULL, &rectangle2);


    SDL_Rect rectangle3;
    rectangle3.x = 400;
    rectangle3.y = 400;
    rectangle3.w = 200;
    rectangle3.h = 100;
                SDL_SetRenderDrawColor(renderer1, 0, 0, 255, 32);

        SDL_RenderFillRect(renderer1,&rectangle3);

        //Update the screen
        SDL_RenderPresent(renderer1);
        //Take a quick break after all that hard work
        SDL_Delay(1000);
    }

    ///////////////////////////////////////////////////////////////////////////

    std::cout << "OK!" << std::endl ;

    SDL_Delay( 3000 ) ;

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(renderer1);
    SDL_DestroyWindow(window1);

    SDL_Quit( ) ;
    return( 0 ) ;

}
