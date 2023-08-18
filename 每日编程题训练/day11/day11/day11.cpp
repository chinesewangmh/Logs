#include<iostream>
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

除自身以外数组的乘积

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
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    vector<int> dpf(n, 1);//前缀积
    vector<int> dpg(n, 1);//后缀积

    //dpf(i):[0,i-1]乘积
    //dpg(i):[i+1,n-1]
    for (int i = 1; i < n; ++i)
    {
        dpf[i] = dpf[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; --i)
    {
        dpg[i] = dpg[i + 1] * nums[i + 1];
    }

    //使用前缀和数组
    //
    vector<int> res(n);
    for (int i = 0; i < n; ++i)
    {
        res[i] = dpf[i] * dpg[i];
    }
    return res;
}