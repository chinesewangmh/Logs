#include <iostream>
#include <vector>
using namespace std;




/// <summary>
/// / 最大子数组和
/// </summary>
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        //dp[i]:以i位置元素为结尾的所有子数组最大和
//        int m = nums.size();
//        vector<int> dp(m + 1);
//
//        //初始化
//        //dp[0]=0;
//
//        //填表
//        int ret = INT_MIN;
//        for (int i = 1; i <= m; ++i)
//        {
//            //dp[i] 当子数组只有他自己  nums[i]
//            //      当子数组元素大于1，dp[i-1]+nums[i]
//            dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
//            ret = max(ret, dp[i]);
//        }
//
//        return ret;
//    }
//};

//class Solution {
//public:
//    //解题思路：最大子数组分为中间和两端；max({数组总和-最小子数组},最大子数组)
//    int maxSubArray(vector<int>& nums) {
//        //dpf[i]:以i位置元素为结尾的所有子数组最大和
//        //dpg[i]:以i位置元素为结尾的所有子数组最小和
//        int m = nums.size();
//        vector<int> dpf(m + 1);
//        auto dpg = dpf;
//        //初始化
//        //dpf[0]=dpg[0]=0;
//
//        //填表
//        int ret = INT_MIN;
//        int cur = INT_MAX;
//        int sum = 0;
//        for (int i = 1; i <= m; ++i)
//        {
//            sum += nums[i - 1];
//            //dp[i] 当子数组只有他自己  nums[i]
//            //      当子数组元素大于1，dp[i-1]+nums[i]
//            dpf[i] = max(nums[i - 1], dpf[i - 1] + nums[i - 1]);
//            dpg[i] = min(nums[i - 1], dpg[i - 1] + nums[i - 1]);
//            ret = max(ret, dpf[i]);
//            cur = min(cur, dpg[i]);
//        }
//        //特殊处理，数组里面全是负数，返回dpf表最大值
//        if (sum == cur) return ret;
//
//        //返回【dpf最大值】与【数组总和减去dpg最小值】的最大值
//        return max(ret, sum - cur);
//    }
//    int maxSubarraySumCircular(vector<int>& nums) {
//        return maxSubArray(nums);
//    }
//};

#include <algorithm>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m = nums.size();

        vector<int> dpf(m + 1);
        auto dpg = dpf;
        dpf[0] = dpg[0] = 1;

        int ret = INT_MIN;
        for (int i = 1; i <= m; ++i)
        {
            dpf[i] = max(nums[i - 1], max(dpf[i - 1] * nums[i - 1], dpg[i - 1] * nums[i - 1]));
            dpg[i] = min(nums[i - 1], min(dpf[i - 1] * nums[i - 1], dpg[i - 1] * nums[i - 1]));
            ///ret = max(ret, dpf[i]);
        }
        return *max_element(dpf.begin()+1,dpf.end());
        //return ret;
    }
};
//class Solution {
//public:
//    //dpf[i]:以i位置为结尾的最大子数组乘积
//    //dpg[i]:以i位置为结尾的最小子数组乘积
//    int maxProduct(vector<int>& nums) {
//        int m = nums.size();
//
//        vector<int> dpf(m + 1);
//        auto dpg = dpf;
//        dpf[0] = dpg[0] = 1;
//
//        int ret = INT_MIN;
//        for (int i = 1; i <= m; ++i)
//        {
//            //dpf[i] 分两个状态{长度为1，长度大于1}
//            //长度大于1的又可以分为，nums[i]大于0还是小于0
//            //小于0乘以最小值；大于0乘以最大值
//            dpf[i] = max(nums[i - 1], max(dpf[i - 1] * nums[i - 1], dpg[i - 1] * nums[i - 1]));
//            //同上
//            dpg[i] = min(nums[i - 1], min(dpf[i - 1] * nums[i - 1], dpg[i - 1] * nums[i - 1]));
//            ret = max(ret, dpf[i]);
//        }
//
//        return ret;
//    }
//};

class Solution {
public:
    //dpf[i]:以i为结尾的所有子数组乘积为正数的子数组最大长度
    //dpg[i]:以i为结尾的所有子数组成绩为负数的子数组最大长度
    int getMaxLen(vector<int>& nums) {

        int m = nums.size();

        vector<int> dpf(m + 1), dpg(m + 1);

        dpf[0] = 0;
        dpg[0] = 0;

        int ret = INT_MIN;
        for (int i = 1; i <= m; ++i)
        {
            //不可以，要考虑范围
            // dpf[i]:max{nums[i-1]>0?1:0；dpf[i-1]+1,dpg[i-1]==0?0:dpg[i-1]+1));
            // dpg[i]=max(nums[i-1]<0?1:0,max(dpf[i-1]+1,dpg[i-1]==0?0:dpg[i-1]+1));

            if (nums[i - 1] > 0)
            {
                dpf[i] = dpf[i - 1] + 1;//max(nums[i-1]>0?1:0；dpf[i-1]+1)
                dpg[i] = dpg[i - 1] == 0 ? 0 : dpg[i - 1] + 1;//max(nums[i-1]<0?1:0,dpg[i-1]==0?0:dpg[i-1]+1)
            }
            else if (nums[i - 1] < 0)
            {
                dpf[i] = dpg[i - 1] == 0 ? 0 : dpg[i - 1] + 1;
                dpg[i] = dpf[i - 1] + 1;
            }
            ret = max(ret, dpf[i]);
        }

        return ret;

    }
};
class Solution {
public:
    //dp[i]:以i位置元素为结尾的所有等差数组个数
    int numberOfArithmeticSlices(vector<int>& nums) {
        int m = nums.size();

        vector<int> dp(m);
        //dp[0]=dp[1]=0

        int ret = 0;
        for (int i = 2; i < m; ++i)
        {
            //dp[i-1]+1  123 4 ==》234能构成一个，1234也能构成一个，所以+1 
            //dp[i-1]+1:前i位置前一个元素为结尾的等差数组补上i位置元素构成一个，i位置元素与他前两个又构成一个
            dp[i] = nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2] ? dp[i - 1] + 1 : 0;
            ret += dp[i];//求得是所有等差数组个数
        }
        return ret;
    }
};

int main()
{
    vector<int> v{ -2,0,-1 };
    //Solution().maxProduct(v);
}