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
//
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param numbers int整型vector
//     * @return int整型
//     */
//    int MoreThanHalfNum_Solution(vector<int>& numbers) {
//        if (numbers.empty())
//        {
//            return 0;
//        }
//        if (numbers.size() == 1)
//        {
//            return numbers[0];
//        }
//        int begin = 0;
//        int end = numbers.size() - 1;
//        while (begin < end)
//        {
//            if (numbers[begin] != numbers[end])
//            {
//                begin++;
//                end--;
//            }
//            else
//            {
//                begin++;
//            }
//        }
//        int count = 0;
//        for (int i = 0; i < numbers.size(); ++i)
//        {
//            if (numbers[i] == numbers[begin])
//            {
//                count++;
//            }
//        }
//        return count > numbers.size() / 2 ? numbers[begin] : 0;
//    }
//};


//#include<iostream>
//using namespace std;
//int main()
//{
//    int a, b, c, d;
//    cin >> a >> b >> c >> d;
//    int A = (a + c) / 2;
//    int B = (b + d) / 2;
//    int C = (d - b) / 2;
//
//    int BB = (c - a) / 2;
//
//    if (BB == B)
//    {
//        cout << A << " " << B << " " << C << endl;
//    }
//    else
//        cout << "No" << endl;
//
//    return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    int M, N;
//    char arr[] = { 'A','B','C','D','E','F' };
//    string str;
//    cin >> M >> N;
//    int flag = 1;
//    if (M < 0)
//    {
//        M = 0 - M;
//        flag = 0;
//    }
//    if (M==0)
//    {
//        cout << M << endl;
//    }
//    while (M)
//    {
//        int Mod = M % N;
//        if (Mod >= 10)
//        {
//            Mod = arr[Mod - 10] - '0';
//
//        }
//        str += Mod + '0';
//        M /= N;
//    }
//    if (flag == 0)
//    {
//        str += "-";
//    }
//
//    reverse(str.begin(), str.end());
//    cout << str << endl;
//    return 0;
//}

#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

bool IsReverseStr(string s)
{
   string str(s);
   reverse(s.begin(),s.end());
   return str==s;

}

//int main() {
//    string s1, s2;
//    getline(cin,s1);
//    getline(cin,s2);
//    int count = 0;
//    for (int i=0;i<=s1.size();++i)
//    {
//        string Ref = s1;
//        Ref.insert(i,s2);
//        if (IsReverseStr(Ref))
//        {
//            count++;
//        }
//    }
//    cout << count << endl;
//}

#include<iostream>
#include<vector>
using namespace std;

//int main() {
//    int n;
//    cin >> n;
//    vector<int> v = {-1,2,1,-1,3};
//
//    //for (int i = 0; i < n; ++i) {
//    //    cin >> v[i];
//    //}
//    int MaxSum = v[0];
//    int Sum = v[0];//临时最大值
//    for (int i = 1; i < n; ++i) {
//       /* v[i] = max(v[i], v[i - 1] + v[i]);
//        if (v[i] >= MaxSum) {
//            MaxSum = v[i];
//        }*/
//         Sum=max(v[i],v[i]+Sum);
//         if(Sum>MaxSum)
//         {
//             MaxSum=Sum;
//         }
//    }
//    cout << MaxSum << endl;
//
//
//    return 0;
//}


//int main()
//{
//    char p1[15] = "abcd", str[50] = "xyz";
//    const char* p2 = "ABCD";
//    char* arr=strcat(p1+2, p2 + 1);
//    cout << arr << endl;
//   strcpy(str + 2, arr);
// 
//    printf("%s", str);
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    if (n == 0) return 0;
//    if (n == 1) return 1;
//    int f1 = 0;
//    int f2 = 1;
//    int fn = 0;
//    int minNum = 0;
//    for (int i = 2; fn < n; ++i)
//    {
//        fn = f1 + f2;
//        f1 = f2;
//        f2 = fn;
//        if (minNum < n && fn<n)
//        {
//            minNum = fn;
//        }
//    }
//    cout << min(n - minNum, fn - n) << endl;
//    return 0;
//}

//template<class T> 
//class BigNumber {
//	long n;
//public:
//	BigNumber(T i) :n(i) {}
//	BigNumber operator+(BigNumber b) {
//		return BigNumber(n + b.n);
//	}
//};
//int main()
//{
//	BigNumber<int> b1(10);
//	BigNumber<int> b2(20);
//	//int sum = 3 + 3;
//	BigNumber<int> sum = b1+ 3;
//	//BigNumber<int> sum =  3+b1;
//
//
//
//}
#include<iostream>
using namespace std;
//int main()
//{
//    int A, B;
//    while (cin >> A >> B)
//    {
//        int a = A, b = B;
//
//        if (A < B)
//        {
//            swap(A, B);
//        }
//        while (A % B)
//        {
//            int mod = A / B;
//            A = B;
//            B = mod;
//        }
//        cout << a * b / B << endl;
//    }
//    return 0;
//}
//int gcd(int a, int b) {
//    int r;
//    while (r = a % b) {
//        a = b;
//        b = r;
//    } return b;
//}
//int main() {
//    int a, b;
//    while (cin >> a >> b) {
//        cout << a * b / gcd(a, b) << endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
////改进，无论是以长度判断还是以字典判断，默认认为：
////单调递增，单调递减
//bool IslengthSort(vector<string>& v)
//{
//    int n = v.size();
//    if (n<2)
//    {
//        return true;
//    }
//    if (v[0].size()<=v[1].size())
//    {
//        for (int i = 2; i < n; ++i)//判断升序
//        {
//            if (v[i - 1].size() > v[i].size())
//            {
//                return false;
//            }
//        }
//
//    }
//    else
//    {
//        //判断降序
//        for (int i = 2; i < n; ++i)//判断升序
//        {
//            if (v[i - 1].size() < v[i].size())
//            {
//                return false;
//            }
//        }
//    }
//    
//    return true;
//}
//bool IsDictsort(vector<string>& v)
//{
//    int n = v.size();
//    if (n < 2)
//    {
//        return true;
//    }
//    if (v[0]<=v[1])
//    {
//        for (int i = 2; i < n; ++i)//判断升序
//        {
//            //比较的是整个字符串的，而不是起始位
//             //if(v[i-1][0]>v[i][0])错误
//            if (v[i - 1] > v[i])
//            {
//                return false;
//            }
//        }
//    }
//    else
//    {
//        for (int i = 2; i < n; ++i)//判断升序
//        {
//            //比较的是整个字符串的，而不是起始位
//             //if(v[i-1][0]>v[i][0])错误
//            if (v[i - 1] < v[i])
//            {
//                return false;
//            }
//        }
//    }
//    
//    return true;
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//    vector<string> v(n);
//    string s;
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> s;
//        v[i] = s;
//    }
//    if (IsDictsort(v) && IslengthSort(v))
//        cout << "both" << endl;
//    else if (IsDictsort(v) && !IslengthSort(v))
//        cout << "lexicographically" << endl;
//    else if (!IsDictsort(v) && IslengthSort(v))
//        cout << "lengths" << endl;
//    else
//        cout << "none" << endl;
//    return 0;
//}

struct A {
	long a1;
	short a2;
	int a3;
	int* a4;
};
//请问在64位编译器下用sizeof(struct A)计算出的大小是多少（）
int main()
{
	cout << sizeof(long) << endl;
	cout << sizeof(A) << endl;
}