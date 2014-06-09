using namespace std;

//写程序判断一个9*9的数字盘面是否为合法的数独（查看定义）。
//9*9的盘面按照Row-major order表示为一个81维的一维数组。
//提示：请直接在一维数组上操作，不要先将一维数组拷贝到9*9的二维数组。

int isValidSudoku(int arr[]) {
    // is valid row
    for (int i = 0; i < 9; i++) {
        vector<int> vec(10, -1);
        for (int j = 0; j < 9; j++) {
            int idx = i * 9 + j;
            if (arr[idx] <= 0 || arr[idx] > 9)
                return 0;
            if (vec[arr[idx]] != -1) {
                return 0; // false
            } else {
                vec[arr[idx]] = 1;
            }
        }
    }
    // is valid column
    for (int i = 0; i < 9; i++) {
        vector<int> vec(10, -1);
        for (int j = 0; j < 9; j++) {
            int idx = i + j * 9;
            if (vec[arr[idx]] != -1) {
                return 0; // false
            } else {
                vec[arr[idx]] = 1;
            }
        }
    }
    // is valid sub sudoku
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            vector<int> vec(10, -1);
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    int idx = (x + 3 * i) * 9 + (y + 3 * j);
                    if (vec[arr[idx]] != -1) {
                        return 0; // false
                    } else {
                        vec[arr[idx]] = 1;
                    }
                }
            }
        }
    }
    return 1;
}