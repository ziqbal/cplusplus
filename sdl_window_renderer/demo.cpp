#include <iostream>
#include <SDL2/SDL.h>

int main()
{
    /* Starting SDL */
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    /* Create a Window */
    SDL_Window *window = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    /* Create a Render */
    SDL_Renderer *render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (render == nullptr) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return 1;
    }


    SDL_SetRenderDrawColor(render, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(render,10,10,100,100);

    SDL_RenderPresent(render); // Show render on window

    SDL_Delay(5000);

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}