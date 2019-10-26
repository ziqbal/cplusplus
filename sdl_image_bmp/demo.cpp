
#include "SDL2/SDL.h"
#include <iostream>
#include <sstream>

int main( int argc , char* argv[ ] ) {

    if( SDL_Init( SDL_INIT_EVERYTHING ) != 0 ) {

        std::cout << "SDL_Init Error: " << SDL_GetError( ) << std::endl ;
        return( 1 ) ;

    }

    ///////////////////////////////////////////////////////////////////////////

    SDL_Window *window1 = SDL_CreateWindow( "Hello World!" , 100 , 100 , 640 , 480 , SDL_WINDOW_SHOWN ) ;

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

    std::string imagePath = "test.bmp";
    SDL_Surface *bmp = SDL_LoadBMP(imagePath.c_str());
    if (bmp == nullptr){
        SDL_DestroyRenderer(renderer1);
        SDL_DestroyWindow(window1);
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    ///////////////////////////////////////////////////////////////////////////

    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer1, bmp);
    SDL_FreeSurface(bmp);
    if (tex == nullptr){
        SDL_DestroyRenderer(renderer1);
        SDL_DestroyWindow(window1);
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    ///////////////////////////////////////////////////////////////////////////

    for (int i = 0; i < 3; ++i){
        std::cout << "Z\n";
                SDL_SetRenderDrawColor(renderer1, 0, 128, 0, SDL_ALPHA_OPAQUE);
        //First clear the renderer
        SDL_RenderClear(renderer1);
                SDL_SetRenderDrawColor(renderer1, 255, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawLine(renderer1, 0, 0, 300, 240);
        //Draw the texture
        SDL_RenderCopy(renderer1, tex, NULL, NULL);
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
