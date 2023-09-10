#include<iostream>
#include <vector>
using namespace std;

//�滻���е��ʺ�
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

//��Ī����
int findPoisonedDuration(vector<int>& timeSeries, int d)
{
    //1 4 5 6 12 15
    int n = timeSeries.size();

    int ret = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        int x = timeSeries[i + 1] - timeSeries[i];
        if (x >= d)//����ʱ����
            ret += d;
        else//����
            ret += x;
    }

    //�������һ�ι�������ʱ��
    return ret + d;
}



//N���α仯
string convert(string s, int numRows) {

    //һ�еĻ�����ԭ����
    if (numRows == 1) return s;
    int n = s.size();
    int d = 2 * numRows - 2;//����

    string str;
    for (int i = 0; i < numRows; ++i)
    {
        //ÿһ�еĽ��
        string ss;
        if (i == 0 || i == numRows - 1)//�����һ�к����һ��
        {
            for (int j = i; j < n; j += d)
            {
                ss += s[j];
            }
        }
        else//�����м���
        {
            //ͬʱ��������λ��
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



///��۶���
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
        //hash[k]�����ս��
        for (int i = 0; i < n; ++i)
        {
            //�������c��k���ڣ��ó���һ����֤��С����
            if (s[i] == 'c' && hash['k'] > 0)
            {
                hash['c']++;
                hash['k']--;
                continue;
            }
            else if (s[i] == 'c' && hash['k'] == 0)//����������
            {
                hash['c']++;
                continue;

            }

            //��c֮����ַ���ÿ����һ�����Ͳ鿴ǰһ���ַ��Ƿ���ڣ�������ھ��ƶ���Ӧ��ֵ
            //������ֱ�ӷ���-1
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

        //�鿴��k�����±��Ƿ��в�Ϊ0��
        for (auto pair : hash)
        {
            if (pair.first != 'k' && pair.second != 0)
                return -1;
        }
        return hash['k'];
    }

    //������
    int minNumberOfFrogs2(string croakOfFrogs)
    {

        string s = "croak";
        int n = s.size();
        //������ģ��hash�������±��Ӧs���ַ���ֵ��Ӧ���ֵĴ���
        vector<int> hash(n);

        //����±�s���ַ�����Ӧ���±�
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
                //��ȡ�ַ���Ӧ�±�
                int i = idx[ch];
                //�鿴���ַ�ǰһ���ַ��Ƿ����
                if (hash[i - 1] > 0)
                {
                    //���ڸ�����ֵ
                    hash[i - 1]--;
                    hash[i]++;
                }
                else//�����ڲ����ϣ�����
                    return -1;
            }
        }

        //�鿴ǰn-1���ַ��Ƿ�Ϊ0
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