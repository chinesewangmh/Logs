#include<iostream>
#include <vector>
using namespace std;

//替换所有的问号
string modifyString(string s)
{
    int n = s.size();
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '?')
        {
            for (char ch = 'a'; ch <= 'z'; ++ch)
            {
                if ((i == 0 || ch != s[i - 1]) && (i == n - 1 || ch != s[i + 1]))
                {
                    s[i] = ch;
                    break;
                }
            }
        }
    }

    return s;
}

//提莫攻击
int findPoisonedDuration(vector<int>& timeSeries, int d)
{
    //1 4 5 6 12 15
    int n = timeSeries.size();

    int ret = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        int x = timeSeries[i + 1] - timeSeries[i];
        if (x >= d)//持续时间满
            ret += d;
        else//重置
            ret += x;
    }

    //考虑最后一次攻击持续时间
    return ret + d;
}



//N字形变化
string convert(string s, int numRows) {

    //一行的话返回原数组
    if (numRows == 1) return s;
    int n = s.size();
    int d = 2 * numRows - 2;//公差

    string str;
    for (int i = 0; i < numRows; ++i)
    {
        //每一行的结果
        string ss;
        if (i == 0 || i == numRows - 1)//处理第一行和最后一行
        {
            for (int j = i; j < n; j += d)
            {
                ss += s[j];
            }
        }
        else//处理中间行
        {
            //同时处理两个位置
            for (int j = i, k = d - j; j < n; j += d, k += d)
            {
                if (j < n) ss += s[j];
                if (k < n) ss += s[k];
            }
        }

        str += ss;
    }

    return str;

}



///外观队列
class facequeue
{
    string fun(string& s)
    {
        int n = s.size();
        int left = 0, right = 0;
        string str;
        while (left < n || right < n)
        {
            while (right < n && s[left] == s[right])
            {
                right++;
            }
            str += (right - left) + '0';
            str += s[left];

            left = right;
        }


        return str;
    }
    string countAndSay(int n)
    {
        string res = "1";

        for (int i = 2; i <= n; ++i)
        {
            res = fun(res);
        }
        return res;
    }
};

#include <unordered_map>


class Solution {
public:
    int minNumberOfFrogs(string s)
    {
        int n = s.size();
        unordered_map<char, int> hash;
        //hash[k]存最终结果
        for (int i = 0; i < n; ++i)
        {
            //如果遇到c且k存在，拿出来一个保证最小数量
            if (s[i] == 'c' && hash['k'] > 0)
            {
                hash['c']++;
                hash['k']--;
                continue;
            }
            else if (s[i] == 'c' && hash['k'] == 0)//不存在新增
            {
                hash['c']++;
                continue;

            }

            //从c之后的字符，每遍历一个，就查看前一个字符是否存在，如果存在就移动对应的值
            //不存在直接返回-1
            if (s[i] == 'r' && hash['c'] > 0)
            {
                hash['c']--; hash['r']++;
                continue;

            }
            else if (s[i] == 'o' && hash['r'] > 0)
            {
                hash['r']--;
                hash['o']++;
                continue;
            }
            else if (s[i] == 'a' && hash['o'] > 0)
            {
                hash['o']--; hash['a']++; continue;

            }
            else if (s[i] == 'k' && hash['a'] > 0)
            {
                hash['a']--; hash['k']++; continue;

            }
            else
                return -1;
        }

        //查看出k以外下标是否还有不为0的
        for (auto pair : hash)
        {
            if (pair.first != 'k' && pair.second != 0)
                return -1;
        }
        return hash['k'];
    }

    //方法二
    int minNumberOfFrogs2(string croakOfFrogs)
    {

        string s = "croak";
        int n = s.size();
        //用数组模拟hash，数组下标对应s的字符，值对应出现的次数
        vector<int> hash(n);

        //存放下标s中字符所对应的下标
        unordered_map<char, int> idx;
        for (int i = 0; i < n; ++i)
        {
            idx[s[i]] = i;
        }

        for (auto ch : croakOfFrogs)
        {
            if (ch == 'c')
            {
                if (hash[n - 1] > 0) hash[n - 1]--;
                hash[0]++;
            }
            else
            {
                //获取字符对应下标
                int i = idx[ch];
                //查看该字符前一个字符是否存在
                if (hash[i - 1] > 0)
                {
                    //存在更新数值
                    hash[i - 1]--;
                    hash[i]++;
                }
                else//不存在不符合，返回
                    return -1;
            }
        }

        //查看前n-1个字符是否不为0
        for (int i = 0; i < n - 1; ++i)
        {
            if (hash[i] != 0)
                return -1;
        }

        return hash[n - 1];
    }


};


int main()
{
    string s = "croakcrook";
    cout << minNumberOfFrogs(s);
	return 0;
}