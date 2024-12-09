//
// Created by 20212 on 24-12-10.
//
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <initializer_list>
using namespace std;
class Point
{
public:
    Point(int x = 0, int y = 0):_x(x),_y(y),_z(1)
    {

    }
private:
    int _x;
    int _y,_z;
};
int main()
{
    int x = 1;
    //c++11
    vector<int> v1{1,2,3,4,5,6};
    vector<int> v2 = {7,8,9,10,11,12};
    list<int> l1{1,2,3,4,5};
    list<int> l2 = {6,7,8,9,10};

    map<string,int> m{{"苹果",1},{"香蕉",2},{"橘子",3}};
    Point p1(1,2);
    Point p2{3,4};
    Point p3 = {5,6};
}