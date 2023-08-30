#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

//��ȫ������01������֮ͬ��
//1.�Ż�ǰ��״̬ת�Ʒ��̲�ͬ�����ǵ���ȫ����һ����Ʒ����ʹ�ö�Σ���
//dp[i][j] = dp[i - 1][j];
//if (j >= v[i])
//dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
//
//2.�Ż���01�����Ǵ���������£���ȫ�����Ǵ������Ҹ���


const int N = 1010;
int v[N], w[N];

int dp[N][N];

int main()
{
    int n, V;
    cin >> n >> V;
    for (int i = 1; i <= n; ++i)
        cin >> v[i] >> w[i];

    //��һ��
    //dp[i][j]:ǰi�����飬��ѡ��������j����Ʒ����ֵ
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

    //�ڶ���
    //dp[i][j]:ǰi�����飬��ѡ������Ϊj����Ʒ����ֵ
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
//    //��һ��
//    //dp[i][j]:ǰi�����飬��ѡ��������j����Ʒ����ֵ
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = v[i]; j <= V; ++j)//����ȫ�������������Ż��������ҡ�
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
//    //�ڶ���
//    //dp[i][j]:ǰi�����飬��ѡ������Ϊj����Ʒ����ֵ
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
//    //��һ��
//    //dp[i][j]:ǰi�����飬��ѡ��������j����Ʒ����ֵ
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = v[i]; j <= V; ++j)//��ȫ�������������Ż���������
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
//    //�ڶ���
//    //dp[i][j]:ǰi�����飬��ѡ������Ϊj����Ʒ����ֵ
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = v[i]; j <= V; ++j)
//        {
//
//            // if(dp[j-v[i]]!=-1)   dp[j-v[i]]+w[i]�㹻С���Ͳ���Ӱ����
//            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
//        }
//    }
//   cout<<(dp[V]<0?0:dp[V])<<endl;  
//
//}



//��Ǯ����
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    //dp[i][j]:��ǰi��Ӳ���У�ѡȡӲ�Ҽ�ֵ�ܺ�ǡ��Ϊj������Ҫ����СӲ����
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
    for (int j = 1; j <= amount; ++j) dp[0][j] = 0x3f3f3f3f;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= amount; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= coins[i - 1])
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);//������min��Ϊ�˲�Ӱ�죬ѡ��ǳ����ֵ
        }
    }

    return dp[n][amount] >= 0x3f3f3f3f ? -1 : dp[n][amount];

}
//�ռ��Ż�
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    //dp[i][j]:��ǰi��Ӳ���У�ѡȡӲ�Ҽ�ֵ�ܺ�ǡ��Ϊj������Ҫ����СӲ����
    vector<int> dp(amount + 1);
    for (int j = 1; j <= amount; ++j) dp[j] = 0x3f3f3f3f;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = coins[i - 1]; j <= amount; ++j)
        {
            dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);//������min��Ϊ�˲�Ӱ�죬ѡ��ǳ����ֵ
        }
    }

    return dp[amount] >= 0x3f3f3f3f ? -1 : dp[amount];

}

/*��Ǯ�һ�2*/
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    //dp[i][j]:��ǰi��Ӳ����ѡȡǡ�ÿ��Դճ�j��ֵ�ķ�����
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

/*��ȫƽ����*/
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
            //������min��Ϊ�˲�Ӱ�죬ѡ��ǳ����ֵ
            if (j >= arr[i - 1])
                dp[i][j] = min(dp[i - 1][j], dp[i][j - arr[i - 1]] + 1);
        }
    }
    return dp[n][sum];

}