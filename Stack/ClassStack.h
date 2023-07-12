#pragma once
template <class T>
class TStack {
	struct Node {
		T data;
		Node* next;
	};
	Node* top;
public:
	Node* getTop() {
		return top;
	}
	TStack():top(nullptr){}
	bool isEmpty() {
		return top == nullptr;
	}
	void push(T elem) {
		Node* p = new Node;
		p->data = elem;
		p->next = top;
		top = p;
	}
	void pop() {
		if (!isEmpty()) {
			Node* p = top;
			top = p->next;
			p->next = nullptr;
			delete p;
			p = nullptr;
		}
	}
	void clear() {
		while (!isEmpty())
			pop();
	}
	T peek() {
		return top->data;
	}
	~TStack() {
		clear();
	}
};
