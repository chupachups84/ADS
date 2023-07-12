#include <iostream>
#include"ChainHashTable.h"
#include "StringHash.h"


int main() {
	string s1 = "aabbccae",s2 = "aabbccaab";
	int result = compareStrings(s1, s2);

	if (result == 0) {
		cout << s1 << " and " << s2 << " are equal" << endl;
	}
	else if (result < 0) {
		cout << s1 << " is less than " << s2 << endl;
	}
	else {
		cout << s1 << " is greater than " << s2 << endl;
	}
	return 0;

	



}