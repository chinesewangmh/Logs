#include<iostream>
#include <vector>
using namespace std;

int longestCommonSubsequence(string s1, string s2) {
    if (s1.size() < s2.size())
        swap(s1, s2);
    int size1 = s1.size();
    int size2 = s2.size();
    //dp[i][j]:以i位置为结尾的最长子序列长度    
    vector<vector<int>> dp(size2 + 1, vector<int>(size1 + 1));

    for (int i = 1; i <= size2; ++i)
    {
        for (int j = 1; j <= size1; ++j)
        {
            if (s1[j] == s2[i])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string res;
    for (int i = size2, j = size1; dp[i][j] >= 1;)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            res += s1[i - 1];
            i--;
            j--; //根据递推公式可得
        }
        else
        {
            if (dp[i - 1][j] >= dp[i][j - 1])
                j--; //说明当前最大是由左边转换而来的
            else
            {
                i--;
            }
        }
    }
    reverse(res.begin(), res.end());
    //         return res;需要判断是否为空
    return res.empty() ? "-1" : res;
}

int main()
{
    string text1 = "abc", text2 = "def";
    longestCommonSubsequence(text1,text2);
	return 0;
}