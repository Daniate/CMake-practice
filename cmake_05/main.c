#include <SDL2/SDL.h>
#include <SDL2/SDL2_framerate.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int err = -1;

    err = SDL_Init(SDL_INIT_EVERYTHING);
    SDL_assert(0 == err);

    printf("SDL init successfully.\n");

    return 0;
}
