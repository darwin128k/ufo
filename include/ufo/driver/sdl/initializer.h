#ifndef UFO_DRIVER_SDL_INITIALIZER_H
#define UFO_DRIVER_SDL_INITIALIZER_H

#include <ufo/driver/sdl.h>

#define ufo_driver_sdl_initializer                                             \
    ((ufo_driver_sdl_t){                                                       \
        .base = {.kind = UFO_DRIVER_KIND_SDL, .backend = NULL},                \
    })

#endif /* UFO_DRIVER_SDL_INITIALIZER_H */
