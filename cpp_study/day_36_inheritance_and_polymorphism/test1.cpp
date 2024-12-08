//
// Created by 20212 on 24-10-24.
//
//面向对象三大特征:封装，继承,多态
//继承本质是一种封装

//派生类对象 可以赋值给基类对象/基类指针/基类引用
//引用的底层也是用指针实现

//继承当中的作用域
//子类和父类中有同名成员，子类成员将屏蔽父类对同名成员的访问,这种叫隐藏，也叫重定义
//函数名相同叫做隐藏

//继承public 基类public 继承到派生类仍然是public
//protect 基类public 继承到派生类之后 在派生类里面是protect protect仍是protect

using namespace std;
#include <iostream>
#include <string>
//构造父类调父类的构造 析构调父类的析构
//不能自己初始化父类的

//拷贝构造 也会 父类调用父类的拷贝构造 自己内置类型自己拷贝
//子类对象可以传引用给父类对象 切片

//~Student ~Person构成隐藏 因为他们的名字会被编译器统一处理

//如何设计一个不能被继承的类
//构造私有私有的构造函数
// class A
// {
// private:
//     A(){};
// };
// class B:public A{};
// int main()
// {
//     //B b此时B无法生成，因为构造函数被私有，即使B中没有成员，但因为是继承的A，在构造的时候也会采用父类的构造函数，不会生成自己的
//
//
// }

//友缘关系不能被继承 有缘关系各自是各自的
//静态被继承还是同一个

//一个子类只有一个父类 单继承
//一个子类有两个或者以上的直接父类 多继承
//还有棱形继承  棱形继承存在很大的问题

//继承是类的复用
//菱形继承的问题是:数据冗余和二义性 二义性无法明确知道访问的是哪一个

//显示指定访问哪个父类成员可以解决二义性问题

//虚继承解决了数据冗余和二义性
//面试题:c++的缺陷有哪些?多继承就是一个问题 ->菱形继承 ->虚继承 引发的问题 底层结构的对象非常复杂，且有一定的效率损失
//什么是菱形继承 菱形继承的问题 数据冗余二义性

//内存对象模型(对象在内存中是怎么存的)

#include <iostream>
using namespace std;

// 基类 A
class A {
public:
    A() { cout << "Constructing A" << endl; }
    virtual void sayHello() { cout << "Hello from A" << endl; }
};

// 类 B 和类 C 都继承自 A，且使用虚继承
class B : virtual public A {
public:
    B() { cout << "Constructing B" << endl; }
    void sayHello() override { cout << "Hello from B" << endl; }
};

class C : virtual public A {
public:
    C() { cout << "Constructing C" << endl; }
    void sayHello() { cout << "Hello from C" << endl; }
};

// 类 D 同时继承 B 和 C
class D : public B, public C {
public:
    D() { cout << "Constructing D" << endl; }
    void sayHello() {
        cout << "Hello from D" << endl;
        B::sayHello(); // 调用B的sayHello
        C::sayHello(); // 调用C的sayHello
        A::sayHello(); // 调用A的sayHello
    }
};

int main() {
    // D d;
    // d.sayHello();
    // return 0;
    B b;
    b.sayHello();
}
//虚拟继承原理 虚基表 存偏移量 找虚基类
//实际中不到万不得已，不要把类的关系设计成菱形继承，因为菱形继承太过复杂，容易出各种问题

//什么是继承什么是组合
//继承
//class A{}
//class B:public A{}; A和B的关系就是继承

//class C{}
//class D{C c;};C和D的关系就是组合 都完成了类层次的复用

//继承是一种白箱复用 父类对子类基本透明，但是它一定程度破坏了父类的封装
//组合是一种黑箱复用 C对D不透明，C继续保持它的封装

//对比来看 组合更好 组合的类的耦合度更低 继承的类是一种高耦合
//继承是 is a 组合是 has a

//符合is a 就使用继承
//符合has a 就使用组合
//都适用就使用组合

//菱形