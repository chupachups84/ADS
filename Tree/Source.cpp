#include "Tree.h"
#include<iostream>
using namespace std;
void main() {
	setlocale(LC_ALL, "rus");
	TTree sumtree;
	initTTree(sumtree, -6);
	attachLeftSon(sumtree, -5);
	attachLeftSon(sumtree->left, 8);
	attachRightSon(sumtree, 4);
	attachLeftSon(sumtree->right, -1);
	attachRightSon(sumtree->right, 0);
	attachLeftSon(sumtree->right->right, 3);
	inorder(sumtree);
	TList list;
	init(list);
	getListOfSum(sumtree, list);
	print(list);

}