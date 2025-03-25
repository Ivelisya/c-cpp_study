//
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
void test_set1()
{
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(3);
    s.insert(7);
    s.insert(8);
    // ����ȥ��
    set<int>::iterator it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;

    // set<int> copy(s);

    // for (auto e : copy)
    // {
    //     cout << e << " ";
    // }
    // cout << endl;
    // auto pos = s.find(3);
    set<int>::iterator pos = s.find(3);
    // set �� ���������� O(logN)
    // �㷨 find O(N)
    //  ʹ���㷨 find ��ʹ�� set ���� find ������
    s.erase(pos);
    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;
}
// erase ��ֵ �ײ�����ɵ�����ʵ��
// erase �������������ж��Ƿ��ҵ������ֵ

void test_map1()
{
    // map -> pair (key,value)
    map<int, int> m;
    m.insert(pair<int, int>(1, 1));
    m.insert(pair<int, int>(2, 2));
    m.insert(pair<int, int>(3, 3));
    m.insert(make_pair(4, 4)); // ����ģ�幹��һ������
    // ��Ҷ�ϲ����make_pair����Ϊ���ɱ������Լ�����

    map<int, int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << (*it).first << ":" << (*it).second << " ";
        cout << it->first << ":" << it->second << " ";

        ++it;
    }
    cout << endl;

    for (auto& e : m)
    {
        cout << e.first << ":" << e.second << " ";
    }
    cout << endl;
}

void test_map2()
{
    std::map<std::string, std::string> dict;
    dict.insert(pair<std::string, std::string>("sort", "����"));
    dict.insert(make_pair("string", "����"));

    std::map<std::string, std::string>::iterator it = dict.begin();
    while (it != dict.end())
    {
        cout << it->first << ":" << it->second << " ";
        ++it;
    }
    cout << endl;
}

void test_map3()
{
    string strs[]{"����", "����", "����", "����", "����", "����", "����"};
    map<string, int> coutMap;
    for (auto& str : strs)
    {
        map<string, int>::iterator ret = coutMap.find(str);
        if (ret != coutMap.end())
        {
            ret->second++;
        }
        else
        {
            coutMap.insert(make_pair(str, 1));
        }
    }

    for (auto& e : coutMap)
    {
        cout << e.first << " : " << e.second << " ";
    }
    cout << endl;
}
int main()
{
    // test_set1();
    // test_map1();
    // test_map2();
    test_map3();
}

// ������й������˵���ݴ���set�У�����һ�����ڲ������31��
// set �� ��

// ��ֵ ��ȡ��ַ�Ķ��� ����һ���־ö�����ڴ�λ��
// ��ֵ ��ʱֵ
