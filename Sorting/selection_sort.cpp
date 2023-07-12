#include <algorithm>
#include "sorting.h"

// Сортировка выбором минимального элемента.
// Временная сложность: в общем случае - O(n^2).
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (arr[i] != arr[min_index])
            std::swap(arr[min_index], arr[i]);
    }
}