#include <iostream>
#include "Bohr.h"
using namespace std;
void main() {
	Bohr b;
	b.add("the");
	b.add("of");
	b.add("method");
	b.add("name");
	b.add("method");
	b.add("aho");
	b.add("is");
	b.add("this");
	b.add("korasik");
	b.find_all_pos("thenameofthismethodisahokorasik");
	cout << "thenameofthismethodisahokorasik";
	cout << endl;
}