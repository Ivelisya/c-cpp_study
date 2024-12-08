//
// Created by 20212 on 24-9-24.
//
#include <iostream>
//using namespace std;
//using namespace std;
#include <string>

using namespace std;

//int main() {
//    string s1;
//    string s2("hello");
//    string s3(s2);
//    string s4(10, 'a');
//    string s5 = "hello";
//    string s6 = s2;
//
//    s1 = s2;
//    cout << s1 << endl;
//    cout << s2 << endl;
//    cout << s3 << endl;
//    cout << s4 << endl;
//    cout << s5 << endl;
//    cout << s6 << endl;
//    return 0;
//}
int main(){
//    string s("12345");
//    s.push_back('6');
//    s.append("abcdefg");
//    s += "hijklmn";
//    cout << s << endl;
//    s.insert(5, "123");
    string s("12345");
    int val = 0;
    for(size_t i = 0;i < s.size();i++){
        val += s[i] - '0';
        val *= 10;
        cout << val << endl;
    }
}