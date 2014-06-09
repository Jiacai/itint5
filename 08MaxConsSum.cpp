//有一个包含n个元素的数组arr，计算最大的子段和（允许空段）

#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int maxConsSum(const vector<int> &arr) {
    int max = 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (sum < 0) sum = 0;
        sum += arr[i];
        if (sum > max) max = sum;
    }
    return max;
}