#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        //1.创建dp表
        vector<int> dp(n);


        //2.初始化dp表
        dp[0] = s[0] != '0';//dp[0] 0  1
        //2.1处理边界 
        if (n < 2) return dp[0];

        if (s[0] != '0' && s[1] != '0') dp[1] += 1;
        int sum = (s[0] - '0') * 10 + s[1] - '0';//dp[1] 0 1 2
        if (sum >= 10 && sum <= 26) dp[1] += 1;

        //3.填表
        for (int i = 2; i < n; ++i)
        {
            if (s[i] != '0') dp[i] += dp[i - 1];//处理i位置单独编码情况

            int sum = (s[i - 1] - '0') * 10 + s[i] - '0';//处理组合编码情况
            if (sum >= 10 && sum <= 26) dp[i] += dp[i - 2];

        }

        return dp[n - 1];
    }
};
class Solution {
public:
    int numDecodings(string s) {
        //优化
        int n = s.size();
        //1.创建dp表
        vector<int> dp(n + 1);


        //2.初始化dp表
        dp[0] = 1;//这里dp[0]不能为0，因为如果dp[2]=dp[0]+dp[1],当需要dp[0]满足加的条件时，为1，代表s[0]s[1]可以被解码

        //注意映射关系，所有dp元素比之前后移一位所以要-1找到对应的字符
        dp[1] = s[1 - 1] != 0;

        //3.填表
        for (int i = 2; i <= n; ++i)
        {
            if (s[i - 1] != '0') dp[i] = dp[i - 1];//处理i位置单独编码情况

            int sum = (s[i - 2] - '0') * 10 + s[i - 1] - '0';//处理组合编码情况
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