#include <iostream>
#include <vector>
using namespace std;

//
///// <summary>
///// 按摩师问题
///// </summary>
////class Solution {
////public:
////    int massage(vector<int>& nums) {
////
////        int size = nums.size();
////        if (size == 0) return 0;
////        //1.创建dp表
////        //dpf[i]表示第i位置选上的最大值
////        //dpg[i]表示第i位置不选的最大值
////        vector<int> dpf(size);
////        vector<int> dpg(size);
////        //2.初始化dp表
////        dpf[0] = nums[0];
////        dpg[0] = 0;
////
////        for (int i = 1; i < size; ++i)
////        {
////            dpf[i] = dpg[i - 1] + nums[i];
////            dpg[i] = max(dpf[i - 1], dpg[i - 1]);
////        }
////
////        return max(dpf[size - 1], dpg[size - 1]);
////    }
////};
//
//class Solution {
//public:
//    int massage(vector<int>& nums) {
//
//        int size = nums.size();
//        if (size == 0) return 0;
//        //1.创建dp表
//        //dpf[i]表示第i位置选上的最大值
//        //dpg[i]表示第i位置不选的最大值
//        vector<int> dpf(size);
//        vector<int> dpg(size);
//        //2.初始化dp表
//        dpf[0] = nums[0];
//        dpg[0] = 0;
//
//        for (int i = 1; i < size; ++i)
//        {
//            dpf[i] = dpg[i - 1] + nums[i];
//            dpg[i] = max(dpf[i - 1], dpg[i - 1]);
//        }
//
//        return max(dpf[size - 1], dpg[size - 1]);
//    }
//    int rob(vector<int>& nums) {
//        int length = nums.size();
//        if (length == 1) {
//            return nums[0];
//        }
//        else if (length == 2) {
//            return max(nums[0], nums[1]);
//        }
//        //第一种，0位置偷，则数组【2，n-2】是原来方法
//        //第二种，0位置不偷，则数组【1，n-1】是原来方法
//        vector<int> v1(nums.begin() + 2, nums.end() - 1);
//        vector<int> v2(nums.begin() + 1, nums.end());
//        return max(nums[0] + massage(v1), massage(v2));//返回最大值
//    }
//};
//
////int main()
////{
////    vector<int> nums{1,2,3,4,5,6};
////    Solution().rob(nums);
////}
//
//
///// <summary>
///// 删除并获得点数
///// </summary>
//class Solution {
//public:
//    int deleteAndEarn(vector<int>& nums) {
//        //预处理，将nums映射到v里面
//        vector<int> v(10001);
//        //v里面存储的是nums中同一数字之出现的总和
//        //nums[2,2,,3,3,3,4]
//        //v[0,0,4,9,4]
//
//        for (auto x : nums)
//            v[x] += x;
//
//        //转化成打家劫舍问题
//
//        //创建dp表
//        vector<int> dpf(10001);
//        vector<int> dpg(10001);
//
//        //初始化dp表
//        dpf[0] = v[0];
//        dpg[0] = 0;
//        //填表
//        for (int i = 1; i < 10001; ++i)
//        {
//            dpf[i] = dpg[i - 1] + v[i];
//            dpg[i] = max(dpf[i - 1], dpg[i - 1]);
//        }
//        return max(dpg[10000], dpf[10000]);
//    }
//};

//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int m = prices.size();
//
//        //1.创建dp表
//        vector<vector<int>> dp(m, vector<int>(3));
//        //2.初始化dp表
//        dp[0][0] = -prices[0];//买入状态
//        dp[0][1] = dp[0][2] = 0;//可交易与冷冻期状态
//        //3.填表
//        for (int i = 1; i < m; ++i)
//        {
//            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);//买入状态转移方程
//            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);//可交易状态转移方程
//            dp[i][2] = dp[i - 1][0] + prices[i];//冷冻期状态转移方程
//        }
//        return max(dp[m - 1][1], dp[m - 1][2]);
//    }
//};
//
//
//class Solution {
//public:
//    int maxProfit(vector<int>& prices, int fee) {
//        //dpf[i]:第i天买入股票，持有股票
//        //dpg[i]:第i天卖出股票，没有股票，可交易状态
//        int m = prices.size();
//        //创建dp表
//        vector<int> dpf(m);
//        auto dpg = dpf;
//        //初始化dp表
//        dpf[0] = -prices[0];
//        dpg[0] = 0;
//
//        //填表
//        for (int i = 1; i < m; ++i)
//        {
//            dpf[i] = max(dpf[i - 1], dpg[i - 1] - prices[i]);
//            dpg[i] = max(dpf[i - 1] + prices[i] - fee, dpg[i - 1]);
//        }
//
//        return dpg[m - 1];
//    }
//};




///////股票三
#include <algorithm>
class Solution {
public:
    //dpf[i][j]表示在第i天结束之后，完成j次交易，处于买入状态的最大利益
    //dpg[i][j]表示在第i天结束之后，完成j次交易，处于卖出状态的最大利益

    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        int n = 3;
        vector<vector<int>> dpf(m, vector<int>(n));
        vector<vector<int>> dpg(m, vector<int>(n));

        //第1天完成1笔及以上交易不存在，为了不影响max,选择最小值
        //⽤INT_MIN在计算过程中会有溢出的⻛险，这⾥INF折半取0x3f3f3f3f ，⾜够⼩即可
        dpf[0][1] = dpf[0][2] = dpg[0][1] = dpg[0][2] = -0x3f3f3f3f;
        dpf[0][0] = -prices[0];
        dpg[0][0] = 0;

        for (int i = 1; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dpf[i][j] = max(dpf[i - 1][j], dpg[i - 1][j] - prices[i]);

                //当从买入转换到卖出状态的时候，交易次数+1；
                //换句话说：前一天结束手里面有股票，今天卖出，今天结束之后交易次数+1
                //例如：今天结束交易次数是2，则应该找昨天交易次数为1的
                // dpg[i][j]=max(g[i-1][j],f[i-1][j-1]+prices[i]);

                dpg[i][j] = dpg[i - 1][j];//为了避免初始化第0列，修改状态转移方程 单独处理
                if (j >= 1) dpg[i][j] = max(dpg[i][j], dpf[i - 1][j - 1] + prices[i]);
            }
        }

        //选取最后一行中的三种状态最大值
        return *max_element(dpg[m - 1].begin(), dpg[m - 1].end());
    }
};
/// <summary>
/// 股票4
/// </summary>

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int m = prices.size();
        int n = k + 1;
        vector<vector<int>> dpf(m, vector<int>(n, -0x3f3f3f3f));
        vector<vector<int>> dpg(m, vector<int>(n, -0x3f3f3f3f));

        dpf[0][0] = -prices[0];
        dpg[0][0] = 0;

        for (int i = 1; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dpf[i][j] = max(dpf[i - 1][j], dpg[i - 1][j] - prices[i]);
                // dpg[i][j]=max(g[i-1][j],f[i-1][j-1]+prices[i]);
                dpg[i][j] = dpg[i - 1][j];
                if (j >= 1) dpg[i][j] = max(dpg[i][j], dpf[i - 1][j - 1] + prices[i]);
            }
        }

        return *max_element(dpg[m - 1].begin(), dpg[m - 1].end());
    }
};


int main()
{
    vector<int> nums{ 1,2,3,4,5 };
    Solution().maxProfit(nums);
}