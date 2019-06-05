#include <string.h>
#include "quicksort.h"

void swap(char *a, char *b) {
  char temp[strlen(a)+1];
  strcpy(temp, a);
  strcpy(a, b);
  strcpy(b, temp);
}

int partition(char **arr, int low, int high) {
  int pivot = low;
  for (int i = low+1; i <= high; i++) {
    if (strcmp(arr[i], arr[low]) <= 0)
      swap(arr[i], arr[++pivot]);
  }
  swap(arr[pivot], arr[low]);
  return pivot;
}

void quicksort(char **arr, int low, int high) {
  if (low < high) {
    int pivot = partition(arr, low, high);
    quicksort(arr, low, pivot-1);
    quicksort(arr, pivot+1, high);
  }
}
