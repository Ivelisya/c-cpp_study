//
// Created by 20212 on 18/9/2024.
//
#include <iostream>
using namespace std;
class Solution{
public:
    Solution(){
        cout << "Solution()" << endl;
    }
    int Sum_Solution(int n){
        cout << "Sum_Solution()" <<endl;
        return n;
    }
};
int main(){
    Solution s1;//s1的生命周期在main函数当中
    s1.Sum_Solution(10);

//Solution();匿名对象 生命周期就在这一行
    Solution().Sum_Solution(10);//只有我这一行会使用这个创建对象，别人不需要使用
    return 0;
}