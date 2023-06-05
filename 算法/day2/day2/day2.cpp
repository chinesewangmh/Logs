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

class Solution {
public:
    int uniquePaths(int m, int n) {
        //�࿪һ��һ��
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        //��ʼ��dp��

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
/// ��ͬ·��2
/// </summary>

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1));//�࿪һ��һ��

        //��ʼ��dp
        dp[1][0] = 1;
        for (int i = 1; i <= row; ++i)
        {
            for (int j = 1; j <= col; ++j)
            {
                if (obstacleGrid[i - 1][j - 1] == 1)//ע��ӳ���ϵ����������ϰ������Ϊ0
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[row][col];
    }
};

/// <summary>
/// ���������ֵ
/// </summary>
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        //����dp��
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1));//�࿪һ��һ��

        //��ʼ��
        //����ⲻ��Ҫ

        //���
        for (int i = 1; i <= row; ++i)
        {
            for (int j = 1; j <= col; ++j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];//ע��ӳ���ϵ
            }
        }

        return dp[row][col];
    }
};

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        //1.����dp��
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

        //ѡȡ��Сֵ
        int ret = INT_MAX;
        for (int i = 1; i <= col; ++i)
        {
            ret = min(dp[row][i], ret);
        }

        return ret;
    }
};

/// <summary>
/// ��С·����
/// </summary>
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //����dp��
        int row = grid.size();
        int col = grid[0].size();

        //����С����ʼ���߽�Ϊ���ֵ������󣬳�ʼ���߽�Ϊ��Сֵ��0
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT_MAX));//�࿪һ��һ��

        //��ʼ��,ֻ��Ҫ������λ��Ϊ0������ΪINT_MAX
        dp[0][1] = dp[1][0] = 0;

        //���
        for (int i = 1; i <= row; ++i)
        {
            for (int j = 1; j <= col; ++j)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];//ע��ӳ���ϵ
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
        //1.����dp��
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        //dp[i][j]��ʾ��[i,j]λ�ó��������յ��������ͽ�������
        //2.��ʼ��dp��
        dp[m - 1][n] = dp[m][n - 1] = 1;

        //3.���
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                //����dp[i][j]=x;��ôx+dungeon[i][j]>=dp[i][j+1],x=dp[i][j+1]-dungeon[i][j];��һ��ͬ��
                //��ʽ��ʾ������dp[i][j]ʱ�Ľ����������������ܰ�ȫ��ȥdp[i][j],
                //����Ҫ�����ȥ֮��Ľ���������������������յ�����Ҫ�ĵ���
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];

                if (dp[i][j] <= 0)//���dungeon[i][j]�ܴ󣬼�Ѫ���ܴ�dp[i][j]Ϊ������������������
                    dp[i][j] = max(1, dp[i][j]);
            }
        }
        return dp[0][0];
    }
};


