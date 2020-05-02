#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ans;
vector<int> cur;

void get_results(int n, int m, int i, int curSum)
{
    if (curSum == m)
    {
        ans.push_back(cur);
        return;
    }
    //越界
    if (i > m || i > n || curSum > m)
        return;

    cur.push_back(i);
    get_results(n, m, i + 1, curSum + i);
    cur.pop_back();
    get_results(n, m, i + 1, curSum);
}

int main()
{
    int n, m;
    cin >> n >> m;
    get_results(n, m, 1, 0);
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}