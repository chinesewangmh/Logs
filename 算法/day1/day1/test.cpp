/**/
#include <iostream>
#include <vector>
using namespace std;
/*̩����������*/
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2)
            return 1;
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};
/*��������*/
class Solution {
public:
    int tribonacci(int n) {
        if (n < 1) return 0;
        if (n == 1 || n == 2) return 1;
        int t0 = 0, t1 = 1, t2 = 1;
        int tn = 0;
        //tn=t0+t1+t2;
        while (n-- >= 3)
        {
            tn = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = tn;

        }
        return tn;
    }
};
int main()
{
	return 0;
}

//��������
class Solution {
public:
    int waysToStep(int n) {

        const int mod = 1e9 + 7;

        //��ֹԽ��
        if (n == 1 || n == 2) return n;
        if (n == 3) return 4;

        //��ʼ��
        //���
        vector<int> v(n + 1);
        v[1] = 1; v[2] = 2; v[3] = 4;

        //v(i)��ʾ��i��¥���ж������Ϸ�
        for (int i = 4; i <= n; i++)
            v[i] = ((v[i - 1] + v[i - 2]) % mod + v[i - 3]) % mod;

        return v[n];
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {//¥��������ĩβ����һ��
        int size = cost.size();


        //dp[0]=dp[1]=0
        vector<int> dp(cost.size() + 1, 0);
        //dp[i]��ʾ�����iλ�õ���С����
        for (int i = 2; i <= size; ++i)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[size];
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //�Ӻ���ǰ

        //dp[i]��ʾ�ӵ�i��λ�ÿ�ʼ����¥������С����
        int n = cost.size();
        vector<int> dp(n);//����Ҫ�࿪һ��
        dp[n - 1] = cost[n - 1];
        dp[n - 2] = cost[n - 2];

        for (int i = n - 3; i >= 0; --i)
        {
            //״̬ת�Ʒ���
            dp[i] = min(dp[i + 1] + cost[i], dp[i + 2] + cost[i]);
        }

        return min(dp[0], dp[1]);
    }
};