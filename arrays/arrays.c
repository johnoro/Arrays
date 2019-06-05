#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct Array {
  unsigned capacity;  // How many elements can this array hold?
  unsigned count;  // How many states does the array currently hold?
  char **elements;  // The string elements contained in the array
} Array;


/************************************
 *
 *   CREATE, DESTROY, RESIZE FUNCTIONS
 *
 ************************************/

/*****
 * Allocate memory for a new array
 *****/
Array *create_array(unsigned capacity) {
  // Allocate memory for the Array struct
  Array *arr = malloc(sizeof(Array));

  // Set initial values for capacity and count
  arr->capacity = capacity;
  arr->count = 0;

  // Allocate memory for elements
  arr->elements = malloc(capacity * sizeof(char*));

  return arr;
}


/*****
 * Free memory for an array and all of its stored elements
 *****/
void destroy_array(Array *arr) {
  // Free all elements
  for (size_t i = 0; i < arr->count; i++)
    free(arr->elements[i]);

  free(arr->elements);

  // Free array
  free(arr);
}

/*****
 * Create a new elements array with double capacity and copy elements
 * from old to new
 *****/
void resize_array(Array *arr) {
  // Create a new element storage with double capacity
  // Copy elements into the new storage
  // Free the old elements array (but NOT the strings they point to)
  // Update the elements and capacity to new values
  arr->capacity *= 2;
  arr->elements = realloc(
    arr->elements,
    arr->capacity * sizeof(char*)
  );
}



/************************************
 *
 *   ARRAY FUNCTIONS
 *
 ************************************/

/*****
 * Return the element in the array at the given index.
 *
 * Throw an error if the index is out of range.
 *****/
char *arr_read(Array *arr, unsigned index) {
  // Throw an error if the index is greater or equal to than the current count
  if (index >= arr->count) {
    perror("Your index is too great");
    return NULL;
  }

  // Otherwise, return the element at the given index
  return arr->elements[index];
}


/*****
 * Insert an element to the array at the given index
 *
 * Store the VALUE of the given string, not the REFERENCE
 *****/
void arr_insert(Array *arr, char *element, unsigned index) {
  // Throw an error if the index is greater than the current count
  if (index > arr->count) {
    perror("Your index is too great");
    return;
  }

  // Resize the array if the number of elements is over capacity
  if (arr->count == arr->capacity)
    resize_array(arr);

  // Move every element after the insert index to the right one position
  for (size_t i = arr->count; i > index; i--)
    arr->elements[i] = arr->elements[i-1];

  // Copy the element (hint: use `strdup()`) and add it to the array
  arr->elements[index] = strdup(element);

  // Increment count by 1
  arr->count++;
}

/*****
 * Append an element to the end of the array
 *****/
void arr_append(Array *arr, char *element) {
  // Resize the array if the number of elements is over capacity
  // or throw an error if resize isn't implemented yet.
  if (arr->count == arr->capacity)
    resize_array(arr);

  // Copy the element and add it to the end of the array
  // Increment count by 1
  arr->elements[arr->count++] = strdup(element);
}

/*****
 * Remove the first occurence of the given element from the array,
 * then shift every element after that occurence to the left one slot.
 *
 * Throw an error if the value is not found.
 *****/
void arr_remove(Array *arr, char *element) {
  int found = 0;
  size_t i = 0;
  // Search for the first occurence of the element and remove it.
  // Don't forget to free its memory!
  while (!found && i < arr->count) {
    if (strcmp(arr->elements[i], element) == 0) {
      found = 1;
      free(arr->elements[i]);
    } else i++;
  }

  if (!found) {
    perror("Element not found");
    return;
  }

  // Shift over every element after the removed element to the left one position
  for (size_t j = i+1; j < arr->count; j++)
    arr->elements[j-1] = arr->elements[j];

  // Decrement count by 1
  arr->count--;
}

/************************************
 *
 *   STRETCH ARRAY FUNCTIONS
 *   Check out
 *   https://www.programiz.com/python-programming/methods/list
 *   for reference.
 *
 ************************************/

void arr_clear(Array *arr) {
  for (size_t i = 0; i < arr->count; i++)
    free(arr->elements[i]);
  arr->count = 0;
}

Array *arr_copy(Array *arr) {
  Array *cpy_arr = create_array(arr->capacity);
  for (size_t i = 0; i < arr->count; i++)
    arr_append(cpy_arr, arr->elements[i]);
  return cpy_arr;
}

void arr_extend(Array *arr, Array *extension_arr) {
  return;
}

unsigned arr_index(Array *arr, unsigned index) {
  return 0;
}

char *arr_pop(Array *arr, int index) {
  return NULL;
}

void arr_reverse(Array *arr) {
  return;
}

void arr_sort(Array *arr) {
  return;
}

/*****
 * Utility function to print an array.
 *****/
void arr_print(Array *arr) {
  printf("[");
  for (size_t i = 0; i < arr->count; i++) {
    printf("%s", arr->elements[i]);
    if (i != arr->count-1)
      printf(",");
  }
  printf("]\n");
}


#ifndef TESTING
int main(void) {
  Array *arr = create_array(1);

  arr_insert(arr, "STRING1", 0);
  arr_append(arr, "STRING4");
  arr_insert(arr, "STRING2", 0);
  arr_insert(arr, "STRING3", 1);
  arr_print(arr);
  arr_remove(arr, "STRING3");
  arr_print(arr);

  destroy_array(arr);

  return 0;
}
#endif
