//Набор из n костей домино. Можно ли из них составить цепочку
#include <iostream>
using namespace std;

void swapDomino(pair<int, int>& dominos) {
	swap(dominos.first, dominos.second);
}

bool linking(pair<int, int>* dominos, int n, bool* used, int index,int count) {
	if (count == n) return true;
	bool flag = false;
	for (int i = 0; i < n&&!flag; i++) {
		if (!used[i]) {
			if (dominos[index].second == dominos[i].first|| dominos[index].second == dominos[i].second) {
				if (dominos[index].second == dominos[i].second) { 
					swapDomino(dominos[i]); 
				}
				used[i] = true;
				flag =linking(dominos, n, used, i,count+1);
				used[i] = false;
			}
		}
	}
	return flag;

}

bool isLinkDomino(pair<int, int>* dominos, int n) {
	bool flag = false;
	int i = 0;
	bool* used = new bool(n);
	for (int j = 0; j < n;j++ ) { 
		used[j] = false;
	}

	while (!flag&&i < n) {
		used[i] = true;
		flag = linking(dominos,n,used,i,1);
		if (!flag) {
			swapDomino(dominos[i]);
			flag = linking(dominos, n, used, i,1);
		}
		used[i] = false;
		i++;
	}
	return flag;
}

void main() {
	pair<int, int >* dominos = new pair<int, int>[5]{
		{0,1},
		{1,2},
		{2,3},
		{3,4},
		{4,5},
	};
	cout << isLinkDomino(dominos, 5)<<endl;
}