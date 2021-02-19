#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct vec {
    int size;
    int data[];
};

struct vec *vec_create(int size, int mod) {
    srand(time(NULL));
    struct vec *new = malloc(sizeof *new + size * sizeof(*new->data));
    new->size = size;
    for(int i = 0; i < size; ++i)
        new->data[i] = rand() % mod;
    return new;
}

void vec_free(struct vec *this) {
    free(this);
}

void vec_print(struct vec *this) {
    printf("[ ");
    for(int i = 0; i < this->size; ++i)
        printf("%d ", this->data[i]);
    printf("]\n");
}

int main(void) {
    struct vec *vec = vec_create(10, 100);
    vec_print(vec);
    vec_free(vec);
}
