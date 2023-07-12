#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <string>

/*
Абстрактный список представляется собой 
позиционно-ориентированный тип данных , т.е. операции имеют вид:
вcтавить элемент в i-ю позицию
удалить элемент из i-ю позиции
и тд

Абстрактный упорядоченый список , ориентированный на 
значения элемента ,операции имеют вид :
вставить значение 
удалить по значению
найти по значению

Бинарное дерево является позиционно ориентированным абстрактным
типом , но не линейным

Бинарное дерево поиска ориентировано на значения элемента
*/
using namespace std;

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
};
typedef TreeNode* TTree;
struct Node{
	pair<TTree,int> data;
	Node* next;
};
typedef Node* TList;
// 1)INIT
void init(TList& head) {
	head = nullptr;
}

// 7)isEmpty
bool isEmpty(TList head) {
	return head == nullptr;
}
// 5)deleteFromHead
void deleteFromHead(TList& head) {
	TList p = head;
	head = head->next;
	p->next = nullptr;
	delete p;
	p = nullptr;
}

// 2)CLEAR
void clear(TList& head) {
	while (!isEmpty(head)) {
		deleteFromHead(head);
	}
}

// 3)addToHead
void addToHead(TList &head, pair<TTree,int> elem) {
	TList p = new Node;
	p->data = elem;
	p->next = head;
	head = p;
}

// 4)addAfterNode
void addAfterNode(TList pNode, pair<TTree, int> elem) {
	TList p = new Node;
	p->data = elem;
	p->next = pNode->next;
	pNode->next = p;
}



// 6)deleteAfterNode
void deleteAfterNode(TList pNode) {
	if (pNode->next != nullptr) {
		TList p = pNode->next;
		pNode->next = p->next;
		p->next = nullptr;
		delete p;
		p = nullptr;
	}
}


void print(TList list) {
	while (list){
		cout << list->data.second << "  ";
		list = list->next;
	}
}

void init(TTree& root) {
	root = nullptr;
}
bool isEmpty(TTree root) {
	return root == nullptr;
}
void initTTree(TTree& root, int elem) {
	root = new TreeNode;
	root->data = elem;
	root->left = nullptr;
	root->right = nullptr;
}
void attachLeftSon(TTree root, int elem) {

	if (!isEmpty(root) && root->left == nullptr) {
		root->left = new TreeNode;
		root->left->data = elem;
		root->left->left = nullptr;
		root->left->right = nullptr;
	}
}
void attachRightSon(TTree root, int elem) {
	if (!isEmpty(root) && root->right == nullptr) {
		root->right = new TreeNode;
		root->right->data = elem;
		root->right->left = nullptr;
		root->right->right = nullptr;
	}
}
void attachLeftSubtree(TTree root, TTree subtree) {
	if (!isEmpty(root) && root->left == nullptr) {
		root->left = subtree;
	}
}
void attachRightSubtree(TTree root, TTree subtree) {
	if (!isEmpty(root) && root->right == nullptr) {
		root->right = subtree;
	}
}

void detachLeftSubtree(TTree root, TTree& subtree)
{
	if (isEmpty(root)) cout << "Tree is empty";
	else
	{
		subtree = root->left;
		root->left = nullptr;
	}
}

void copyTree(TTree root, TTree& newRoot)
{
	if (root != nullptr)
	{
		newRoot = new TreeNode;
		newRoot->data = root->data;
		newRoot->left = nullptr;
		newRoot->right = nullptr;
		copyTree(root->left, newRoot->left);
		copyTree(root->right, newRoot->right);
	}
	else newRoot = nullptr;
}
TTree getLeftSubtree(TTree root)
{
	TTree leftSubtree;
	if (root != nullptr) {
		copyTree(root->left, leftSubtree);
		return leftSubtree;
	}
	else return nullptr;
}
TTree getRightSubtree(TTree root)
{
	TTree rightSubtree;
	if (root != nullptr) {
		copyTree(root->right, rightSubtree);
		return rightSubtree;
	}
	else return nullptr;
}
TTree destroyTree(TTree& root)
{
	if (root != nullptr)
	{
		destroyTree(root->left);
		destroyTree(root->right);
		root->left = nullptr;
		root->right = nullptr;
		delete root;
		root = nullptr;
	}
	return root;
}
void preorder(TTree root,int depth = 0) {
	if (root != nullptr) {
		for (int i = 0; i < depth; i++)
			cout << "\t";
		cout << root->data<<'\n';
		preorder(root->left,depth+1);
		preorder(root->right,depth+1);
	}
}
void inorder(TTree root) {
	if (root != nullptr) {
		inorder(root->left);
		cout << root->data<<" ";
		inorder(root->right);
	}
}
void postfix(TTree root) {
	if (root != nullptr) {
		postfix(root->left);
		postfix(root->right);
		cout << root->data;
	}
}
void infixIterative(TTree root) {
	stack<TTree> st;
	bool done = false;
	TTree cur = root;
	while (!done) {
		if (cur != nullptr) {
			st.push(cur);
			cur = cur->left;
		}
		else if (!st.empty()) {
			cur = st.top();
			cout << cur->data;
			cur = cur->right;
			st.pop();
		}
		else
			done = true;
	}
}
void breathTraverse(TTree root) {
	queue<TTree> q;
	if (root != nullptr) {
		q.push(root);
		while (!q.empty()) {
			TTree cur = q.front();
			cout << cur->data;
			q.pop();
			if (cur->left != nullptr)
				q.push(cur->left);
			if (cur->right != nullptr)
				q.push(cur->right);
		}
	}

} 

int sumSons(TTree root) {
	if (root == nullptr)
		return 0;
	int sum;
	return sum =root->data + sumSons(root->left) + sumSons(root->right);
}

TList findNode(TList l, pair<TTree, int> p) {
	TList pNode = l;
	while (!isEmpty(pNode)&&!isEmpty(pNode->next) && p.second > pNode->next->data.second)
		pNode = pNode->next;
	return pNode;
}

void getListOfSum(TTree root, TList& l ) {
	if (root == nullptr) return;
	int k = sumSons(root);
	pair<TTree, int> p = { root, k };
	if (l == nullptr) {
		init(l);
		addToHead(l, p);
	}
	else if (k < l->data.second)
		addToHead(l, p);
	else {
		TList pNode = findNode(l, p);
		addAfterNode(pNode, p);
	}
	getListOfSum(root->right, l);
	getListOfSum(root->left, l);
}

//void insertElement(TTree& root, int elem) //ОДИНАКОВЫЕ ЭЛЕМЕНТЫ ИДУТ ВПРАВО
//{
//	if (root == NULL) initTree(root, elem);
//	else {
//		if (elem < root->data)
//			insertElement(root->left, elem);
//		else
//		{
//			insertElement(root->right, elem);
//		}
//	}
//}
//TTree search(TTree root, int elem)
//{
//	if (root == NULL)
//		return NULL;
//	else {
//		if (root->data == elem) return root;
//		if (root->data < elem) return search(root->right, elem);
//		if (root->data > elem) return search(root->left, elem);
//	}
//}
//void deleteElement(TTree& root, int elem) {
//	if (root != NULL) {
//		if (elem == root->data)
//			deleteNode(root);
//		else
//		{
//			if (elem < root->data) deleteElement(root->left, elem);
//			else
//				deleteElement(root->right, elem);
//		}
//	}
//}
//int findSuccessor(TTree& pNode)
//{
//	if (pNode->left == NULL)
//	{
//		int elem = pNode->data;
//		TTree delNode = pNode;
//		pNode = pNode->right;
//		delete delNode;
//		return elem;
//	}
//	else
//		findSuccessor(pNode->left);
//}
//void deleteNode(TTree& pNode) {
//	if (pNode->left == NULL && pNode->right == NULL)
//	{
//		delete pNode;
//		pNode = NULL;
//	}
//	else
//	{
//		TTree delNode;
//		if (pNode->left == NULL || pNode->right == NULL)
//		{
//			delNode = pNode;
//			if (pNode->left == 0)
//				pNode = pNode->right;
//			else
//				pNode = pNode->left;
//			delete delNode;
//			delNode = NULL;
//		}
//		else
//		{
//			pNode->data = findSuccessor(pNode->right);
//		}
//	}
//}


//int numberOfSons(TTree root) {
//	if (root == nullptr)
//		return 0;
//	if (root->left == nullptr && root->right == nullptr)
//		return 1;
//	return numberOfSons(root->left) + numberOfSons(root->right);
//}
//void nonEqualsSons(TTree root, vector<TTree>& vect) {
//	if (root == nullptr)
//		return;
//	if (numberOfSons(root->left) != numberOfSons(root->right))
//		vect.push_back(root);
//	nonEqualsSons(root->left, vect);
//	nonEqualsSons(root->right, vect);
//}
////Работает если в структуре char data а не int
//TTree createFormula(ifstream& fin) {
//	char ch = fin.get();
//	TTree root = new TreeNode;
//	if (ch >= '0' && ch <= '9') {
//		root->data = ch;
//		root->left = nullptr;
//		root->right = nullptr;
//	}
//	else {//  ch='('
//		root->left = createFormula(fin);
//		root->data = fin.get();
//		root->right = createFormula(fin);
//		ch = fin.get(); //ch = ')'
//	}
//	return root;
//}
//string printToStr(TTree root) {
//	if (root->left == nullptr && root->right == nullptr)
//		return string(to_string(root->data));
//	else
//		return "(" + printToStr(root->left) 
//		+ to_string(root->data) + printToStr(root->right) + ")";
//}
//int calcFormula(TTree root) {
//	int res;
//	if (root->right == nullptr && root->left == nullptr)
//		return root->data - '0';
//	else {
//		int left_res = calcFormula(root->left);
//		int right_res = calcFormula(root->right);
//		switch (root->data) {
//		case '+': {
//			res = left_res + right_res;
//			break;
//		}
//		case '-': {
//			res = left_res - right_res;
//			break;
//		}
//		case '*': {
//			res = left_res * right_res;
//			break;
//		}
//		case '/': {
//			res = left_res / right_res;
//			break;
//		}
//		}
//		return res;
//	}
//}
////Идеально сбалансированное дерево 
//void createBalancedTree(ifstream& fin, TTree& root) {
//	int nodeCount;
//	fin >> nodeCount;
//	root = createNodes(nodeCount, fin);
//}
//TTree createNodes(int nodeCount, ifstream& fin) {
//	if (nodeCount == 0) return nullptr;
//	else {
//		TTree node = new TreeNode;
//		int data;
//		fin >> data;
//		node->data = data;
//		node->left = createNodes(nodeCount / 2, fin);
//		node->right = createNodes(nodeCount - nodeCount / 2 - 1, fin);
//	}
//}