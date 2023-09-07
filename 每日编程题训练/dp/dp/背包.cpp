#include <cstring>
#include <iostream>
using namespace std;

//const int N = 1010;
//
//int n, V, v[N], w[N];
//
//int dp[N][N];
//
//int main() {
//    //读入数据
//    cin >> n >> V;
//    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
//    //第一问
//    //dp[i][j]:从前i个物品中挑选，容量不超过j的最大价值
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= V; j++) {
//            dp[i][j] = dp[i - 1][j]; //不选i位置物品
//            if (j >= v[i]) //选i位置物品，要保证j-v[i]>=0
//                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
//        }
//    }
//    cout << dp[n][V] << endl;
//
//    //第二问
//    //dp[i][j]:从前i个物品中挑选，容量正好等于j的最大价值
//    memset(dp, 0, sizeof dp);
//    //将选择物品后无法满足体积正好为j的初始化为-1
//    for (int j = 1; j <= V; j++) dp[0][j] = -1;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= V; j++) {
//            dp[i][j] = dp[i - 1][j]; //不选i位置物品
//            //选i位置物品，要保证j-v[i]>=0并且保证它上一个位置可被选
//            if (j >= v[i] && dp[i - 1][j - v[i]] != -1)
//                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
//        }
//    }
//    cout << (dp[n][V] == -1 ? 0 : dp[n][V]) << endl;
//
//}
//
///*滚动数组优化*/
//
//#include <cstring>
//#include <iostream>
//using namespace std;
//
//const int N = 1010;
//
//int n, V, v[N], w[N];
//
//int dp[N];
///*
//1.一维数组
//2.从右往左更新
//
//*/
//int main() {
//    //读入数据
//    cin >> n >> V;
//    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
//    //第一问
//    //dp[i][j]:从前i个物品中挑选，容量不超过j的最大价值
//    for (int i = 1; i <= n; ++i) {
//        for (int j = V; j >= v[i]; j--) {
//            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
//        }
//    }
//    cout << dp[V] << endl;
//
//    //第二问
//    //dp[i][j]:从前i个物品中挑选，容量正好等于j的最大价值
//    memset(dp, 0, sizeof dp);
//    //将选择物品后无法满足体积正好为j的初始化为-1
//    for (int j = 1; j <= V; j++) dp[j] = -1;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = V; j >= v[i]; j--) {
//
//            if (dp[j - v[i]] != -1)
//                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
//        }
//    }
//    cout << (dp[V] == -1 ? 0 : dp[V]) << endl;
//
//}
#include <vector>
//bool canPartition(vector<int>& nums) {
//    //将问题转化为在数组中找一些数，合为sum/2;
//    int n = nums.size();
//    int sum = 0;
//    for (auto e : nums)
//    {
//        sum += e;
//    }
//    if (sum % 2 != 0) return false;
//    //dp[i][j]:从前i个数中，能否挑选出和为j的这个数
//    vector<bool>dp(sum / 2 + 1, false);
//
//    dp[0] = true;
//    for (int i = 1; i <= n; ++i)
//    {
//        //j>=nums[i-1]:当背包容量小于num[i-1]后面的都没有意义了
//        for (int j = sum / 2; j >= nums[i - 1]; --j)
//        {
//            dp[j] = dp[j] || dp[j - nums[i - 1]];//选和不选只要有一个满足条件就行
//        }
//    }
//
//    return dp[sum / 2];
//}
//bool canPartition(vector<int>& nums) {
//    //将问题转化为在数组中找一些数，合为sum/2;
//    int n = nums.size();
//    int sum = 0;
//    for (auto e : nums)
//    {
//        sum += e;
//    }
//    if (sum % 2 != 0) return false;
//    //dp[i][j]:从前i个数中，能否挑选出和为j的这个数
//    vector<bool>dp(sum / 2 + 1, false);
//
//    dp[0] = true;
//    for (int i = 1; i <= n; ++i)
//    {
//        //j>=nums[i-1]:当背包容量小于num[i-1]后面的都没有意义了
//        for (int j = sum / 2; j >= nums[i - 1]; --j)
//        {
//            dp[j] = dp[j] || dp[j - nums[i - 1]];//选和不选只要有一个满足条件就行
//        }
//    }
//
//    return dp[sum / 2];
//}



//int findTargetSumWays(vector<int>& nums, int target) {
//    //解题思路：假设nums数组中添加符号之后，所有正数绝对值为a，所有负数绝对值为b
//    //则有：a+b=sum,a-b=target;==>a=(sum+target)/2
//    //题目转化成在数组nums挑选出和为a的有几种选法
//    int sum = 0;
//    for (auto e : nums) sum += e;
//    int a = (sum + target) / 2;
//    //题目中都是整数，sum+target为奇数的时候，凑不出来
//    if (a < 0 || (sum + target) % 2 != 0) return 0;
//    int n = nums.size();
//
//    //dp[i][j]:从前i个数中，和为j有多少种选法
//    //细节：第一列不用初始化，当j=0时，可能发生越界，
//    //但是要想用dp[i-1][j-nums[i-1]]，需要满足j>=nums[i-1]
//    //j=0，那么nums[i-1]只能为0才满足0>=0,因此dp[i-1][j-nums[i-1]]=>dp[i-1][0]
//    vector<vector<int>> dp(n + 1, vector<int>(a + 1));
//    dp[0][0] = 1;
//
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = 0; j <= a; ++j)
//        {
//            dp[i][j] = dp[i - 1][j];
//            if (j >= nums[i - 1])
//                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
//        }
//    }
//
//    return dp[n][a];
//
//}
//int findTargetSumWays(vector<int>& nums, int target) {
//    //解题思路：假设nums数组中添加符号之后，所有正数绝对值为a，所有负数绝对值为b
//    //则有：a+b=sum,a-b=target;==>a=(sum+target)/2
//    //题目转化成在数组nums挑选出和为a的有几种选法
//    int sum = 0;
//    for (auto e : nums) sum += e;
//    int a = (sum + target) / 2;
//    //题目中都是整数，sum+target为奇数的时候，凑不出来
//    if (a < 0 || (sum + target) % 2 != 0) return 0;
//    int n = nums.size();
//
//    //dp[i][j]:从前i个数中，和为j有多少种选法
//    //细节：第一列不用初始化，当j=0时，可能发生越界，
//    //但是要想用dp[i-1][j-nums[i-1]]，需要满足j>=nums[i-1]
//    //j=0，那么nums[i-1]只能为0才满足0>=0,因此dp[i-1][j-nums[i-1]]=>dp[i-1][0]
//    vector<int> dp(a + 1);
//    dp[0] = 1;
//
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = a; j >= nums[i - 1]; --j)
//        {
//            dp[j] = dp[j] + dp[j - nums[i - 1]];
//        }
//    }
//
//    return dp[a];
//}



int lastStoneWeightII(vector<int>& stones) {
    // 任意两块⽯头在⼀起粉碎，重量相同的部分会被丢掉，重量有差异的部分会被留下来。那就
    // 相当于在原始的数据的前⾯，加上「加号」或者「减号」，是最终的结果最⼩即可。也就是
    // 说把原始的⽯头分成两部分，两部分的和越接近越好。
    // ⼜因为当所有元素的和固定时，分成的两部分越接近数组「总和的⼀半」，两者的差越⼩
    int sum = 0;
    for (auto e : stones) sum += e;
    int mid = sum / 2;

    int n = stones.size();
    //dp[i][j]:前i个数中，不超过j的 元素最大和
    vector<vector<int>> dp(n + 1, vector<int>(mid + 1));


    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= mid; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= stones[i - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
        }

    }
    //dp[n][mid]表示一堆石子的最大和,但不超过sum/2
    //另一堆则是sum-dp[n][mid]
    //两者相减
    return sum - 2 * dp[n][mid];
}



//const int MOD = 1e9 + 7;
//int fun(int m) {
//    //3 *pow(2, m - 1)项
//    vector<vector<int>> array(m + 1, vector<int>(3));// array[n][i]表示第n组以i结尾的数组的权值
//    array[2][0] = 3; // 10,20
//    array[2][1] = 2; // 01,21
//    array[2][2] = 3; // 02,12
//
//    for (int n = 3; n <= m; n++) 
//    {
//        int count = (int)pow(2,n - 2); // n-1组中分别以以0，1，2结尾的各有多少项
//        // 第n组中以0结尾的分别是由上一组中以1和2结尾的组成
//        // 将0添加在1后面权值+1， 共有count项，总权制增加count*1
//        // 将0添加在2后面权值+2， 共有count项，总权制增加count*2， 其他的类推
//        array[n][0] = (count * 1 + array[n - 1][1]) + (count * 2 + array[n - 1][2]) % MOD;
//
//        array[n][1] = (count * 1 + array[n - 1][0]) + (count * 1 + array[n - 1][2]) % MOD;
//
//        array[n][2] = (count * 2 + array[n - 1][0]) + (count * 1 + array[n - 1][1]) % MOD;
//  
//    }
//
//    return (array[m][0] + array[m][1] + array[m][2]) % MOD;
//
//}


//
const int MOD = 1e9 + 7;
int fun(int m) {
    vector<int> curArray(3), prevArray(3); // curArray[i]表示第n组以i结尾的数组的权值，prevArray[i]表示第n-1组以i结尾的数组的权值
    curArray[0] = 3; // 10,20
    curArray[1] = 2; // 01,21
    curArray[2] = 3; // 02,12

    for (int n = 3; n <= m; n++)
    {
        int count = (int)pow(2, n - 2);
        prevArray[0] = curArray[0];
        prevArray[1] = curArray[1];
        prevArray[2] = curArray[2];

        int temp0 = (count * 1 + prevArray[1]) % MOD+ (count * 2 + prevArray[2]) % MOD;
        int temp1 = (count * 1 + prevArray[0]) % MOD + (count * 1 + prevArray[2]) % MOD;
        int temp2 = (count * 2 + prevArray[0]) % MOD + (count * 1 + prevArray[1]) % MOD;


        curArray[0] = temp0;
        curArray[1] = temp1;
        curArray[2] = temp2;
    }

    return ((curArray[0] + curArray[1])%MOD + curArray[2]) % MOD;
}



const int m = 1e9 + 7;
int fastMi(int n) {
    int a = n - 1;
    n = n + 1;
    int x = 2;
    int  res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        n /= 2;
    }
    return (a * res)%m;
}




int main()
{
    vector<int> v{ 1,5,11,5 };
   // canPartition(v);
    fun(3);
}