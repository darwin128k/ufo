#include <lh/array.h>
#include <lh/null.h>
#include <lh/size.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

static bool bytes_mul_ok(lh_usize_t n, lh_usize_t elem_size,
                         lh_usize_t *out_bytes) {
    if (elem_size == 0 || n == 0) {
        *out_bytes = n * elem_size;
        return elem_size != 0 || n == 0;
    }
    if (n > (lh_usize_t)(UINT_MAX / elem_size)) {
        return false;
    }
    *out_bytes = n * elem_size;
    return true;
}

void lh_array_init(lh_array_t *a, lh_usize_t elem_size) {
    a->data = lh_null;
    a->size = 0;
    a->capacity = 0;
    a->elem_size = elem_size;
}

void lh_array_deinit(lh_array_t *a) {
    free(a->data);
    a->data = lh_null;
    a->size = 0;
    a->capacity = 0;
    a->elem_size = 0;
}

bool lh_array_reserve(lh_array_t *a, lh_usize_t capacity) {
    if (a->elem_size == 0) {
        return capacity == 0;
    }
    if (capacity <= a->capacity) {
        return true;
    }
    lh_usize_t bytes = 0;
    if (!bytes_mul_ok(capacity, a->elem_size, &bytes)) {
        return false;
    }
    void *p = realloc(a->data, bytes);
    if (p == lh_null && bytes != 0) {
        return false;
    }
    a->data = p;
    a->capacity = capacity;
    return true;
}

bool lh_array_resize(lh_array_t *a, lh_usize_t size, const void *fill_elem) {
    if (a->elem_size == 0) {
        return size == 0;
    }
    if (size > a->size) {
        lh_usize_t need = size;
        if (need > a->capacity) {
            if (!lh_array_reserve(a, need)) {
                return false;
            }
        }
        char *base = (char *)a->data + a->size * a->elem_size;
        lh_usize_t extra = size - a->size;
        lh_usize_t span = 0;
        if (!bytes_mul_ok(extra, a->elem_size, &span)) {
            return false;
        }
        if (fill_elem != lh_null) {
            for (lh_usize_t i = 0; i < extra; i++) {
                memcpy(base + i * a->elem_size, fill_elem, a->elem_size);
            }
        } else {
            memset(base, 0, span);
        }
    }
    a->size = size;
    return true;
}

bool lh_array_push(lh_array_t *a, const void *elem) {
    if (a->elem_size == 0 || elem == lh_null) {
        return false;
    }
    if (a->size == a->capacity) {
        lh_usize_t new_cap = a->capacity ? a->capacity * 2 : 8;
        if (a->size + 1 > new_cap) {
            new_cap = a->size + 1;
        }
        if (!lh_array_reserve(a, new_cap)) {
            return false;
        }
    }
    memcpy((char *)a->data + a->size * a->elem_size, elem, a->elem_size);
    a->size++;
    return true;
}

void lh_array_pop(lh_array_t *a) {
    if (a->size == 0) {
        return;
    }
    a->size--;
}

bool lh_array_pop_copy(lh_array_t *a, void *out) {
    if (a->size == 0 || out == lh_null || a->elem_size == 0) {
        return false;
    }
    a->size--;
    memcpy(out, (char *)a->data + a->size * a->elem_size, a->elem_size);
    return true;
}

void lh_array_clear(lh_array_t *a) {
    a->size = 0;
}

void *lh_array_at(lh_array_t *a, lh_usize_t index) {
    if (a->elem_size == 0 || index >= a->size) {
        return lh_null;
    }
    return (char *)a->data + index * a->elem_size;
}

const void *lh_array_at_const(const lh_array_t *a, lh_usize_t index) {
    if (a->elem_size == 0 || index >= a->size) {
        return lh_null;
    }
    return (const char *)a->data + index * a->elem_size;
}

lh_usize_t lh_array_len(const lh_array_t *a) {
    return a->size;
}

bool lh_array_is_empty(const lh_array_t *a) {
    return a->size == 0;
}
