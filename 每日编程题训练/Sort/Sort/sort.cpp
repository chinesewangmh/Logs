#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
//#include "heapSort.h"
//#include "insertSort.h"
#include "MergeSort.hpp"
using namespace std;


//
//int main()
//{
//	/*vector<int> v{ 9,1,4,6,5,2 };*/
//	//Headsort<greater<int>> hs(v);
//	//hs.headsort();
//	//hs.print();
//	/*int a[] = { 9,1,4,6,5,2 };
//	heapSortC(a,6);*/
//
//
//	//int  a[]={ 6, 1, 2, 7,6, 9, 3, 4, 5, 6, 8 };
//	//int n = sizeof(a) / sizeof(a[0]);
//	//insetSort(a,n);
//	//quickSort3(a,0,n-1);
//	int  a[] = { 10,6,7,1,3,9,4,2 };
//	int n = sizeof(a) / sizeof(a[0]);
//
//	MergeSort(a, n);
//}



//struct A{
//
//    int member1;
//    int member2;
//    int member3;
//    int member4;
//};
//
//int main()
//{
//    struct A a = {1,2,3,4};
//}

//Topk

//void adjustdown(vector<int>& arr, int parent, int n)
//{
//    int child = parent * 2 + 1;
//    while (child < n)
//    {
//        if (child + 1 < n && arr[child] < arr[child + 1])
//            child++;
//        if (arr[parent] < arr[child])
//        {
//            swap(arr[parent], arr[child]);
//            parent = child;
//            child = parent * 2 + 1;
//        }
//        else
//            break;
//    }
//}
//void make_Kheap(vector<int>& topk, int k)
//{
//    for (int i = (k - 1 - 1) / 2; i >= 0; i--) {
//        adjustdown(topk, k, i);
//    }
//
//}
//vector<int> topKFrequent(vector<int>& nums, int k) {
//    vector<int> topk(nums.begin(), nums.begin() + k);
//    make_Kheap(topk, k);
//    for (int i = k; i < nums.size(); ++i)
//    {
//        if (nums[i] < topk[0])
//            topk[0] = nums[i];
//        adjustdown(topk, 0, k);
//    }
//
//    vector<int> res;
//    for (auto e : topk)
//        res.push_back(e);
//
//    return res;
//}




//
//int _MergeSort(vector<int>& a, int begin, int end, vector<int>& tmp)
//{
//    if (begin >= end) {
//        return 0;
//    }
//    int mid = (begin + end) / 2;
//    //[begin, mid] [mid+1, end] 递归让子区间有序
//    int left = _MergeSort(a, begin, mid, tmp);
//    int right = _MergeSort(a, mid + 1, end, tmp);
//
//    //归并[begin,mid],[mid+1,end]
//    int begin1 = begin, end1 = mid;
//
//    int begin2 = mid + 1, end2 = end;
//    int i = begin;
//    while (begin1 <= end1 && begin2 <= end2) {
//        //等同于尾插
//        if (a[begin1] <= a[begin2]) {
//            tmp[i++] = a[begin1++];
//            //核心：当左边的数组移动时，需要考虑逆序对，即右边的数组当前位置相对于起始位置的偏移量
//            left += begin2 - (mid + 1);
//        }
//        else
//        {
//            tmp[i++] = a[begin2++];
//        }
//    }
//    //如果前半组没走完
//    while (begin1 <= end1) {
//        tmp[i++] = a[begin1++];
//        left += begin2 - (mid + 1);
//    }
//    //如果后半组没走完
//    while (begin2 <= end2) {
//        tmp[i++] = a[begin2++];
//    }
//    copy(tmp.begin() + begin, tmp.begin() + end + 1, a.begin() + begin);
//    return left + right;
//
//}
//int reversePairs(vector<int>& nums)
//{
//    vector<int> tmp(nums.size());
//
//    return _MergeSort(nums, 0, nums.size() - 1, tmp);
//}


#include <algorithm>
#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int m = 1000000007;
    int MergeSort(vector<int>& nums, vector<int>& tmp, int begin, int end) {
        if (begin >= end) return 0;
        int mid = (begin + end) / 2;
        int res = MergeSort(nums, tmp, begin, mid) + MergeSort(nums, tmp, mid + 1, end);
        res %= m;
        //归并[begin,mid],[mid+1,end]
        int begin1 = begin, end1 = mid;

        int begin2 = mid + 1, end2 = end;
        int i = begin;
        while (begin1 <= end1 && begin2 <= end2) {
            //等同于尾插
            if (nums[begin1] <= nums[begin2]) {
                tmp[i++] = nums[begin1++];
                res += (begin2 - (mid + 1)) % m;
            }
            else {
                tmp[i++] = nums[begin2++];
            }
        }
        //如果前半组没走完
        while (begin1 <= end1) {
            tmp[i++] = nums[begin1++];
            res += (begin2 - (mid + 1)) % m;
        }
        //如果后半组没走完
        while (begin2 <= end2) {
            tmp[i++] = nums[begin2++];
        }
        copy(tmp.begin() + begin, tmp.begin() + end + 1, nums.begin() + begin);
        return res % m;

    }
    int InversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        return MergeSort(nums, tmp, 0, nums.size() - 1);
    }
};

int main()
{
    //vector<int> v{ 1,3,2,3,1 };
    ////cout << reversePairs(v);
    //int a = 10;
    //int* p = &a;
    //cout << p << endl;
    //int* p1 = *&p;
    //cout << p1 << endl;

    //int* p2 = &*p1;
    //cout << p2 << endl;

    //int** p3 = &p;
    //cout << p3 << endl;

    

}


