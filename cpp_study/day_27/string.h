#include <cassert>
#include <iostream>
using namespace std;

namespace simulation {
    class string {
    public:
        // 类型定义：迭代器
        typedef char *iterator;

        string(const char *str = "") {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1];
            strcpy_s(_str, _capacity + 1, str);
        }
        void swap(string&s) {
            ::swap(_str,s._str);
            ::swap(_size,s._size);
            ::swap(_capacity,s._capacity);
        }
        string(const string &s) : _str(nullptr),_size(0),_capacity(0) {
            string tmp(s._str);
            this -> swap(tmp);
        }

        ~string() {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }

        string &operator=(string s) {
            if (this != &s) {
                this -> swap(s);
            }
            return *this;
        }

        char &operator[](size_t i) {
            assert(i < _size);
            return _str[i];
        }

        const char &operator[](size_t i) const {
            assert(i < _size);
            return _str[i];
        }

        string &operator+=(char ch) {
            this->push_back(ch);
            return *this;
        }

        string &operator+=(const char *str) {
            this->append(str);
            return *this;
        }

        iterator begin() {
            return _str;
        }

        iterator end() {
            return _str + _size;
        }

        size_t size() const {
            return _size;
        }

        size_t capacity() const {
            return _capacity;
        }

        const char *c_str() const {
            return _str;
        }

        void push_back(char ch) {
            if (_size == _capacity) {
                size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
                reserve(newcapacity);
            }
            _str[_size] = ch;
            ++_size;
            _str[_size] = '\0';
        }

        void reserve(size_t n) {
            if (n > _capacity) {
                char *newstr = new char[n + 1];
                strcpy_s(newstr, _size + 1, _str);
                delete[] _str;
                _str = newstr;
                _capacity = n;
            }
        }

        void append(const char *str) {
            size_t len = strlen(str);
            if (_size + len > _capacity) {
                reserve(_size + len);
            }
            strcpy_s(_str + _size, len + 1, str);
            _size += len;
        }

        string &insert(size_t pos, char ch) {
            assert(pos <= _size);
            if (_size == _capacity) {
                size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
                reserve(newcapacity);
            }
            int end = _size;
            //有符号与无符号进行比较时 往数据大的转 有符号无符号都是占用4个字节 无符号的数更大
            while (end >= (int)pos) {
                _str[end + 1] = _str[end];
                --end;
            }
            _str[pos] = ch;
            ++_size;
            _str[_size] = '\0';
            return *this;
        }

        string &insert(size_t pos, const char *stt) {
            assert(pos <= _size);
            size_t len = strlen(stt);
            if (_size + len > _capacity) {
                reserve(_size + len);
            }
            for (int i = _size - 1; i >= (int)pos; --i) {
                _str[i + len] = _str[i];
            }
            for (size_t i = 0; i < len; ++i) {
                _str[pos + i] = stt[i];
            }
            _size += len;
            _str[_size] = '\0';
            return *this;
        }

        void resize(size_t n, char ch = '\0') {
            if (n < _size) {
                _str[n] = '\0';
                _size = n;
            } else {
                if (n > _capacity) reserve(n);
                for (size_t i = _size; i < n; i++) _str[i] = ch;
                _str[n] = '\0';
                _size = n;
            }
        }

        void erase(size_t pos, size_t len) {
            assert(pos < _size);
            if (len >= _size - pos) {
                _str[pos] = '\0';
                _size = pos;
            } else {
                size_t i = pos + len;
                while (i <= _size) {
                    _str[i - len] = _str[i];
                    i++;
                }
                _size -= len;
            }
        }

        size_t find(char ch, size_t pos = 0) {
            for (size_t i = pos; i < _size; ++i) {
                if (_str[i] == ch) return i;
            }
            return npos;
        }

        size_t find(const char *str, size_t pos = 0) {
            char *p = strstr(_str, str);
            if (p == nullptr) return npos;
            else return p - _str;
        }

        bool operator<(const string &s) {
            return strcmp(_str, s._str) < 0;
        }

        bool operator==(const string &s) {
            return strcmp(_str, s._str) == 0;
        }

        bool operator<=(const string &s) {
            return *this == s || *this < s;
        }

        bool operator>(const string &s) {
            return !(*this <= s);
        }

        bool operator>=(const string &s) {
            return !(*this < s);
        }

        bool operator!=(const string &s) {
            return !(*this == s);
        }

        static size_t npos;

    private:
        char *_str; // 字符串指针
        size_t _size; // 字符串长度
        size_t _capacity; // 字符串容量
    };

    size_t string::npos = -1;

    // 输出运算符重载
    // 输出运算符重载
    ostream &operator<<(ostream &out, const string &s) {
        for (size_t i = 0; i < s.size(); ++i) out << s[i];
        return out;
    }

    // 输入运算符重载
    istream &operator>>(istream &in, string &s) {
        // s.resize(0);
        // char buffer[1024];
        // in >> buffer;
        // s.append(buffer);
        // return in;
        while (1) {
            char ch;
            ch = in.get();
            if (ch == ' ' || ch == '\n') {
                break;
            }
            s += ch;
        }
        return in;
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
        for (auto e: s2) {
            cout << e << " ";
        }
        cout << endl;
    }

    void test_string4() {
        string s1("hello");
        s1.insert(1, 'x');
        cout << s1 << endl;
        s1.insert(1, "helloworld");
        cout << s1 << endl;
    }

    void test_string5() {
        std::string s2("hello");

        // 输出初始状态
        std::cout << "Initial size: " << s2.size() << std::endl;
        std::cout << "Initial string: " << s2 << std::endl;
        std::cout << "Initial capacity: " << s2.capacity() << std::endl;

        // 扩展到 8 个字符，应该用 '\0' 填充多余的部分
        s2.resize(8);
        std::cout << "\nAfter resize(8):" << std::endl;
        std::cout << "Size: " << s2.size() << std::endl;
        std::cout << "String: " << s2 << std::endl;
        std::cout << "Capacity: " << s2.capacity() << std::endl;

        // 扩展到 10 个字符，用 'a' 填充
        s2.resize(10, 'a');
        std::cout << "\nAfter resize(10, 'a'):" << std::endl;
        std::cout << "Size: " << s2.size() << std::endl;
        std::cout << "String: " << s2 << std::endl;
        std::cout << "Capacity: " << s2.capacity() << std::endl;

        // 扩展到 20 个字符，用 'y' 填充
        s2.resize(20, 'y');
        std::cout << "\nAfter resize(20, 'y'):" << std::endl;
        std::cout << "Size: " << s2.size() << std::endl;
        std::cout << "String: " << s2 << std::endl;
        std::cout << "Capacity: " << s2.capacity() << std::endl;
    }

    void test_string6() {
        string s1("abcde");

        // 插入单个字符
        s1.insert(2, 'X');
        cout << "After inserting 'X' at index 2: " << s1 << endl; // abXcde

        // 插入字符串
        s1.insert(4, "YZ");
        cout << "After inserting 'YZ' at index 4: " << s1 << endl; // abXYcYZde
    }

    // 测试用例7：测试字符串删除
    void test_string7() {
        string s1("abcdefgh");

        // 删除从索引2开始的3个字符
        s1.erase(2, 3);
        cout << "After erasing 3 characters from index 2: " << s1 << endl; // abfgh

        // 删除超出范围的字符，应该处理得当
        s1.erase(3, 10);
        cout << "After trying to erase more characters than available: " << s1 << endl; // abf
    }

    // 测试用例8：测试字符串查找
    void test_string8() {
        string s1("hello world");

        // 查找字符
        size_t pos1 = s1.find('o');
        cout << "First occurrence of 'o': " << pos1 << endl; // 4

        // 查找不存在的字符
        size_t pos2 = s1.find('z');
        if (pos2 == -1)
            cout << "'z' not found" << endl; // 'z' not found

        // 查找子字符串
        size_t pos3 = s1.find("world");
        cout << "Position of 'world': " << pos3 << endl; // 6

        // 从指定位置开始查找
        size_t pos4 = s1.find('o', 5);
        cout << "First occurrence of 'o' after index 5: " << pos4 << endl; // 7
    }

    // 测试用例9：测试+= 运算符
    void test_string9() {
        string s1("abc");

        // 添加单个字符
        s1 += 'd';
        cout << "After adding 'd': " << s1 << endl; // abcd

        // 添加字符串
        s1 += "efg";
        cout << "After adding 'efg': " << s1 << endl; // abcdefg
    }

    // 测试用例10：测试扩容与 push_back
    void test_string10() {
        string s1;

        // 添加字符，测试自动扩容
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            s1.push_back(ch);
            cout << "String: " << s1 << ", Size: " << s1.size() << ", Capacity: " << s1.capacity() << endl;
        }
    }
}

// 常量，代码指令都在代码段

namespace string_copy {
    //构造 析构 拷贝 赋值
    class string {
        string(const char *str = ""): _str(new char[strlen(str) + 1]) {
            strcpy(_str, str);
        }

        ~string() {
            delete[]_str;
            _str = nullptr;
        }

        //传统写法
        // string(const string &s): _str(new char[strlen(s._str) + 1]) {
        //     strcpy(this->_str, s._str);
        // }

        //现代写法
        string(const string &s): _str(nullptr) {
            string tmp(s._str);
            //使用s._str调用析构函数开空间
            //然后用空 和 这个 进行交换
            swap(_str, tmp._str);
        }

        //s1 = s2
        // string &operator=(string &s) {
        //     //比较 当前和 传入的地址 这样就可以判断
        //     if (this != &s) {
        //         // char *tmp = new char[strlen(s._str) + 1];
        //         // strcpy(tmp, _str);
        //         // delete[] _str;
        //         // _str = tmp;
        //         string tmp(s._str);
        //         //tmp是一个临时对象，出作用域调用析构函数
        //         swap(_str, tmp._str);
        //     }
        //     return *this;
        // }
        string &operator=(string s) {
            swap(_str,s._str);
            return *this;
        }

    private:
        char *_str;
    };
}
