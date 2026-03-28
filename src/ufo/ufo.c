#include <ufo/ufo.h>

void ufo_send_event(ufo_window_t *window, const SDL_Event *event,
                    void *userdata) {
    window->event_cb(window, event, userdata);
}

bool ufo_events_pump(void) {
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
                props, UFO_WINDOW_SELF_PROP, NULL);
            window->event_cb(window, &event, NULL);
        }
    }

    return quit;
}
