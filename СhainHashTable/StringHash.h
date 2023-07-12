#pragma once
#include <string>
#include <iostream>
using namespace std;
class StringHash {
public:
	string str;
	int BASE;
	unsigned int hash() {
		unsigned int h = 0;
		for (int i = 0; i < str.length(); i++) {
			h += (str[i] - 'a' + 1)*pow(BASE,i);
		}
		return h;
	}
	unsigned int prefix(StringHash& b, int tableSize) {
		unsigned int h = 0;
		tableSize = tableSize == 0 ? 1 : tableSize;
		h = hash();
		h-=b.hash();
		h /= pow(BASE, 6);
		return h % tableSize;
	}
	StringHash(string str,int BASE):str(str),BASE(BASE){}
	void setStr(string s){str=s;}
	bool operator==(StringHash str) {
		return this->str._Equal(str.str);
	}
	friend ostream& operator << (ostream& os, StringHash& obj) {
		os << obj.str;
		return os;
	}
	int size() {
		return str.length();
	}
	
};
string substr(string s, int i, int j) {
	string str = "";
	for (i; i < j + 1; ++i)  str += s[i];
	return str;
}
int binaryFindPrefixIndex(StringHash ha, StringHash hb) {
	int mid, l = 0, r = min(ha.str.size(), hb.str.size()) - 1;
	StringHash substr1(ha.str, ha.BASE);
	StringHash substr2(hb.str, hb.BASE);
	while (l < r) {
		mid = (l + r) / 2;
		substr1.setStr(substr(ha.str, 0, mid));
		substr2.setStr(substr(hb.str, 0, mid));
		if (substr1.hash() == substr2.hash()) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	int common;
	substr1.setStr(substr(ha.str, 0, l));
	substr2.setStr(substr(hb.str, 0, l));

	if (substr1.hash() == substr2.hash()) common = l + 1;
	else {
		substr1.setStr(substr(ha.str, 0, l - 1));
		substr2.setStr(substr(hb.str, 0, l - 1));
		if (l - 1 >= 0 && substr1.hash() == substr2.hash())
			common = l;
		else common = 0;
	}

	return common;
}
int compareStrings(string s1, string s2) {
	StringHash str1(s1, 10);
	StringHash str2(s2, 10);
	int index = binaryFindPrefixIndex(str1, str2);
	int n = s1.size(), m = s2.size();
	if (index == n && index == m)
		return 0;
	else if (index == n)
		return -1;
	else if (index == m)
		return 1;
	else {
		ChainHashTable<StringHash> table(17);
		for (int i = index; i < n; i++) {
			str1.setStr(substr(s1, i, i));
			table.add(str1);
		}
		for (int i = index; i < m; i++) {
			str2.setStr(substr(s2, i, i));
			if (!table.search(str2)) {
				return s1[i] < s2[i] ? -1 : 1;
			}
			else {
				table.add(str2);
			}
		}
		return 0;
	}
}

