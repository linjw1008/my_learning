/*
第二题：
一个矩阵格子，每个值代表从这走过所消耗的体力值，从最上一行任意格子走到最下一行任意格子，每次可以走上下左右四个方向，求消耗的最小体力值。
输入：第一行两个数为n,m，代表矩阵格子的长宽，剩下n行，每行m个数，代表矩阵格子每格会消耗的体力值a
输出：消耗的最小体力值
例如：
输入：
3 4
9 9 1 1
9 1 1 9
1 1 9 9
输出
4

*/

#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int curRes = 0;
int res = INT_MAX;

void dfs(vector<vector<int>>& map, int x, int y, vector<vector<bool>>& isVisited)
{
    //注意，出口要在这里判断，而不是最后一行！
    if (x == map.size())
    {
        res = min(curRes, res);
        return;
    }

    if (x < 0 || y < 0 || x >= map.size() || y >= map[0].size() || isVisited[x][y])
        return;
    //没有必要继续搜索了
    if (curRes >= res) return;

    curRes += map[x][y];
    isVisited[x][y] = true;
    
    dfs(map, x + 1, y, isVisited);
    dfs(map, x - 1, y, isVisited);
    dfs(map, x, y + 1, isVisited);
    dfs(map, x, y - 1, isVisited);

    curRes -= map[x][y];
    isVisited[x][y] = false;
}

int main()
{
    int N, M;
    
    while (cin >> N >> M)
    {
        vector<vector<int>> input(N, vector<int>(M, 0));
        vector<vector<bool>> isVisited(N, vector<bool>(M, false));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cin >> input[i][j];

        for (int i = 0; i < M; ++i)
            dfs(input, 0, i, isVisited);
        
        cout << res << endl;
    }
}