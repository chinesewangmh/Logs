#include <iostream>
#include <vector>
using namespace std;




/// <summary>
/// / 最大子数组和
/// </summary>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //dp[i]:以i位置元素为结尾的所有子数组最大和
        int m = nums.size();
        vector<int> dp(m + 1);

        //初始化
        //dp[0]=0;

        //填表
        int ret = INT_MIN;
        for (int i = 1; i <= m; ++i)
        {
            //dp[i] 当子数组只有他自己  nums[i]
            //      当子数组元素大于1，dp[i-1]+nums[i]
            dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
            ret = max(ret, dp[i]);
        }

        return ret;
    }
};