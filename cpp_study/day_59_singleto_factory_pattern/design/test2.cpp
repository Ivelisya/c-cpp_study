#include <iostream>
using namespace std;
namespace hungry_man
{
    // 懒汉模式 一开始(main函数之前)就创建对象
    class Singleton
    {
    public:
        static Singleton* getInstance() { return &_inst; }
        Singleton(const Singleton&) = delete; // 删除拷贝构造函数，防止外部拷贝
        Singleton& operator=(const Singleton&) = delete; // 删除赋值运算符，防止外部赋值

    private:
        Singleton()
        { // 私有默认构造函数
            // 在这里初始化单例的成员变量
            cout << "Singleton instance created." << endl;
        }
        static Singleton _inst;
    };
    Singleton Singleton::_inst; // static是在main函数之前创建的
} // namespace hungry_man

int main()
{
    hungry_man::Singleton* instance1 = hungry_man::Singleton::getInstance();
    hungry_man::Singleton* instance2 = hungry_man::Singleton::getInstance();

    // 验证两个指针是否指向同一个实例
    if (instance1 == instance2)
    {
        cout << "Both instances are the same." << endl;
    }
    else
    {
        cout << "Instances are different." << endl;
    }
    return 0;
}
//总结对比一下饿汉和懒汉的区别
//1.懒汉模式需要考虑线程安全和释放的问题，实现相对更复杂
//2.饿汉模式不存在以上的问题，实现相对简单
//3.如果有多个单例类，  假设有依赖关系，要求a实例先启动，b再启动创建，那么就不能用饿汉，因为无法保证启动初始化顺序
//懒汉模式是一种懒加载模式，需要时初始化创建对象，不会影响程序的启动
//饿汉模式相反 c程序启动截断就创建初始化实例对象，会导致程序启动慢， 影响体验