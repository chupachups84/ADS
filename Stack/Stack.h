#pragma once
#include <iostream>
//—тек - абстрактный тип данных , в котором
//элементы хран€тс€ последовательно, и добавление, и удаление
//элементов производитс€ с одного конца , называемого вершиной стека

//–еализаци€ стека на основе линейного одонаправленного списка
struct Node {
	int data;
	Node* next;
};
typedef Node* TStack;
void init(TStack& top) {
	top = nullptr;
}
bool isEmpty(TStack top) {
	return top == nullptr;
}
void push(TStack& top, int elem) {
	TStack p = new Node;
	p->data = elem;
	p->next = top;
	top = p;
}
void pop(TStack& top) {
	if (!isEmpty(top)) {
		TStack p = top;
		top = p->next;
		p->next = nullptr;
		delete p;
		p = nullptr;
	}
}
void clear(TStack& top) {
	while (!isEmpty(top))
		pop(top);
}
int peek(TStack top)
{
	return top->data;
}
