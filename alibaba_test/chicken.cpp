#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
    int n, m, k, tmp;
    long sum = 0;

    while (cin >> n >> m >> k)
    {
        priority_queue<int, vector<int>, less<int>> heap;
        for (int i = 0; i < n; ++i)
        {
            cin >> tmp;
            heap.push(tmp);
        }
        
        //第i天
        for (int i = 0; i < m; ++i)
        {
            //第j个养鸡场
            vector<int> v;
            for (int j = 0; j < n; ++j)
            {
                tmp = heap.top();
                heap.pop();
                //增加k只鸡
                v.push_back(tmp + k);
            }
            //重新加入大顶堆
            for (int k = 0; k < n; ++k)
            {
                heap.push(v[k]);
            }
            //对堆顶的数字进行处理（减半）
            tmp = heap.top();
            heap.pop();
            tmp = tmp / 2;
            heap.push(tmp);
        }
        //统计总和并输出结果
        for (int i = 0; i < n; ++i)
        {
            sum += heap.top();
            heap.pop();
        }
        cout << sum << endl;
    }

    return 0;
}