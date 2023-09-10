#include<iostream>
#include <vector>
using namespace std;


#include <cmath>
#include <unordered_map>
#include <vector>


//�������� 1 1 2 5 14 42
///  1/(n+1)* C(n,2n)
// 
const int MOD = 1e9 + 7;
void fun(unordered_map<int, int>& mp)
{
    for (int i = 1; i <= 12; ++i)
    {
        int key = pow(2, i) - 1;
        mp[key]++;
    }

}

int cntOfTrees(int n) {
    // write code here
    if (n % 2 == 0)
        return 0;


    vector<long long> arr(n+1);
    arr[1] = 1;
    arr[3] = 1;
    unordered_map<int, int> mp;
    fun(mp);
    for (int i = 5; i < n+1; i += 2)
    {
        //Ҷ�ӽڵ���
        int prev = i - 2;
        int n0 = (prev - 1) / 2 + 1;

        if (i % 2 != 0)
            arr[i] = ((arr[i - 2])%MOD * n0%MOD)%MOD;
        //��������������ڵ�
        if (mp.count(i) > 0)
        {
            arr[i]--;
        }
    }
    return arr[n];
}


//const int MOD = 1e9 + 7;
//bool Isnum(int i)
//{
//    string str = to_string(i);
//    int count = 0;
//    for (int i = 0; i < str.size(); ++i)
//    {
//        if (str[i] != '0')
//            count++;
//    }
//    return count == 1;
//}
//int perfectPair(vector<int>& arr) {
//    int n = arr.size();
//    vector<int> v(n);
//
//    for (int i = 1; i < n; ++i)
//    {
//        for (int j = 0; j < i; ++j)
//        {
//            int num = ((arr[j] % MOD) * (arr[i] % MOD)) % MOD;
//            if (Isnum(num))
//                v[i]++;
//        }
//    }
//    int sum = 0;
//    for (auto e : v)
//    {
//        sum += e;
//    }
//    return sum;
//}
//};

int numTrees(int m)
{
    if (m % 2 == 0) return 0;
    int n = (m - 1) / 2;
    //dp[i]:�ڵ���Ϊi�� ��ɶ����������ķ�����
    vector<long long> dp(n + 1);
    dp[0] = 1;


    //���ѭ�����Ƽ����ڵ�
    for (int i = 1; i <= n; ++i)
    {
        //�ڲ�ѭ�����Ƹ��ڵ���˭
        for (int j = 1; j <= i; ++j)
        {
            dp[i] =(dp[i] + dp[j - 1] * dp[i - j])%MOD;
        }
    }
    return (int)dp[n];
}


int main()
{
    numTrees(191);
    
	return 0;
}