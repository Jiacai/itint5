//有一个包含n个元素的首尾相连的环形数组arr，计算最大的子段和（允许空段）。
//样例：数组[1, 3, -2, 6, -1]，最大子段和应该为9，对应的子段为[6, -1, 1, 3]。

#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int maxConsSum2(const vector<int> &arr) {
    if (arr.size() == 0) return 0;
    int dp = 0;
    int max1 = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (dp < 0) dp = 0;
        dp += arr[i];
        if (dp > max1) max1 = dp;
    }
    dp = arr[0];
    int min = arr[0];
    int sum = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (dp > 0) {
            dp = arr[i];
        }
        else {
            dp += arr[i];
        }
        if (dp < min) min = dp;
        sum += arr[i];
    }
    int max2 = sum - min;
    if (max1 > max2) return max1;
    else return max2;
}