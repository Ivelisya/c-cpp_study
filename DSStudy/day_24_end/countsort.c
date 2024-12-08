#include <assert.h>
#include <stdlib.h>
#include <string.h>

void CountSort(int* a, int n) {
    assert(a);

    int min = a[0];
    int max = a[0];
    //空间复杂度 O（n + range);
    // Find the minimum and maximum elements in the array
    for (int i = 1; i < n; ++i) {
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
    }

    int range = max - min + 1;
    int* countArr = (int*)malloc(sizeof(int) * range);
    memset(countArr, 0, sizeof(int) * range);

    // Count the occurrences of each element
    for (int i = 0; i < n; ++i) {
        countArr[a[i] - min]++;
    }

    // Sort the array
    int index = 0;
    for (int j = 0; j < range; ++j) {
        while (countArr[j]--) {
            a[index++] = j + min;
        }
    }

    free(countArr);
}
