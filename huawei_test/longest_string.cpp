#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.size();
    int len2 = s2.size();
    int ans = 0;
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 1; i <= len1; ++i)
    {
        for (int j = 1; j <= len2; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}