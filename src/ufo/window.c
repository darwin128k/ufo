#include <ufo/null.h>
#include <ufo/ufo.h>

void ufo_window_attach(ufo_window_t *self) {
    SDL_PropertiesID props = SDL_GetWindowProperties(self->handle);
    SDL_SetPointerProperty(props, UFO_WINDOW_SELF_PROP, self);
}

void ufo_window_detach(ufo_window_t *self) {
    SDL_PropertiesID props = SDL_GetWindowProperties(self->handle);
    SDL_SetPointerProperty(props, UFO_WINDOW_SELF_PROP, ufo_null);
    self->handle = ufo_null;
    self->event_cb = ufo_null;
}

void ufo_window_create(ufo_window_t *self, const char *title,
                       const ufo_size_t *size) {
    self->handle =
        SDL_CreateWindow(title, (int)size->width, (int)size->height, 0);
    ufo_window_attach(self);
}

void ufo_window_get_size(ufo_window_t *self, ufo_size_t *size) {
    SDL_GetWindowSize(self->handle, (int *)&size->width, (int *)&size->height);
}

ufo_extent_t ufo_window_get_width(ufo_window_t *self) {
    ufo_size_t size = {0, 0};
    ufo_window_get_size(self, &size);
    return size.width;
}

ufo_extent_t ufo_window_get_height(ufo_window_t *self) {
    ufo_size_t size = {0, 0};
    ufo_window_get_size(self, &size);
    return size.height;
}

void ufo_window_set_size(ufo_window_t *self, const ufo_size_t *size) {
    SDL_SetWindowSize(self->handle, size->width, size->height);
}

void ufo_window_set_width(ufo_window_t *self, ufo_extent_t width) {
    ufo_size_t size = {0, 0};
    ufo_window_get_size(self, &size);
    size.width = width;
    ufo_window_set_size(self, &size);
}

void ufo_window_set_height(ufo_window_t *self, ufo_extent_t height) {
    ufo_size_t size = {0, 0};
    ufo_window_get_size(self, &size);
    size.height = height;
    ufo_window_set_size(self, &size);
}

void ufo_window_get_position(ufo_window_t *self, ufo_point_t *position) {
    SDL_GetWindowPosition(self->handle, &position->x, &position->y);
}

ufo_coord_t ufo_window_get_x(ufo_window_t *self) {
    ufo_point_t position = {0, 0};
    ufo_window_get_position(self, &position);
    return position.x;
}

ufo_coord_t ufo_window_get_y(ufo_window_t *self) {
    ufo_point_t position = {0, 0};
    ufo_window_get_position(self, &position);
    return position.y;
}

void ufo_window_set_position(ufo_window_t *self, const ufo_point_t *position) {
    SDL_SetWindowPosition(self->handle, position->x, position->y);
}

void ufo_window_set_x(ufo_window_t *self, ufo_coord_t x) {
    ufo_point_t position = {0, 0};
    ufo_window_get_position(self, &position);
    position.x = x;
    ufo_window_set_position(self, &position);
}

void ufo_window_set_y(ufo_window_t *self, ufo_coord_t y) {
    ufo_point_t position = {0, 0};
    ufo_window_get_position(self, &position);
    position.y = y;
    ufo_window_set_position(self, &position);
}

ufo_opacity_t ufo_window_get_opacity(ufo_window_t *self) {
    float f = SDL_GetWindowOpacity(self->handle);
    if (f < 0.0f || f > 1.0f) {
        f = 1.0f;
    }
    return (ufo_opacity_t)(f * 255.0f + 0.5f);
}

void ufo_window_set_opacity(ufo_window_t *self, ufo_opacity_t opacity) {
    SDL_SetWindowOpacity(self->handle, (float)opacity / 255.0f);
}

const char *ufo_window_get_title(ufo_window_t *self) {
    return SDL_GetWindowTitle(self->handle);
}

void ufo_window_set_title(ufo_window_t *self, const char *title) {
    SDL_SetWindowTitle(self->handle, title);
}

void ufo_window_show(ufo_window_t *self) {
    SDL_ShowWindow(self->handle);
}

void ufo_window_hide(ufo_window_t *self) {
    SDL_HideWindow(self->handle);
}

void ufo_window_raise(ufo_window_t *self) {
    SDL_RaiseWindow(self->handle);
}

void ufo_window_destroy(ufo_window_t *self) {
    SDL_Window *w = self->handle;
    ufo_window_detach(self);
    SDL_DestroyWindow(w);
}

void ufo_window_set_event_cb(ufo_window_t *self, ufo_window_event_cb cb) {
    self->event_cb = cb;
}
