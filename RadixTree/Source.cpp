#include <iostream>
#include "RadixTree.h"
int main() {
	RadixTree tr;
	tr.add("abcd");
	tr.add("abc");
	tr.add("efc");
	tr.print();

}