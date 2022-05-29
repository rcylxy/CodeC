#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// #include <iostream>
// 数组作为函数参数会退化为指针
#define BASKETSIZE 10000
// 规范打印数组
void printArray(int b[], int length) {
  for (int i = 0; i < length; ++i) {
    printf("%d ", b[i]);
  }
  printf("\n");
  return;
}

// 冒泡排序
void bubbleSort(int b[], int length) {
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

// 简单选择排序
void simpleSelectSort(int b[], int length) {
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

// 直接插入排序
void straightInsertSort(int b[], int length) {
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

// 折半排序
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

// 希尔插入
void shellInsert(int b[], int length, int dk) {
  int i = 0;
  int j = 0;
  for (i = dk; i < length; ++i) {  // dk之前默认排好序了
    int compare = b[i];
    for (j = i - dk; j >= 0 && b[j] > compare; j -= dk) {
      b[j + dk] = b[j];
    }
    b[j + dk] = compare;
  }
  return;
}

// 希尔排序
void shellSort(int b[], int length, int dlta[], int t) {
  for (int k = 0; k < t; ++k) {
    shellInsert(b, length, dlta[k]);
  }
}

// 桶排序
void basketSort(int b[], int length) {
  int basket[BASKETSIZE] = {0};
  for (int i = 0; i < length; ++i) {
    basket[b[i]]++;
  }
  int j = 0;
  for (int i = 0; i < BASKETSIZE; ++i) {
    while (basket[i] != 0) {
      b[j] = i;
      j++;
      basket[i]--;
    }
  }
  return;
}

// 快速排序
void quickSort(int b[], int left, int right) {
  int i, j, temp;

  if (left > right) {
    return;
  }

  i = left;
  j = right;
  temp = b[left];

  while (i != j) {
    while (b[j] >= temp && i < j) {
      j--;
    }
    while (b[i] <= temp && i < j) {
      i++;
    }
    if (i < j) {
      int temp2 = b[i];
      b[i] = b[j];
      b[j] = temp2;
    }
  }
  b[left] = b[i];
  b[i] = temp;
  quickSort(b, left, i - 1);
  quickSort(b, i + 1, right);
}

int main() {
  int a[] = {4, 8, 5, 8, 74, 12, 8, 0, 0, 7};
  int length = sizeof(a) / sizeof(a[0]);
  // bubbleSort(a, length);
  // simpleSelectSort(a, length);
  // straightInsertSort(a, length);
  // halfIntervalSort(a, length);
  // int dlta[] = {5, 3, 1};
  // int dltaLength = sizeof(dlta) / sizeof(dlta[0]);
  // shellSort(a, length, dlta, dltaLength);
  // basketSort(a, length);
  // quickSort(a, 0, length - 1);
  quickSort(a, 0, length - 1);
  printArray(a, length);
  return 0;
}