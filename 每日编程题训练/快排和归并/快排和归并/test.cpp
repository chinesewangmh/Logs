#include<iostream>
#include <vector>
using namespace std;

/*分治---快排|归并*/

void sortColors(vector<int>& nums)
{
    int left = 0, right = nums.size() - 1;
    int cur = 0;
    while (cur <= right)
    {
        if (nums[cur] == 0)
            swap(nums[left++], nums[cur++]);
        else if (nums[cur] == 1)
        {
            ++cur;
        }
        else
        {
            swap(nums[cur], nums[right--]);
        }
    }
}

class Solution {
public:
    void quickSort(vector<int>& nums, int begin, int end)
    {
        if (begin >= end) return;

        int left = begin, right = end;
        int key = getTimeNum(nums, begin, end);

        int cur = begin;
        while (cur <= right)
        {
            if (nums[cur] < key)
            {
                swap(nums[left++], nums[cur++]);
            }
            else if (nums[cur] == key)
            {
                ++cur;
            }
            else
            {
                swap(nums[right--], nums[cur]);
            }
        }

        quickSort(nums, begin, left - 1);
        quickSort(nums, right + 1, end);
    }

    vector<int> sortArray(vector<int>& nums)
    {
        srand(time(NULL));//种下一个随机数种子
        int n = nums.size();
        quickSort(nums, 0, n - 1);
        return nums;
    }

    int getTimeNum(vector<int>& nums, int left, int right)
    {
        int r = rand();
        return nums[r % (right - left + 1) + left];
    }
};

//数组中第k大的元素O(n)
class TOPK {
public:
    void AdjustDown(vector<int>& a, int n, int parent) {
        int child = 2 * parent + 1;
        while (child < n)
        {
            if (child + 1 < n && a[child + 1] < a[child]) {
                child++;
            }
            if (a[child] < a[parent]) {
                swap(a[child], a[parent]);
                parent = child;
                child = 2 * parent + 1;
            }
            else  break;
        }
    }

    int findKthLargest(vector<int>& nums, int k)
    {
        int n = nums.size();
        for (int i = (k - 1 - 1) / 2; i >= 0; i--)
        {
            AdjustDown(nums, k, i);
        }

        for (int i = k; i < n; ++i)
        {
            if (nums[i] > nums[0])
            {
                swap(nums[0], nums[i]);
                AdjustDown(nums, k, 0);
            }
        }

        return nums[0];


    }
};
class Qsort {
public:

    int getTimeNum(vector<int>& nums, int left, int right)
    {
        int r = rand();
        return nums[r % (right - left + 1) + left];
    }

    int quickSort(vector<int>& nums, int begin, int end, int k)
    {
        if (begin == end) return nums[begin];
        int key = getTimeNum(nums, begin, end);
        int left = begin, right = end;
        int cur = begin;
        while (cur <= right)
        {
            if (nums[cur] > key)
            {
                swap(nums[right--], nums[cur]);
            }
            else if (nums[cur] < key)
            {
                swap(nums[left++], nums[cur++]);
            }
            else
                cur++;
        }
        // [begin,left-1][left,right][right+1,end]
        //      a             b             c
        int c = end - right, b = right - left + 1;
        if (c >= k) return quickSort(nums, right + 1, end, k);//第k大的值落在c区域
        else if (b + c >= k) return key;//第k大的值落在b区域
        else return quickSort(nums, begin, left - 1, k - b - c);//第k大的值落在a区域

    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));//种下一个随机数种子
        int n = nums.size();
        return quickSort(nums, 0, n - 1, k);

    }
};
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(ListNode*& node)
    {
        next = node->next;
        val = node->val;
    }
};
int main()
{
    vector<int> nums = { 3,2,3,1,2,4,5,5,6 };
    /*sortColors(nums);*/
    //Solution().sortArray(nums);
    Qsort().findKthLargest(nums,4);
	return 0;
}