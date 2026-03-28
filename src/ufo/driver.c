#include <ufo/driver.h>
#include <ufo/driver/sdl.h>

bool ufo_driver_init(ufo_driver_t *driver) {
    switch (driver->kind) {
    case UFO_DRIVER_KIND_NONE:
        return true;
    case UFO_DRIVER_KIND_SDL:
        return ufo_driver_sdl_init(driver);
    default:
        return false;
    }
}

void ufo_driver_shutdown(ufo_driver_t *driver) {
    switch (driver->kind) {
    case UFO_DRIVER_KIND_SDL:
        ufo_driver_sdl_shutdown(driver);
        break;
    default:
        break;
    }
}
