#include <iostream>
#include "TTree.h"
#include <fstream>
void main() {
	int n;
	cin >> n;
	float** a = new float* [n];
	for (int i = 0; i < n; i++) a[i] = new float[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++) {
		cout << "\n";
		for (int j = 0; j < n; j++)
			cout << a[i][j]<<" ";
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = i + 1; k < n; k++) {
				a[j][k] = (a[j][k] * a[i][i] - a[j][i] * a[i][k]) / a[i - 1][i - 1];
			}
		}
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << "\n";
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
	}

}