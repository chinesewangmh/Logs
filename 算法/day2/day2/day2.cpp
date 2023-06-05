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

class Solution {
public:
    int uniquePaths(int m, int n) {
        //多开一行一列
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        //初始化dp表

        dp[0][1] = 1;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m][n];

    }
};


/// <summary>
/// 不同路径2
/// </summary>

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1));//多开一行一列

        //初始化dp
        dp[1][0] = 1;
        for (int i = 1; i <= row; ++i)
        {
            for (int j = 1; j <= col; ++j)
            {
                if (obstacleGrid[i - 1][j - 1] == 1)//注意映射关系，如果遇到障碍物，设置为0
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[row][col];
    }
};

/// <summary>
/// 礼物的最大价值
/// </summary>
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        //创建dp表
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1));//多开一行一列

        //初始化
        //这道题不需要

        //填表
        for (int i = 1; i <= row; ++i)
        {
            for (int j = 1; j <= col; ++j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];//注意映射关系
            }
        }

        return dp[row][col];
    }
};

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        //1.创建dp表
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 2, INT_MAX));
        for (int i = 0; i < dp[0].size(); ++i) dp[0][i] = 0;

        for (int i = 1; i <= row; ++i)
        {
            for (int j = 1; j <= col; ++j)
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1])) + matrix[i - 1][j - 1];
            }
        }

        //选取最小值
        int ret = INT_MAX;
        for (int i = 1; i <= col; ++i)
        {
            ret = min(dp[row][i], ret);
        }

        return ret;
    }
};

/// <summary>
/// 最小路径和
/// </summary>
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //创建dp表
        int row = grid.size();
        int col = grid[0].size();

        //求最小，初始化边界为最大值，求最大，初始化边界为最小值或0
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT_MAX));//多开一行一列

        //初始化,只需要这两个位置为0，其余为INT_MAX
        dp[0][1] = dp[1][0] = 0;

        //填表
        for (int i = 1; i <= row; ++i)
        {
            for (int j = 1; j <= col; ++j)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];//注意映射关系
            }
        }

        return dp[row][col];
    }
};

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int  m = dungeon.size();
        int n = dungeon[0].size();
        //1.创建dp表
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        //dp[i][j]表示从[i,j]位置出发到达终点所需的最低健康点数
        //2.初始化dp表
        dp[m - 1][n] = dp[m][n - 1] = 1;

        //3.填表
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                //假设dp[i][j]=x;那么x+dungeon[i][j]>=dp[i][j+1],x=dp[i][j+1]-dungeon[i][j];另一个同理
                //上式表示，到达dp[i][j]时的健康点数必须满足能安全出去dp[i][j],
                //并且要满足出去之后的健康点数能满足后续到达终点所需要的点数
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];

                if (dp[i][j] <= 0)//如果dungeon[i][j]很大，即血包很大，dp[i][j]为非正数，不满足题意
                    dp[i][j] = max(1, dp[i][j]);
            }
        }
        return dp[0][0];
    }
};


