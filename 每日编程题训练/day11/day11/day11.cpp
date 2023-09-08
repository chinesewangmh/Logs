#include<iostream>
#include<unordered_map>
#include <vector>
using namespace std;
//寻找数组的中心下标
int pivotIndex(vector<int>& nums) {
    int n = nums.size();

    vector<int> dpf(n), dpg(n);

    //dpf(i)：[0,i-1]数组之和
    //dpg(i):[i+1,n-1]数组之和
    for (int i = 1; i < n; ++i)//前缀和
    {
        dpf[i] = dpf[i - 1] + nums[i - 1];
    }
    for (int i = n - 2; i >= 0; --i)//后缀和
    {
        dpg[i] = dpg[i + 1] + nums[i + 1];
    }

    //使用数组
    for (int i = 0; i < n; ++i)
    {
        if (dpf[i] == dpg[i])
            return i;
    }
    return -1;
}

//除自身以外数组的乘积

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    vector<int> res(n);
    res[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        res[i] = res[i - 1] * nums[i - 1];
    }

    int R = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        res[i] *= R;
        R *= nums[i];
    }
    return res;
}

//方法二
//vector<int> productExceptSelf(vector<int>& nums) {
//    int n = nums.size();
//
//    vector<int> dpf(n, 1);//前缀积
//    vector<int> dpg(n, 1);//后缀积
//
//    //dpf(i):[0,i-1]乘积
//    //dpg(i):[i+1,n-1]
//    for (int i = 1; i < n; ++i)
//    {
//        dpf[i] = dpf[i - 1] * nums[i - 1];
//    }
//    for (int i = n - 2; i >= 0; --i)
//    {
//        dpg[i] = dpg[i + 1] * nums[i + 1];
//    }
//
//    //使用前缀和数组
//    //
//    vector<int> res(n);
//    for (int i = 0; i < n; ++i)
//    {
//        res[i] = dpf[i] * dpg[i];
//    }
//    return res;
//}

int subarraySum(vector<int>& nums, int k) {
    //前缀和，出现次数
    unordered_map<int, int> hash;
    hash[0] = 1;//特殊处理【0，i】恰好为K，需要在[0,-1]找0出现的次数

    //sum:前缀和
    int sum = 0, res = 0;

    for (auto n : nums)
    {
        sum += n;
        //在遍历的时候，i位置表示：哈希表每次存放的是[0,i-1]的前缀和
        //查找在[0,i-1]中sum-k出现的次数，即前缀和为sum-k
        if (hash.count(sum - k)) res += hash[sum - k];
        hash[sum]++;
    }

    return res;
}

int subarraysDivByK(vector<int>& nums, int k) {
    //当遍历到某一个位置时，对当前位置前缀和取余，
    //然后从前面的前缀和余数和数组中，找是否出现当前余数等于前面余数的
    //前缀和的余数为：出现的次数
    unordered_map<int, int> hash;
    hash[0 % k] = 1;

    int sum = 0, res = 0;
    for (auto e : nums)
    {
        sum += e;
        // 注意 C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正 
        int mod = (sum % k + k) % k;
        if (hash.count(mod) )res += hash[mod];
        hash[mod]++;
    }

    return res;
}

class A
{
public:
    A() { cout << "a"; }
    virtual ~A() { cout << "~a"; }
};
class B
{
public:
    B() { cout << "b"; }
    virtual ~B() { cout << "~b"; }
};

class C :public  B,public A
{
public:
    C(){ cout << "c"; }
    ~C(){ cout << "~c"; }
    //A a;
};

//int main()
//{
//    /*int a = (-3 % 5+5)%5;
//    cout << a;*/
//   // C c; //bac ~c~a~b
//    //uint8_t* p1 = reinterpret_cast<uint8_t*>(0x801000);
//    //uint32_t* p2 = reinterpret_cast<uint32_t*>(0x801000);
//    //cout << p1 + 5 << "   " <<p2 + 5 << endl;
//
//    /*uint8_t* p1 = reinterpret_cast<uint8_t*>(0x801000);
//    uint32_t* p2 = reinterpret_cast<uint32_t*>(0x802000);
//    cout << reinterpret_cast<uintptr_t>(p1 + 5) << "   " << reinterpret_cast<uintptr_t>(p2) + 5 << endl;*/
//    
//    //uint8_t* p1 = reinterpret_cast<uint8_t*>(0x801000);
//    //cout << p1 << endl;
//    uint32_t* p2 = reinterpret_cast<uint32_t*>(0x802000);
//    cout << p2 << endl;
//    cout << p2+5 << endl;
//
//    //cout << p1 + 5 << "   " << p2 + 5 << endl;
//    int a = 10;
//    int* pa = &a;
//    cout << pa << endl;
//
//    int* new_pa = pa + 5;
//    cout << new_pa << endl;
//
//    return 0;
//}



int main()
{
    char arr[] = "dasda";
    char arr2[10] = "dasda";
    cout << sizeof(arr2)<<endl;
    char arr3[3] = {'0','1','2'};
    cout << sizeof(arr3) << endl;

    //char arr4[2] = { '0','1','2' };//编译时出错
    
    cout<<strcmp(arr,arr2);

    
}
