#include "vector.h"

static const int DEFAULT_CAPACITY = 4;

typedef struct vector_t {
    int* elements;
    int capacity;
    int size;
} vector_t;

vector_t* vector_new() {
    #ifdef _DEBUG
    printf("Initialised vector");
    #endif
    return (vector_t*) malloc(sizeof(vector_t));
}

void vector_ctr(vector_t* obj) {
    obj->elements = calloc(DEFAULT_CAPACITY, sizeof(int));
    obj->capacity = DEFAULT_CAPACITY;
    obj->size= 0;
    #ifdef _DEBUG
    printf("Created vector");
    #endif
}

void vector_dtr(vector_t* obj) {
    free(obj->elements);
    free(obj);
    #ifdef _DEBUG
    printf("Destroyed instance of vector");
    #endif
}

int vector_size(vector_t* obj) {
    return obj->size;
}

int vector_capacity(vector_t* obj) {
    return obj->capacity;
}

// Function adds more space to the vector's capacity if it is full
// In powers in 2 (0,0; 1,4; 5,8)
void vector_push_back(vector_t* obj, const int element) {
    // If the vector is full
    if(obj->size > 0 && obj->size % obj->capacity == 0) {
        obj->capacity = (obj->size / DEFAULT_CAPACITY + 1) * DEFAULT_CAPACITY;
        obj->elements = realloc(obj->elements, obj->capacity * sizeof(int));
        printf("New Allocation: %d\n", obj->capacity);
    }
    obj->elements[obj->size++] = element;
}

void vector_print(vector_t* obj, char additional_text[]) {
    printf("Vector Size %s: %d\n", additional_text, vector_size(obj));
    printf("Vector Capacity %s: %d\n", additional_text, vector_capacity(obj));
}

int vector_at(vector_t* obj, const int index) {
    return obj->elements[index];
}

int* vector_begin(vector_t* obj) {
    return &obj->elements[0];
}

int* vector_end(vector_t* obj) {
    return &obj->elements[obj->size];
}

void vector_pop_back(vector_t* obj) {
    int lastIndex = obj->size - 1;
    obj->elements[lastIndex] = 0;
    obj->size--;
}

void vector_erase(vector_t* obj, int* first, int* last) {
    int lastElement = (obj->size - 1);
    int firstElement = first - &obj->elements[0];

    for (int i = firstElement ; i < lastElement ; i++) {
        obj->elements[i] = obj->elements[i+1];
    }

    obj->size -= (last - first) > 0 ? (last - first) : 1;
}