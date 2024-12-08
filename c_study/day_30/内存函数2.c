//
// Created by 20212 on 24-4-21.
//
//memcpy内存拷贝函数
//memcpy应该拷贝内存不重叠的函数
//memmove 可以处理内存重叠的情况
//memcmp 内存比较
//memset 内存设置
void *my_memmove(void *dest, const void *src, size_t num) {

// 可以把源数据从后往前拷贝

    if (dest < src) {
        //从前向后
        while(num --) {
            *(char *) dest = *(char *) src;
            dest = (char *) dest + 1;
            src = (char*)src + 1;
        }
    } else {
        //从后向前
    };
}


int main(){
    int arr1[10] = {1,2,3,4,5,9,6,7,8,10};
    my_memmove(arr1 + 2,arr1,20);
//    memcpy()原本是不可以的，但是在vs中的实现，既可以拷贝不重叠又可以拷贝重叠
    return 0;
}