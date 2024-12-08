//
// Created by 20212 on 24-9-25.
//
#include <iostream>
#include <string>
using namespace std;

void TextString() {
    string s1("hello world");
    string s2("hello");
    cout << s1.size() << endl;
    cout << s2.size() << endl;
    cout << s1.length() << endl;
    cout << s2.length() << endl;

    // cout << s1.max_size() << endl;
    cout << s1.capacity() << endl;

    s1 += "11111111";
    s1.reserve(1000);
    cout << s1.capacity() << endl;
    cout << s2.capacity() << endl;
    //string 可以自己增容

    string s("hellow world");
    s.resize(5);
    s.resize(20,'x');
}

void test_string() {
    string s;
    s.push_back('x');
    s.append("1234");

    s += 'x';
    s.insert(s.begin(),'0');
    s.insert(1,"9");
    cout << s << endl;
    // s.erase(2,3);
    s.erase(2);
    cout << s << endl;
}
int main() {
    // TextString();
    test_string();
}
