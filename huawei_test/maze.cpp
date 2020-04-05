#include <vector>
#include <iostream>
#include <climits>

using namespace std;

vector<pair<int, int>> result;
vector<pair<int, int>> tmp;

void dfs(vector<vector<int>>& maze, int x, int y, vector<vector<bool>>& visited)
{
    //边界条件
    if (x < 0 || y < 0 || x >= maze.size() || y >= maze[0].size())
        return;
    if (maze[x][y] == 1 || visited[x][y]) return;

    tmp.push_back({x, y});
    visited[x][y] = true;
    
    //到达出口，此处进行最优判断
    if (x == maze.size() - 1 && y == maze[0].size() - 1)
        if (result.size() == 0 || tmp.size() < result.size())
            result = tmp;
    
    //向左走
    dfs(maze, x - 1, y, visited);
    //向右走
    dfs(maze, x + 1, y, visited);
    //向下走
    dfs(maze, x, y + 1, visited);
    //向上走
    dfs(maze, x, y - 1, visited);
    
    tmp.pop_back();
    visited[x][y] = false;
    
    return;
}

int main()
{
    int N, M;
    while (cin >> N >> M)
    {
        vector<vector<int>> maze(N, vector<int>(M));
        result.clear();
        tmp.clear();
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cin >> maze[i][j];
        
        dfs(maze, 0, 0, visited);
        for (int i = 0; i < result.size(); ++i)
            cout << "(" << result[i].first << "," << result[i].second << ")" << endl;
    }
    
    return 0;
}