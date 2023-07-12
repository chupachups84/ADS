#pragma once
#include <iostream>
#include <list>
#include <string>
using namespace std;
template <class T >
class ChainHashTable
{
private:
	int tableSize;
	int nowSize;
	list<T>* arr;
	void rehash() {
		list<T>* newArr = new list<T>[tableSize * 2];
		for (int i = 0; i < tableSize; ++i) {
			for (T el : arr[i]) {
				unsigned int hash = el.hash()%tableSize;
				newArr[hash].push_back(el);
			}
		}
		tableSize *= 2;
		delete[] arr;
		arr = newArr;
	}
public:
	friend ostream& operator<< (ostream &os,ChainHashTable<T> &obj) {
		for (int i = 0; i < obj.tableSize; i++) {
			os << " index = " << i << ": ";
			for (T el : obj.arr[i]) {
				os << el << " ";
			}
			os << "\n";
		}
		return os;
	}
	int getTableSize() { return tableSize; }
	int getNowSize() { return nowSize; }
	list<T>* getTable() { return arr; }
	void clear() {
		for (int i = 0; i < tableSize; i++) {
			arr[i].clear();
		}
		nowSize = 0;
	}
	ChainHashTable(int size) {
		arr = new list<T>[size];
		tableSize = size;
		nowSize = 0;
	}
	~ChainHashTable() {
		delete[] arr;
		nowSize = 0;
		tableSize = 0;
	}
	bool search(T& el) {
		unsigned int hash = el.hash() % tableSize;
		for (T node : arr[hash]) {		
			if (node == el) {
				return true;
			}
		}
		return false;
	}
	void add(T el) {
		if (nowSize * 2 > tableSize)
		{
			rehash();
		}
		unsigned int hash = el.hash() % tableSize;
		arr[hash].push_back(el);
	}
	void del(T el) {
		unsigned int hash = el.hash() % tableSize;
		auto i = arr[hash].begin();
		bool flag = true;
		while (flag&& i != arr[hash].end()) {		//foreach
			if (*i == el) {
				arr[hash].erase(i);
				nowSize--;
				flag = false;
			}
			else {
				++i;
			}
		}
	}

};