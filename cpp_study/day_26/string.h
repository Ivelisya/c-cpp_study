#include <cassert>
#include <iostream>
using namespace std;

namespace simulation {
    class string {
    public:
        // 类型定义：迭代器
        typedef char* iterator;

        // 构造函数，默认参数为""，即空字符串
        string(const char* str = "") {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1];
            strcpy_s(_str, _capacity + 1, str); // 使用安全的strcpy_s
        }

        // 拷贝构造函数，深拷贝
        string(const string& s) : _str(new char[strlen(s._str) + 1]) {
            strcpy_s(_str, strlen(s._str) + 1, s._str); // 使用安全的strcpy_s
            _size = s._size;
            _capacity = s._capacity;
        }

        // 析构函数
        ~string() {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }

        // 赋值运算符重载，确保深拷贝
        string& operator=(const string& s) {
            if (this != &s) {
                char* tmp = new char[strlen(s._str) + 1];
                strcpy_s(tmp, strlen(s._str) + 1, s._str); // 使用安全的strcpy_s
                delete[] _str;
                _str = tmp;
                _size = s._size;
                _capacity = s._capacity;
            }
            return *this;
        }

        // 下标运算符重载，非const版本
        char& operator[](size_t i) {
            assert(i < _size);
            return _str[i];
        }

        // 下标运算符重载，const版本
        const char& operator[](size_t i) const {
            assert(i < _size);
            return _str[i];
        }

        // += 运算符重载，添加字符
        string& operator+=(char ch) {
            this->push_back(ch);
            return *this;
        }

        // += 运算符重载，添加字符串
        string& operator+=(const char* str) {
            this->append(str);
            return *this;
        }

        // 迭代器起点
        iterator begin() {
            return _str;
        }

        // 迭代器终点
        iterator end() {
            return _str + _size;
        }

        // 获取字符串长度
        size_t size() const {
            return _size;
        }

        // 获取字符串容量
        size_t capacity() const {
            return _capacity;
        }

        // 返回 C 风格字符串
        const char* c_str() const {
            return _str;
        }

        // 添加单个字符
        void push_back(char ch) {
            if (_size == _capacity) {
                size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
                reserve(newcapacity);
            }
            _str[_size] = ch;
            ++_size;
            _str[_size] = '\0'; // 保证最后一位为\0
        }

        // 保留容量
        void reserve(size_t n) {
            if (n > _capacity) {
                char* newstr = new char[n + 1];
                strcpy_s(newstr, _size + 1, _str); // 使用安全的strcpy_s
                delete[] _str;
                _str = newstr;
                _capacity = n;
            }
        }

        // 添加字符串
        void append(const char* str) {
            size_t len = strlen(str);
            if (_size + len > _capacity) {
                reserve(_size + len);
            }
            strcpy_s(_str + _size, len + 1, str); // 使用安全的strcpy_s
            _size += len;
        }
        //resize将字符串大小调整为 n 个字符 

    private:
        char* _str; // 字符串指针
        size_t _size; // 字符串长度
        size_t _capacity; // 字符串容量
        static size_t npos;
    };
    size_t string::npos = -1;

    // 输出运算符重载
    ostream& operator<<(ostream& out, const string& s) {
        for (size_t i = 0; i < s.size(); ++i) {
            out << s[i];
        }
        return out;
    }

    // 测试用例1：测试字符串的修改和访问
    void test_string1() {
        string s1("hello");
        string s2;

        // 对s1中的字符逐个修改
        for (size_t i = 0; i < s1.size(); i++) {
            s1[i] += 1;
            cout << s1[i] << " ";
        }
        cout << endl;

        // 测试空字符串s2
        for (size_t i = 0; i < s2.size(); i++) {
            s2[i] += 1;
            cout << s2[i] << " ";
        }
        cout << endl;
    }

    // 测试用例2：测试深拷贝和输出
    void test_string2() {
        string s1("hello");
        string s2(s1); // 深拷贝

        // 输出s1和s2
        cout << s1 << endl;
        cout << s1.c_str() << endl;
        cout << s2.c_str() << endl;
    }

    // 测试用例3：测试字符串的迭代器操作
    void test_string3() {
        string s1("hello");
        string s2(s1);

        for (size_t i = 0; i < s2.size(); ++i) {
            s2[i] += 2;
            cout << s2[i] << " ";
        }
        cout << endl;

        string::iterator it2 = s2.begin();
        while (it2 != s2.end()) {
            *it2 -= 1;
            cout << *it2 << " ";
            ++it2;
        }
        cout << endl;

        // 范围for最终会被替换为迭代器
        for (auto e : s2) {
            cout << e << " ";
        }
        cout << endl;
    }
}

// 常量，代码指令都在代码段
