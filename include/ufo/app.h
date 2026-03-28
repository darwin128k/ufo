#ifndef UFO_APP_H
#define UFO_APP_H

#include <stdbool.h>
#include <ufo/driver.h>
#include <ufo/monitor.h>
#include <ufo/window.h>

#define UFO_MAX_WINDOWS 1024

typedef struct ufo_app {
    ufo_driver_t *driver;
    ufo_window_t windows[UFO_MAX_WINDOWS];
    const char *application_id;
} ufo_app_t;

bool ufo_app_init(ufo_app_t *app, ufo_driver_t *driver,
                  const char *application_id);
void ufo_app_shutdown(ufo_app_t *app);

void ufo_app_send_event(ufo_app_t *app, ufo_window_t *window,
                        const SDL_Event *event, void *userdata);

bool ufo_app_pump_events(ufo_app_t *app);

#endif // UFO_APP_H
