#include <iostream>
#include <string>

using namespace std;

void test_string() {
    // 用于存储测试字符串
    string testStrings[] = {"string.cpp.zip", "string.c", "string.txt"};

    // 遍历每个字符串，提取并输出后缀
    for (const auto &str : testStrings) {
        size_t pos = str.rfind('.');
        if (pos != string::npos) {
            cout << str.substr(pos) << endl;
        }
    }

    // 解析 URL
    string url("https://blog.simazhangyu.com/");
    size_t scheme_end = url.find(':'); // 查找 ':' 的位置
    if (scheme_end != string::npos) {
        cout << url.substr(0, scheme_end) << endl; // 输出协议部分
    }

    size_t host_start = scheme_end + 3; // 跳过 '://'
    size_t path_start = url.find('/', host_start);
    if (path_start != string::npos) {
        cout << url.substr(host_start, path_start - host_start) << endl; // 输出主机名部分
    }

    // 输出路径部分
    cout << url.substr(path_start + 1) << endl;
}

void test_string1() {
    string s1("hello");
    string ret1 = s1 + "world";
    string ret2 = s1+= "world";
    cout << ret1 <<endl;
    cout << ret2 <<endl;

    string s2 = "abcd";
    cout << (s2 < "bbcd") <<endl;
}
int main() {
    // test_string();

    //cin遇到空格换行都结束
    //getline 遇到换行才结束
    test_string1();
}
