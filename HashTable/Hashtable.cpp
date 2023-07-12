#include "HashTable.h"


void HashTable::rehash()
{
	std::pair < status, std::string>* table1 = table;
	table = new std::pair < status, std::string>[size * 2];
	size *= 2;
	nowSize = 0;
	for (int i = 0; i < size / 2; i++)
	{
		if (table1[i].first == FULL)
			add(table1[i].second); // size удваивается перед for т.к инче метод add будет работать неапрвильно (для старого size)

	}
	delete[] table1;

}

int HashTable::getIndexOf(std::string data)
{
	int place = this->hash(data) % size;
	bool done = false;
	int i = 0;
	while (i < size && !done && table[place].first != EMTY)
	{
		if (table[place].first == FULL && table[place].second == data)
			done = true;

		i++;
		place = (place + 1) % size;

	}

	if (done)
	{
		if (place - 1 > 0)
			return (place - 1) % size;
		else
			return size - 1;
	}
	else
		return -1;
}

//long long HashTable::hash(std::string str)
//{
//	long long result = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		result += ((int)str[i]) * pow(11, i);
//	}
//	return result % 1000000005;
//}


long long HashTable::hash(std::string str) {
	const int P = 31;  // Вес символа
	const int K = 1e9 + 5;  // Модуль для получения хеш-кода

	long long hash_value = 0;
	long long p_pow = 1;
	for (char c : str) {
		hash_value = (hash_value + (c + 1) * p_pow) % K;
		p_pow = (p_pow * P) % K;
	}
	return hash_value;
}


HashTable::HashTable(int size)
{
	this->size = size;
	table = new std::pair < status, std::string>[size];
	nowSize = 0;
	for (int i = 0; i < size; i++)
	{
		table[i].first = EMTY;
	}

}

HashTable::~HashTable()
{
	delete[] table;
}

void HashTable::add(const std::string data)
{

	if (nowSize > size / 2)
	{
		rehash();
	}

	int place = hash(data) % size;
	for (int i = 0; i < size && table[place].first == FULL; i++)
	{
		place = (place + 1) % size;
	}
	table[place].first = FULL;
	table[place].second = data;
	nowSize++;
	std::cout << data << std::endl;
}


void HashTable::remove(int index)
{
	table[index].first = DELETED;
	table[index].second = "";
	nowSize--;
}

void HashTable::remove(std::string data)
{
	remove(getIndexOf(data));
}

bool HashTable::searh(std::string data)
{
	return getIndexOf(data) == -1 ? false : true;
}

void HashTable::print()
{
	for (int i = 0; i < size; i++)
	{
		if (table[i].first == FULL)
			std::cout << table[i].second << " ";
	}
	std::cout << std::endl;
}