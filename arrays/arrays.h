#ifndef arrays_h
#define arrays_h

typedef struct Array {
  unsigned capacity;
  unsigned count;
  char **elements;
} Array;

Array *create_array (unsigned capacity);

void destroy_array(Array *arr);

char *arr_read(Array *arr, unsigned index);

void arr_append(Array *arr, char *element);

void arr_insert(Array *arr, char *element, unsigned index);

void arr_remove(Array *arr, char *element);

#endif
