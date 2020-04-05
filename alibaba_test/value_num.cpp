#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<long> nums(n);
        //存储左侧截止到某个下标为止最大的数
        vector<long> left(n);
        //储存右侧截止到某个下标为止最小的数
        vector<long> right(n);
        int ans = 0;
        for (int i = 0; i < n; ++i)
            cin >> nums[i];
        left[0] = nums[0];
        for (int i = 1; i < n; ++i)
            left[i] = max(left[i - 1], nums[i]);
        right[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; --i)
            right[i] = min(right[i + 1], nums[i]);
        for (int i = 1; i < nums.size() - 1; ++i)
            if (nums[i] < left[i - 1] && nums[i] > right[i + 1])
                ans++;
        cout << ans << endl;
    }

    return 0;
}