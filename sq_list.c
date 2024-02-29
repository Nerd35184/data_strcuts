#include "sq_list.h"
#include <stdlib.h>
#include <stdint.h>

#define alloc_sq_list_definition(T)                       \
    alloc_sq_list_prototype(T)                            \
    {                                                     \
        SqList(T) *sq_list_p = malloc(sizeof(SqList(T))); \
        if (sq_list_p == NULL)                            \
        {                                                 \
            exit(-1);                                     \
        }                                                 \
        memset(sq_list_p, 0, sizeof(SqList(T)));          \
        sq_list_p->capacity = capacity;                   \
        sq_list_p->length = 0;                            \
        sq_list_p->elem_life_cycle = elem_life_cycle;     \
        sq_list_p->buf = NULL;                            \
        if (sq_list_p->capacity == 0)                     \
        {                                                 \
            goto end;                                     \
        }                                                 \
        sq_list_p->buf = malloc(capacity * sizeof(T));    \
        if (sq_list_p->buf == NULL)                       \
        {                                                 \
            exit(-1);                                     \
        }                                                 \
    end:                                                  \
        return sq_list_p;                                 \
    }

#define free_sq_list_definition(T)                                                                   \
    free_sq_list_prototype(T)                                                                        \
    {                                                                                                \
        if (sq_list_pp == NULL || *sq_list_pp == NULL)                                               \
        {                                                                                            \
            goto end;                                                                                \
        }                                                                                            \
        SqList(T) *sq_list_p = *sq_list_pp;                                                          \
        for (int i = 0; i < sq_list_p->length && sq_list_p->elem_life_cycle.destructor != NULL; ++i) \
        {                                                                                            \
            sq_list_p->elem_life_cycle.destructor(sq_list_p->buf + i);                               \
        }                                                                                            \
        free(sq_list_p->buf);                                                                        \
        free(sq_list_p);                                                                             \
        *sq_list_pp = NULL;                                                                          \
    end:                                                                                             \
        return;                                                                                      \
    }

#define get_sq_list_elem_definition(T)                         \
    get_sq_list_elem_prototype(T)                              \
    {                                                          \
        int ret = 0;                                           \
        if (sq_list_p == NULL || postion >= sq_list_p->length) \
        {                                                      \
            ret = -1;                                          \
            goto end;                                          \
        }                                                      \
                                                               \
        *result = sq_list_p->buf + postion;                    \
    end:                                                       \
        return ret;                                            \
    }

#define set_sq_list_elem_definition(T)                                 \
    set_sq_list_elem_prototype(T)                                      \
    {                                                                  \
        int ret = 0;                                                   \
        if (sq_list_p == NULL || postion >= sq_list_p->length)         \
        {                                                              \
            ret = -1;                                                  \
            goto end;                                                  \
        }                                                              \
        T *elem_p = sq_list_p->buf + postion;                          \
        *elem_p = elem;                                                \
        sq_list_p->elem_life_cycle.operator_assignment(elem_p, &elem); \
    end:                                                               \
        return ret;                                                    \
    }

#define insert_sq_list_definition(T)                                                    \
    insert_sq_list_prototype(T)                                                         \
    {                                                                                   \
        int ret = 0;                                                                    \
        if (sq_list_p == NULL)                                                          \
        {                                                                               \
            ret = -1;                                                                   \
            goto end;                                                                   \
        }                                                                               \
        if (position < 0 || position > sq_list_p->length)                               \
        {                                                                               \
            ret = -1;                                                                   \
            goto end;                                                                   \
        }                                                                               \
        int move_elem_count = sq_list_p->length - position;                             \
        if (sq_list_p->length >= sq_list_p->capacity)                                   \
        {                                                                               \
            int new_capacity = sq_list_p->capacity * 2;                                 \
            if (new_capacity == 0)                                                      \
            {                                                                           \
                new_capacity = 2;                                                       \
            }                                                                           \
            T *new_elem = realloc(sq_list_p->buf, new_capacity * sizeof(T));            \
            if (new_elem == NULL)                                                       \
            {                                                                           \
                printf("insert_sq_list realloc 1 errno:%d %s", errno, strerror(errno)); \
                exit(errno);                                                            \
            }                                                                           \
            sq_list_p->buf = new_elem;                                                  \
            sq_list_p->capacity = new_capacity;                                         \
        }                                                                               \
        T *src = sq_list_p->buf + position;                                             \
        T *dst = src + 1;                                                               \
        size_t move_byte_count = move_elem_count * sizeof(T);                           \
        memcpy(dst, src, move_byte_count);                                              \
        ++sq_list_p->length;                                                            \
        *src = elem;                                                                    \
        sq_list_p->elem_life_cycle.copy_constructor(src, &elem);                        \
    end:                                                                                \
        return ret;                                                                     \
    }

#define push_back_sq_list_definition(T)                               \
    push_back_sq_list_prototype(T)                                    \
    {                                                                 \
        if (sq_list_p == NULL)                                        \
        {                                                             \
            return -1;                                                \
        }                                                             \
        return insert_sq_list(T)(sq_list_p, elem, sq_list_p->length); \
    }

#define remove_sq_list_definition(T)                                      \
    remove_sq_list_prototype(T)                                           \
    {                                                                     \
        if (sq_list_p == NULL)                                            \
        {                                                                 \
            return -1;                                                    \
        }                                                                 \
        if (position < 0 || position >= sq_list_p->length)                \
        {                                                                 \
            return -1;                                                    \
        }                                                                 \
        sq_list_p->elem_life_cycle.destructor(sq_list_p->buf + position); \
        size_t move_elem_count = sq_list_p->length - position - 1;        \
        T *dst = sq_list_p->buf + position;                               \
        T *src = dst + 1;                                                 \
        size_t move_byte_count = move_elem_count * sizeof(T);             \
        memcpy(dst, src, move_byte_count);                                \
        --sq_list_p->length;                                              \
        return 0;                                                         \
    }

// call_sq_list_elem_operator_assignment_prototype(int);
// call_sq_list_elem_operator_assignment_definition(int);
// call_sq_list_elem_copy_constructor_prototype(int);
// call_sq_list_elem_copy_constructor_definition(int);
// call_sq_list_elem_destructor_prototype(int);
// call_sq_list_elem_destructor_definition(int);

alloc_sq_list_definition(int);
free_sq_list_definition(int);
get_sq_list_elem_definition(int);
set_sq_list_elem_definition(int);
insert_sq_list_definition(int);
push_back_sq_list_definition(int);
remove_sq_list_definition(int);