#pragma once
#include <iostream>
struct Node {
	int data;
	Node* next;
	Node* prev;
};
typedef Node* TList;
//1)INIT
void init(TList& head, TList& tail) {
	head = tail = nullptr;
}

//2)isEmpty
bool isEmpty(TList head) {
	return head == nullptr;
}

//3)CLEAR
void clear(TList& head, TList& tail) {
	while (!isEmpty(head))
		deleteCurrentNode(head, head, tail);
}
//4)addBeforeNode
void addBeforNode(TList pNode, TList& head, int elem) {
	TList p = new Node;
	p->data = elem;
	p->prev = pNode->prev;
	p->next = pNode;
	pNode->prev = p;
	if (p->prev != nullptr)
		p->prev->next = p;
	else
		head = p;
}

//5)addAfterNode
void addAfterNode(TList pNode, TList &tail, int elem){
	TList p = new Node;
	p->data = elem;
	p->next = pNode->next;
	p->prev = pNode;
	pNode->next = p;
	if (p->next != nullptr)
		p->next->prev = p;
	else
		tail = p;
}

//6)deleteAfterNode
void deleteAfterNode(TList pNode, TList& tail) {
	if (pNode!= tail) {
		TList p = pNode->next;
		pNode->next = p->next;
		if (p != tail)
			p->next->prev = pNode;
		else
			tail = pNode;
		p->next = p->prev = nullptr;
		delete p;
		p = nullptr;
	}
}

//7)deleteBeforeNode
void deleteBeforeNode(TList pNode, TList& head) {
	if (pNode != head) {
		TList p = pNode->prev;
		pNode->prev = p->prev;
		if (p != head)
			p->prev->next = pNode;
		else
			head = pNode;
		p->next = p->prev = nullptr;
		delete p;
		p = nullptr;
	}
}
//8)deleteCurrentNode
void deleteCurrentNode(TList pNode, TList& head, TList& tail) {
	if (pNode->next != nullptr)
		deleteBeforeNode(pNode, head);
	else if (pNode->prev != nullptr)
		deleteAfterNode(pNode, tail);
}
