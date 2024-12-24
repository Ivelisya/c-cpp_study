//
// Created by 20212 on 24-12-24.
//
#include <iostream>
using namespace std;
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>
// int main()
// {
//     atomic<int> x = 0;
//     auto add = [&x](int n)
//     {
//         for (int i = 0; i < n; ++i)
//         {
//             ++x;
//         }
//     };
//     thread t1(add, 10);
//     thread t2(add, 10);
//
//     cout << t1.get_id() << endl;
//     cout << t2.get_id() << endl;
//
//     t1.join();
//     t2.join();
// }

//m个线程对x加n次
int main()
{
    atomic<int> x = 0;
    int m, n;
    cin >> m >> n;
    // vector<thread> vthreads;
    // for (int i = 0; i < m; ++i)
    // {
    //     vthreads.push_back(thread([&x](int count)
    //     {
    //         for (int i = 0; i < count; ++i)
    //         {
    //             ++x;
    //         }
    //     }, n));
    // }
    vector<thread> vthreads(10);
    for (int i = 0;i < m;++i)
    {
        //匿名函数也是将亡值
        vthreads[i] = thread([&x](int count)
        {
            for (int i = 0; i < count; ++i)
            {
                ++x;
            }
        }, n);
    }
    for (auto &t:vthreads)
    {
        cout << t.get_id() << ".join()" << endl;
        t.join();
    }
}
