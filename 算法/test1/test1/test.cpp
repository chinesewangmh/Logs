#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
#include <vector>

//class Solution {
//public:
//    int Fibonacci(int n) {
//        // if(n==0)
//        // {
//        //     return 0;
//        // }
//        // if(n==1 || n==2)
//        // {
//        //     return 1;
//        // }
//
//        // return Fibonacci(n-1)+Fibonacci(n-2);
//
//        //第二种
//    //    if (n == 0)
//    //    {
//    //        return 0;
//    //    }
//    //    if (n == 1 || n == 2)
//    //    {
//    //        return 1;
//    //    }
//    //    vector<int> v;
//    //    v.resize(n + 1);
//    //    v[0] = 0;
//    //    v[1] = 1;
//    //    for (int i = 2; i <= n; i++)
//    //    {
//    //        v[i] = v[i - 1] + v[i - 2];
//    //    }
//    //    return v[n];
//
//    //}
//    //第三种
//        if (n == 0)
//        {
//            return 0;
//        }
//        if (n == 1 || n == 2)
//        {
//            return 1;
//        }
//        int f1 = 0;
//        int f2 = 1;
//        int fi = 0;
//        for (int i = 2; i <= n; i++)
//        {
//            fi = f1 + f2;
//            f1 = f2;
//            f2 = fi;
//        }
//        return fi;
//    }
//};
//
//int main()
//{
//    Solution().Fibonacci(4);
//    return 0;
//}

#include <vector>
#include<unordered_set>
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& dict) {
        if (s.empty())
        {
            return false;
        }
        if (dict.empty()) {
            return false;
        }
        vector<bool> vb(s.size() + 1, false);
        vb[0] = true;
        //前i个字符能否被分割
        for (int i = 1; i <= s.size(); ++i)
        {
            //j<i && f(j) &&dict[j+1,i]
            for (int j = 0; j < i; ++j)
            {
                cout << s.substr(j, i - j) << endl;
                if (vb[j] && (dict.find(s.substr(j, i - j)) != dict.end()))
                {
                    vb[i] = true;
                    break;
                }
            }
        }
        return vb[s.size()];
    }
    
};
int main()
{
    string str = "newcode";
    unordered_set<string> st = { "new", "code" };
    cout<<Solution().wordBreak(str,st);
    return 0;
}







//#include <algorithm>
//#include <memory>
//#include <vector>
//class Solution {
//public:
//    int minimumTotal(vector<vector<int> >& triangle) {
//        // if (triangle.empty()) {
//        //     return 0;
//        // }
//        // int row = triangle.size();
//        // for (int i = 1; i < row ; i++) {
//        //     for (int j = 0; j <= i; j++) {
//        //         //左边界
//        //         if (j == 0) {
//        //             triangle[i][j] = triangle[i - 1][j] + triangle[i][j];
//        //         } else if (j == i) { //右边界
//        //             triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j];
//        //         } else { //正常情况
//        //             triangle[i][j] = min(triangle[i - 1][j],
//        //                                  triangle[i - 1][j - 1]) + triangle[i][j];
//        //         }
//        //     }
//        // }
//        // //最后一行找最小值
//        // int minWay = triangle[row - 1][0];
//        // int col = triangle[0].size();
//        // for (int j = 1; j < row; j++) {
//        //     minWay = min(minWay, triangle[row - 1][j]);
//        // }
//        // return minWay;
//        if (triangle.empty()) {
//            return 0;
//        }
//        int row = triangle.size();
//        //逆向，从倒数第二行开始
//        for (int i = row - 2; i >= 0; i--) {
//
//            for (int j = 0; j <= i; j++) {
//                triangle[i][j] = min(triangle[i + 1][j],
//                    triangle[i + 1][j + 1]) + triangle[i][j];
//            }
//        }
//
//        return triangle[0][0];
//
//    }
//}


class Solution {
public:
    /**
     *
     * @param m int整型
     * @param n int整型
     * @return int整型
     */
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1)
        {
            return 0;
        }
        vector<vector<int>> vv(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; j++)
            {
                vv[i][j] = vv[i][j - 1] + vv[i - 1][j];
            }
        }
        return vv[m - 1][n - 1];
    }
};


class Solution {
public:
    /**
     *
     * @param grid int整型vector<vector<>>
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& grid) {
        if (grid.empty())
        {
            return 0;
        }
        int row = grid.size();
        int col = grid[0].size();
        //第一行
        for (int j = 1; j < col; ++j)
        {
            grid[0][j] = grid[0][j - 1] + grid[0][j];

        }
        //第一列
        for (int i = 1; i < row; ++i)
        {
            grid[i][0] = grid[i - 1][0] + grid[i][0];

        }
        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < col; ++j)
            {
                grid[i][j] = min(grid[i][j - 1], grid[i - 1][j]) + grid[i][j];
            }
        }
        return grid[row - 1][col - 1];
    }
};

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param a: Given n items with size A[i]
     * @param v: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int>& a, vector<int>& v) {
        if (m <= 0 || a.empty() || v.empty())
        {
            return 0;
        }
        vector<vector<int>> vv(a.size() + 1, vector<int>(m + 1, 0));
        int row = a.size();
        int col = m;
        for (int i = 1; i <= row; ++i)
        {
            for (int j = 1; j <= col; ++j)
            {
                //第i个商品在A中对应的索引为i-1: i从1开始
                //如果第i个商品大于j,说明放不下， 所以(i,j)的最大价值和(i-1,j)相同
                if (a[i - 1] > j)
                {
                    vv[i][j] = vv[i - 1][j];
                }

                //如果可以装下，分两种情况，装或者不装
                //如果不装，则即为(i-1, j)
                //如果装，需要腾出放第i个物品大小的空间： j - A[i-1],装入之后的最大价值即为(i - 1, j- A[i-1]) + 第i个商品的价值V[i - 1]
                //最后在装与不装中选出最大的价值
                else
                {
                    vv[i][j] = max(vv[i - 1][j], vv[i - 1][j - a[i - 1]] + v[i - 1]);
                }
            }
        }
        return vv[row][col];

    }
};


class Solution {
public:
    /**
     *
     * @param s string字符串
     * @return int整型
     */
    vector<vector<bool>> GetMat(string& s)
    {
        int len = s.size();
        vector<vector<bool>> matD = vector<vector<bool>>(len, vector<bool>(len, false));
        for (int i = len - 1; i >= 0; --i)
        {
            for (int j = i; j < len; ++j)
            {
                //单字符串，回文
                if (j == i)
                {
                    matD[i][j] = true;
                }
                else if (j == i + 1)//相邻两个字符串
                {
                    matD[i][j] = (s[i] == s[j]);
                }
                else
                {
                    matD[i][j] = ((s[i] == s[j]) && matD[i + 1][j - 1]);
                }
            }
        }
        return matD;
    }

    int minCut(string s) {
        if (s.empty())
        {
            return 0;
        }
        int len = s.size();
        vector<int> v(len + 1);
        //初始化前i个字符最大分割次数
        for (int i = 0; i < len + 1; ++i)
        {
            v[i] = i - 1;
        }

        vector<vector<bool>> mat = GetMat(s);
        for (int i = 1; i <= len; ++i)
        {
            //min{f[j],f[j+1,i]}
            for (int j = 0; j < i; ++j)
            {
                //判断j+1到i是否为回文串
                if (mat[j][i - 1])
                {

                    v[i] = min(v[i], v[j] + 1);
                }
            }
        }
        return v[len];

    }
};


class Solution {
public:
    /**
     *
     * @param word1 string字符串
     * @param word2 string字符串
     * @return int整型
     */
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> vv(len1 + 1, vector<int>(len2 + 1, 0));
        //初始化
        for (int i = 0; i <= len1; ++i) {
            vv[i][0] = i;
        }

        for (int i = 0; i <= len2; ++i) {
            vv[0][i] = i;
        }
        for (int i = 1; i < len1 + 1; ++i)
        {
            for (int j = 1; j < len2 + 1; ++j)
            {
                //插入，删除
                vv[i][j] = min(vv[i][j - 1], vv[i - 1][j]) + 1;
                //替换
                if (word1[i - 1] == word2[j - 1])
                {
                    vv[i][j] = min(vv[i][j], vv[i - 1][j - 1]);
                }
                else
                    vv[i][j] = min(vv[i][j], vv[i - 1][j - 1] + 1);

            }
        }
        return vv[len1][len2];
    }
};



















