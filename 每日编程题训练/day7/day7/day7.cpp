#include <iostream>

using namespace std;

//int main(void)
//{
//http://www.taobao.com
//	
//	cout << "welcome to taobao" << endl;
//	goto http;
//	return 0;
//}

// write your code here cpp
#include<iostream>
#include<string>
using namespace std;

//int main()
//{
//    string str;
//    while (getline(cin, str))
//    {
//        for (auto& s : str)
//        {
//            if (s + 5 > 'Z')
//            {
//                s = 'A' + 4 - 'Z' - s;
//            }
//            else
//            {
//                s += 5;
//            }
//        }
//        cout << str << endl;
//    }
//    return 0;
//}


void test()
{
    int n, cnt;
    while (cin >> n)
    {
        cnt = 0;
        for (int i = 2; i <= sqrt(n); ++i)
        {
            if (n % i == 0)
            {
                while (n % i == 0)
                    n /= i;
                cnt++;
            }
            
        }
        if (n != 1)
            cnt++;
        cout << cnt << endl;
    }
}

#include <vector>
bool isPrim(int n)
{
    if (n < 2) return false;
    for (int i=2;i<=sqrt(n);++i)
    {
        if (n % i == 0) 
            return false; 
    }
    return true;
}
//vector<int> Primset(vector<int>& v)
//{
//    
//    for (int i=2;i<=10000;++i)
//    {
//        if (isPrim(i))
//            v.push_back(i);
//    }
//}
void Test()
{

    int n, cnt;
    while (cin >> n)
    {
        cnt = 0;
       vector<int> v;
       for(int i=1;i<=sqrt(n);++i)
       {
           if (n % i == 0)
           {
               v.push_back(i);
               v.push_back(n/i);
           }
       }
       for (int i=0;i<v.size();++i)
       {
           if (isPrim(v[i]))
               cnt++;
       }
       cout << cnt << endl;
    }
}



int main()
{
    Test();
}





//int main()
//{
//	int n, k, i;
//	while (cin >> n) {
//		k = 0;
//		for (i = 2; i <= sqrt(n); i++) {
//			if ((n % i) == 0) {
//				while ((n % i) == 0) {
//					n = n / i;
//				} 
//				k++;
//			}
//		} 
//		if(n != 1)
//			k++;
//		cout << k << endl;
//	}
//    
//}