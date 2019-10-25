#include "SDL2/SDL.h"
#include <iostream>
#include <sstream>


unsigned long long frame = 0 ;
int mouseX = -1 ;
int mouseY = -1 ;



int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;


            while (!done) {

                std::cout << frame << "\n";
                frame++;

                SDL_Event event;

                SDL_Delay( 42 ) ;
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

                SDL_RenderDrawLine(renderer, 320, 200, 300, 240);
                SDL_RenderDrawLine(renderer, 300, 240, 340, 240);
                SDL_RenderDrawLine(renderer, 340, 240, 320, 200);

                SDL_RenderDrawPoint(renderer,rand()%640,rand()%480);

                if(mouseX!=-1){
                    for(int i = 0;i<64;i++){
                        SDL_RenderDrawLine(renderer, i*10, 0, mouseX, mouseY);
                        SDL_RenderDrawLine(renderer, i*10, 480, mouseX, mouseY);
                    }
                    for(int i = 0;i<48;i++){
                        SDL_RenderDrawLine(renderer, 0,i*10, mouseX, mouseY);
                        SDL_RenderDrawLine(renderer, 640,i*10, mouseX, mouseY);
                    }
                }

                SDL_RenderPresent(renderer);


                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        done = SDL_TRUE;
                    }
                    switch (event.type) {
                        case SDL_MOUSEBUTTONDOWN:
                            switch (event.button.button)
                            {
                                case SDL_BUTTON_LEFT:
                                    SDL_ShowSimpleMessageBox(0, "Mouse", "Left button was pressed!", window);
                                    break;
                                case SDL_BUTTON_RIGHT:
                                    SDL_ShowSimpleMessageBox(0, "Mouse", "Right button was pressed!", window);
                                    break;
                                default:
                                    SDL_ShowSimpleMessageBox(0, "Mouse", "Some other button was pressed!", window);
                                    break;
                            }
                            break;
                        case SDL_MOUSEMOTION:
                            mouseX = event.motion.x;
                            mouseY = event.motion.y;
                         
                            std::stringstream ss;
                            ss << "X: " << mouseX << " Y: " << mouseY;
                         
                            SDL_SetWindowTitle(window, ss.str().c_str());
                            break;

                    }

                }
            }
        }

        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
    return 0;
}
