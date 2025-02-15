#include "vector.h"

int main() {
    vector_t* my_vector = vector_new();
    vector_ctr(my_vector);

    vector_push_back(my_vector, 55);

    vector_print(my_vector, NOTHING);

    vector_push_back(my_vector, 65);
    vector_push_back(my_vector, 66);
    vector_push_back(my_vector, 67);
    vector_push_back(my_vector, 68);

    printf("Vector Size before Pop: %d\n", vector_size(my_vector));
    printf("Vector Capacity before Pop: %d\n", vector_capacity(my_vector));
        
    vector_pop_back(my_vector);

    for(int i = 0; i<4; i++) {
        printf("Element at %d: %d\n", i, vector_at(my_vector, i));
    }

    printf("Vector Size after Pop: %d\n", vector_size(my_vector));
    printf("Vector Capacity after Pop: %d\n", vector_capacity(my_vector));

    /* Remove first element only */
    vector_erase(my_vector, vector_begin(my_vector), NULL); 
    /* Remove all Elements from second to last */
    vector_erase(my_vector, vector_begin(my_vector) + 1, vector_end(my_vector)); 
    
    for(int i = 0; i<vector_size(my_vector); i++) {
        printf("Element at %d: %d\n", i, vector_at(my_vector, i));
    }

    printf("Vector Size after Erase: %d\n", vector_size(my_vector));
    printf("Vector Capacity after Erase: %d\n", vector_capacity(my_vector));
}