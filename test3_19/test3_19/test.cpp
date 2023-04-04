//#define  _CRT_SECURE_NO_WARNINGS 1
////#include<iostream>
////#include<string>
////using namespace std;
////int main()
////{
////    string s1, s2, str;
////    getline(cin, s1);
////    getline(cin, s2);
////    int arr[256] = {0};
////
////    for (int i=0;i<s2.size();++i)
////    {
////        arr[s2[i]]++;
////    }
////    for (int i = 0; i < s1.size(); ++i)
////    {
////        if (arr[s1[i]] == 0)
////        {
////            str += s1[i];
////        }
////    }
////    cout << str << endl;
////    return 0;
////}
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
////int main()
////{
////    int n = 0;
////    cin >> n;
////    vector<int> v(3 * n, 0);
////    for (int i = 0; i < 3 * n; ++i)
////    {
////        cin >> v[i];
////    }
////    sort(v.begin(), v.end());
////    int maxSum = 0;
////    for (int i = 0; i < n; ++i)
////    {
////        maxSum += v[v.size() - 2 * (i + 1)];
////    }
////    cout << maxSum << endl;
////    return 0;
////}
/////////////////////////////////////////////////////////////////////
////#include<iostream>
////#include<algorithm>
////#include<string>
////using namespace std;
////
////int main()
////{
////    string s;
////    getline(cin, s);
////    reverse(s.begin(), s.end());
////    size_t pos = s.find(" ");
////    size_t prevPos = 0;
////    while (pos != std::string::npos)
////    {
////        reverse(s.begin() + prevPos, s.begin() + pos);
////        prevPos = pos;
////        pos = s.find(" ", pos + 1);
////    }
////    pos = s.rfind(" ");
////    reverse(s.begin() + pos + 1, s.end());
////    cout << s << endl;
////    return 0;
////}
////
////class Solution {
////public:
////    /**
////     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
////     *
////     *
////     * @param numbers int整型vector
////     * @return int整型
////     */
////    int MoreThanHalfNum_Solution(vector<int>& numbers) {
////        if (numbers.empty())
////        {
////            return 0;
////        }
////        if (numbers.size() == 1)
////        {
////            return numbers[0];
////        }
////        int begin = 0;
////        int end = numbers.size() - 1;
////        while (begin < end)
////        {
////            if (numbers[begin] != numbers[end])
////            {
////                begin++;
////                end--;
////            }
////            else
////            {
////                begin++;
////            }
////        }
////        int count = 0;
////        for (int i = 0; i < numbers.size(); ++i)
////        {
////            if (numbers[i] == numbers[begin])
////            {
////                count++;
////            }
////        }
////        return count > numbers.size() / 2 ? numbers[begin] : 0;
////    }
////};
//
//
////#include<iostream>
////using namespace std;
////int main()
////{
////    int a, b, c, d;
////    cin >> a >> b >> c >> d;
////    int A = (a + c) / 2;
////    int B = (b + d) / 2;
////    int C = (d - b) / 2;
////
////    int BB = (c - a) / 2;
////
////    if (BB == B)
////    {
////        cout << A << " " << B << " " << C << endl;
////    }
////    else
////        cout << "No" << endl;
////
////    return 0;
////}
//
//
////#include<iostream>
////#include<vector>
////#include<algorithm>
////using namespace std;
////int main()
////{
////    int M, N;
////    char arr[] = { 'A','B','C','D','E','F' };
////    string str;
////    cin >> M >> N;
////    int flag = 1;
////    if (M < 0)
////    {
////        M = 0 - M;
////        flag = 0;
////    }
////    if (M==0)
////    {
////        cout << M << endl;
////    }
////    while (M)
////    {
////        int Mod = M % N;
////        if (Mod >= 10)
////        {
////            Mod = arr[Mod - 10] - '0';
////
////        }
////        str += Mod + '0';
////        M /= N;
////    }
////    if (flag == 0)
////    {
////        str += "-";
////    }
////
////    reverse(str.begin(), str.end());
////    cout << str << endl;
////    return 0;
////}
//
//#include <iostream>
//#include <algorithm>
//#include<string>
//using namespace std;
//
//bool IsReverseStr(string s)
//{
//   string str(s);
//   reverse(s.begin(),s.end());
//   return str==s;
//
//}
//
////int main() {
////    string s1, s2;
////    getline(cin,s1);
////    getline(cin,s2);
////    int count = 0;
////    for (int i=0;i<=s1.size();++i)
////    {
////        string Ref = s1;
////        Ref.insert(i,s2);
////        if (IsReverseStr(Ref))
////        {
////            count++;
////        }
////    }
////    cout << count << endl;
////}
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
////int main() {
////    int n;
////    cin >> n;
////    vector<int> v = {-1,2,1,-1,3};
////
////    //for (int i = 0; i < n; ++i) {
////    //    cin >> v[i];
////    //}
////    int MaxSum = v[0];
////    int Sum = v[0];//临时最大值
////    for (int i = 1; i < n; ++i) {
////       /* v[i] = max(v[i], v[i - 1] + v[i]);
////        if (v[i] >= MaxSum) {
////            MaxSum = v[i];
////        }*/
////         Sum=max(v[i],v[i]+Sum);
////         if(Sum>MaxSum)
////         {
////             MaxSum=Sum;
////         }
////    }
////    cout << MaxSum << endl;
////
////
////    return 0;
////}
//
//
////int main()
////{
////    char p1[15] = "abcd", str[50] = "xyz";
////    const char* p2 = "ABCD";
////    char* arr=strcat(p1+2, p2 + 1);
////    cout << arr << endl;
////   strcpy(str + 2, arr);
//// 
////    printf("%s", str);
////}
//
////#include<iostream>
////using namespace std;
////
////int main()
////{
////    int n;
////    cin >> n;
////    if (n == 0) return 0;
////    if (n == 1) return 1;
////    int f1 = 0;
////    int f2 = 1;
////    int fn = 0;
////    int minNum = 0;
////    for (int i = 2; fn < n; ++i)
////    {
////        fn = f1 + f2;
////        f1 = f2;
////        f2 = fn;
////        if (minNum < n && fn<n)
////        {
////            minNum = fn;
////        }
////    }
////    cout << min(n - minNum, fn - n) << endl;
////    return 0;
////}
//
////template<class T> 
////class BigNumber {
////	long n;
////public:
////	BigNumber(T i) :n(i) {}
////	BigNumber operator+(BigNumber b) {
////		return BigNumber(n + b.n);
////	}
////};
////int main()
////{
////	BigNumber<int> b1(10);
////	BigNumber<int> b2(20);
////	//int sum = 3 + 3;
////	BigNumber<int> sum = b1+ 3;
////	//BigNumber<int> sum =  3+b1;
////
////
////
////}
//#include<iostream>
//using namespace std;
////int main()
////{
////    int A, B;
////    while (cin >> A >> B)
////    {
////        int a = A, b = B;
////
////        if (A < B)
////        {
////            swap(A, B);
////        }
////        while (A % B)
////        {
////            int mod = A / B;
////            A = B;
////            B = mod;
////        }
////        cout << a * b / B << endl;
////    }
////    return 0;
////}
////int gcd(int a, int b) {
////    int r;
////    while (r = a % b) {
////        a = b;
////        b = r;
////    } return b;
////}
////int main() {
////    int a, b;
////    while (cin >> a >> b) {
////        cout << a * b / gcd(a, b) << endl;
////    }
////    return 0;
////}
////#include<iostream>
////#include<vector>
////#include<string>
////using namespace std;
//////改进，无论是以长度判断还是以字典判断，默认认为：
//////单调递增，单调递减
////bool IslengthSort(vector<string>& v)
////{
////    int n = v.size();
////    if (n<2)
////    {
////        return true;
////    }
////    if (v[0].size()<=v[1].size())
////    {
////        for (int i = 2; i < n; ++i)//判断升序
////        {
////            if (v[i - 1].size() > v[i].size())
////            {
////                return false;
////            }
////        }
////
////    }
////    else
////    {
////        //判断降序
////        for (int i = 2; i < n; ++i)//判断升序
////        {
////            if (v[i - 1].size() < v[i].size())
////            {
////                return false;
////            }
////        }
////    }
////    
////    return true;
////}
////bool IsDictsort(vector<string>& v)
////{
////    int n = v.size();
////    if (n < 2)
////    {
////        return true;
////    }
////    if (v[0]<=v[1])
////    {
////        for (int i = 2; i < n; ++i)//判断升序
////        {
////            //比较的是整个字符串的，而不是起始位
////             //if(v[i-1][0]>v[i][0])错误
////            if (v[i - 1] > v[i])
////            {
////                return false;
////            }
////        }
////    }
////    else
////    {
////        for (int i = 2; i < n; ++i)//判断升序
////        {
////            //比较的是整个字符串的，而不是起始位
////             //if(v[i-1][0]>v[i][0])错误
////            if (v[i - 1] < v[i])
////            {
////                return false;
////            }
////        }
////    }
////    
////    return true;
////}
////
////int main()
////{
////    int n;
////    cin >> n;
////    vector<string> v(n);
////    string s;
////    for (int i = 0; i < n; ++i)
////    {
////        cin >> s;
////        v[i] = s;
////    }
////    if (IsDictsort(v) && IslengthSort(v))
////        cout << "both" << endl;
////    else if (IsDictsort(v) && !IslengthSort(v))
////        cout << "lexicographically" << endl;
////    else if (!IsDictsort(v) && IslengthSort(v))
////        cout << "lengths" << endl;
////    else
////        cout << "none" << endl;
////    return 0;
////}
//
//struct A {
//	long a1;
//	short a2;
//	int a3;
//	int* a4;
//};
////请问在64位编译器下用sizeof(struct A)计算出的大小是多少（）
////int main()
////{
////	cout << sizeof(long) << endl;
////	cout << sizeof(A) << endl;
////}
//
//int uniquePaths(int m, int n) {
//    // if(m<1||n<1)
//    // {
//    //     return 0;
//    // }
//    // vector<vector<int>> vv(m,vector<int>(n,1));
//    // for(int i=1;i<m;++i)
//    // {
//    //     for(int j=1;j<n;j++)
//    //     {
//    //         vv[i][j]=vv[i][j-1]+vv[i-1][j];
//    //     }
//    // }
//    // return vv[m-1][n-1];
//    long long x = 1;
//    int y = 1;
//    /*if (m < n)
//        std::swap(m, n);*/
//    for (int i = 1; i < n; i++) {
//        x *= (m - 1) + i; //获取分子
//        y *= i; //获取分母
//    }
//    return x / y;
//}
////int main()
////{
////    uniquePaths(11,18);
////}
//
//class Board {
//public:
//    bool checkWon(vector<vector<int> > board) {
//        int row = board.size();
//        int col = board[0].size();
//        //同一行全为1
//        for (int i = 0; i < row; ++i)
//        {
//            for (int j = 0; j < col; ++j)
//            {
//                
//
//            }
//        }
//
//        //正对角线
//        for (int i = 0; i < row; ++i)
//        {
//            for (int j = 0; j < col; ++j)
//            {
//                if (i == j && board[i][j] == 1)
//                {
//
//                }
//            }
//        }
//    }
//};
//
////int main()
////{
////    for (int i=0;i<10;++i)
////    {
////        if (3<=i)
////        {
////            cout << i << endl;
////        }
////    }
////}
//#include<iostream>
//#include<string>
//using namespace std;
//int lengthNum(string& s)
//{
//    if (s.size() <= 4) return 5;
//    else if (s.size() >= 5 && s.size() <= 7) return 10;
//    else return 25;
//}
//int AZNum(string& s)
//{
//    bool a = false;
//    bool A = false;
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if (islower(s[i])) a = true;
//        if (isupper(s[i])) A = true;
//    }
//    if (A && a)
//    {
//        return 25;
//    }
//    else if (A && !a || !A && a)
//    {
//        return 10;
//    }
//    else
//        return 0;
//}
//int Numsum(string& s)
//{
//    int sum = 0;
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if (isdigit(s[i]))
//        {
//            ++sum;
//        }
//    }
//    if (sum > 1)
//    {
//        return 20;
//    }
//    else if (sum == 1)
//        return 10;
//    else
//        return 0;
//}
//
//int Fsum(string& s)
//{
//    int sum = 0;
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if (0x21 <= s[i] && s[i] <= 0x2F ||
//            s[i] >= 0x3A && s[i] <= 0x40 ||
//            s[i] >= 0x5B && s[i] <= 0x60 ||
//            s[i] >= 0x7B && s[i] <= 0x7E
//            )
//        {
//            ++sum;
//        }
//    }
//    if (sum > 1)
//    {
//        return 20;
//    }
//    else if (sum == 1)
//        return 10;
//    else
//        return 0;
//
//}
//int endSum(string& s)
//{
//
//    if (AZNum(s) == 20 && Numsum(s) > 0 && Fsum(s) > 0) return 5;
//    else if (AZNum(s) > 0 && Numsum(s) > 0 && Fsum(s) > 0) return 3;
//    else if (AZNum(s) > 0 && Numsum(s) > 0) return 2;
//    return 0;
//}
//
//
//
//
//
//
////int main()
////{
////    string s;
////    getline(cin, s);
////    int sum = 0;
////    int a1 = lengthNum(s);
////    int a2 = AZNum(s);
////    int a3 = Numsum(s);
////    int a4 = Fsum(s);
////    int a5 = endSum(s);
////    sum = lengthNum(s) + AZNum(s) + Numsum(s) + Fsum(s) + endSum(s);
////    if (sum >= 90)
////        cout << "VERY_SECURE" << endl;
////    else if (sum >= 80)
////        cout << "SECURE" << endl;
////    else if (sum >= 70)
////        cout << "VERY_STRONG" << endl;
////    else if (sum >= 60)
////        cout << "STRONG" << endl;
////    else if (sum >= 50)
////        cout << "AVERAGE" << endl;
////    else if (sum >= 25)
////        cout << "WEAK" << endl;
////    else
////        cout << "VERY_WEAK" << endl;
////
////
////
////
////    return 0;
////}
//
//#include<iostream>
//using namespace std;
//
////int main()
////{
////    int n;
////    cin >> n;
////    string str;
////    while (n)
////    {
////        int mod = n % 2;
////        str += (mod + '0');
////        n /= 2;
////    }
////    int Maxone = 0;
////    int Nowone = 0;
////    for (int i = 0; i < str.size(); ++i)
////    {
////        if (str[i] == '1')
////        {
////            Nowone++;
////            Maxone = max(Maxone, Nowone);
////        }
////        else
////        {
////            /*if (Maxone < Nowone)
////            {
////                Maxone = Nowone;
////                Nowone = 0;
////            }*/
////            Nowone = 0;
////        }
////    }
////    cout << Maxone << endl;
////    return 0;
////}
#include<iostream>
using namespace std;
//class MY
//{
//    MY()
//    {
//        count++;
//    }
//
//    static int count;
//};
//int MY::count = 0;
//int main()
//{
//    MY m;
//
//}
class MyClass {
public:
    MyClass() {
        count++; // 每次调用构造函数时增加计数器
    }

    static int count; // 静态成员变量，用于记录构造函数被调用的次数
};

int MyClass::count = 0;

template <class T>
T fun(T x, T y) {
    return x * x + y * y;
}
//}
//int main() {
//
//    fun<float>(1.0,2);
//    //int* b = new int[3];
//    ////MyClass obj1;
//    ///*MyClass obj2;
//    //MyClass obj3;*/
//    ////MyClass* obj7 = new MyClass();
//    //
//
//    ////MyClass obj4[4];
//    //MyClass* obj5[5];//0
//    //MyClass(*obj6)[6];//0
//    // 
//    // 
//    // 
//    MyClass* arr[3];
//    for (int i=0;i<3;++i)
//    {
//        arr[i] = new MyClass();
//    }
//    std::cout << MyClass::count << std::endl; // 输出 3，表示构造函数被调用了 3 次
//
//    return 0;
//}

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//int main()
//{
//    string str;
//    getline(cin, str);
//    int cnt = 0;
//
//    vector<string> vs;
//    string Ref;
//    for (int i = 0; i < str.size(); ++i)
//    {
//        if (str[i] != ' '&& str[i] != '"')
//        {
//            while (i < str.size() && str[i] != '"' && str[i] != ' ')
//            {
//                Ref += str[i];
//                ++i;
//            }
//        }
//        else if (str[i] == '"')
//        {
//            ++i;
//            while (i < str.size() && str[i] != '"')
//            {
//                Ref += str[i];
//                ++i;
//            }
//            ++i;
//        }
//        if (!Ref.empty())
//        {
//            vs.push_back(Ref);
//            ++cnt;
//            Ref.clear();
//        }
//
//
//    }
//    cout << cnt << endl;
//    for (int i = 0; i < vs.size(); ++i)
//    {
//        cout << vs[i] << endl;
//    }
//
//    return 0;
//}


#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<limits.h>
using namespace std;
void GetPrim(int n,vector<int>& v)
{
    for (int i=2;i<=sqrt(n);++i)
    {
        if (n%i==0)
        {
            v.push_back(i);
            if (n/i != i)//n的另一半约数
            {
                v.push_back(n/i);
            }
        }
    }
}
int Jump(int n,int m)
{
    vector<int> v(m+1,INT_MAX);//保存步数
    v[n] = 0;//初始化起始位置
    for (int i=n;i<m;++i)
    {
        if (v[i]==INT_MAX)
        {
            continue;
        }
        vector<int> vPrim;//保存约数
        GetPrim(i,vPrim);
        for (int j=0;j<vPrim.size();++j)
        {
            //vPrim[j]是约数
            if(vPrim[j]+i <= m && v[vPrim[j]+i] != INT_MAX)
            {
                //取步数最小值：该位置当前步数值与当前位置步数+1相比较
                v[vPrim[j] + i] = min(v[vPrim[j]+i],v[i]+1);
            }
            else if (vPrim[j]+i<=m)
            {
                v[vPrim[j] + i] = v[i] + 1;
            }
        }
    }
    return v[m] == INT_MAX ? -1 : v[m];
}

#include<iostream>
using namespace std;

int Days(int year, int month)
{
    int Monthday[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
    {
        return Monthday[month] += 1;
    }
    return Monthday[month];
}

//int main()
//{
//    int year, month, day;
//    cin >> year >> month >> day;
//    int sum = 0;
//    for (int i = 1; i < month; ++i)
//    {
//        sum += Days(year, month);
//    }
//    cout << sum + day << endl;
//    return 0;
//}
//int main()
//{
//    /*int n, m;
//    cin >> n >> m;
//
//    int min_stmp = Jump(n,m);
//    cout << min_stmp << endl;
//    return 0;*/
//}

#include<algorithm>
int getLuckyPacket(int x[], int n, int pos, int sum, int multi)
{
    int count = 0;
    //循环，搜索以位置i开始所有可能的组合
    for (int i = pos; i < n; i++)
    {
        sum += x[i];
        multi *= x[i];
        if (sum > multi)
        {
            //找到符合要求的组合，加1，继续累加后续的值，看是否有符合要求的集合
            count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
        } 
            else if (x[i] == 1)
        {
            //如何不符合要求，且当前元素值为1，则继续向后搜索
            count += getLuckyPacket(x, n, i + 1, sum, multi);
        } 
            else
        {
            //如何sum大于multi,则后面就没有符合要求的组合了
            break;
        } 
            //要搜索下一个位置之前，首先恢复sum和multi
            sum -= x[i];
        multi /= x[i];
        //数字相同的球，没有什么区别，都只能算一个组合，所以直接跳过
        while (i < n - 1 && x[i] == x[i + 1])
        {
            i++;
        }
    } 
    return count;
       
} 
int main()
{
    int n;
    while (cin >> n)
    {
        int x[5];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        } 
        sort(x, x + n);
        //从第一个位置开始搜索
        cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
    } 
        return 0;
}