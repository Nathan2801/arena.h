/** The arena structure */
typedef struct Arena {
    void *ptr;
    int index;
    size_t size;
} Arena;

/** Initialize the arena */
void init_arena(Arena *, size_t);

/** Free the arena */
void free_arena(Arena *);

/** Reallocate the arena */
void realloc_arena(Arena *, size_t);

/** Allocate some space in the arena */
void *arena_alloc(Arena *, size_t);

#ifdef ARENA_C_IMPLEMENTATION

#include <assert.h>
#include <stdlib.h>

#define ARENA_ALLOC(arena, type) arena_alloc(&arena, sizeof(type))

void init_arena(Arena *arena, size_t size) {
    arena->ptr = malloc(size);
    arena->index = 0;
    arena->size = size;
}

void free_arena(Arena *arena) {
    free(arena->ptr);
    arena->ptr = NULL;
}

void realloc_arena(Arena *arena, size_t size) {
    arena->ptr = realloc(arena->ptr, size);
    arena->size = size;
}

void *arena_alloc(Arena *arena, size_t size) {
    assert(arena->size - arena->index >= size);
    void *ptr = (char *) arena->ptr + arena->index;
    arena->index += size;
    return ptr;
}

#endif
