//
// Created by 20212 on 25-2-17.
//
#include <memory>
#include <iostream>
using namespace std;
class A
{
public:
    ~A()
    {
        std::cout << "A::~A()" << std::endl;
    }
private:
    int _a1;
    int _a2;
};

int main()
{
    std::shared_ptr<A> sp(new A);
    return 0;
}