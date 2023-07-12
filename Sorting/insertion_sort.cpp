#include <algorithm>
#include "sorting.h"

// Сортировка вставками.
// Временная сложность: в общем случае - O(n^2).
void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; ++i)
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; --j)
            std::swap(arr[j - 1], arr[j]);
}

void insertionSort2(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && temp < arr[j]) {
            std::swap(arr[j + 1], arr[j]);
            j--;
        }
    }
}

void insertionSort3(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i;
        while (j > 0 && temp < arr[j - 1]) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}