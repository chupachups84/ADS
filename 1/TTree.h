#pragma once
#include <queue>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef int Data;
struct Branch {
	Data data;
	int level;
	Branch* left;
	Branch* right;
};
typedef Branch* TTree;
void init(TTree& root);//initialization
void addElem(Data _data, TTree& root, int k=1);//insert elem
bool isEmpty(TTree root);void deleteTTree(TTree &root); // delete all tree
void deleteByKey(TTree& root, Data data);// delete certain branch
void breadthTraverse(TTree root);//print tree
void preorder(TTree root);//print tree
void inorder(TTree root);//print tree
void postfix(TTree root);//print tree
TTree find(TTree root, Data key);//search branch in tree
TTree findMinElem(TTree root);
void fillTTreeFromFile(ifstream& fin,TTree&root);
bool isSubTree(TTree base, TTree child);
bool isEqual(TTree first, TTree second);