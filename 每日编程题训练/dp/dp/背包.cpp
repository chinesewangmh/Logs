#include <cstring>
#include <iostream>
using namespace std;

const int N = 1010;

int n, V, v[N], w[N];

int dp[N][N];

int main() {
    //读入数据
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
    //第一问
    //dp[i][j]:从前i个物品中挑选，容量不超过j的最大价值
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= V; j++) {
            dp[i][j] = dp[i - 1][j]; //不选i位置物品
            if (j >= v[i]) //选i位置物品，要保证j-v[i]>=0
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << dp[n][V] << endl;

    //第二问
    //dp[i][j]:从前i个物品中挑选，容量正好等于j的最大价值
    memset(dp, 0, sizeof dp);
    //将选择物品后无法满足体积正好为j的初始化为-1
    for (int j = 1; j <= V; j++) dp[0][j] = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= V; j++) {
            dp[i][j] = dp[i - 1][j]; //不选i位置物品
            //选i位置物品，要保证j-v[i]>=0并且保证它上一个位置可被选
            if (j >= v[i] && dp[i - 1][j - v[i]] != -1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << (dp[n][V] == -1 ? 0 : dp[n][V]) << endl;

}

/*滚动数组优化*/

#include <cstring>
#include <iostream>
using namespace std;

const int N = 1010;

int n, V, v[N], w[N];

int dp[N];
/*
1.一维数组
2.从右往左更新

*/
int main() {
    //读入数据
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
    //第一问
    //dp[i][j]:从前i个物品中挑选，容量不超过j的最大价值
    for (int i = 1; i <= n; ++i) {
        for (int j = V; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[V] << endl;

    //第二问
    //dp[i][j]:从前i个物品中挑选，容量正好等于j的最大价值
    memset(dp, 0, sizeof dp);
    //将选择物品后无法满足体积正好为j的初始化为-1
    for (int j = 1; j <= V; j++) dp[j] = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = V; j >= v[i]; j--) {

            if (dp[j - v[i]] != -1)
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << (dp[V] == -1 ? 0 : dp[V]) << endl;

}