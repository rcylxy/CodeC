#include <stdio.h>
#include <stdlib.h>

int comparefuc(const void* a, const void* b) {
  return -(*(int*)(a) - *(int*)(b));
}

void printArray(int test[], int length) {
  for (int i = 0; i < length; ++i) {
    printf("%d ", test[i]);
  }
  return;
}

int main() {
  int demo[10] = {4, 5, 7, 8, 9, 1, 4, 5, 9, 7};
  int length = sizeof(demo) / sizeof(demo[0]);
  qsort(demo, length, sizeof(int), comparefuc);
  printArray(demo, length);
}