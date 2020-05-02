/*
第一题是修水管，大致题意是在一个二维坐标轴上，
给定你房子的坐标，然后修一条垂直于x轴的水管，
问你所有房子到这条水管的垂直最短距离之和
*/

#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>nums, int left, int right)
{
    if (left >= right)
        return;
    int pivot = left, low = left + 1, high = right;
    while (left <= high)
    {
        if (nums[pivot] <= nums[low])
        {
            swap(nums[low], nums[high]);
            --high;
        }
        else
            ++low;
    }
    low--;
    swap(nums[pivot], nums[low]);
    quickSort(nums, left, low - 1);
    quickSort(nums, low + 1, right);
}

int main()
{
    int m;
    while (cin >> m)
    {
        vector<int> xIndex(m, 0);
        int yIndex;
        for (int i = 0; i < m; ++i)
            scanf("%d,%d", &xIndex[i], &yIndex);
        
        //排序
        quickSort(xIndex, 0, xIndex.size() - 1);

        int mid, ans = 0;
        if (xIndex.size() % 2 == 1)
            mid = xIndex[xIndex.size() / 2];
        else
            mid = xIndex[xIndex.size() / 2 - 1] + xIndex[xIndex.size() / 2];
        for (int i = 0; i < xIndex.size(); ++i)
            ans += abs(xIndex[i] - mid);
        cout << ans << endl;
    }
}