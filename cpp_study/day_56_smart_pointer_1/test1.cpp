//
// Created by 20212 on 25-1-7.
//
#include <iostream>
using namespace std;

int div()
{
    int a, b;
    cin >> a >> b;
    if (b == 0)
    {
        throw invalid_argument("除0错误");
    }
    return a / b;
};

void f1()
{
    int* p = new int;
    try
    {
        cout << div() << endl;
    }
    catch (...)
    {
        delete p;
        throw;
    }
    //... 捕捉任意异常
    delete p;
};

int main()
{
    try
    {
        f1();
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
