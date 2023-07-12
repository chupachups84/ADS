#pragma once;
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

class graphs
{
	int** a;
	vector<int> used, par, mt;
	int rows, cols;
public:
	graphs(int rows,int cols):rows(rows),cols(cols)
	{
		a = new int* [rows];
		for (int i = 0; i < rows; i++)
			a[i] = new int[cols];
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				a[i][j] = 1;
	}
	~graphs() {
		for (int i = 0; i < rows; i++) delete[] a[i];
		delete[] a;
	}
	void removeEdge(int i, int j) {
		a[i][j] = 0;
	}
	bool checkEdge(int i, int j) {
		return a[i][j] == 1;
	}
	bool isEmpty() {
		return a == nullptr;
	}
	int vertexCount() {
		return rows + cols + 2;
	}
	int edgeCount() {
		int c = 0;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				c+= a[i][j] == 1 ? 1 :  0;
		return c;
	}
	int** getMatrix() {
		return a;
	}
	friend ostream& operator<<(ostream& out,const graphs& other ) {
		out << "rows: " << other.rows << endl;
		out << "cols: " << other.cols << endl;
		for (int i = 0; i < other.rows; i++) {
			for (int j = 0; j < other.cols; j++) {
				out << other.a[i][j] << " ";
			}
			out << endl;
		}
		return out;
	}
	void augmentPath() {
		int i, run = 1;
		mt.assign(cols, -1);
		par.assign(rows, -1);
		while (run){
			run = 0;
			used.assign(rows, 0);
			for (i = 0; i < rows; i++)
				if ((par[i] == -1) && dfs(i))
					run = 1;
		}
	}
	int dfs(int i){
		if (used[i])
			return 0;
		used[i] = 1;
		for (int j = 0; j < cols; j++)
		{
			if (a[i][j] != 0 && (mt[j] == -1 || dfs(mt[j]))) {
				mt[j] = i;
				par[i] = 1;
				return 1;
			}
		}
		return 0;
	}
	int maxFlow() {
		int flow=0,i;
		for (flow, i = 0; i < cols; i++) {
			if (mt[i] != -1) flow++;
		}
		return flow;
	}
	
};
