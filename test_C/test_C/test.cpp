#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//template<typename Type>
//
//Type Max(const Type& a, const Type& b)
//
//{
//
//	cout << "This is Max<Type>" << endl;
//
//	return a > b ? a : b;
//
//}
//
//template<>
//
//int Max<int>(const int& a, const int& b)
//
//{
//
//	cout << "This is Max<int>" << endl;
//
//	return a > b ? a : b;
//
//}
//
//template<>
//
//char Max<char>(const char& a, const char& b)
//
//{
//
//	cout << "This is Max<char>" << endl;
//
//	return a > b ? a : b;
//
//}
//
//int Max(const int& a, const int& b)
//
//{
//
//	cout << "This is Max" << endl;
//
//	return a > b ? a : b;
//
//}
//
//int main()
//
//{
//
//	Max(10, 20);
//
//	Max(12.34, 23.45);
//
//	Max('A', 'B');
//
//	Max<int>(20, 30);
//
//	return 0;
//
//}
//class A
//{
//public:
//	void fun(){}
//	int _a;
//};
//class B :public A
//{
//public:
//	void fun(int n){}
//	int _a;
//};
//int main()
//{
//	B b;
//	b.A::fun();
//}

//﻿class A
//{
//public:
//  A() :m_iVal(0) { test(); }
//  virtual void func() { std::cout << m_iVal << ‘ ’; }
//  void test() { func(); }
//public:
//  int m_iVal;
//};
//
//class B : public A
//{
//public:
//	B() { test(); }
//	virtual void func()
//	{
//		++m_iVal;
//		std::cout << m_iVal << ‘ ’;
//	}
//};
//
//int main(int argc, char* argv[])
//{
//	A* p = new B;
//	p->test();
//	return 0;
//}

//class A
//{
//public:
//
//	A()
//		:_m(0)
//	{
//		test();
//	}
//	virtual void func()
//	{
//		std::cout << _m << " ";
//
//	}
//	void test()
//	{
//		func();
//	}
//public:
//	int _m;
//};
//class B : public A
//{
//public:
//	B() { 
//		test(); 
//	}
//	virtual void func()
//	{
//		++_m;
//		std::cout << _m << " ";
//	}
//};
//
//int main(int argc, char* argv[])
//{
//	A* p = new B;
//	p->test();
//	return 0;
//}

//class A
//{
//public:
//    virtual void f()
//    {
//        cout << "A::f()" << endl;
//    }
//};
//
//class B : public A
//{
//private:
//    virtual void f()
//    {
//        cout << "B::f()" << endl;
//    }
//};
//
//int main()
//{
//    A* pa = (A*)new B;
//    pa->f();
//}
#include <vector>
//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        int ans = 0;
//        for (int i = 0; i < 32; ++i) {
//            int total = 0;
//            for (int num : nums) {
//                total += ((num >> i) & 1);
//            }
//            if (total % 3) {
//                ans |= (1 << i);
//            }
//        }
//        return ans;
//    }
//};

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        vector<int> arr(10001);
        for (auto e : numbers)
        {
            arr[e]++;
        }
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (arr[numbers[i]] > (numbers.size() / 2))
            {
                return numbers[i];
            }

        }
        return 0;

    }
};
//int main()
//{
//   // int arr[] = { 2,2,3,2 };
//    vector<int> v;
//    v.push_back(2);
//    v.push_back(2);
//    v.push_back(3);
//
//    v.push_back(2);
//   int n= Solution().MoreThanHalfNum_Solution(v);
//   cout << n << endl;
//
//}

//int main()
//{
//    int n = 0;
//    char ch;
//    //for (ch = getchar(); ch != '\n'; n++)
//    for(n = 0; getchar() != '\n'; n++)
//    {
//        printf("%d",n);
//    }
//}

//int main() {
//    long long a = 1, b = 2, c = 3;
//    printf("%d %d %d\n", a, b, c);
//    return 0;
//}

class A
{
public:
    A(string s)
        :test(s)
    {}
    const char& operator[](size_t pos) const
    {
        return test[pos];
    }
     char& operator[](size_t pos) 
    {
        return test[pos];
    }

     string add(string str)
     {
         return str;
     }
private:
    string test;
};
int max(int a,int b)
{
    return a + b;
}

//int main()
//{
//    A a("Hello");
//    cout << a[0] << endl;
//    a[0] = 'v';
//    cout << a[0] << endl;
//    //cout << a.add("ssss") << endl;;
//    string strc=a.add("ssss") = "ccccc";
//    cout << strc << endl;
//    const A ca("Hello");
//    cout << ca[0] << endl;
//    
//   
//
//}
//#include<iostream>
//#include<cstdio>
//using namespace std;
//int main() {
//    int m = 0123, n = 123;
//    printf("%o %o\n", m, n);
//    return 0;
//}
//#include <iostream>
//using namespace std;
//void func(char** m) {
//    ++m;
//    cout << *m << endl;
//}
//int main() {
//
//    static char* a[] = { "morning", "afternoon", "evening" };
//    char** p;
//    p = a;
//    func(p);
//    return 0;
//}

//int func(int x) {
//    int count = 0;
//    while (x)
//    {
//        count++;
//        x = x & (x - 1);//与运算
//    } 
//        return count;
//}
//int main()
//{
//    int a=func(9999);
//    cout << a << endl;
//}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//int main()
//{
//    int n = 0;
//    cin >> n;
//    vector<int> v;
//    v.resize(n + 1);
//    //v[n]=0;//此处是为了防止越界，不影响正确的判断
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> v[i];
//    }
//    int i = 0;
//    int count = 0;
//    while (i < n)
//    {
//        //进入非递减队列
//        if (v[i] < v[i + 1])
//        {
//            while (i < n && v[i] <= v[i + 1])
//            {
//                ++i;
//            }
//            count++;
//            ++i;
//        }
//        else if (v[i] == v[i + 1])//相等，i直接++
//        {
//            ++i;
//        }
//        else//进入非递增队列
//        {
//            while (i < n && v[i] >= v[i + 1])
//            {
//                ++i;
//            }
//            count++;
//            ++i;
//        }
//
//    }
//    cout << count << endl;
//
//    return 0;
//}

int MoreThanHalfNum_Solution(vector<int> numbers) {
    int count = 0;
    sort(numbers.begin(), numbers.end());
    int mid = numbers[numbers.size() / 2];
    for (auto& e : numbers)
    {
        if (e == mid)
        {
            count++;
        }
    }
    return (count > numbers.size() / 2) ? mid : 0;
 
}
//int main()
//{   
//    int arr[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
//    vector<int> v(arr,arr+sizeof(arr)/sizeof(int));
//    cout<<MoreThanHalfNum_Solution(v);
//}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int number;
    vector<int> v;
    int i = 0;
    while (i<4)
    {
        cin >> number;
        v.push_back(number);
        i++;
    }
    int A = (v[0] + v[2]) / 2;
    int B = (v[1] + v[3]) / 2;
    int C = B - v[1];
    int C1 = v[3] - B;
    if (C1 == C)
    {
        cout << A << " " << B << " " << C;
    }
    else
    {
        cout << "No" << endl;
    }


    // int C=(v[3]-v[1])/2;

    // int B1=(v[2]-v[0])/2;
    // if(B1==B)
    // {
    //     cout<<A<<" "<<B<<" "<<C;
    // }
    // else
    // {
    //     cout<<"No"<<endl;
    // }



}
// 64 位输出请用 printf("%lld")