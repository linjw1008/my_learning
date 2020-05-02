/*
https://www.nowcoder.com/discuss/402914
# 第二题
> 给定一个n阶矩阵，从左上角开始，每次移动不大于m个单位，可以上下左右移动。只有移动到的位置比当前的值大的时候才能移动，直到不能移动位置
问：找出值最大的路径
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<pair<int, int>> path;
int ans = INT_MIN;
int curAns = 0;
vector<pair<int, int>> curPath;

void dfs(vector<vector<int>>& matrix, int x, int y, int m, vector<pair<int, int>>& curPath)
{
    //终止
    if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size() || (curPath.size() != 0 && matrix[curPath[curPath.size() - 1].first][curPath[curPath.size() - 1].second] >= matrix[x][y]))
    {
        if (ans < curAns)
        {
            path = curPath;
            ans = curAns;
        }
        return;
    }

    curAns += matrix[x][y];
    curPath.push_back({x, y});
    for (int i = 1; i <= m; ++i)
    {
        dfs(matrix, x + i, y, m, curPath);
        dfs(matrix, x - i, y, m, curPath);
        dfs(matrix, x, y + i, m, curPath);
        dfs(matrix, x, y - i, m, curPath);
    }
    curAns -= matrix[x][y];
    curPath.pop_back();
}

int main()
{
    int n, m;
    
    while (cin >> n >> m)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> matrix[i][j];

        dfs(matrix, 0, 0, m, curPath);

        for (int i = 0; i < path.size(); ++i)
            cout << path[i].first << " " << path[i].second << endl;
        cout << ans << endl;
    }

    return 0;
}