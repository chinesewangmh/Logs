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
//��John Conway������������Ϸ�У�ϸ����������״̬��������, ÿ��ϸ����Χ��8�����ڸ�(����ľŹ����ȥ����)����Ϸ��������:
//1�����һ������ϸ������Χ�����ڸ�������������˸���ڹ¶�����ȥ��
//2�����һ������ϸ������Χ�����ڸ������������˸����ӵ������ȥ��
//3�����һ������ϸ������Χ�����ڸ�Ϊ����������������˸������
//4�����һ��������ϸ������Χ�����ڸ�ǡ��Ϊ��������˸�����������
//����Ϊn * n(2 < n && n < 100)������, ��Ŵ�1��ʼ��n* n���������������У�����3 * 3����
//    1 2 3
//    4 5 6
//    7 8 9
//    m(0 < m && m < 1000)Ϊ�ݱ�Ĵ��������մ�ӡ���յĴ��ϸ����
//    list Ϊ����ϸ����� ���ϸ����������50��
//    ����1 : �����½���˼·��Ҫ�㣬˼·��ȷ�ɵñ���1 / 3�ķ֡�
//    ����2 : ��д���Ӧ�ĳ�����룬�����ܿ���Ч�ʸߵķ�ʽ��
//    ���� :
//���� list = { 1,2,3,4,5 }, n = 5, m = 1 ���Ϊ : 2 3 4 7 8 9
//���� list = { 10,14,16,21,22 }, n = 6, m = 4 ���Ϊ : 17 21 23 28 29


//����1������˼·��Ҫ��
//
//����˼·��
//
//ʹ��һ����ά����grid���洢��ǰ��״̬��grid[i][j]��ʾ���Ϊi* n + j��ϸ����״̬��0��ʾ������1��ʾ����
//����ÿһ���ݱ䣬���ݹ��򣬱������е�ϸ��������grid���顣
//��¼����ϸ����ÿ���һ���ݱ䣬����һ�Ρ�
//Ҫ�㣺
//
//��������ϸ��ʱ��Ҫע��߽�������
//����һ��ϸ����Χ�����ڸ�����ʱ����Ҫ���Ǹ�ϸ�������������ĸ����������ϸ����
//�ж�һ��ϸ����״̬ʱ��Ҫ���ݹ�����С�



//cpp
#include <iostream>  
#include <vector>  
using namespace std;

vector<vector<int>> countCells(vector<int>& list, int n) {
    int m = list.size();
    //������λ״̬����
    vector<vector<int>> grid(n, vector<int>(n, 0));
    //��ʼ����ά����
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
        // �������ÿһ���������ϸ��
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                // ����ÿһ��ϸ��ͳ����˸�����λ����Ļ�ϸ������
                int liveNeighbors = 0;

                //�����ĵ����ƫ��
                //�ң���
                //�£����¡�����
                //�ϡ����ϡ�����
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {

                        if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
                            int r = (row + neighbors[i]);
                            int c = (col + neighbors[j]);

                            // �鿴���ڵ�ϸ���Ƿ��ǻ�ϸ�����ڷ�Χ���Ҵ��/-1��ʾ֮ǰ�����������
                            if ((r < rows && r >= 0) && (c < cols && c >= 0) && (abs(board[r][c]) == 1)) {
                                liveNeighbors += 1;
                            }
                        }
                    }
                }

                // ���� 1 ����� 3      
                if ((board[row][col] == 1) && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[row][col] = -1;
                }
                // ���� 4
                if (board[row][col] == 0 && liveNeighbors == 3) {//2��ʾ֮ǰ�������ڻ���
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
//    // ������������ copyBoard
//    vector<vector<int> >copyBoard(rows, vector<int>(cols, 0));
//
//    // ��ԭ���鸴��һ�ݵ� copyBoard ��
//    for (int row = 0; row < rows; row++) {
//        for (int col = 0; col < cols; col++) {
//            copyBoard[row][col] = board[row][col];
//        }
//    }
//
//    // �������ÿһ���������ϸ��
//    for (int row = 0; row < rows; row++) {
//        for (int col = 0; col < cols; col++) {
//
//            // ����ÿһ��ϸ��ͳ����˸�����λ����Ļ�ϸ������
//            int liveNeighbors = 0;
//
//            //�����ĵ����ƫ��
//            //�ң���
//            //�£����¡�����
//            //�ϡ����ϡ�����
//            for (int i = 0; i < 3; i++) {
//                for (int j = 0; j < 3; j++) {
//
//                    if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
//                        int r = (row + neighbors[i]);
//                        int c = (col + neighbors[j]);
//
//                        // �鿴���ڵ�ϸ���Ƿ��ǻ�ϸ�����ڷ�Χ���Ҵ��
//                        if ((r < rows && r >= 0) && (c < cols && c >= 0) && (copyBoard[r][c] == 1)) {
//                            liveNeighbors += 1;
//                        }
//                    }
//                }
//            }
//
//            // ���� 1 ����� 3      
//            if ((copyBoard[row][col] == 1) && (liveNeighbors < 2 || liveNeighbors > 3)) {
//                board[row][col] = 0;
//            }
//            // ���� 4
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