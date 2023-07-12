#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <climits>

using namespace std;
struct point
{
    double x{}, y{}, z{};
    friend bool operator==(point const& a, point const& b)
    {
        return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
    }
    friend ostream& operator<<(ostream& ost, point const& pt)
    {
        ost << "(" << pt.x << " " << pt.y << " " << pt.z << ")";
        return ost;
    }
};

// центр масс двух точек
point cm(point const& a, point const& b)
{
    return { a.x + (b.x - a.x) / 2.,  a.y + (b.y - a.y) / 2., a.z + (b.z - a.z) / 2. };
}

double dmin = DBL_MAX;;

vector<vector<point>::const_iterator> vit, vres;



void calc(int rd, vector<point> const& ust, vector<point>::const_iterator ib)
{
    if (rd == 0)
    {
        point cm1{ *vit[0] };
        for (int i = 1; i < vit.size(); ++i)
        {
            cm1 = cm(cm1, *vit[i]);
        }
        auto it = find_if(ust.begin(), ust.end(), [](auto pt)
            {
                return none_of(vit.begin(), vit.end(), [&pt](auto it) {
                    return pt == *it; 
                    });
            });
        point cm2 = *it;
        ++it;
        for (auto ib = it; ib != ust.end(); ++ib)
        {
            if (none_of(vit.begin(), vit.end(), [ib](auto it) 
                {
                return ib == it;
                }))
            {
                cm2 = cm(cm2, *ib);
            }
        }
        double x = cm1.x - cm2.x;
        double y = cm1.y - cm2.y;
        double z = cm1.z - cm2.z;
        double dc = sqrt(x * x + y * y + z * z);
        if (dmin > dc)
        {
            dmin = dc;
            vres = vit;
        }
    }
    else
    {
        for (; ib != ust.end(); )
        {
            vit.push_back(ib);
            ++ib;
            calc(rd - 1, ust, ib);
            vit.pop_back();
        }
    }
}



int main()
{
    system("chcp 1251 > 0");
    std::vector<point> ust{ {0,1,0}, {0,0,0}, {10,0,0}, {10,1,0}  }; // множество точек
    for (int i = 0; i < ust.size() / 2; ++i)
    {
       calc(i + 1, ust, ust.begin());
        /*calculate(ust, ust.begin());*/
    }

    // мин. расстояние между центрами масс
    std::cout << "min distance: " << dmin << "\n";

    // одно из двух множеств 
    for (auto it : vres)
    {
        std::cout << *it << " ";
    }
}