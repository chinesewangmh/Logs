#include <iostream>
#include<vector>
using namespace std;


//长度最小的子数组
//int minSubArrayLen(int target, vector<int>& nums) {
//
//    int sum = 0, len = INT_MAX;
//    for (int left = 0, right = 0; right < nums.size(); ++right)
//    {
//        sum += nums[right];//右边进窗口
//        while (sum >= target)
//        {
//            len = min(len, right - left + 1);//更新结果
//            sum -= nums[left];//左边出窗口
//            left++;
//        }
//    }
//    return len == INT_MAX ? 0 : len;
//}
//
//
////不重复的最长子串
//int lengthOfLongestSubstring(string s) {
//    int left = 0, right = 0, n = s.size();
//    int hash[128] = { 0 };
//    int ret = 0;
//    while (right < n)
//    {
//        hash[s[right]]++;//进窗口
//        while (hash[s[right]] > 1)//判断
//        {
//            hash[s[left]]--;//出窗口
//            left++;//更新左边界
//        }
//        ret = max(ret, right - left + 1);//更新结果
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
//    //转化成：求不超过k个0的最长子数组
//    int ret = 0, left = 0, right = 0;
//    int n = nums.size();
//    int zero = 0;
//    while (right < n)
//    {
//        if (nums[right] == 0) zero++; //条件
//
//        while (zero > k)//判断
//        {
//            if (nums[left++] == 0) zero--;//出窗口
//        }
//
//        ret = max(ret, right - left + 1);
//
//        right++;//进窗口
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


int minOperations(vector<int>& nums, int x) {
    //转换成求最长连续子数组问题
    int n = nums.size();
    int sum = 0;//数组总和
    for (auto e : nums)
        sum += e;
    int target = sum - x;//最长子数组之和

    if (target < 0) return -1;//查找子数组之和为负数，不符合

    int left = 0, right = 0, tmp = 0;//临时子数组之和
    int len = -1;//临时子数组长度
    while (right < n)
    {
        tmp += nums[right];//进窗口
        while (tmp > target)//判断
        {
            tmp -= nums[left++];//出窗口
        }
        if (tmp == target)
            len = max(len, right - left + 1);//更新结果
        ++right;
    }

    return len == -1 ? -1 : n - len;
}


int totalFruit(vector<int>& fruits) {

    int ret = 0;
    for (int i = 0; i < fruits.size(); ++i)
    {
        int  mp[100001] = { 0 };
        int cnt = 0;//计数器
        for (int j = i; j < fruits.size(); ++j)
        {
            if (mp[fruits[j]] == 0) cnt++;
            // mp[fruits[j]]++;
            if (cnt > 2) break;

            ret = max(ret, j - i + 1);
        }

    }
    return ret;
}
int main()
{
   // lengthOfLongestSubstring("deabcabca");
    vector<int> v = { 1,2,1 };
    cout<< totalFruit(v);
}