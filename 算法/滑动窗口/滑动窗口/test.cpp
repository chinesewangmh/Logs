#include <iostream>
#include<vector>
using namespace std;


//������С��������
//int minSubArrayLen(int target, vector<int>& nums) {
//
//    int sum = 0, len = INT_MAX;
//    for (int left = 0, right = 0; right < nums.size(); ++right)
//    {
//        sum += nums[right];//�ұ߽�����
//        while (sum >= target)
//        {
//            len = min(len, right - left + 1);//���½��
//            sum -= nums[left];//��߳�����
//            left++;
//        }
//    }
//    return len == INT_MAX ? 0 : len;
//}
//
//
////���ظ�����Ӵ�
//int lengthOfLongestSubstring(string s) {
//    int left = 0, right = 0, n = s.size();
//    int hash[128] = { 0 };
//    int ret = 0;
//    while (right < n)
//    {
//        hash[s[right]]++;//������
//        while (hash[s[right]] > 1)//�ж�
//        {
//            hash[s[left]]--;//������
//            left++;//������߽�
//        }
//        ret = max(ret, right - left + 1);//���½��
//        right++;
//    }
//    return ret;
//}
//
//int lengthOfLongestSubstring(string s) {
//    int left = 0, right = 0, n = s.size();
//    int ret = 0;
//
//    for (int i = 0; i < n; ++i)
//    {
//        int hash[128] = { 0 };
//        for (int j = i; j < n; ++j)
//        {
//            hash[s[j]]++;
//            if (hash[s[j]] > 1) break;
//            ret = max(ret, j - i + 1);
//        }
//    }
//    return ret;
//}



//int longestOnes(vector<int>& nums, int k) {
//    //ת���ɣ��󲻳���k��0���������
//    int ret = 0, left = 0, right = 0;
//    int n = nums.size();
//    int zero = 0;
//    while (right < n)
//    {
//        if (nums[right] == 0) zero++; //����
//
//        while (zero > k)//�ж�
//        {
//            if (nums[left++] == 0) zero--;//������
//        }
//
//        ret = max(ret, right - left + 1);
//
//        right++;//������
//    }
//    return ret;
//}

int longestOnes(vector<int>& nums, int k) {
    int ret = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        int zero = 0;
        for (int j = i; j < n; j++)
        {
            if (nums[j] == 0) zero++;
            if (zero > k) break;
            ret = max(ret, j - i + 1);
        }
    }
    return ret;
}
int main()
{
   // lengthOfLongestSubstring("deabcabca");
    vector<int> v = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };
    cout<<longestOnes(v,3);
}