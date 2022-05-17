#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// #include <iostream>
// 数组作为函数参数会退化为指针

// 规范打印数组
void printArray(int b[], int length) {
  for (int i = 0; i < length; ++i) {
    printf("%d ", b[i]);
  }
  printf("\n");
  return;
}

// 冒泡排序实现一
void bubbleSortOne(int b[], int length) {
  int i = 0;
  int j = 0;
  for (; i < length; ++i) {
    for (j = i + 1; j < length; ++j) {
      if (b[j] > b[j - 1]) {
        int temp = b[j];
        b[j] = b[j - 1];
        b[j - 1] = temp;
      }
    }
  }
  return;
}

// 冒泡排序实现二
void bubbleSortTwo(int b[], int length) {
  int i = 0;
  int j = 0;
  for (; i < length; ++i) {
    for (j = length - 1; j >= i; --j) {
      if (b[j] <= b[j - 1]) {
        int temp = b[j];
        b[j] = b[j - 1];
        b[j - 1] = temp;
      }
    }
  }
  return;
}

// 冒泡排序实现三（时间复杂度较高）
void bubbleSortThree(int b[], int length) {
  int i = 0;
  int j = 0;
  for (; i < length; ++i) {
    for (j = i; j < length; ++j) {
      // if (b[j] <= b[i]) {
      if (b[j] >= b[i]) {
        int temp = b[j];
        b[j] = b[i];
        b[i] = temp;
      }
    }
  }
  return;
}

// 简单选择排序实现一
void simpleSelectSortOne(int b[], int length) {
  int min = b[0];
  int loc = 0;
  int i = 0;
  int j = 0;
  for (i = 0; i < length - 1; ++i) {
    for (j = i; j < length; ++j) {
      if (b[j] <= min) {
        min = b[j];
        loc = j;
      }
    }
    int temp = b[loc];
    b[loc] = b[i];
    b[i] = temp;
    min = b[i + 1];
  }
  return;
}

// 简单选择排序实现二
void simpleSelectSortTwo(int b[], int length) {
  int max = b[0];
  int loc = 0;
  int i = 0;
  int j = 0;
  for (i = 0; i < length - 1; ++i) {
    for (j = i; j < length; ++j) {
      if (b[j] >= max) {
        max = b[j];
        loc = j;
      }
    }
    int temp = b[loc];
    b[loc] = b[i];
    b[i] = temp;
    max = b[i + 1];
  }
  return;
}

// 直接插入排序实现一
void straightInsertSortOne(int b[], int length) {
  int i = 0;
  int j = 0;
  for (i = 0; i < length; ++i) {
    int compare = b[i];
    for (j = i - 1; j >= 0 && b[j] > compare; --j) {
      b[j + 1] = b[j];
    }
    b[j + 1] = compare;
  }
  return;
}

// 直接插入排序实现二
void straightInsertSortTwo(int b[], int length) {
  int i = 0;
  int j = 0;
  for (i = 0; i < length; ++i) {
    int compare = b[i];
    for (j = i - 1; j >= 0 && b[j] < compare; --j) {
      b[j + 1] = b[j];
    }
    b[j + 1] = compare;
  }
  return;
}

void halfIntervalSort(int b[], int length) {
  int i = 0, j = 0;
  int loc = 0;
  int compare = 0;
  for (i = 1; i < length; ++i) {
    int right = i - 1;
    int left = 0;
    int mid;
    compare = b[i];
    while (left <= right) {
      mid = (left + right) / 2;
      if (b[mid] > compare) {
        right = mid - 1;
      } else
        left = mid + 1;
    }
    loc = right + 1;
    for (j = i - 1; j >= loc; --j) {
      b[j + 1] = b[j];
    }
    b[loc] = compare;
  }
  return;
}

int main() {
  int a[] = {4, 8, 7, 8, 2, 5, 8, 7, 4, 7};
  int length = sizeof(a) / sizeof(a[0]);
  // bubbleSortOne(a, length);
  // bubbleSortTwo(a, length);
  // bubbleSortThree(a, length);
  // simpleSelectSortOne(a, length);
  // simpleSelectSortTwo(a, length);
  // straightInsertSortOne(a, length);
  // straightInsertSortTwo(a, length);
  halfIntervalSort(a, length);
  // printf("%d\n", halfSearch(a, length, 6));

  printArray(a, length);
  return 0;
}