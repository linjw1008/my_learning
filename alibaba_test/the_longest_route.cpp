/*
4.13

第二道题

n个城市n个人，每个城市一个人，选择一个城市x，所有人去那聚会，聚合结束所有人返回各自城市。
有m条单向路径，保证每个人可以到达城市x，一个人所消耗时间为往返距离和，且每个人都会选择最短路径，问最长的距离是多少。

第一行 输入 n,m,l 对应城市、路径、聚会城市
接下来m行，x,y,z从城市x到城市y的距离为z
输出
输出最长距离
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int curLen = 0;
int len = INT_MAX;

//用dfs
void dfs(vector<vector<pair<int, int>>>& distance, int x, int target, unordered_map<int, int>& mem, vector<vector<bool>>& isVisited)
{
    if (mem.find(x) != mem.end())
    {
        curLen += mem[x];
        len = min(curLen, len);
        curLen -= mem[x];
        return;
    }

    if (x == target)
    {
        len = min(curLen, len);
        return;
    }

    //找出从x开始可以走哪些路径
    for (auto& p : distance[x])
    {
        if (!isVisited[x][p.first])
        {
            curLen += p.second;
            isVisited[x][p.first] = true;
            dfs(distance, p.first, target, mem, isVisited);
            curLen -= p.second;
            isVisited[x][p.first] = false;
        }
    }
}

int main()
{
    int n, m, l;

    while (cin >> n >> m >> l)
    {
        vector<vector<pair<int, int>>> distance(n);
        unordered_map<int, int> mem;
        vector<vector<bool>> isVisited(n, vector<bool>(n, false));
        int ans = INT_MIN;

        int x, y, z;
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y >> z;
            distance[x].push_back({y, z});
        }

        for (int i = 0; i < n; ++i)
        {
            len = INT_MAX;
            curLen = 0;
            dfs(distance, i, l, mem, isVisited);
            mem[i] = len;
            cout << i << " " << len << endl;
            ans = max(ans, len);
        }

        cout << ans << endl;
    }

    return 0;
}