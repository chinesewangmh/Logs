#include <iostream>
#include <vector>
using namespace std;




/// <summary>
/// / ����������
/// </summary>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //dp[i]:��iλ��Ԫ��Ϊ��β����������������
        int m = nums.size();
        vector<int> dp(m + 1);

        //��ʼ��
        //dp[0]=0;

        //���
        int ret = INT_MIN;
        for (int i = 1; i <= m; ++i)
        {
            //dp[i] ��������ֻ�����Լ�  nums[i]
            //      ��������Ԫ�ش���1��dp[i-1]+nums[i]
            dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
            ret = max(ret, dp[i]);
        }

        return ret;
    }
};