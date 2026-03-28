#ifndef UFO_UFO_H
#define UFO_UFO_H

#include <stdbool.h>
#include <ufo/window.h>

#define UFO_WINDOW_SELF_PROP "org.ufo.window.self"

void ufo_send_event(ufo_window_t *window, const SDL_Event *event,
                    void *userdata);

bool ufo_events_pump(void);

#endif // UFO_UFO_H
