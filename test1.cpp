#include <iostream>
using namespace std;
class MyClass
{
private:
    int myPrivateData;

public:
    MyClass(int data) : myPrivateData(data) {}
    friend void accessPrivateData(MyClass& obj); // 声明友元函数
};

void accessPrivateData(MyClass& obj)
{
    std::cout << "Private data: " << obj.myPrivateData << std::endl; // 友元函数可以访问私有成员
}

int main()
{
    MyClass obj(30);
    accessPrivateData(obj); // 调用友元函数
    return 0;
}
