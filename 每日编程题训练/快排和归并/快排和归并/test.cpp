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
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int x) : val(x), next(NULL) {}
//    ListNode(ListNode*& node)
//    {
//        next = node->next;
//        val = node->val;
//    }
//};
//int main()
//{
//    vector<int> nums = { 3,2,3,1,2,4,5,5,6 };
//    /*sortColors(nums);*/
//    //Solution().sortArray(nums);
//    Qsort().findKthLargest(nums,4);
//	return 0;
//}



//归并
class Mergesort {
    vector<int> tmp;
public:
    vector<int> sortArray(vector<int>& nums)
    {
        tmp.resize(nums.size());
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    //归并排序类似于二叉树后序遍历
    void mergeSort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;
        int mid = (left + right) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        int cur1 = left, cur2 = mid + 1, i = 0;
        while (cur1 <= mid && cur2 <= right)
        {
            tmp[i++] = nums[cur1] <= nums[cur2] ? nums[cur1++] : nums[cur2++];
        }
        while (cur1 <= mid) tmp[i++] = nums[cur1++];
        while (cur2 <= right) tmp[i++] = nums[cur2++];

        //还原数据
        for (int i = left; i <= right; ++i)
        {
            nums[i] = tmp[i - left];
        }
    }
};


class 数组中的逆序对 {
    int tmp[50001];
public:
    int MergeSort(vector<int>& nums, int begin, int end) {
        if (begin >= end) return 0;
        int mid = (begin + end) / 2;
        int ret = 0;
        //先挑选出左边的个数+排序+再挑选出右边的个数+排序
        ret += MergeSort(nums, begin, mid);
        ret += MergeSort(nums, mid + 1, end);
        //归并[begin,mid],[mid+1,end]
        int begin1 = begin, end1 = mid;

        int begin2 = mid + 1, end2 = end;

        //左一个，右一个挑选个数
        int i = 0;//只针对与tmp
        while (begin1 <= end1 && begin2 <= end2) {
            //等同于尾插
            if (nums[begin1] <= nums[begin2]) {
                tmp[i++] = nums[begin1++];
            }
            else {
                tmp[i++] = nums[begin2++];
                ret += end1 - begin1 + 1;//当前位置已经与后半部分构成逆序对，那么begin1后面的都可以构成
            }
        }
        //如果前半组没走完
        while (begin1 <= end1) {
            tmp[i++] = nums[begin1++];
        }
        //如果后半组没走完
        while (begin2 <= end2) {
            tmp[i++] = nums[begin2++];
        }

        for (int j = begin; j <= end; ++j)
        {
            nums[j] = tmp[j - begin];
        }
        return ret;

    }
    int reversePairs(vector<int>& nums) {

        return MergeSort(nums, 0, nums.size() - 1);
    }
};


class Solution {
    int tmp1[50001];//数据合并
    int tmp2[50001];//idx合并
    vector<int> idx;
    vector<int> res;
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        res.resize(nums.size());
        idx.resize(nums.size());

        for (int i = 0; i < nums.size(); ++i) idx[i] = i;
        Mergesort(nums, 0, nums.size() - 1);
        return res;
    }

    void Mergesort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;
        int mid = (left + right) / 2;
        Mergesort(nums, left, mid);
        Mergesort(nums, mid + 1, right);
        int cur1 = left, cur2 = mid + 1;
        int i = 0;
        while (cur1 <= mid && cur2 <= right)
        {
            if (nums[cur1] <= nums[cur2])
            {
                tmp1[i] = nums[cur2];
                tmp2[i] = idx[cur2];//下标跟着移动
                ++i;
                ++cur2;
            }
            else
            {
                res[idx[cur1]] += right - cur2 + 1;//关键
                tmp1[i] = nums[cur1];
                tmp2[i++] = idx[cur1++];//下标跟着移动

            }
        }
        while (cur1 <= mid)
        {
            tmp1[i] = nums[cur1];
            tmp2[i++] = idx[cur1++];//下标跟着移动
        }
        while (cur2 <= right)
        {
            tmp1[i] = nums[cur2];
            tmp2[i++] = idx[cur2++];//下标跟着移动
        }
        for (int j = left; j <= right; ++j)
        {
            nums[j] = tmp1[j - left];
            idx[j] = tmp2[j - left];
        }

    }
};
int main()
{
    vector<int> nums{ 5,2,3,1 };
    Mergesort().sortArray(nums);
}