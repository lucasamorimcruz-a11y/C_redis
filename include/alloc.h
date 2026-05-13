#include <stdlib.h>
#include <stdio.h>

void *alloc (size_t size, const char *file, int line){
    void *mem = malloc(size);
    if (mem == NULL){
        fprintf(stderr, "%s:%d Failed to allocate %zu bytes of memory\n", file, line, size);
        exit(EXIT_FAILURE);
    }
    else{
        return mem;
    }
}
#define ALLOC (SIZE) alloc ((SIZE), __FILE__, __LINE__)