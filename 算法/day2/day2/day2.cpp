#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        //1.����dp��
        vector<int> dp(n);


        //2.��ʼ��dp��
        dp[0] = s[0] != '0';//dp[0] 0  1
        //2.1����߽� 
        if (n < 2) return dp[0];

        if (s[0] != '0' && s[1] != '0') dp[1] += 1;
        int sum = (s[0] - '0') * 10 + s[1] - '0';//dp[1] 0 1 2
        if (sum >= 10 && sum <= 26) dp[1] += 1;

        //3.���
        for (int i = 2; i < n; ++i)
        {
            if (s[i] != '0') dp[i] += dp[i - 1];//����iλ�õ����������

            int sum = (s[i - 1] - '0') * 10 + s[i] - '0';//������ϱ������
            if (sum >= 10 && sum <= 26) dp[i] += dp[i - 2];

        }

        return dp[n - 1];
    }
};
class Solution {
public:
    int numDecodings(string s) {
        //�Ż�
        int n = s.size();
        //1.����dp��
        vector<int> dp(n + 1);


        //2.��ʼ��dp��
        dp[0] = 1;//����dp[0]����Ϊ0����Ϊ���dp[2]=dp[0]+dp[1],����Ҫdp[0]����ӵ�����ʱ��Ϊ1������s[0]s[1]���Ա�����

        //ע��ӳ���ϵ������dpԪ�ر�֮ǰ����һλ����Ҫ-1�ҵ���Ӧ���ַ�
        dp[1] = s[1 - 1] != 0;

        //3.���
        for (int i = 2; i <= n; ++i)
        {
            if (s[i - 1] != '0') dp[i] = dp[i - 1];//����iλ�õ����������

            int sum = (s[i - 2] - '0') * 10 + s[i - 1] - '0';//������ϱ������
            if (sum >= 10 && sum <= 26) dp[i] += dp[i - 2];

        }

        return dp[n];
    }
};
int main()
{
    string s = "2101";
    Solution().numDecodings(s);
}