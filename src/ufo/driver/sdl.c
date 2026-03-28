#include <SDL3/SDL.h>
#include <stddef.h>
#include <ufo/driver/sdl.h>

bool ufo_driver_sdl_init(ufo_driver_t *driver) {
    (void)driver;
    return SDL_Init(SDL_INIT_VIDEO);
}

void ufo_driver_sdl_shutdown(ufo_driver_t *driver) {
    (void)driver;
    SDL_Quit();
}
