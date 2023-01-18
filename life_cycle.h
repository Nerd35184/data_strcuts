

typedef struct LifeCycle{
    void (*constructor)(void* elem);
    void (*destructor)(void* elem);
    void (*copy_constructor)(void* dst,const void* src);
}LifeCycle;