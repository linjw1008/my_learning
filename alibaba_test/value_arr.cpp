/**
 * 第1题：对一个数组，求每个数左边比他大的数的最小值，
 * 右边比他小的数的最大值，若这两个数成倍数关系，记录。
 * 求被记录的总数量。
 * 
*/
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    while (cin >> N)
    {
        vector<int> input(N, 0);
        //储存左边的数值，相当于排序，set默认从小到大
        set<int> leftSet;
        //储存右边的数值，相当于排序，set从大到小
        set<int, greater<int>> rightSet;
        vector<int> left(N, 0), right(N, 0);
        int ans = 0;

        for (int i = 0; i < N; ++i)
            cin >> input[i];
        
        //从左到右找出每个数左边比他大的数的最小值
        for (int i = 0; i < input.size(); i++)
        {
            int targetNum = input[i];
            //从set中找出目标值
            for (auto &s : leftSet)
            {
                if (s > targetNum)
                {
                    targetNum = s;
                    break;
                }
            }
            leftSet.insert(input[i]);
            left[i] = targetNum;
        }
        //从右到左找出每个数右边比他小的数的最大值
        for (int i = input.size() - 1; i >= 0; --i)
        {
            int targetNum = input[i];
            //从set中找出目标
            for (auto &s : rightSet)
            {
                if (s < targetNum)
                {
                    targetNum = s;
                    break;
                }
            }
            rightSet.insert(input[i]);
            right[i] = targetNum;
        }

        //统计结果
        for (int i = 0; i < N; ++i)
        {
            if (right[i] != input[i] && left[i] != input[i] && left[i] != 0&& left[i] % right[i] == 0)
            {
                ans++;
            }
        }

        //输出结果
        cout << ans << endl;
    }


}