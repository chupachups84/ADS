#include "TTree.h"
void init(TTree& root){
	root = nullptr;
}
void addElem(Data _data, TTree& root, int k){
	if (root == nullptr) {
		root = new Branch;
		root->data = _data;
		root->level = k;
		root->left = nullptr;
		root->right = nullptr;
	}
	else {
		if (root->data > _data) 
		{
			addElem(_data, root->left, k + 1);
		}
		else {
			addElem(_data, root->right, k + 1);
		}
	}
}
bool isEmpty(TTree root) {
	return (root == nullptr);
}
void deleteTTree(TTree& root){
	if (root != NULL) {
		deleteTTree(root->left);
		deleteTTree(root->right);
		root->left = NULL;
		root->right = NULL;
		root->data = NULL;
		delete root;
		root = NULL;
	}
}
void breadthTraverse(TTree root){
	queue <TTree> q;
	cout << "\nОбход в ширину: \n";
	if (root != nullptr) {
		q.push(root);
		while (!q.empty()) {
			TTree cur = q.front();
			cout << q.front()->data<<'\n';
			q.pop();
			if (cur->left != nullptr){
				q.push(cur->left);
			}
			if (cur->right != nullptr) {
				q.push(cur->right);
			}
		}
	}
}
void preorder(TTree root){
	if (root != NULL) {
		cout << root->data;
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(TTree root){
	if (root != NULL) {
		inorder(root->left);
		cout << root->data;
		inorder(root->right);
	}
}
void postfix(TTree root){
	if (root != NULL) {
		postfix(root->left);
		postfix(root->right);
		cout << root->data;
	}
}
TTree findMinElem(TTree root) {
	if (root->left == NULL)
		return root;
	else
		return findMinElem(root->left);
}
void deleteByKey(TTree &root,Data data){
	if (root != NULL&&root->data == data ) {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}else if (root->left == NULL&& root->right!=NULL) {
			root = root->right;
			root->level -= 1;
		}else if (root->right == NULL && root->left != NULL) {
			root = root->left;
			root->level -= 1;
		}else if (root->right != NULL && root->left != NULL) {
			Data minimal = min(root->right->data , root->left->data);
			Data maximal = max(root->right->data, root->left->data);
			TTree minRootInRightSubTree = findMinElem(root->right);
			root->data = minRootInRightSubTree->data;root->level -= 1;
			deleteByKey(root->right, minRootInRightSubTree->data);
		}
	}
	if (root == NULL)
		return;
	else {
		deleteByKey(root->left, data);
		deleteByKey(root->right, data);
	}
}
TTree find(TTree root,Data key){
	TTree curr = root;
	while (curr && curr->data != key){
		if (curr->data > key)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if (curr != NULL)
		return curr;
	else
		return NULL;
}
void fillTTreeFromFile(ifstream& fin, TTree& root){
	int temp;string str;
	while (!fin.eof()) {
		getline(fin, str);
		temp = stoi(str);
		addElem(temp, root);
	}
}
bool isSubTree(TTree base, TTree child) {
	base = find(base, child->data);
	if (base != nullptr)
		return isEqual(base, child);
	else
		return false;
}
bool isEqual(TTree first, TTree second){
	if (first != nullptr && second != nullptr)
		return first->data == second->data && isEqual(first->left, second->left) && isEqual(first->right, second->right);
	else if (first == nullptr && second != nullptr || first != nullptr && second == nullptr)
		return false;
} 