/*
4.13
第一道题：蚂蚁森林n个小动物，1~n,
小动物编号越小能力越强，现在筛选国王，
每个小动物都会崇拜别的小动物或者自己，
但只会崇拜比自己能力强的小动物。

问每个人最多可以获得多少票。

第一行输入n，第二行输入n个数值，
数值为0代表只崇拜自己，数值为x即崇拜x.

现在要投票，每个小动物可能会投给自己，也可能跟自己崇拜的人投相同的票
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;

    while (cin >> n)
    {
        vector<int> vote(n + 1);
        for (int i = 1; i <= n; ++i) cin >> vote[i];

        vector<int> ans(n + 1, 0);
        ans[n] = 1;
        ans[vote[n]]++;
        for (int i = n - 1; i >= 1; --i)
        {
            //自己投给自己
            ans[i]++;
            if (vote[i] != 0)
                //把我的所有票投给我支持的人
                ans[vote[i]] += ans[i];
        }

        for (int i = 1; i <= n; ++i)
            cout << ans[i] << endl;
    }

    return 0;
}