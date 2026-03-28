#ifndef UFO_DRIVER_H
#define UFO_DRIVER_H

#include <stdbool.h>

typedef enum ufo_driver_kind {
    UFO_DRIVER_KIND_NONE = 0,
    UFO_DRIVER_KIND_SDL,
} ufo_driver_kind_t;

typedef struct ufo_driver {
    ufo_driver_kind_t kind;
    void *backend;
} ufo_driver_t;

bool ufo_driver_init(ufo_driver_t *driver);
void ufo_driver_shutdown(ufo_driver_t *driver);

#endif // UFO_DRIVER_H
