#include <iostream>
#include <vector>
using namespace std;




/// <summary>
/// / ����������
/// </summary>
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        //dp[i]:��iλ��Ԫ��Ϊ��β����������������
//        int m = nums.size();
//        vector<int> dp(m + 1);
//
//        //��ʼ��
//        //dp[0]=0;
//
//        //���
//        int ret = INT_MIN;
//        for (int i = 1; i <= m; ++i)
//        {
//            //dp[i] ��������ֻ�����Լ�  nums[i]
//            //      ��������Ԫ�ش���1��dp[i-1]+nums[i]
//            dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
//            ret = max(ret, dp[i]);
//        }
//
//        return ret;
//    }
//};

//class Solution {
//public:
//    //����˼·������������Ϊ�м�����ˣ�max({�����ܺ�-��С������},���������)
//    int maxSubArray(vector<int>& nums) {
//        //dpf[i]:��iλ��Ԫ��Ϊ��β����������������
//        //dpg[i]:��iλ��Ԫ��Ϊ��β��������������С��
//        int m = nums.size();
//        vector<int> dpf(m + 1);
//        auto dpg = dpf;
//        //��ʼ��
//        //dpf[0]=dpg[0]=0;
//
//        //���
//        int ret = INT_MIN;
//        int cur = INT_MAX;
//        int sum = 0;
//        for (int i = 1; i <= m; ++i)
//        {
//            sum += nums[i - 1];
//            //dp[i] ��������ֻ�����Լ�  nums[i]
//            //      ��������Ԫ�ش���1��dp[i-1]+nums[i]
//            dpf[i] = max(nums[i - 1], dpf[i - 1] + nums[i - 1]);
//            dpg[i] = min(nums[i - 1], dpg[i - 1] + nums[i - 1]);
//            ret = max(ret, dpf[i]);
//            cur = min(cur, dpg[i]);
//        }
//        //���⴦����������ȫ�Ǹ���������dpf�����ֵ
//        if (sum == cur) return ret;
//
//        //���ء�dpf���ֵ���롾�����ܺͼ�ȥdpg��Сֵ�������ֵ
//        return max(ret, sum - cur);
//    }
//    int maxSubarraySumCircular(vector<int>& nums) {
//        return maxSubArray(nums);
//    }
//};

#include <algorithm>
//class Solution {
//public:
//    int maxProduct(vector<int>& nums) {
//        int m = nums.size();
//
//        vector<int> dpf(m + 1);
//        auto dpg = dpf;
//        dpf[0] = dpg[0] = 1;
//
//        int ret = INT_MIN;
//        for (int i = 1; i <= m; ++i)
//        {
//            dpf[i] = max(nums[i - 1], max(dpf[i - 1] * nums[i - 1], dpg[i - 1] * nums[i - 1]));
//            dpg[i] = min(nums[i - 1], min(dpf[i - 1] * nums[i - 1], dpg[i - 1] * nums[i - 1]));
//            ///ret = max(ret, dpf[i]);
//        }
//        return *max_element(dpf.begin()+1,dpf.end());
//        //return ret;
//    }
//};
//class Solution {
//public:
//    //dpf[i]:��iλ��Ϊ��β�����������˻�
//    //dpg[i]:��iλ��Ϊ��β����С������˻�
//    int maxProduct(vector<int>& nums) {
//        int m = nums.size();
//
//        vector<int> dpf(m + 1);
//        auto dpg = dpf;
//        dpf[0] = dpg[0] = 1;
//
//        int ret = INT_MIN;
//        for (int i = 1; i <= m; ++i)
//        {
//            //dpf[i] ������״̬{����Ϊ1�����ȴ���1}
//            //���ȴ���1���ֿ��Է�Ϊ��nums[i]����0����С��0
//            //С��0������Сֵ������0�������ֵ
//            dpf[i] = max(nums[i - 1], max(dpf[i - 1] * nums[i - 1], dpg[i - 1] * nums[i - 1]));
//            //ͬ��
//            dpg[i] = min(nums[i - 1], min(dpf[i - 1] * nums[i - 1], dpg[i - 1] * nums[i - 1]));
//            ret = max(ret, dpf[i]);
//        }
//
//        return ret;
//    }
//};

//class Solution {
//public:
//    //dpf[i]:��iΪ��β������������˻�Ϊ��������������󳤶�
//    //dpg[i]:��iΪ��β������������ɼ�Ϊ��������������󳤶�
//    int getMaxLen(vector<int>& nums) {
//
//        int m = nums.size();
//
//        vector<int> dpf(m + 1), dpg(m + 1);
//
//        dpf[0] = 0;
//        dpg[0] = 0;
//
//        int ret = INT_MIN;
//        for (int i = 1; i <= m; ++i)
//        {
//            //�����ԣ�Ҫ���Ƿ�Χ
//            // dpf[i]:max{nums[i-1]>0?1:0��dpf[i-1]+1,dpg[i-1]==0?0:dpg[i-1]+1));
//            // dpg[i]=max(nums[i-1]<0?1:0,max(dpf[i-1]+1,dpg[i-1]==0?0:dpg[i-1]+1));
//
//            if (nums[i - 1] > 0)
//            {
//                dpf[i] = dpf[i - 1] + 1;//max(nums[i-1]>0?1:0��dpf[i-1]+1)
//                dpg[i] = dpg[i - 1] == 0 ? 0 : dpg[i - 1] + 1;//max(nums[i-1]<0?1:0,dpg[i-1]==0?0:dpg[i-1]+1)
//            }
//            else if (nums[i - 1] < 0)
//            {
//                dpf[i] = dpg[i - 1] == 0 ? 0 : dpg[i - 1] + 1;
//                dpg[i] = dpf[i - 1] + 1;
//            }
//            ret = max(ret, dpf[i]);
//        }
//
//        return ret;
//
//    }
//};
//class Solution {
//public:
//    //dp[i]:��iλ��Ԫ��Ϊ��β�����еȲ��������
//    int numberOfArithmeticSlices(vector<int>& nums) {
//        int m = nums.size();
//
//        vector<int> dp(m);
//        //dp[0]=dp[1]=0
//
//        int ret = 0;
//        for (int i = 2; i < m; ++i)
//        {
//            //dp[i-1]+1  123 4 ==��234�ܹ���һ����1234Ҳ�ܹ���һ��������+1 
//            //dp[i-1]+1:ǰiλ��ǰһ��Ԫ��Ϊ��β�ĵȲ����鲹��iλ��Ԫ�ع���һ����iλ��Ԫ������ǰ�����ֹ���һ��
//            dp[i] = nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2] ? dp[i - 1] + 1 : 0;
//            ret += dp[i];//��������еȲ��������
//        }
//        return ret;
//    }
//};
//
//int main()
//{
//    vector<int> v{ -2,0,-1 };
//    //Solution().maxProduct(v);
//}


//
//template <typename config>
//class endpoint : public config::socket_type {
//};
//
////
//template <typename config>
//class server : public endpoint<connection<config>,config> {
//    /*��ʼ������������˼������ӵ�accept�¼�����*/
//    void start_accept();
//};
//template <typename config>
//class connection {};
//int main()
//{
//    char a = 128;
//    cout << a << endl;
//}

//class Solution {
//public:
//    //dpf[i]:��i��β�������������г��֡����������Ƶ���������鳤��
//    //dpg[i]:��i��β�������������г��֡��½������Ƶ���������鳤��
//
//    // dpf:arr[i-1]>arr[i]==>1   ����i��ʱ���Ѿ������½����ƣ�Ϊ������ֻ�ܵ���
//    //     arr[i-1]<arr[i]==>g[i-1]+1 ����i��ʱ��ǡ����������ֻ��Ҫ�õ�ǰi-1�½������ֵ+1
//    //     arr[i-1]=arr[i]==>1 ����
//    // dpg����ͬ��
//
//    int maxTurbulenceSize(vector<int>& arr) {
//        int m = arr.size();
//        if (m == 1) return 1;
//        //ȫ��ʼ��Ϊ1���������
//        vector<int> dpf(m, 1);
//        auto dpg = dpf;
//
//        int maxf = INT_MIN;
//        int maxg = INT_MIN;
//        for (int i = 1; i < m; ++i)
//        {
//            if (arr[i - 1] < arr[i])
//                dpf[i] = dpg[i - 1] + 1;
//            if (arr[i - 1] > arr[i])
//                dpg[i] = dpf[i - 1] + 1;
//
//            maxf = max(maxf, dpf[i]);
//            maxg = max(maxg, dpg[i]);
//
//        }
//        //���ؽ��������������ֵ
//        return max(maxf, maxg);
//    }
//};
#include <unordered_set>
class Solution {
public:
    //dp[i]:[0,i]������ַ����ܷ񱻵���ƴ�Ӷ���
    bool wordBreak(string s, vector<string>& wordDict) {
        //�Ż����������
        unordered_set<string> set;
        for (auto& s : wordDict) set.insert(s);

        int m = s.size();
        vector<bool> dp(m + 1);
        dp[0] = true;
        s = ' ' + s;

        //���
        //��Ϊj�����һ�������±�
        //���[0,j-1]�ܱ�ƴ�ӣ�����[j,i]����ַ��������ֵ��б��鵽����֤�����ַ����ɱ�ƴ��
        for (int i = 1; i <= m; ++i)
        {
            for (int j = i; j >= 1; --j)
            {
                if (dp[j - 1] && set.count(s.substr(j, i - j + 1)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[m];
    }
};

int main()
{
    string s = "leetcode";
    vector<string> wordDict = { "leet", "code" };
    Solution().wordBreak(s,wordDict);
}