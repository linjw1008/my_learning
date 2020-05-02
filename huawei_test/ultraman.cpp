/*
https://blog.nowcoder.net/n/34129941eb914e3e9f0b438e134290e4
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int master_num;
int xEnd, yEnd;
int curAns = 0;
int ans = INT_MAX;

int count_master(vector<vector<int>>& map)
{
    int ans = 0;
    for (int i = 0; i < map.size(); ++i)
    {
        for (int j = 0; j < map[0].size(); ++j)
        {
            if (map[i][j] != 0 && map[i][j] != 1)
                ans++;
        }
    }

    return ans;
}

pair<int, int> get_max_index(vector<vector<int>>& map)
{
    pair<int, int> ans = {0, 0};
    for (int i = 0; i < map.size(); ++i)
    {
        for (int j = 0; j < map[0].size(); ++j)
            if (map[i][j] > map[ans.first][ans.second])
                ans = {i, j};
    }

    return ans;
}

void dfs(vector<vector<int>>& map, int x, int y, int &master_count, int last_master)
{
    //处理越界情况
    if (x < 0 || y < 0 || 
        x >= map.size() || y >= map[0].size() || 
        map[x][y] == 0)
        return;
    //消灭顺序不对
    if (map[x][y] >= 2 && map[x][y] < last_master)
        return;
    //到达最后一个怪兽
    if (x == xEnd && y == yEnd)
    {
        //所有怪兽都消灭了
        if (master_count + 1 == master_num)
            ans = min(ans, curAns + 1);
        cout << master_num << " " << master_count <<endl;
        return;
    }

    curAns++;
    int tmp = map[x][y];
    int lastMaster = last_master;
    //消灭一个怪兽
    if (tmp != 1)
    {
        map[x][y] = 1;   
        master_count++;
        lastMaster = tmp;
    }
    
    //dfs
    dfs(map, x + 1, y, master_count, lastMaster);
    dfs(map, x - 1, y, master_count, lastMaster);
    dfs(map, x, y + 1, master_count, lastMaster);
    dfs(map, x, y - 1, master_count, lastMaster);

    //回溯
    curAns--;
    map[x][y] = tmp;
    if (tmp != 1)
        master_count--;
}

int main()
{
    int M;
    cin >> M;
    vector<vector<int>> map(M, vector<int>(M, 0));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < M; ++j)
            cin >> map[i][j];

    master_num = count_master(map);
    pair<int, int> pos = get_max_index(map);
    xEnd = pos.first; yEnd = pos.second;
    int master_count = 0;
    dfs(map, 0, 0, master_count, INT_MIN);

    if (ans == INT_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;
    
}