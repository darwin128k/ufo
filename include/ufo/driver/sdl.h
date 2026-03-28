#ifndef UFO_DRIVER_SDL_H
#define UFO_DRIVER_SDL_H

#include <ufo/driver.h>

typedef struct ufo_driver_sdl {
    ufo_driver_t base;
} ufo_driver_sdl_t;

bool ufo_driver_sdl_init(ufo_driver_t *driver);

void ufo_driver_sdl_shutdown(ufo_driver_t *driver);

#endif // UFO_DRIVER_SDL_H
