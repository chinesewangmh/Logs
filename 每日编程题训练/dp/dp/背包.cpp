#include <cstring>
#include <iostream>
using namespace std;

const int N = 1010;

int n, V, v[N], w[N];

int dp[N][N];

int main() {
    //��������
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
    //��һ��
    //dp[i][j]:��ǰi����Ʒ����ѡ������������j������ֵ
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= V; j++) {
            dp[i][j] = dp[i - 1][j]; //��ѡiλ����Ʒ
            if (j >= v[i]) //ѡiλ����Ʒ��Ҫ��֤j-v[i]>=0
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << dp[n][V] << endl;

    //�ڶ���
    //dp[i][j]:��ǰi����Ʒ����ѡ���������õ���j������ֵ
    memset(dp, 0, sizeof dp);
    //��ѡ����Ʒ���޷������������Ϊj�ĳ�ʼ��Ϊ-1
    for (int j = 1; j <= V; j++) dp[0][j] = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= V; j++) {
            dp[i][j] = dp[i - 1][j]; //��ѡiλ����Ʒ
            //ѡiλ����Ʒ��Ҫ��֤j-v[i]>=0���ұ�֤����һ��λ�ÿɱ�ѡ
            if (j >= v[i] && dp[i - 1][j - v[i]] != -1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << (dp[n][V] == -1 ? 0 : dp[n][V]) << endl;

}

/*���������Ż�*/

#include <cstring>
#include <iostream>
using namespace std;

const int N = 1010;

int n, V, v[N], w[N];

int dp[N];
/*
1.һά����
2.�����������

*/
int main() {
    //��������
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
    //��һ��
    //dp[i][j]:��ǰi����Ʒ����ѡ������������j������ֵ
    for (int i = 1; i <= n; ++i) {
        for (int j = V; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[V] << endl;

    //�ڶ���
    //dp[i][j]:��ǰi����Ʒ����ѡ���������õ���j������ֵ
    memset(dp, 0, sizeof dp);
    //��ѡ����Ʒ���޷������������Ϊj�ĳ�ʼ��Ϊ-1
    for (int j = 1; j <= V; j++) dp[j] = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = V; j >= v[i]; j--) {

            if (dp[j - v[i]] != -1)
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << (dp[V] == -1 ? 0 : dp[V]) << endl;

}