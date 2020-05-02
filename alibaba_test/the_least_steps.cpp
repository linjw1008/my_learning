/*
3.23 第二题

输入n,m两个整数代表n行m列
下面输入n行字符串，每个字符串都包含m个字符（只含有'.','#','E','S'）
其中S代表起点，E代表终点，#代表无法通过
从起点出发，可向左，向右，向上，向下移动一步
也可按如下中心对称移动，也只算移动一步
X（i,j）→ X‘（n+1-i,m+1-j）
求从起点到终点最少需要移动几步

示例输入
4 4
#S..
E#..
#...
....

输出
4
说明
先中心对称到达（4，3），然后向上一步，向右一步，中心对称到达终点





飞行次数似乎有限制，设置为M

*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int curAns = 0;
int ans = INT_MAX;

//考虑
void dfs(vector<vector<char>>& map, int x, int y, vector<vector<bool>>& isVisited, int M)
{
    //剪枝
    if (ans <= curAns)
        return;
    //终点
    if (map[x][y] == 'E')
    {
        ans = min(ans, curAns);
        return;
    }

    curAns++;
    isVisited[x][y] = true;

    if (x + 1 < map.size() && (map[x + 1][y] == '.' || map[x + 1][y] == 'E') && !isVisited[x + 1][y])
        dfs(map, x + 1, y, isVisited, M);
    if (x - 1 >= 0 && (map[x - 1][y] == '.' || map[x - 1][y] == 'E') && !isVisited[x - 1][y])
        dfs(map, x - 1, y, isVisited, M);
    if (y + 1 < map[0].size() && (map[x][y + 1] == '.' || map[x][y + 1] == 'E') && !isVisited[x][y + 1])
        dfs(map, x, y + 1, isVisited, M);
    if (y - 1 >= 0 && (map[x][y - 1] == '.' || map[x][y - 1] == 'E') && !isVisited[x][y - 1])
        dfs(map, x, y - 1, isVisited, M);
    if (map.size() - 1 - x >= 0 &&
        map.size() - 1 - x < map.size() && 
        map[0].size() - 1 - y >= 0 && 
        map[0].size() - 1 - y < map[0].size() && 
        !isVisited[map.size() - 1 - x][map[0].size() - 1 - y] &&
        M >= 1)
        dfs(map, map.size() - 1 - x, map[0].size() - 1 - y, isVisited, M - 1);

    curAns--;
    isVisited[x][y] = false;
}

int main()
{
    int n, m, M;
    while (cin >> n >> m >> M)
    {
        vector<vector<char>> map(n, vector<char>(m));
        vector<vector<bool>> isVisited(n, vector<bool>(m, false));
        int x, y;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                cin >> map[i][j];
                if (map[i][j] == 'S')
                    x = i, y = j;
            }

        //一定要重新初始化ans 和 curAns !!!
        ans = INT_MAX;
        curAns = 0;
        dfs(map, x, y, isVisited, M);    
        if (ans == INT_MAX)
            cout << "UNKNOWN" << endl;
        else
            cout << ans << endl;
    }

    return 0;
}
