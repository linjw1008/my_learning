/*
3.27 第一题
问题1：给两个等长字符串，长度范围1e5，
你可以选择第一个字符串的一个字符移动到字符串尾部，
目的是让两个字符串相等，求最小的移动次数。
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s1, s2;

    while (cin >> s1 >> s2)
    {
        vector<int> count1(26, 0), count2(26, 0);
        //统计s1和s2每个字母出现次数
        for (int i = 0; i < s1.size(); ++i)
        {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        //判断s1和s2是否拥有相同个数的字母
        int i = 0;
        while (i < 26 && count1[i] == count2[i])
            i++;
        if (i != 26)
        {
            cout << -1 << endl;
            continue;
        }

        //找出s1的子序列等于s2前缀的最长子序列长度
        int len = 0;
        for (int i = 0; i < s1.size(); ++i)
            if (s1[i] == s2[len])
                len++;
        
        cout << s1.size() - len << endl;
    }

    return 0;
}