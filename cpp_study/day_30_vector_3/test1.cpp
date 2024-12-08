//
// Created by admin on 24-10-11.
//
#include <stdio.h>

int main() {
    float result = (854 - 12 * 48) / 1024.0;
    int result_int = (int)result;
    printf("浮点型结果: %f\n", result);
    printf("整型结果: %d\n", result_int);
    return 0;
}
