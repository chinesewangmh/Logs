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