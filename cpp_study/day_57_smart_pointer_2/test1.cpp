#if 0
new/malloc/fopen

func(); 有可能会抛出异常size_t
delete/free/fclose
1.忘记释放
2.异常安全

智能指针来解决

构造时保存资源
析构时释放资源

string拥有智能空间 智能指针受人托管资源空间，可以访问空间
#endif
#include "SmartPtr.h"
// c++98 auto_ptr 使用管理权转移 即管理权给你之后自己就置空   早期的设计缺陷 一般公司都不允许使用这个
//
// c++11 unique_ptr 不能拷贝构造和赋值构造 但是可以移动构造和移动赋值 缺陷：不能共享资源
//
// c++11 shared_ptr 可以共享资源 但是有循环引用的问题
