#include<iostream>
#include <vector>
using namespace std;

/*����---����|�鲢*/

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
        srand(time(NULL));//����һ�����������
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

//�����е�k���Ԫ��O(n)
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
        if (c >= k) return quickSort(nums, right + 1, end, k);//��k���ֵ����c����
        else if (b + c >= k) return key;//��k���ֵ����b����
        else return quickSort(nums, begin, left - 1, k - b - c);//��k���ֵ����a����

    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));//����һ�����������
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



//�鲢
class Mergesort {
    vector<int> tmp;
public:
    vector<int> sortArray(vector<int>& nums)
    {
        tmp.resize(nums.size());
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    //�鲢���������ڶ������������
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

        //��ԭ����
        for (int i = left; i <= right; ++i)
        {
            nums[i] = tmp[i - left];
        }
    }
};


class �����е������ {
    int tmp[50001];
public:
    int MergeSort(vector<int>& nums, int begin, int end) {
        if (begin >= end) return 0;
        int mid = (begin + end) / 2;
        int ret = 0;
        //����ѡ����ߵĸ���+����+����ѡ���ұߵĸ���+����
        ret += MergeSort(nums, begin, mid);
        ret += MergeSort(nums, mid + 1, end);
        //�鲢[begin,mid],[mid+1,end]
        int begin1 = begin, end1 = mid;

        int begin2 = mid + 1, end2 = end;

        //��һ������һ����ѡ����
        int i = 0;//ֻ�����tmp
        while (begin1 <= end1 && begin2 <= end2) {
            //��ͬ��β��
            if (nums[begin1] <= nums[begin2]) {
                tmp[i++] = nums[begin1++];
            }
            else {
                tmp[i++] = nums[begin2++];
                ret += end1 - begin1 + 1;//��ǰλ���Ѿ����벿�ֹ�������ԣ���ôbegin1����Ķ����Թ���
            }
        }
        //���ǰ����û����
        while (begin1 <= end1) {
            tmp[i++] = nums[begin1++];
        }
        //��������û����
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
    int tmp1[50001];//���ݺϲ�
    int tmp2[50001];//idx�ϲ�
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
                tmp2[i] = idx[cur2];//�±�����ƶ�
                ++i;
                ++cur2;
            }
            else
            {
                res[idx[cur1]] += right - cur2 + 1;//�ؼ�
                tmp1[i] = nums[cur1];
                tmp2[i++] = idx[cur1++];//�±�����ƶ�

            }
        }
        while (cur1 <= mid)
        {
            tmp1[i] = nums[cur1];
            tmp2[i++] = idx[cur1++];//�±�����ƶ�
        }
        while (cur2 <= right)
        {
            tmp1[i] = nums[cur2];
            tmp2[i++] = idx[cur2++];//�±�����ƶ�
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