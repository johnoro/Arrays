#ifndef arrays_h
#define arrays_h

typedef struct Array {
  unsigned capacity;
  unsigned count;
  char **elements;
} Array;

Array *create_array(unsigned capacity);

void destroy_array(Array *arr);

char *arr_read(Array *arr, unsigned index);

void arr_append(Array *arr, char *element);

void arr_insert(Array *arr, char *element, unsigned index);

void arr_remove(Array *arr, char *element);

void arr_print(Array *arr);

/* Stretch array declarations */
void arr_clear(Array *arr);

Array *arr_copy(Array *arr);

void arr_extend(Array *arr, Array *extension_arr);

unsigned arr_index(Array *arr, char *element);

char *arr_pop(Array *arr, int index);

void arr_reverse(Array *arr);

void arr_sort(Array *arr);
// void arr_sort(Array *arr, cmp_func, reverse?);

#endif
