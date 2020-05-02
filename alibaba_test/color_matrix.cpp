/*
第二题是涂格子，大致题意是先给你x y n，x和y分别是长宽，n是涂料的种类，然后给你n种涂料各自的数量，
要求: 每次涂的格子 其相邻格子不能涂相同的颜色，问你能不能把全部格子涂满
*/

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& matrix, vector<int>& color, int x, int y)
{
    //移到下一行
    if (y >= matrix[0].size())
    {
        x++;
        y = 0;
    }
    //超出范围
    if (x >= matrix.size())
        return;

    for (int i = 0; i < color.size(); ++i)
    {
        if (color[i] != 0)
        {
            //重复的情况
            if (x > 0 && i == matrix[x - 1][y])
                continue;
            if (y > 0 && i == matrix[x][y - 1])
                continue;
            //没有重复
            color[i]--;
            matrix[x][y] = i;
            //到达终点，全部填满
            if (x == matrix.size() - 1 && y == matrix[0].size() - 1)
                return;
            dfs(matrix, color, x, y + 1);
            color[i]++;
            matrix[x][y] = -1;
        }
    }
}

int main()
{
    int x, y, n;
    while (cin >> x >> y >> n)
    {
        vector<int> color(n, 0);
        vector<vector<int>> matrix(x, vector<int>(y, -1));

        for (int i = 0; i < n; ++i)
            cin >> color[i];
        
        dfs(matrix, color, 0, 0);

        if (matrix[x - 1][y - 1] == -1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}