#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n;

    while (cin >> n)
    {
        vector<string> melody(n);
        string tmp;
        for (int i = 0; i < n; ++i)
            cin >> melody[i];

        sort(melody.begin(), melody.end());

        //动态规划求解
        vector<int> dp_selected(n);
        vector<int> dp_not_selected(n);
        vector<char> dp_selected_bound(n);
        vector<char> dp_not_selected_bound(n);
        dp_selected[0] = melody[0].size();
        dp_not_selected[0] = 0;
        dp_selected_bound[0] = melody[0][melody[0].size() - 1];
        dp_not_selected_bound[0] = 'a' - 1;

        for (int i = 1; i < n; ++i)
        {
            int select_last = 0;
            int not_select_last = 0;

            //处理选择本旋律的情况
            //上一个旋律可以选
            if (melody[i][0] >= dp_selected_bound[i - 1])
            {
                select_last = dp_selected[i - 1] + melody[i].size();
            }
            else if (melody[i][0] >= dp_not_selected_bound[i - 1])//上一个旋律不可以选，且无需从本旋律重新开始
            {
                not_select_last = dp_not_selected[i - 1] + melody[i].size();
            }
            else //上一个旋律不可以选，且需从本旋律重新开始
            {
                not_select_last = melody[i].size();
            }
            dp_selected[i] = max(not_select_last, select_last);
            dp_selected_bound[i] = melody[i][melody[i].size() - 1];

            //处理不选择本旋律的情况
            //选择上一个旋律
            if (dp_selected[i - 1] > dp_not_selected[i - 1])
            {
                dp_not_selected[i] = dp_selected[i - 1];
                dp_not_selected_bound[i] = dp_selected_bound[i - 1];
            }
            else //不选择上一个旋律
            {
                dp_not_selected[i] = dp_not_selected[i - 1];
                dp_not_selected_bound[i] = dp_not_selected_bound[i - 1];
            }
        }

        cout << max(dp_selected[n - 1], dp_not_selected[n - 1]);
    }

    return 0;
}