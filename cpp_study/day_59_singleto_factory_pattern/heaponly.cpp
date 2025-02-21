#include <iostream>
#include <memory>
using namespace std;
//创建出的类对象只能在堆上
//思路：正常创建对象一定要调用构造函数,或者析构函数
class HeapOnly{
public:
    static HeapOnly* GetObj(){
        return new HeapOnly;
    }

private:
    HeapOnly(){};
};

int main(){
    // HeapOnly hp;
    // HeapOnly* p = new HeapOnly;
    // HeapOnly* p = HeapOnly::GetObj();
    std::shared_ptr<HeapOnly> p(HeapOnly::GetObj());
    return 0;
}