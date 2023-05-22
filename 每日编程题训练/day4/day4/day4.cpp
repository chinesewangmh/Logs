//// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;
//
//void number(vector<int>& v)
//{
//
//    v.push_back(1);
//    v.push_back(1);
//    for (int i = 2; i <= 10000; ++i)
//    {
//        v.push_back((v[i - 2] + v[i - 1]) % 10000);
//    }
//}
//
//int main()
//{
//    int n;
//    vector<int> v;
//    number(v);
//    while (cin >> n)
//    {
//        int i;
//
//        while (n--)
//        {
//            cin >> i;
//            printf("%04d", v[i]);
//        }
//        cout << endl;
//    }
//}
//
//// write your code here cpp
//#include <iostream>
//using namespace std;
//
//int Rootnum(int n)
//{
//    int rootnum = 0;
//    while (n)
//    {
//        rootnum += n % 10;
//        n /= 10;
//    }
//    if (rootnum > 9)
//        return Rootnum(rootnum);
//
//    return rootnum;
//}
//
//int main()
//{
//    string n;
//    while (cin >> n)
//    {
//        int sum = 0;
//        //防止输入数字过大
//        for (auto& e : n)
//        {
//            sum += e - '0';
//        }
//        cout << Rootnum(sum) << endl;
//    }
//
//    return 0;
//}

class A
{
public:
	void Init()
	{
		test(10);
		
	}
	void test(int n)
	{
		cout << n << endl;
	}

	int member_var;
};

#include<iostream>

using namespace std;

//int main()
//{
//	double  n, r;
//	while (cin >> n >> r)
//	{
//		if (n <= 3.14 * r * 2)
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//	return 0;
//}

int main()
{
	/*int arr1[]= { 1,2 };
	int arr2[] = {1,2,3};

	cout << std::equal(begin(arr1),end(arr1),begin(arr2));*/

	int a = 10;
	double b = 10.000000001;

	bool bl = a < b;
	cout << bl;

}


int