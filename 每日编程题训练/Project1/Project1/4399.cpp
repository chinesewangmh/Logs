//#include<iostream>
//#include <vector>
//using namespace std;
//
//#include <stdio.h>
//
//using namespace std;
//
//bool isnumber(char c)
//{
//    return '0'<=c && c <= '9';
//}
//
//string FindLongestIncreasingDigitsSubstr(const string& s) {
//
//    int maxstr = 0;
//    int cur = 0;
//    string result;
//    string str;
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if (!isnumber(s[i]))
//        {
//            if (cur > maxstr)
//            {
//                maxstr = cur;
//                result = str;
//
//            }
//            else
//            {
//                cur = 0;
//                str = "";
//            }
//            continue;
//        }
//
//        if (cur== 0 || (s[i] - '0') - 1 == (s[i - 1] - '0'))
//        {
//            cur++;
//            str += s[i];
//            if (cur > maxstr)
//            {
//                maxstr = cur;
//                result = str;
//            }
//        }
//        else
//        {
//            cur = 1;
//            str = "";
//            str += s[i];
//
//        }
//    }
//
//    return result;
//
//}
// 

// 
//
//bool isdigit(char c) {
//    return '0' <= c && c <= '9';
//}
//
//string FindLongestIncreasingDigitsSubstr2(const string& s) {
//    int maxstr = 0;
//    string result;
//    for (int i = 0, j = 0; i < s.size(); ++i) {
//        if (!isdigit(s[i])) {
//            if (j > maxstr) {
//                maxstr = j;
//                result = s.substr(i - maxstr, maxstr);
//            }
//            j = 0;
//        }
//        else {
//            if (j == 0 || (s[i] - '0') - 1 == (s[i - 1] - '0')) {
//                ++j;
//            }
//            else {
//                j = 1;
//            }
//        }
//    }
//
//    return result;
//}
//int main()
//{
//    string s = "1245de789";
//    cout<< FindLongestIncreasingDigitsSubstr(s);
//}
#include<string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    string Minstr(string str1, string str2)
    {
        int len1 = str1.size();
        int len2 = str2.size();
        while (len1 >= 0 && len2 >= 0)
        {
            if (str1[len1] < str2[len2])
                return str1;
            else
                return str2;
            len2--;
            len1--;
        }
        return len1 > len2 ? str2 : str1;

    }
    string smallestFromLeaf(TreeNode* root) {

        string res;
        string result = func(root, res);
        for (int i = 0; i < res.size(); ++i)
        {
            result[i] += 'a';
        }

        return result;
    }

    string  func(TreeNode* root, string res)
    {
        if (root == nullptr)
            return "";
        res += to_string(root->val);

        string left = func(root->left, res);
        string right = func(root->right, res);
        return Minstr(left, right);
    }

};
//
//由John Conway发明的生命游戏中，细胞存在两种状态存活和死亡, 每个细胞周围有8个相邻格(网格的九宫格除去自身)。游戏规则如下:
//1、如果一个存活的细胞格周围存活的邻格少于两个，则此格过于孤独而死去。
//2、如果一个存活的细胞格周围存活的邻格多余三个，则此格过于拥挤而死去。
//3、如果一个存活的细胞格周围存活的邻格为两个或者三个，则此格继续存活。
//4、如果一个死亡的细胞格周围存活的邻格恰好为三个，则此格死而复生。
//网格为n * n(2 < n && n < 100)的网格, 序号从1开始到n* n，按照行优先排列，例如3 * 3网格。
//    1 2 3
//    4 5 6
//    7 8 9
//    m(0 < m && m < 1000)为演变的次数，最终打印最终的存活细胞。
//    list 为存活的细胞序号 存活细胞数量少于50。
//    问题1 : 阐述下解题思路和要点，思路正确可得本题1 / 3的分。
//    问题2 : 编写相对应的程序代码，尽可能考虑效率高的方式。
//    例如 :
//输入 list = { 1,2,3,4,5 }, n = 5, m = 1 输出为 : 2 3 4 7 8 9
//输入 list = { 10,14,16,21,22 }, n = 6, m = 4 输出为 : 17 21 23 28 29


//问题1：解题思路和要点
//
//解题思路：
//
//使用一个二维数组grid来存储当前的状态，grid[i][j]表示序号为i* n + j的细胞的状态（0表示死亡，1表示存活）。
//对于每一次演变，根据规则，遍历所有的细胞，更新grid数组。
//记录存活的细胞，每完成一次演变，更新一次。
//要点：
//
//遍历所有细胞时，要注意边界条件。
//计算一个细胞周围存活的邻格数量时，需要考虑该细胞的上下左右四个方向的相邻细胞。
//判断一个细胞的状态时，要根据规则进行。



//cpp
#include <iostream>  
#include <vector>  
using namespace std;

vector<vector<int>> countCells(vector<int>& list, int n) {
    int m = list.size();
    //构建二位状态数组
    vector<vector<int>> grid(n, vector<int>(n, 0));
    //初始化二维数组
    for (int i = 0; i < m; ++i) {
        int idx = list[i];
        grid[(idx-1)/n][(idx-1)%n] = 1;
    }
    cout << "Initial grid: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return grid;
}

void printGrid(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void evolveCells(vector<vector<int>>& board, int n, int m) {
    int neighbors[3] = { 0, 1, -1 };

    int rows = board.size();
    int cols = board[0].size();
    for (int i = 0; i < m; ++i) {
        // 遍历面板每一个格子里的细胞
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                // 对于每一个细胞统计其八个相邻位置里的活细胞数量
                int liveNeighbors = 0;

                //以中心点进行偏移
                //右，左
                //下，右下、左下
                //上、右上、左上
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {

                        if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
                            int r = (row + neighbors[i]);
                            int c = (col + neighbors[j]);

                            // 查看相邻的细胞是否是活细胞：在范围内且存活/-1表示之前存活现在死了
                            if ((r < rows && r >= 0) && (c < cols && c >= 0) && (abs(board[r][c]) == 1)) {
                                liveNeighbors += 1;
                            }
                        }
                    }
                }

                // 规则 1 或规则 3      
                if ((board[row][col] == 1) && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[row][col] = -1;
                }
                // 规则 4
                if (board[row][col] == 0 && liveNeighbors == 3) {//2表示之前死，现在活了
                    board[row][col] = 2;
                }
            }
        }

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (board[i][j] > 0) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
}

void printSurvivors(vector<vector<int>>& grid, int n) {
    int survivorCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                ++survivorCount;
                cout << i * n + j + 1 << " ";
            }
        }
    }
    cout << endl << "Survivors: " << survivorCount << endl;
}


//void gameOfLife(vector<vector<int>>& board) {
//    int neighbors[3] = { 0, 1, -1 };
//
//    int rows = board.size();
//    int cols = board[0].size();
//
//    // 创建复制数组 copyBoard
//    vector<vector<int> >copyBoard(rows, vector<int>(cols, 0));
//
//    // 从原数组复制一份到 copyBoard 中
//    for (int row = 0; row < rows; row++) {
//        for (int col = 0; col < cols; col++) {
//            copyBoard[row][col] = board[row][col];
//        }
//    }
//
//    // 遍历面板每一个格子里的细胞
//    for (int row = 0; row < rows; row++) {
//        for (int col = 0; col < cols; col++) {
//
//            // 对于每一个细胞统计其八个相邻位置里的活细胞数量
//            int liveNeighbors = 0;
//
//            //以中心点进行偏移
//            //右，左
//            //下，右下、左下
//            //上、右上、左上
//            for (int i = 0; i < 3; i++) {
//                for (int j = 0; j < 3; j++) {
//
//                    if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
//                        int r = (row + neighbors[i]);
//                        int c = (col + neighbors[j]);
//
//                        // 查看相邻的细胞是否是活细胞：在范围内且存活
//                        if ((r < rows && r >= 0) && (c < cols && c >= 0) && (copyBoard[r][c] == 1)) {
//                            liveNeighbors += 1;
//                        }
//                    }
//                }
//            }
//
//            // 规则 1 或规则 3      
//            if ((copyBoard[row][col] == 1) && (liveNeighbors < 2 || liveNeighbors > 3)) {
//                board[row][col] = 0;
//            }
//            // 规则 4
//            if (copyBoard[row][col] == 0 && liveNeighbors == 3) {
//                board[row][col] = 1;
//            }
//        }
//    }
//}

int main()
{
    int n = 6, m = 4;
    vector<int> list{ 10,14,16,21,22 };
    vector<vector<int>> gird=countCells(list, n);
    evolveCells(gird,n,m);
    printSurvivors(gird, n);

    
}