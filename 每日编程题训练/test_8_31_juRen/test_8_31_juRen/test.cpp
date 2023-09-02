#include <iostream>  
#include <vector>  
#include <algorithm>
using namespace std;



//分发糖果，最接近的三数之和，跳跃游戏2
// 

//跳棋游戏

//bool canJump(vector<int>& nums) {
//    if (nums.size() == 1) return true;
//    if (nums[0] == 0) return false;
//    int n = nums.size();
//    //dp[i]:从【0，i】出发，最大可以跳的位置
//    vector<int> dp(n);
//    dp[0] = nums[0];
//    for (int i = 1; i < dp.size() - 1; ++i)
//    {
//        //从i出发：num[i]+i
//        //不从i：dp[i-1]
//        dp[i] = max(dp[i - 1], nums[i] + i);
//        //如果跳跃之后的位置位于最后一个或者之后，true
//        if (dp[i] >= nums.size() - 1)
//            return true;
//        //如果前i个位置最大只能到i，死锁，false    
//        if (dp[i] == i)
//            return false;
//    }
//
//    return true;
//}
////贪心
//bool canJump(vector<int>& nums) {
//
//    int n = nums.size();
//    int target = 0;
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        if (i <= target)
//        {
//            target = max(target, nums[i] + i);
//            //如果跳跃之后的位置位于最后一个或者之后，true
//            if (target >= nums.size() - 1)
//                return true;
//        }
//        else
//            break;
//    }
//
//    return false;
//}
//
//
///*跳跃游戏2*/
//
////贪心
//int jump(vector<int>& nums)
//{
//    int n = nums.size();
//    int maxPos = 0, cnt = 0, end = 0;
//
//    //遍历数组的时候，不访问最后一个元素，如果end是最后一个元素位置，会多加一次访问
//    for (int i = 0; i < n - 1; ++i)
//    {
//        if (i <= maxPos)
//        {
//            maxPos = max(maxPos, nums[i] + i);
//            if (i == end)
//            {
//                end = maxPos;
//                ++cnt;
//            }
//        }
//    }
//    return cnt;
//}
//
//
//
////dp
//int jump(vector<int>& nums) {
//    int n = nums.size();
//    vector<int> dp(n, 0x3f3f3f3f);
//    dp[0] = 0;
//    for (int i = 1; i < n; ++i)
//    {
//        for (int j = 0; j < i; ++j)
//        {
//            if (j + nums[j] >= i)
//                // dp[i]=min(dp[i],dp[j]+1);
//            {
//                dp[i] = dp[j] + 1;
//                break;//选取最左边的j，使其能调到i
//            }
//        }
//    }
//
//    return dp[n - 1];
//}

//分糖果2
vector<int> distributeCandies(int candies, int num_people) {
    vector<int> v(num_people);
    int i = 0;
    while (candies > 0)
    {
        v[i % num_people] += min(candies, i + 1);
        candies -= min(candies, i + 1);
        ++i;
    }

    return v;
}
//分发糖果
int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> left(n, 1);
    vector<int> right(n, 1);
    //左规则
    for (int i = 1; i < n; ++i)
    {
        if (ratings[i] > ratings[i - 1])
            left[i] = left[i - 1] + 1;
    }
    int res = 0;
    //右规则
    for (int i = n - 1; i >= 0; --i)
    {
        if (i<n - 1 && ratings[i]>ratings[i + 1])
            right[i] = right[i + 1] + 1;

        res += max(left[i], right[i]);
    }

    return res;
}

//最接近的三数之和
int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    //1.排序
    sort(nums.begin(), nums.end());
    //2.固定i值
    int res = 0x3f3f3f3f;
    int result = 0;
    for (int i = 0; i < n - 2;)
    {
        //双指针查找符合的j k
        int left = i + 1, right = n - 1;
        int sum = 0;
        while (left < right)
        {
            sum = nums[left] + nums[right] + nums[i];
            if (sum < target)
            {
                left++;
                while (left < right && nums[left] == nums[left - 1]) left++;
            }
            else if (sum > target)
            {
                right--;
                while (left < right && nums[right] == nums[right + 1]) right--;
            }
            else
            {
                return target;
            }
            int diff = abs(target - sum);
            res = min(res, diff);
            if (res == diff)
                result = sum;
        }
        //3.一轮结束，更新，并且对i去重
        ++i;
        while (i < n && nums[i] == nums[i - 1]) ++i;
    }

    return result;
}

#include <functional>
class A
{
public:
    A(int a) { _num = a; }
    void a(int a)
    {
        cout << _num + a << endl;
    }
    int _num;
};
int main()
{
    /*vector<int> nums = { 2,3,8,9,10 }; int target = 16;
    threeSumClosest(nums, target);*/
    A a(1);
    auto&& f4 = std::bind(&A::a,&a, std::placeholders::_1);
    f4(5);
}