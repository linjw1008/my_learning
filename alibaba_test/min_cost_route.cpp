/*
小强有一天想去郊区玩，但是路上会经过一片山路。
山路可以看作是一个n * m (n行m列)的网格，每个网格代表一个区域。
山路崎岖不平，每一个区域都有一个会消耗的体力值。
小强在走山路的时候，只能从一个区域走到相邻的4个(上下左右的网格)区域中的任意一个。
每到一个区域，会消耗对应的体力值。
小强初始位置在第1行上方，需要去到第n行下方(可以在第1行任意区域作为起点，第n行任意区域作为终点)
小强想找种走法，使得经过山路的总体力值消耗最小。
请你帮小强找到这么一条路，并输出最小的总体力值消耗。
*/
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<bool>>& visited)
{
    if (x >= matrix.size() || x < 0 || y >= matrix[0].size() || y < 0) return INT_MAX;
    //最后一行,递归结束
    if (x == matrix.size() - 1) return matrix[x][y];
    if (visited[x][y]) return INT_MAX;

    int ans = INT_MAX;
    int tmp;
    //记录本点被访问过
    visited[x][y] = true;
    tmp = dfs(matrix, x + 1, y, visited);
    if (tmp != INT_MAX) ans = min(tmp + matrix[x][y], ans);
    tmp = dfs(matrix, x - 1, y, visited);
    if (tmp != INT_MAX) ans = min(tmp + matrix[x][y], ans);
    tmp = dfs(matrix, x, y + 1, visited);
    if (tmp != INT_MAX) ans = min(tmp + matrix[x][y], ans);
    tmp = dfs(matrix, x, y - 1, visited);
    if (tmp != INT_MAX) ans = min(tmp + matrix[x][y], ans);

    //用于回溯
    visited[x][y] = false;

    return ans;
}

int main()
{
    int m, n;
    while (cin >> n >> m)
    {
        vector<vector<int>> matrix(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> matrix[i][j];

        for (int i = 0; i < m; ++i)
            ans = min(ans, dfs(matrix, 0, i, visited));
        
        cout << ans << endl;
    }

    return 0;
}