#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        int n = nums.size();
//        priority_queue<pair<int, int>> q;
//        for (int i = 0; i < k; ++i) {
//            q.emplace(nums[i], i);
//        }
//        vector<int> ans = { q.top().first };
//        for (int i = k; i < n; ++i) {
//            q.emplace(nums[i], i);
//            while (q.top().second <= i - k) {
//                q.pop();
//            }
//            ans.push_back(q.top().first);
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        int n = nums.size();
//        deque<int> q;
//        for (int i = 0; i < k; ++i) {
//            while (!q.empty() && nums[i] >= nums[q.back()]) {
//                q.pop_back();
//            }
//            q.push_back(i);
//        }
//
//        vector<int> ans = { nums[q.front()] };
//        for (int i = k; i < n; ++i) {
//            while (!q.empty() && nums[i] >= nums[q.back()]) {
//                q.pop_back();
//            }
//            q.push_back(i);
//            while (q.front() <= i - k) {
//                q.pop_front();
//            }
//            ans.push_back(nums[q.front()]);
//        }
//        return ans;
//    }
//};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> vResult;//存储滑动窗口最大值

        if (nums.size() >= k && k >= 1)
        {
            deque<int>  dq_index;//存储滑动窗口最大值的下标

            for (int i = 0; i < k; ++i)
            {
                while (!dq_index.empty() && nums[i] > nums[dq_index.back()])
                    dq_index.pop_back();

                dq_index.push_back(i);
            }
            vResult.push_back(nums[dq_index.front()]);
            for (int i = k; i < nums.size(); ++i)
            {
                while (!dq_index.empty() && nums[i] > nums[dq_index.back()])
                    dq_index.pop_back();

                dq_index.push_back(i);

                if (!dq_index.empty() && (i - dq_index.front()) >= k)//当前处理的数据下标与最大值对应下标之差超过滑动窗口大小，删除！
                {
                    dq_index.pop_front();
                }

                vResult.push_back(nums[dq_index.front()]);

            }
        }
        return vResult;
    }
};

int main()
{
    vector<int> v{ 2,3,4,2,6,2,5,1 };
    int k = 3;
    Solution().maxSlidingWindow(v,k);
}



class MaxQueue {
public:
    MaxQueue() {

    }

    int max_value() {
        return dq.empty() ? -1 : dq.front();
    }

    void push_back(int value) {

        while (!dq.empty() && dq.back() < value)
        {
            dq.pop_back();
        }

        dq.push_back(value);
        q.push(value);
    }

    int pop_front() {
        if (q.empty()) return -1;

        int result = q.front();
        if (q.front() == dq.front())
        {
            dq.pop_front();
        }
        q.pop();
        return result;
    }
private:
    deque<int> dq;
    queue<int>  q;
};

