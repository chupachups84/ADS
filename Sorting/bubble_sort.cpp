#include <algorithm>
#include "sorting.h"

// Сортировка простым обменом (пузырьковая).
// Временная сложность: в общем случае - O(n^2).
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j + 1], arr[j]);
        }
    }
}