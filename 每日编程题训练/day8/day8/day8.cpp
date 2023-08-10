#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    if (nums[left] < target) return left + 1;
    return left;
}


int lengthOfLIS(vector<int>& nums) {
    //dp[i]:以i位置为结尾的所有子序列中，最长的递增子序列长度
    //dp[i]:
    //1)就自己，dp[i]=1;
    //2)和前面的组合：dp[i]=dp[j]+1,前提是nums[j]<nums[i]
    int n = nums.size();
    //创建dp并初始化
    vector<int> dp(n, 1);

    int ret = 1;
    //填表
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[j] < nums[i])
                dp[i] = max(dp[j] + 1, dp[i]);
        }
        ret = max(ret, dp[i]);

    }

    return ret;
}
