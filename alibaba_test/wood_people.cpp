/*
https://www.nowcoder.com/discuss/402914

# 第一题
> 你有一次特训时间为n秒，木头人个数为m，血量为a，你的攻击范围为b，每次最多攻击b个木头人，每次攻击持续1s
问：经过n秒的特训木头人血量为0的最多个数是多少
样例:
输入：
1
5 5 2 2

输出：
5
解释
五次攻击
初始为 2 2 2 2 2
第一次 1 1 2 2 2
1 0 1 2 2
0 0 0 2 2
0 0 0 1 1
0 0 0 0 0
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, a, b;
    while (cin >> n >> m >> a >> b)
    {
        //一个木头人都杀不死
        if (n < a)
            cout << 0 << endl;
        if (n == a)
            cout << b << endl;
        //攻击力总量大于木头人生命总量
        else if (m * a <= n * b)
            cout << m << endl;
        else
        {
            //攻击力总量小于木头人生命总量
            //把生命总量缺额平摊给尽可能少的木头人
            cout << m - (m * a - n * b) % a - 1 << endl;
        }
    }

    return 0;
}