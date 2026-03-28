#ifndef UFO_WINDOW_H
#define UFO_WINDOW_H

#include <SDL3/SDL.h>
#include <ufo/opacity.h>
#include <ufo/point.h>
#include <ufo/size.h>

typedef struct ufo_window ufo_window_t;

typedef void (*ufo_window_event_cb)(ufo_window_t *window,
                                    const SDL_Event *event, void *userdata);

struct ufo_window {
    SDL_Window *handle;
    ufo_window_event_cb event_cb;
};

#define UFO_WINDOW_SELF_PROP "org.ufo.window.self"

void ufo_window_create(ufo_window_t *self, const char *title,
                       const ufo_size_t *size);
void ufo_window_get_size(ufo_window_t *self, ufo_size_t *size);
ufo_extent_t ufo_window_get_width(ufo_window_t *self);
ufo_extent_t ufo_window_get_height(ufo_window_t *self);
void ufo_window_set_size(ufo_window_t *self, const ufo_size_t *size);
void ufo_window_set_width(ufo_window_t *self, ufo_extent_t width);
void ufo_window_set_height(ufo_window_t *self, ufo_extent_t height);

void ufo_window_get_position(ufo_window_t *self, ufo_point_t *position);
ufo_coord_t ufo_window_get_x(ufo_window_t *self);
ufo_coord_t ufo_window_get_y(ufo_window_t *self);
void ufo_window_set_position(ufo_window_t *self, const ufo_point_t *position);
void ufo_window_set_x(ufo_window_t *self, ufo_coord_t x);
void ufo_window_set_y(ufo_window_t *self, ufo_coord_t y);

ufo_opacity_t ufo_window_get_opacity(ufo_window_t *self);
void ufo_window_set_opacity(ufo_window_t *self, ufo_opacity_t opacity);

const char *ufo_window_get_title(ufo_window_t *self);
void ufo_window_set_title(ufo_window_t *self, const char *title);

void ufo_window_show(ufo_window_t *self);
void ufo_window_hide(ufo_window_t *self);
void ufo_window_raise(ufo_window_t *self);
void ufo_window_destroy(ufo_window_t *self);

void ufo_window_attach(ufo_window_t *self);
void ufo_window_detach(ufo_window_t *self);

void ufo_window_set_event_cb(ufo_window_t *self, ufo_window_event_cb cb);

#endif // UFO_WINDOW_H