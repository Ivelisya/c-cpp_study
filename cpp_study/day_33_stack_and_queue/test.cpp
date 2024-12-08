//
// Created by 20212 on 24-10-17.
//
//stack queue

//empty size top push emplace pop swap
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
void test_stack()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
void test_queue()
{
    queue<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    while(!st.empty())
    {
        cout << st.front() << " ";
        st.pop();
    }
    cout << endl;
}
int main()
{
    test_stack();
    test_queue();
}