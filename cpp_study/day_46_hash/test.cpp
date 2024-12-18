#include <chrono>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void test_unordered_map_set()
{
    std::set<int> s = {1, 3, 4, 7};

    for (int value : s)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::unordered_map<std::string, std::string> dict = {
        {"sort", "排序"}, {"string", "字符串"}, {"left", "左边"}};

    for (const auto &pair : dict)
    {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    std::cout << "----------------" << std::endl;
}

void test_op()
{
    std::vector<int> v;
    auto start1 = std::chrono::high_resolution_clock::now();
    std::unordered_set<int> us(v.begin(), v.end());
    auto end1 = std::chrono::high_resolution_clock::now();
    std::cout << "unordered_set: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end1 -
                                                                       start1)
                     .count()
              << " ms" << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    std::set<int> s(v.begin(), v.end());
    auto end2 = std::chrono::high_resolution_clock::now();
    std::cout << "set: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end2 -
                                                                       start2)
                     .count()
              << " ms" << std::endl;
}

int main()
{
    // test_unordered_map_set();

    test_op();
    return 0;
}
