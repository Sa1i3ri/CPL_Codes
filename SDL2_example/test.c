//
// Created by 14832 on 2023/1/10.
//


#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_main.h"
#include "stdio.h"


void LOAD();
void QUIT();



SDL_Window *Window = NULL;
SDL_Renderer *Renderer = NULL;
SDL_Surface *MainBackGroundSurface = NULL;
SDL_Texture *MainBackGroundTexture = NULL;
SDL_Rect MainBackGroundRect;


int SDL_main(int argc, char *argv[]){
    SDL_Init(SDL_INIT_VIDEO);

    Window = SDL_CreateWindow("Example",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,1000,SDL_WINDOW_SHOWN);
    Renderer = SDL_CreateRenderer(Window,-1,SDL_RENDERER_ACCELERATED);

    SDL_Event MainEvent;
    LOAD();

    SDL_RenderClear(Renderer);
    SDL_RenderCopy(Renderer,MainBackGroundTexture,NULL,&MainBackGroundRect);
    SDL_RenderPresent(Renderer);

    while (SDL_WaitEvent(&MainEvent)){
        switch (MainEvent.type) {
            case SDL_QUIT:
                QUIT();
                break;
            case SDL_KEYDOWN:
                switch (MainEvent.key.keysym.sym) {
                    case SDLK_RETURN:
                        //some function
                        break;
                    case SDLK_ESCAPE:
                        QUIT();
                        break;
                    case SDLK_w:
                        //some function
                        break;
                    default:
                        break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                //function
                printf("(%d,%d)\n",MainEvent.button.x,MainEvent.button.y);
                break;
            case SDL_MOUSEBUTTONUP:
                printf("(%d,%d)\n",MainEvent.button.x,MainEvent.button.y);
                break;
            case SDL_MOUSEMOTION:
                break;
            default:
                break;
        }


    }


    QUIT();
}

void LOAD(){
    MainBackGroundSurface = IMG_Load("MainBackGround.jpg");
    MainBackGroundTexture = SDL_CreateTextureFromSurface(Renderer,MainBackGroundSurface);
    MainBackGroundRect.x = 0;
    MainBackGroundRect.y = 0;
    MainBackGroundRect.w = MainBackGroundSurface->w;
    MainBackGroundRect.h = MainBackGroundSurface->h;
}


void QUIT(){
    SDL_DestroyWindow(Window);
    SDL_DestroyRenderer(Renderer);
    SDL_Quit();
}
