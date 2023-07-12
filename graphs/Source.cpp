#include <iostream>
#include "graphs.h"
using namespace std;
void main() {
	int rows, cols, cuts;
	int a, b;
	cin >> rows >> cols >> cuts;
	graphs graph(rows,cols);
	for (int i = 0; i < cuts; i++) {
		cin >> a >> b;
		graph.removeEdge(a, b);
	}
	cout << graph;
	graph.augmentPath();

	cout << graph.maxFlow() << endl;
}