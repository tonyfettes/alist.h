#include "list.h"
#include <stdio.h>
#include <time.h>
#include "sort_size.h"

int comp(const int *a, const int *b) {
  return *a - *b;
}

int main() {
  srand(1234);
  clock_t start = clock();
  __auto_type list = list_init(int);
  for (int i = 0; i < BENCH_LIST_SIZE; i++) {
    list_push_back(list, rand());
  }
  clock_t stop = clock();
  printf("setup: %lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
  start = clock();
  list_sort(list, comp);
  stop = clock();
  printf("sort: %lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
  start = clock();
  list_trivial_destroy(list);
  stop = clock();
  printf("dealloc: %lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
  return 0;
}
