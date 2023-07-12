#pragma once
#include <iostream>
#include <string>
#define ALPHABET_SIZE 26
using namespace std;
class RadixTree {
private:
	class Node {
	public:
		bool isTerminal;
		Node** arr;
		Node() :isTerminal(false) {
			arr = new Node * [ALPHABET_SIZE];
			for (int i = 0; i < ALPHABET_SIZE; i++) {
				arr[i] = nullptr;
			}
		}

		bool isTerm() { return isTerminal; }
		~Node() {
			for (int i = 0; i < ALPHABET_SIZE; i++) {
				delete arr[i];
			}
			delete[] arr;
		}
		
	};
	Node* root;
	void _del(string str, int num, Node* node) {
		if (str.length() >= num) {
			int index = int(str[num] - 'a');
			if (node->arr[index] != nullptr) {
				_del(str, num + 1, node->arr[index]);
			}
			if (str.length() == num) {
				node->isTerminal = false;
			}
			bool flag = true;
			for (int i = 0; i < str.length(); i++) {
				if (node->arr[i] != nullptr) {
					flag = false;
				}
			}
			if (flag) {
				delete node;
			}
		}
	}
	void _print(Node* node, int lvl) {
		if (node != nullptr) {
			for (int i = 0; i < ALPHABET_SIZE; i++) {
				_print(node->arr[i], lvl + 1);
				cout << char('a' + i)<<" ";
			}
		}
	}
public:
	RadixTree() {
		root = nullptr;
	}
	~RadixTree() { 
		delete root;
	}
	void add(string str) {
		if (root == nullptr) {
			root = new Node();
		}
		Node* ptr = root;
		int len = str.length();
		for (int i = 0; i < len; i++) {
			int index = int(str[i] - 'a');
			if (ptr->arr[index] == nullptr) {
				ptr->arr[index] = new Node;
			}
			ptr = ptr->arr[index];
		}
		ptr->isTerminal = true;
	}
	bool search(string str) {
		Node* ptr = root;
		int len = str.length();
		for (int i = 0; i < len; i++) {
			int index = int(str[i] - 'a');
			if (ptr->arr[index] == nullptr) {
				return false;
			}
			ptr = ptr->arr[index];
		}
		if (!ptr->isTerminal)
		{
			return false;
		}
		return true;
	}
	void del(string str) {
		_del(str, 0, root);
	}
	bool isEmpty() {
		return root == nullptr;
	}
	void clear() {
		delete root;
		root = nullptr;
	}
	void print() {
		_print(root, 0);
	}
};