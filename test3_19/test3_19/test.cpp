#define  _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//    string s1, s2, str;
//    getline(cin, s1);
//    getline(cin, s2);
//    int arr[256] = {0};
//
//    for (int i=0;i<s2.size();++i)
//    {
//        arr[s2[i]]++;
//    }
//    for (int i = 0; i < s1.size(); ++i)
//    {
//        if (arr[s1[i]] == 0)
//        {
//            str += s1[i];
//        }
//    }
//    cout << str << endl;
//    return 0;
//}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//int main()
//{
//    int n = 0;
//    cin >> n;
//    vector<int> v(3 * n, 0);
//    for (int i = 0; i < 3 * n; ++i)
//    {
//        cin >> v[i];
//    }
//    sort(v.begin(), v.end());
//    int maxSum = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        maxSum += v[v.size() - 2 * (i + 1)];
//    }
//    cout << maxSum << endl;
//    return 0;
//}
///////////////////////////////////////////////////////////////////
//#include<iostream>
//#include<algorithm>
//#include<string>
//using namespace std;
//
//int main()
//{
//    string s;
//    getline(cin, s);
//    reverse(s.begin(), s.end());
//    size_t pos = s.find(" ");
//    size_t prevPos = 0;
//    while (pos != std::string::npos)
//    {
//        reverse(s.begin() + prevPos, s.begin() + pos);
//        prevPos = pos;
//        pos = s.find(" ", pos + 1);
//    }
//    pos = s.rfind(" ");
//    reverse(s.begin() + pos + 1, s.end());
//    cout << s << endl;
//    return 0;
//}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        if (numbers.empty())
        {
            return 0;
        }
        if (numbers.size() == 1)
        {
            return numbers[0];
        }
        int begin = 0;
        int end = numbers.size() - 1;
        while (begin < end)
        {
            if (numbers[begin] != numbers[end])
            {
                begin++;
                end--;
            }
            else
            {
                begin++;
            }
        }
        int count = 0;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (numbers[i] == numbers[begin])
            {
                count++;
            }
        }
        return count > numbers.size() / 2 ? numbers[begin] : 0;
    }
};