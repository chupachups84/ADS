#pragma once
#include <iostream>
#include <list>
using namespace std;
class GraphList {
private:
	list<list<int>> vert;
public:
	GraphList();
	GraphList(int n);
	GraphList(int** mass,int size);
	~GraphList();
	int getSize();
	void addEdge(int vrtxI,int vrtxJ);
	void addVertex();
	void removeEdge(int vrtxI,int vrtxJ);
	void removeVertex(int vertex);
	list<int> relatedVertex(int vertex);
	bool operator==(GraphList& graph);
	bool operator!=(GraphList& graph);
	friend ostream& operator<<(const ostream& os, GraphList& graph);
};