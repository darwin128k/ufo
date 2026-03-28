#include <lh/null.h>
#include <ufo/app.h>

bool ufo_app_init(ufo_app_t *app, ufo_driver_t *driver,
                  const char *application_id) {
    app->driver = driver;
    app->application_id = application_id;
    return ufo_driver_init(app->driver);
}

void ufo_app_shutdown(ufo_app_t *app) {
    ufo_driver_shutdown(app->driver);
}

void ufo_app_send_event(ufo_app_t *app, ufo_window_t *window,
                        const SDL_Event *event, void *userdata) {
    (void)app;
    window->event_cb(window, event, userdata);
}

bool ufo_app_pump_events(ufo_app_t *app) {
    (void)app;
    SDL_Event event;
    bool quit = false;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            quit = true;
        }

        SDL_Window *sdl_window = SDL_GetWindowFromEvent(&event);
        if (sdl_window != NULL) {
            SDL_PropertiesID props = SDL_GetWindowProperties(sdl_window);
            ufo_window_t *window = (ufo_window_t *)SDL_GetPointerProperty(
                props, UFO_WINDOW_SELF_PROP, lh_null);
            window->event_cb(window, &event, lh_null);
        }
    }

    return quit;
}
