/*
阿里笔试3月25号

第一题，给定一个数组n，比如
5 10 5 4 4
1  7  8 4 0
3  4  9 0 3
从每一列选择一个数，求出后一列减去前一列的绝对值的和的最小值
比如这里就是5 7 5 4 4，所以输出是5
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<vector<int>> nums(3, vector<int>(n, 0));
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < n; ++j)
                cin >> nums[i][j];
        
        //使用动态规划
        vector<vector<int>> dp(3, vector<int>(n, 0));
        for (int i = 1; i < n; ++i)
        {
            dp[0][i] = min(min(dp[0][i - 1] + abs(nums[0][i] - nums[0][i - 1]), 
                               dp[1][i - 1] + abs(nums[0][i] - nums[1][i - 1])), 
                               dp[2][i - 1] + abs(nums[0][i] - nums[2][i - 1]));
            dp[1][i] = min(min(dp[0][i - 1] + abs(nums[1][i] - nums[0][i - 1]), 
                               dp[1][i - 1] + abs(nums[1][i] - nums[1][i - 1])), 
                               dp[2][i - 1] + abs(nums[1][i] - nums[2][i - 1]));
            dp[2][i] = min(min(dp[0][i - 1] + abs(nums[2][i] - nums[0][i - 1]), 
                               dp[1][i - 1] + abs(nums[2][i] - nums[1][i - 1])), 
                               dp[2][i - 1] + abs(nums[2][i] - nums[2][i - 1]));
        }

        cout << min(min(dp[0][n - 1], dp[1][n - 1]), dp[2][n - 1]) << endl;
    }

    return 0;
}