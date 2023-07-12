#pragma once
#include <iostream>
using namespace std;
template <class T>
class Queue {
	struct Node {
		Node* next;
		T data;
	};
	 Node* head;
	 Node* tail;
public:
	void init() {
		head = tail = NULL;
	}
	Queue() { init(); }
	~Queue() { clear(); }
	bool isEmpty() {
		return head == NULL;
	}
	void push(T elem) {
		Node* p = new Node;
		p->data = elem;
		if (isEmpty()) {
			head = tail = p;
		}
		else {
			tail->next = p; //создаем узел и говорим, что хвост теперь новый добавленный элемент
			tail = p;
		}
		tail->next = nullptr;

	}
	void pop() {

		if (head == tail) {
			head = tail = NULL;
		}
		else {
			Node* p = head;
			head = head->next;
			delete p;
			p = nullptr;
		}
	}
	T front() {
		return head->data;
	}
	T back() {
		return tail->data;
	}
	void clear() {
		while (!isEmpty()) {
			if (head == tail) {
				head = tail = NULL;
			}
			else {
				head = head->next;
			}

		}
	}
	void print() {
		Node* p = head;
		while (p != tail->next) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}

};