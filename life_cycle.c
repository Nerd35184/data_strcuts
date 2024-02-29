#include "life_cycle.h"
#include <stdlib.h>

void empty_default_constructor(void *elem)
{
}

void empty_copy_constructor(void *dst, const void *src)
{
}

void empty_destructor(void *elem)
{
}

void empty_operator_assignment(void *dst, const void *src)
{
}

LifeCycle new_life_cycle(
    void (*constructor)(void *elem),
    void (*copy_constructor)(void *dst, const void *src),
    void (*operator_assignment)(void *dst, const void *src),
    void (*destructor)(void *elem))
{
    LifeCycle life_cycle;
    life_cycle.default_constructor = constructor;
    life_cycle.copy_constructor = copy_constructor;
    life_cycle.destructor = destructor;
    life_cycle.operator_assignment = operator_assignment;
    if (life_cycle.default_constructor == NULL)
    {
        life_cycle.default_constructor = empty_default_constructor;
    }

    if (life_cycle.destructor == NULL)
    {
        life_cycle.destructor = empty_destructor;
    }

    if (life_cycle.copy_constructor == NULL)
    {
        life_cycle.copy_constructor = empty_copy_constructor;
    }
    if (life_cycle.operator_assignment == NULL)
    {
        life_cycle.operator_assignment = empty_operator_assignment;
    }
    return life_cycle;
}

int check_life_cycle(LifeCycle life_cycle)
{
    if (life_cycle.default_constructor == NULL || life_cycle.copy_constructor == NULL || life_cycle.destructor == NULL)
    {
        return -1;
    }
    return 0;
}
