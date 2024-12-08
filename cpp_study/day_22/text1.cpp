//
// Created by 20212 on 24-9-23.
//
//模板 -> 泛型编程
//编写与类型无关的的通用代码，是一种代码复用的手段
//template <typename T> 模板参数 -> 类型
template<class T>
//class typename 告诉编译器 T是一个类型参数

//在预处理阶段就进行类型参数的替换了
//模板的原理是什么:我们写了模板,编译器通过模板实列出
void Swap(T &x1, T &x2) {
    T x = x1;
    x1 = x2;
    x2 = x;
}

//这里我们不能调用函数模板，调用的是函数模板实例化生成类型的函数
int main() {
    int a = 0, b = 1;
    Swap(a, b);
    double c = 1.11, d = 2.22;
    Swap(c, d);
    char e = 'a', f = 'b';
    Swap(e, f);
    return 0;
}
