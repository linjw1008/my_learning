#include "common.h"

/*
字符串匹配，BM算法
*/

//记录每个字符在模式串中的下标
void generateBC(string& pattern, vector<int>& bc)
{
    bc.resize(256);
    for (int i = 0; i < 256; ++i)
        bc[i] = -1;
    
    for (int i = 0; i < pattern.size(); ++i)
        bc[pattern[i]] = i;
}

//计算前缀数组与后缀数组
void generateGS(string& pattern, vector<int>& suffix, vector<bool>& prefix)
{
    suffix.resize(pattern.size());
    prefix.resize(pattern.size());
    for (int i = 0; i < pattern.size(); ++i)
    {
        suffix[i] = -1;
        prefix[i] = false;
    }

    for (int i = 0; i < pattern.size() - 1; ++i) //pattern[0, i]
    {
        int j = i;
        int k = 0;
        //与pattern[0, pattern.size() - 1]求公共后缀子串
        while (j >= 0 && pattern[j] == pattern[pattern.size() - 1 - k])
        {
            --j;
            ++k;
            suffix[k] = j + 1;
        }
        if (j == -1) prefix[k] = true;
    }
}

//j为怀字符对应的模式串中的字符下标，m为模式串长度
int moveByGS(int j, int m, vector<int>& suffix, vector<bool>& prefix)
{
    int k = m - 1 - j;
    if (suffix[k] != -1) return j - suffix[k] + 1;
    for (int r = j + 2; r <= m - 1; ++r)
    {
        if (prefix[m - r] == true)
            return r;
    }

    return m;
}

//bm算法主函数
int bm(string& s, string& p)
{
    int sSize = s.size(), pSize = p.size();
    vector<int> bc;
    vector<int> suffix;
    vector<bool> prefix;
    generateBC(p, bc);
    generateGS(p, suffix, prefix);

    int i = 0;  //主串与模式串对齐的第一个字符
    while (i <= sSize - pSize)
    {
        int j;  //模式串与主串比较时的下标
        for (j = pSize - 1; j >= 0; --j)   //从后往前匹配
            if (s[i + j] != p[j]) break;
        if (j < 0) //匹配成功
            return i;
        //匹配不成功，向后滑动
        int x = j - bc[s[i + j]];
        int y = 0;
        if (j < pSize - 1)
            y = moveByGS(j, pSize, suffix, prefix);

        i = i + max(x, y);
    }

    return -1;
}