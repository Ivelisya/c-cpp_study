//
// Created by 20212 on 24-10-19.
//
//适配器模式
//生活中我们使用的适配器是用来进行电压转化的

//stack queue 叫做容器适配器
//通过容器转换出来的

#pragma once
#include <list>
#include <vector>
#include <deque>
namespace stack_study
{
    template <class T, class Container>
    //container适配器
    //list 适配出链表 vector 适配出数组
    //无论是数组还是链表都可以转换出我们要的东西

    //stl中的stack和queue是通过容器转换出来的，不是原生实现的
    //通过复用

    //适配是一种开放包容的形态

    //! 容器进行适配转化
    class stack
    {
    public:
        void push(const T& x)
        {
            _con.push_back(x);
        }

        void pop()
        {
            _con.pop_back();
        }

        size_t size()
        {
            return _con.size();
        }

        bool empty()
        {
            return _con.empty();
        }

        T& top()
        {
            return _con.back();
        }

    private:
        Container _con;
    };

    void test_stack()
    {
        //list双向链表容器
        //vector数组容器 可随机访问
        //string 顺序容器
        stack<int, std::list<int>> st;
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);
        st.push(6);
        while(!st.empty())
        {
            std::cout << st.top() << " ";
            st.pop();
        }
        std::cout << std:: endl;
    }
}
namespace study_queue
{
    template<class T,class Container>
    class queue
    {
    public:
        void push(const T& x)
        {
            _con.push_back(x);
        }
        void pop(){_con.pop_front();}
        size_t size(){ return _con.size();}
        bool empty(){return _con.empty();}
        T& front(){return _con.front();}
    private:
        Container _con;
    };
}

//c++是一个极度关注效率的语言
//导致有些地方因为一丁点的效率变得有些扭曲
//比如:类型萃取

//container adaptor容器适配器

//deque 双端序列 随机访问 可以在任意位置插入删除， 也可以支持随机访问
//也就是说既有vector优点也有list优点
//看起来好像可以替代vector和list的一个容器
//随机访问效率不容乐观

//为什么栈和队列的适配可以用它
//因为栈和队列并没有使用到它的随机访问