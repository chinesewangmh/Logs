#include<iostream>
#include <vector>
using namespace std;
//Ѱ������������±�
int pivotIndex(vector<int>& nums) {
    int n = nums.size();

    vector<int> dpf(n), dpg(n);

    //dpf(i)��[0,i-1]����֮��
    //dpg(i):[i+1,n-1]����֮��
    for (int i = 1; i < n; ++i)//ǰ׺��
    {
        dpf[i] = dpf[i - 1] + nums[i - 1];
    }
    for (int i = n - 2; i >= 0; --i)//��׺��
    {
        dpg[i] = dpg[i + 1] + nums[i + 1];
    }

    //ʹ������
    for (int i = 0; i < n; ++i)
    {
        if (dpf[i] == dpg[i])
            return i;
    }
    return -1;
}

��������������ĳ˻�

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

//������
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    vector<int> dpf(n, 1);//ǰ׺��
    vector<int> dpg(n, 1);//��׺��

    //dpf(i):[0,i-1]�˻�
    //dpg(i):[i+1,n-1]
    for (int i = 1; i < n; ++i)
    {
        dpf[i] = dpf[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; --i)
    {
        dpg[i] = dpg[i + 1] * nums[i + 1];
    }

    //ʹ��ǰ׺������
    //
    vector<int> res(n);
    for (int i = 0; i < n; ++i)
    {
        res[i] = dpf[i] * dpg[i];
    }
    return res;
}