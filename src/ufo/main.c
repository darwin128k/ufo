#include <ufo/ufo.h>

static void on_window_event(ufo_window_t *window, const SDL_Event *event,
                            void *userdata) {
    (void)window;
    (void)userdata;
    if (event->type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
        SDL_Event quit = {0};
        quit.type = SDL_EVENT_QUIT;
        SDL_PushEvent(&quit);
    }
}

int main(int argc, const char *argv[]) {
    (void)argc;
    (void)argv;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        return 1;
    }

    ufo_window_t window = {0};
    ufo_size_t size = {640, 480};
    ufo_window_create(&window, "UFO", &size);
    ufo_window_set_event_cb(&window, on_window_event);

    ufo_window_show(&window);

    while (!ufo_events_pump()) {
    }

    ufo_window_destroy(&window);

    SDL_Quit();
    return 0;
}
