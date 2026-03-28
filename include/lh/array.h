#ifndef LH_ARRAY_H
#define LH_ARRAY_H

#include <stdbool.h>
#include <lh/size.h>

typedef struct lh_array {
    void *data;
    lh_usize_t size;
    lh_usize_t capacity;
    lh_usize_t elem_size;
} lh_array_t;

void lh_array_init(lh_array_t *a, lh_usize_t elem_size);
void lh_array_deinit(lh_array_t *a);

bool lh_array_reserve(lh_array_t *a, lh_usize_t capacity);
bool lh_array_resize(lh_array_t *a, lh_usize_t size, const void *fill_elem);

bool lh_array_push(lh_array_t *a, const void *elem);
void lh_array_pop(lh_array_t *a);
bool lh_array_pop_copy(lh_array_t *a, void *out);

void lh_array_clear(lh_array_t *a);

void *lh_array_at(lh_array_t *a, lh_usize_t index);
const void *lh_array_at_const(const lh_array_t *a, lh_usize_t index);

lh_usize_t lh_array_len(const lh_array_t *a);
bool lh_array_is_empty(const lh_array_t *a);

#endif /* LH_ARRAY_H */
