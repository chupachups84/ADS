#pragma once
#include <string>
#include <iostream>

class HashTable
{
private:
	int size;
	int nowSize;
	enum status { DELETED = -1, EMTY, FULL };
	std::pair < status, std::string>* table;
	void rehash();
	int getIndexOf(std::string data);
	long long hash(std::string str);
public:
	HashTable(int size);
	~HashTable();
	void add(const std::string data);
	void remove(int ind);
	void remove(std::string data);
	bool searh(std::string data);
	void print();
};
