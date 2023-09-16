#include<iostream>
#include <vector>
using namespace std;

///�����Ӵ�
int countSubstrings(string s)
{
    int n = s.size();
    //dp[i][j]:��iΪ���jΪ�յ���Ӵ��Ƿ��ǻ��Ĵ�
    vector<vector<bool>> dp(n, vector<bool>(n));
    int ret = 0;
    for (int i = n - 1; i >= 0; --i)//����������
    {
        for (int j = i; j < n; ++j)
        {
            //��s[i]==s[j]���������
            //i==j true
            //i+1==j     true
            //j>i+1      dp[i+1][j-1]
            //�ϲ��������
            if (s[i] == s[j])
                dp[i][j] = j > i + 1 ? dp[i + 1][j - 1] : true;
            if (dp[i][j])
                ret++;
        }
    }
    return ret;
}

string longestPalindrome(string s)
{
    int n = s.size();
    //dp[i][j]:��iΪ��ʼ��jΪĩβ���Ӵ��Ƿ��ǻ��Ĵ�
    vector<vector<bool>> dp(n, vector<bool>(n));
    int Maxsize = 0;
    string ret;
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (s[i] == s[j])
                dp[i][j] = j > i + 1 ? dp[i + 1][j - 1] : true;
            if (dp[i][j] && j - i + 1 > Maxsize)//�ǻ��Ĵ������㳤��
            {
                Maxsize = j - i + 1;
                ret.clear();
                ret = s.substr(i, Maxsize);

            }
        }
    }

    return ret;
}

//�ָ���Ĵ�4
bool checkPartitioning(string s)
{
    //1.�����е��Ӵ����һ����ά�����У����ж��Ƿ��ǻ���
    //2.�����仮��Ϊ���Ρ�0��i-1��[i,j][j+1,n-1]�����ǻ����򷵻�true

    int n = s.size();
    //dp[i][j]:��iΪ��jΪ�յ���ַ����Ƿ��ǻ��Ĵ�
    vector<vector<bool>> dp(n, vector<bool>(n));
    //1.
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (s[i] == s[j])
                dp[i][j] = j > i + 1 ? dp[i + 1][j - 1] : true;
        }
    }

    //2.��i,j����ʾ�ڶ������Ĵ������յ�
    //ö�����еĵڶ����Ӵ�����
    for (int i = 1; i < n - 1; ++i)
    {
        for (int j = i; j < n - 1; ++j)
        {
            if (dp[0][i - 1] && dp[i][j] && dp[j + 1][n - 1])
                return true;
        }
    }

    return false;
}

//�ָ���Ĵ�2
int minCut(string s)
{
    int n = s.size();
    //dp[i][j]:��iΪ��jΪ�յ���ַ����Ƿ��ǻ��Ĵ�
    vector<vector<bool>> dp(n, vector<bool>(n));
    //1.
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (s[i] == s[j])
                dp[i][j] = j > i + 1 ? dp[i + 1][j - 1] : true;
        }
    }

    //2.�ָ�
    //v[i]:�ڡ�0��i�������������Ӵ�����Ҫ�ķָ���С����
    vector<int> v(n, INT_MAX);
    for (int i = 0; i < n; ++i)
    {
        //[0,i]�ǻ��Ĵ�������Ҫ�ָ�
        if (dp[0][i])
        {
            v[i] = 0;
            continue;
        }
        //��0��i�����ǻ��Ĵ�����ʼ�ָ�
        for (int j = 1; j <= i; ++j)//j��ȡֵ��Χ(0��i]
        {
            if (dp[j][i])
                v[i] = min(v[i], v[j - 1] + 1);
        }
    }

    return v[n - 1];
}

//�����������
int longestPalindromeSubseq(string s)
{
    int n = s.size();
    //dp[i][j]:�ڡ�i��j����������ڣ�����������д�С
    vector<vector<int>>  dp(n, vector<int>(n));

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (s[i] == s[j])//������
            {
                if (i == j) dp[i][j] = 1;//ֻ��һ��
                else if (i + 1 == j) dp[i][j] = 2;//���������
                else dp[i][j] = dp[i + 1][j - 1] + 2;//��[i+1,j-1]ѡ����+2
            }
            else
            {
                //����Ⱦ���[i,[i+1,j-1],j]������
                //ѡȡ��i,j-1���͡�i+1,j�������ֵ
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }
    return dp[0][n - 1];
}

//���ַ�����Ϊ���Ĵ������ٲ������
int minInsertions(string s)
{
    int n = s.size();
    //dp[i][j]:�ڡ�i,j�������ڵ��ַ���Ҫ��Ϊ���Ĵ�����С�������
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = n - 1; i >= 0; --i)
    {
        //���ﴦ��i==j���Ѿ��ǻ��ĵ�����������ʱ���Ѿ�Ϊ0
        for (int j = i + 1; j < n; ++j)
        {
            if (s[i] == s[j])
                //j==i+1��Ҫ�������Ϊ0��Ҳ�����뵽�����
                dp[i][j] = dp[i + 1][j - 1];
            else
                //����ȵ������Ҫ��i,j�Ա߷ֱ���s[j],s[i]
                //Ȼ����[i][j-1] [i+1][j] ѡȡ��Сֵ+1
                dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
        }
    }
    return dp[0][n - 1];
}

//void func(int * p)
//{
//    cout << *(p + 1) << endl;
//    cout << *(p++) << endl;
//}
//int main()
//{
//    /*float a = 2;
//    int b = 4, c = 3;
//    cout << (a + b) * c / 2 << endl;
//    cout << (1/2) * (a+b)*c  << endl;
//    cout << (a + b) * c *1/ 2 << endl;
//    cout << c / 2*(a+b) << endl;*/
//
//    int a[9] = { 1,2,3,4,5,6,7,8,9 };
//    func(a);
//    cout << *(a + 1) << endl;
//    cout << a++ << endl;
//	return 0;
//}