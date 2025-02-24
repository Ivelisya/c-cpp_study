#include <iostream>
using namespace std;
class StackOnly{
public:
    static StackOnly GetObj(){
        return StackOnly();
    }
private:
    StackOnly() = default;
};


// 父类的私有在子类中是不可见的