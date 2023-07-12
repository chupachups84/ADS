#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;

struct point {
	double x;
	double y;
	double z;
	friend bool operator==(point const& a, point const& b)
	{
		return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
	}
	friend bool operator!=(point const& a, point const& b) {
		return !(a == b);
	}
	friend ostream& operator<<(ostream& ost, point const& pt)
	{
		ost << "(" << pt.x << " " << pt.y << " " << pt.z << ")";
		return ost;
	}
};

point cm(vector<point> vectorOfPoint) {
	double x=0, y=0, z=0;
	int n=0;
	for (point p : vectorOfPoint) {
		x += p.x;
		y += p.y;
		z += p.z;
		n++;
	}
	point p = { x / n,y / n,z / n };
	return p;
}

double dmin = DBL_MAX; 
vector<point> result1,result2, set1;

void findDmin(vector<point> setOfPoints) {
	point cm1 = cm(set1);
	bool isEqualIn; ;
	vector<point> set2;
	for (int i = 0; i < setOfPoints.size(); i++) {
		isEqualIn = false;
		for (point p : set1) {
			if (setOfPoints[i] == p) {
				isEqualIn = true;
				break;
			}
		}

		if (!isEqualIn) {
			set2.push_back(setOfPoints[i]);
		}
	}
	point cm2 = cm(set2);
	double x = cm1.x - cm2.x;
	double y = cm1.y - cm2.y;
	double z = cm1.z - cm2.z;
	double distance = sqrt(x*x +y*y+z*z);
	if (distance < dmin) {
		dmin = distance;
		result1 = set1;
		result2 = set2;

	}
	
}

void calc(vector<point> setOfPoints,int indexBegin,int count) {
	for (int i = indexBegin; i < setOfPoints.size(); i++) {
		set1.push_back(setOfPoints[i]);
		if (count > 1&&i< setOfPoints.size()-1 ) {
			calc(setOfPoints,  i + 1, count - 1);
		}
		findDmin(setOfPoints);
		set1.pop_back();
	}
}

void main() {
	vector<point> ust ={ {10,0,0}, {0,0,0}, {0,1,0}, {10,2,0}};
	for (int i = 0; i < ust.size()/2; ++i)
	{
		calc( ust, 0,i+1);
	}
	cout << dmin<<'\n';
	cout << "set1: ";
	for (auto p : result1) {
		cout << p << " ";
	}
	cout << "\nset2: ";
	for (auto p : result2) {
		cout << p << " ";
	}

}