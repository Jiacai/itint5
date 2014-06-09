//给定一个包含n个整数的数组，计算出它的下一个排列（既C++ STL中的next_permutation函数 http://www.cplusplus.com/reference/algorithm/next_permutation/）。
//数组以引用的形式传入，请直接将下一个排列写回到该引用数组。
//关于函数的返回值，如果存在下一个排列，返回true，否则返回false。

#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
bool next_permutation(vector<int> &arr) {
    bool has_next = false;
    int size = arr.size();
    int i = arr.size() - 1;
    while (i - 1 >= 0) {
        if (arr[i-1] < arr[i]) {
            has_next = true;
            break;
        }
        i--;
    }
    if (!has_next) return false;
    // find the min after i-1
    int min = INT_MAX;
    int minIdx = -1;
    for (int j = i; j < size; j++) {
        if (arr[j] > arr[i-1] && arr[j] < min) {
            min = arr[j];
            minIdx = j;
        }
    }
    int tmp = arr[i-1];
    arr[i-1] = arr[minIdx];
    arr[minIdx] = tmp;
    // sort elements from i
    sort(arr.begin()+i, arr.end());
    return true;
}