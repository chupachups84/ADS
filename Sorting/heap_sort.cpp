#include "sorting.h"
#include <iostream>
void heapify(int arr[],int n){
	for (int i = n / 2; i >= 0; i--) {
		int k = i;
		bool heap = false;
		while (!heap && 2 * k + 1 < n) {
			int j = 2 * k + 1;
			if (j < n - 1) {
				if (arr[j + 1] < arr[j])
					j++;
			}
			if (arr[k] <= arr[j])
				heap = true;
			else {
				std::swap(arr[k], arr[j]);
				k = j;
			}
		}
		
	}
}
void reverse(int arr[],int size) {
	int* res = new int[size];
	for (int i = 0; i <size/2-1; i++) {
		std::swap(arr[i], arr[size - 1 - i]);
	}

}
void heapSort(int* arr, int size) {
	heapify(arr, size);
	int n = size - 1;
	for (int i = 0; i < size; i++) {
		std::swap(arr[0], arr[n]);
		int k = 0;
		bool heap = false;
		while (!heap && 2 * k + 1 < n) {
			int j = 2 * k + 1;
			if (j < n - 1) {
				if (arr[j + 1] < arr[j])
					j++;
			}
			if (arr[k] <= arr[j])
				heap = true;
			else {
				std::swap(arr[k], arr[j]);
				k = j;
			}
		}
		
		n--;
	}
	reverse(arr, size);
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}
