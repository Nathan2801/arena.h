# Arena.h

This is a simple implementation of an arena allocator in C.

Single-header file concept was stolen from [stb libraries](https://github.com/nothings/stb).

```c
#define ARENA_C_IMPLEMENTATION
#include "arena.h"

...

Arena arena;
init_arena(&arena, 69);

char *name = ARENA_ALLOC(arena, char[10]);
memcpy(name, "johnathan\0", 10);

printf("name = %s\n", name);

free_arena(&arena);
```
