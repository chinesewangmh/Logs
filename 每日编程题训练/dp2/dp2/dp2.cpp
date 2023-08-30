#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

//完全背包与01背包不同之处
//1.优化前：状态转移方程不同，考虑到完全背包一个物品可以使用多次，则
//dp[i][j] = dp[i - 1][j];
//if (j >= v[i])
//dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
//
//2.优化：01背包是从右往左更新，完全背包是从左往右更新


const int N = 1010;
int v[N], w[N];

int dp[N][N];

int main()
{
    int n, V;
    cin >> n >> V;
    for (int i = 1; i <= n; ++i)
        cin >> v[i] >> w[i];

    //第一问
    //dp[i][j]:前i个数组，挑选出不超过j的物品最大价值
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= V; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i])
                dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
        }
    }
    cout << dp[n][V] << endl;

    memset(dp, 0, sizeof(dp));
    for (int j = 1; j <= V; ++j) dp[0][j] = -1;

    //第二问
    //dp[i][j]:前i个数组，挑选出正好为j的物品最大价值
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= V; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i] && dp[i][j - v[i]] != -1)
                dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
        }
    }
    cout << (dp[n][V] == -1 ? 0 : dp[n][V]) << endl;

}

//#include <cstring>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//const int N = 1010;
//int v[N], w[N];
//
//int dp[N];
//
//int main()
//{
//    int n, V;
//    cin >> n >> V;
//    for (int i = 1; i <= n; ++i)
//        cin >> v[i] >> w[i];
//
//    //第一问
//    //dp[i][j]:前i个数组，挑选出不超过j的物品最大价值
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = v[i]; j <= V; ++j)//【完全背包滚动数组优化从左往右】
//        {
//
//            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
//        }
//    }
//    cout << dp[V] << endl;
//
//    memset(dp, 0, sizeof(dp));
//    for (int j = 1; j <= V; ++j) dp[j] = -1;
//
//    //第二问
//    //dp[i][j]:前i个数组，挑选出正好为j的物品最大价值
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = v[i]; j <= V; ++j)
//        {
//
//            if (dp[j - v[i]] != -1)
//                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
//        }
//    }
//    cout << (dp[V] == -1 ? 0 : dp[V]) << endl;
//
//}

//#include <cstring>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//const int N = 1010;
//int v[N], w[N];
//
//int dp[N];
//
//int main()
//{
//    int n, V;
//    cin >> n >> V;
//    for (int i = 1; i <= n; ++i)
//        cin >> v[i] >> w[i];
//
//    //第一问
//    //dp[i][j]:前i个数组，挑选出不超过j的物品最大价值
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = v[i]; j <= V; ++j)//完全背包滚动数组优化从左往右
//        {
//
//            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
//        }
//    }
//    cout << dp[V] << endl;
//
//    memset(dp, 0, sizeof(dp));
//    for (int j = 1; j <= V; ++j) dp[j] = -0x3f3f3f3f;
//
//    //第二问
//    //dp[i][j]:前i个数组，挑选出正好为j的物品最大价值
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = v[i]; j <= V; ++j)
//        {
//
//            // if(dp[j-v[i]]!=-1)   dp[j-v[i]]+w[i]足够小，就不会影响结果
//            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
//        }
//    }
//   cout<<(dp[V]<0?0:dp[V])<<endl;  
//
//}



//零钱问题
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    //dp[i][j]:从前i个硬币中，选取硬币价值总和恰好为j，所需要的最小硬币数
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
    for (int j = 1; j <= amount; ++j) dp[0][j] = 0x3f3f3f3f;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= amount; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= coins[i - 1])
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);//这里是min，为了不影响，选择非常大的值
        }
    }

    return dp[n][amount] >= 0x3f3f3f3f ? -1 : dp[n][amount];

}
//空间优化
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    //dp[i][j]:从前i个硬币中，选取硬币价值总和恰好为j，所需要的最小硬币数
    vector<int> dp(amount + 1);
    for (int j = 1; j <= amount; ++j) dp[j] = 0x3f3f3f3f;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = coins[i - 1]; j <= amount; ++j)
        {
            dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);//这里是min，为了不影响，选择非常大的值
        }
    }

    return dp[amount] >= 0x3f3f3f3f ? -1 : dp[amount];

}

/*零钱兑换2*/
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    //dp[i][j]:从前i个硬币中选取恰好可以凑成j价值的方案数
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1));

    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= amount; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= coins[i - 1])
                dp[i][j] = dp[i][j] + dp[i][j - coins[i - 1]];
        }

    }

    return dp[n][amount];
}

/*完全平方和*/
int numSquares(int sum) {
    vector<int> arr;
    int num = 0;
    for (int i = 1; i <= sum; ++i)
    {
        num = i * i;
        if (num > sum) break;
        arr.push_back(num);
    }
    int n = arr.size();
    int INT = 0x3f3f3f3f;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, INT));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= sum; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            //这里是min，为了不影响，选择非常大的值
            if (j >= arr[i - 1])
                dp[i][j] = min(dp[i - 1][j], dp[i][j - arr[i - 1]] + 1);
        }
    }
    return dp[n][sum];

}