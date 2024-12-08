#include <iostream>
#include <string>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x % 10 == 0 && x != 0)) return false;
        std::string str_x = std::to_string(x);
        int begin = 0;
        int end = str_x.size() - 1;
        while(begin <= end){
            if(str_x[begin] == str_x[end]){
                begin++;
                end--;
            }else{
                return false;
            }
        }
        return true;
    }
};