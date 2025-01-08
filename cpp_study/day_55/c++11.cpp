//
// Created by 20212 on 25-1-6.
//
// 异常

// 异常是一种面向对象语言处理错误的一种方式
// c语言传统的处理错误的方式有哪些呢
// 1.返回错误码 很多api接口都是把错误码放到errno中
// 2.终止程序 比如发生越界严重问题时，我们也可以主动调用 exit() 来终止程序

// 传统的错误处理方式有什么问题呢
// 1.有些函数很难处理
//  T& operator[](int index){}
//  如果一个函数是通过返回值拿数据，发生错误时很难处理
// 如果index越界，如何返回
// 2.如果调用的函数很深,一层一层的传递错误码，很麻烦
// 3.拿到错误码，我们也不知道是什么错误，需要去查文档

// 面对上面的问题，c++提供了异常处理机制
// int main() {
//   vector<int> v = {1, 2, 3, 4, 5, 6};
//   for (int i = 0; i < 10; i++) {
//     try {
//       cout << v.at(i) << endl;
//     } catch (const out_of_range &e) {
//       cout << e.what() << endl;
//     }
//   }
//   return 0;
// }

// throw 可以抛出任意类型的异常
// 直接跳转到catch匹配的地方

// 寻找位置最近的catch

// catch(...) 捕获没有匹配的任意类型的异常，避免异常没有捕获时程序直接终止了

// catch(...){
// 未知错误

// 从自己往上找 没有一直没有找到就会终止程序
// new delete
// 异常重新抛出 new 之后 出现异常，delete 之前的内存会泄漏
// 所以需要先拦截异常，再delete 然后重新抛出

// 自定义异常体系

// 公司一般会给一个基类
// 要求你可以自己抛你自己定义的异常，但是必须继承公司给的基类
// 这样的话，外层捕获只需要捕获公司给的基类就可以了
#include <exception>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Exception {
public:
  Exception(const char *str, int errid) : _errid(errid), _errmsg(str) {}
  virtual string what() { return _errmsg; }

protected:
  int _errid;     // 错误码
  string _errmsg; // 错误信息
};

class SqlException : public Exception {
public:
  SqlException(const char *str, int errid = 0) : Exception(str, errid) {}
  string what() override { return "数据库错误: " + _errmsg; }
};

class Network : public Exception {
public:
  Network(const char *str, int errid = 0) : Exception(str, errid) {}
  string what() override { return "网络错误: " + _errmsg; }
};

void ServerStart() {
  int error_type = rand() % 3; // 随机生成 0, 1, 2
  if (error_type == 0)
    throw SqlException("数据库连接失败", 1001);
  else if (error_type == 2)
    throw Network("网络连接失败", 2001);
  else
    throw Exception("未知错误", 0);
}

int main() {
  try {
    ServerStart();
  } catch (SqlException &e) {
    cout << e.what() << endl;
  } catch (Network &e) {
    cout << e.what() << endl;
  } catch (Exception &e) {
    cout << e.what() << endl;
  }
  return 0;
}
//函数规范一下，如果要抛异常，得说明一下
//但是现实中，很多人嫌麻烦，不遵守规范

//1.异常的优缺点
//优点
//1.清晰的包含错误信息
//2.面对 T operator[](int index) 这种函数越界错误，异常可以很好解决
//3.多层调用时，里面发生错误，不再需要层层处理 最外层直接捕获即可
//4，很多第三方库都使用异常，我们也使用异常，可以更好的配合 boost gtest gmock
//缺点
//1.异常会导致执行流乱跳 会给我们调试分析带来一些困难
//2.异常可能会导致资源泄漏 异常安全问题。 需要学会使用RAII技术
//3.c++库里面的异常体系定义不太好用
//4.c++的异常语法可以抛任意类型的异常，不太好控制,所以一般需要定义出自己的异常体系

// 异常整体而言还是一个利大于弊的东西，所以实际日常练习或者小项目，不太使用
// 公司一般还是会选择异常来处理错误

