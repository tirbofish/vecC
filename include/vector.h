#ifndef VECTOR_H
#define VECTOR_H

#include "stdlib.h"
#include "stdio.h"

// Literally defines nothing as an empty string to add to the
// args for the vector_print function
#define NOTHING ""

// Struct storing the vector. This information 
// includes the elements, the size and its capacity.  
typedef struct vector_t vector_t;

// Initialises a new vector type (return value of vector)
vector_t*   vector_new();

// Constructs the vector with elements
void vector_ctr(vector_t* obj);

// Destroys the vector object
void vector_dtr(vector_t* obj);

// Returns the size of the vector
int vector_size(vector_t* obj);

// Returns the capacity of the vector
int vector_capacity(vector_t* obj);

// Adds an element to the vector object
void vector_push_back(vector_t* obj, const int element);

// Returns the value of the vector's element at the index
int vector_at(vector_t* obj, const int index);

// Returns the value of the element at the beginnning of the vector.
// It can be dereferences at calling of the function if you wish to get the value
int* vector_begin(vector_t* obj);

// Returns the value of the element at the end of the vector
//
// Due to this function being just "theoretical", 
// derefencing it will result in unexpected behaviour
int* vector_end(vector_t* obj);

// Fetches the last element, resets it to zero and reduces the size by 1
void vector_pop_back(vector_t* obj);

// Reorganises the array and resets the size but does not shrink the capacity. 
void vector_erase(vector_t*, int* first, int* last);




// Prints out the vector's size and capacity at its current stage
void vector_print(vector_t* obj, char* additional_text);

#endif