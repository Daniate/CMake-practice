#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_net.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

#define SHOW_VERSION(NAME, P_VER) printf("%s: %u.%u.%u\n", #NAME, (P_VER)->major, (P_VER)->minor, (P_VER)->patch)

int main(int argc, char const *argv[]) {
    
    int err = -1;
    err = SDL_Init(SDL_INIT_EVERYTHING);
    SDL_assert(0 == err);

    const SDL_version *version_img = IMG_Linked_Version();
    const SDL_version *version_mix = Mix_Linked_Version();
    const SDL_version *version_net = SDLNet_Linked_Version();
    const SDL_version *version_ttf = TTF_Linked_Version();

    printf("SDL init successfully\n");

    SHOW_VERSION(IMG, version_img);
    SHOW_VERSION(MIX, version_mix);
    SHOW_VERSION(NET, version_net);
    SHOW_VERSION(TTF, version_ttf);

    return 0;
}
