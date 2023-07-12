#pragma once
#include <iostream>
//Список - динамическая структура данных,
//в которой элементы хранят в себе указатель каких-то
//других элементов
struct Node
{
	int data;
	Node* next;
};
typedef Node* TList;
// 1)INIT
void init(TList &head) {
	head = nullptr;
}

// 2)CLEAR
void clear(TList &head ) {
	while (!isEmpty(head)) {
		deleteFromHead(head);
	}
}

// 3)addToHead
void addToHead(TList head, int elem) {
	TList p = new Node;
	p->data = elem;
	p->next = head;
	head = p;
}

// 4)addAfterNode
void addAfterNode(TList pNode, int elem) {
	TList p = new Node;
	p->data = elem;
	p->next = pNode->next;
	pNode->next = p;
}

// 5)deleteFromHead
void deleteFromHead(TList& head) {
	TList p = head;
	head = head->next;
	p->next = nullptr;
	delete p;
	p = nullptr;
}

// 6)deleteAfterNode
void deleteAfterNode(TList pNode){
	if (pNode->next != nullptr) {
		TList p = pNode->next;
		pNode->next = p->next;
		p->next = nullptr;
		delete p;
		p = nullptr;
	}
}

// 7)isEmpty
bool isEmpty(TList head) {
	return head == nullptr;
}

// 8)print
void print(TList head) {
	while (!isEmpty(head)) {
		std::cout << head->data << " ";
		head = head->next;
	}
}