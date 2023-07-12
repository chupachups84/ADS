#pragma once
#include <iostream>
//���� - ����������� ��� ������ , � �������
//�������� �������� ���������������, � ����������, � ��������
//��������� ������������ � ������ ����� , ����������� �������� �����

//���������� ����� �� ������ ��������� ���������������� ������
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
