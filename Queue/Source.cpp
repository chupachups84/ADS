#include "Queue.h"
#include <iostream>
using namespace std;
struct zxc {
	int x;
	int y;
	int k;
};
void main() {
	Queue<zxc> steps;
	int x, y;
	cout << "otkyda ";
	/*cin >> x >> y;*/
	x = 7, y = 6;
	cout << x << " " << y << "\n";
	zxc ourpos = { x,y,0 };
	int chess[8][8] = 
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1},
		{ 1, 1, 1, 1, 1, 1, 1, 1},
		{-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1},
		{ 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0},
	};
	/*cout << "zapolni chess dosky, 0 - white, 1 - black , -1 - empty :\n\n";
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << i << " " << j << " pos: ";
			cin >> chess[i][j];
		}
	}*/
	steps.push(ourpos);
	cout << "kyda: ";
	/*cin >> x >> y;*/
	x = 1, y = 3;
	cout << x << " " << y << '\n';
	zxc pos = { x,y,0 };
	zxc cur = {0,0,0};
	while (!steps.isEmpty() &&(steps.front().x != pos.x || steps.front().y != pos.y)) {
		cur = steps.front();
		steps.pop();
		zxc step;
		cout << "curr: " << cur.x << " " << cur.y << " " << cur.k<<":\n";
		if (cur.x + 1 < 8 && cur.y + 2 < 8 && chess[cur.x + 1][cur.y + 2] != 0) {
			step = { cur.x + 1 ,cur.y + 2,cur.k + 1 };
			if (chess[step.x][step.y] == 1) step.k++;
			steps.push(step);
			cout << step.x << " " << step.y << " " << step.k << "\n";
		}
		if (cur.x + 1 < 8 && cur.y - 2 >= 0 && chess[cur.x + 1][cur.y - 2] != 0) {
			step = { cur.x + 1 ,cur.y - 2,cur.k + 1 };
			if (chess[step.x][step.y] == 1) step.k++;
			steps.push(step);
			cout << step.x << " " << step.y << " " << step.k << "\n";
		}
		if (cur.x - 1 >= 0 && cur.y + 2 < 8 && chess[cur.x - 1][cur.y + 2] != 0) {
			step = { cur.x - 1 ,cur.y + 2,cur.k + 1 };
			if (chess[step.x][step.y] == 1) step.k++;
			steps.push(step);
			cout << step.x << " " << step.y << " " << step.k << "\n";
		}
		if (cur.x - 1 >= 0 && cur.y - 2 >= 0 && chess[cur.x - 1][cur.y - 2] != 0) {
			step = { cur.x - 1 ,cur.y - 2,cur.k + 1 };
			if (chess[step.x][step.y] == 1) step.k++;
			steps.push(step);
			cout << step.x << " " << step.y << " " << step.k << "\n";
		}

		if (cur.x + 2 < 8 && cur.y + 1 < 8 && chess[cur.x + 2][cur.y + 1] != 0) {
			step = { cur.x + 2 ,cur.y + 1,cur.k + 1 };
			if (chess[step.x][step.y] == 1) step.k++;
			steps.push(step);
			cout << step.x << " " << step.y << " " << step.k << "\n";
		}
		if (cur.x - 2 >= 0 && cur.y + 1 < 8 && chess[cur.x - 2][cur.y + 1] != 0) {
			step = { cur.x - 2 ,cur.y + 1,cur.k + 1 };
			if (chess[step.x][step.y] == 1) step.k++;
			steps.push(step);
			cout << step.x << " " << step.y << " " << step.k << "\n";
		}
		if (cur.x + 2 < 8 && cur.y - 1 >= 0 && chess[cur.x + 2][cur.y - 1] != 0) {
			step = { cur.x + 2 ,cur.y - 1,cur.k + 1 };
			if (chess[step.x][step.y] == 1) step.k++;
			steps.push(step);
			cout << step.x << " " << step.y << " " << step.k << "\n";
		}
		if (cur.x - 2 >= 0 && cur.y - 1 >= 0 && chess[cur.x - 2][cur.y - 1] != 0) {
			step = { cur.x - 2 ,cur.y - 1,cur.k + 1 };
			if (chess[step.x][step.y] == 1) step.k++;
			steps.push(step);
			cout << step.x << " " << step.y << " " << step.k << "\n";
		}
	}
	cur = steps.front();
	cout << cur.k;

}