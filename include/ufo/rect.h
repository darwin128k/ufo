#ifndef UFO_RECT_H
#define UFO_RECT_H

#include <ufo/point.h>
#include <ufo/size.h>

typedef struct ufo_rect {
    ufo_point_t point;
    ufo_size_t size;
} ufo_rect_t;

#endif // UFO_RECT_H
