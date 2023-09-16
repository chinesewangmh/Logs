#include<iostream>
#include <vector>
using namespace std;

///回文子串
int countSubstrings(string s)
{
    int n = s.size();
    //dp[i][j]:以i为起点j为终点的子串是否是回文串
    vector<vector<bool>> dp(n, vector<bool>(n));
    int ret = 0;
    for (int i = n - 1; i >= 0; --i)//从下往上填
    {
        for (int j = i; j < n; ++j)
        {
            //当s[i]==s[j]分三种情况
            //i==j true
            //i+1==j     true
            //j>i+1      dp[i+1][j-1]
            //合并三种情况
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
    //dp[i][j]:以i为起始，j为末尾的子串是否是回文串
    vector<vector<bool>> dp(n, vector<bool>(n));
    int Maxsize = 0;
    string ret;
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (s[i] == s[j])
                dp[i][j] = j > i + 1 ? dp[i + 1][j - 1] : true;
            if (dp[i][j] && j - i + 1 > Maxsize)//是回文串，就算长度
            {
                Maxsize = j - i + 1;
                ret.clear();
                ret = s.substr(i, Maxsize);

            }
        }
    }

    return ret;
}

//分割回文串4
bool checkPartitioning(string s)
{
    //1.将所有的子串存进一个二维数组中，并判断是否是回文
    //2.将区间划分为三段【0，i-1】[i,j][j+1,n-1]，都是回文则返回true

    int n = s.size();
    //dp[i][j]:以i为起j为终点的字符串是否是回文串
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

    //2.【i,j】表示第二个回文串起点和终点
    //枚举所有的第二个子串区间
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

//分割回文串2
int minCut(string s)
{
    int n = s.size();
    //dp[i][j]:以i为起j为终点的字符串是否是回文串
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

    //2.分割
    //v[i]:在【0，i】这个区间最大子串所需要的分割最小次数
    vector<int> v(n, INT_MAX);
    for (int i = 0; i < n; ++i)
    {
        //[0,i]是回文串，不需要分割
        if (dp[0][i])
        {
            v[i] = 0;
            continue;
        }
        //【0，i】不是回文串，开始分割
        for (int j = 1; j <= i; ++j)//j的取值范围(0，i]
        {
            if (dp[j][i])
                v[i] = min(v[i], v[j - 1] + 1);
        }
    }

    return v[n - 1];
}

//最长回文子序列
int longestPalindromeSubseq(string s)
{
    int n = s.size();
    //dp[i][j]:在【i，j】这个区间内，最长回文子序列大小
    vector<vector<int>>  dp(n, vector<int>(n));

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (s[i] == s[j])//相等情况
            {
                if (i == j) dp[i][j] = 1;//只有一个
                else if (i + 1 == j) dp[i][j] = 2;//两个都相等
                else dp[i][j] = dp[i + 1][j - 1] + 2;//从[i+1,j-1]选出来+2
            }
            else
            {
                //不相等就在[i,[i+1,j-1],j]区间内
                //选取【i,j-1】和【i+1,j】的最大值
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }
    return dp[0][n - 1];
}

//让字符串成为回文串的最少插入次数
int minInsertions(string s)
{
    int n = s.size();
    //dp[i][j]:在【i,j】区间内的字符串要成为回文串的最小插入次数
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = n - 1; i >= 0; --i)
    {
        //这里处理i==j的已经是回文的情况，建表的时候已经为0
        for (int j = i + 1; j < n; ++j)
        {
            if (s[i] == s[j])
                //j==i+1需要插入次数为0，也被归入到填表中
                dp[i][j] = dp[i + 1][j - 1];
            else
                //不相等的情况需要再i,j旁边分别补是s[j],s[i]
                //然后在[i][j-1] [i+1][j] 选取最小值+1
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