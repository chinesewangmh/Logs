#include <iostream>
#include <vector>
using namespace std;

https://leetcode.cn/problems/peak-index-in-a-mountain-array/description/
int peakIndexInMountainArray(vector<int>& arr) {//二分查找右端点
    int left = 1, right = arr.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left + 1) / 2;
        if (arr[mid] > arr[mid - 1]) left = mid;
        else right = mid - 1;
    }
    return left;
}

https://leetcode.cn/problems/find-peak-element/description/

int findPeakElement(vector<int>& nums) {//二分左端点
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        //最右边是-∞，所以最右边一定存在峰顶
        if (nums[mid] < nums[mid + 1]) left = mid + 1;

        //nums[mid]>nums[mid+1],因为最左边是-∞，所以一定存在封顶，右边不一定
        else right = mid;
    }
    return left;
}



//二分左端点：左边为基准
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    //int target=nums[right];
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) left = mid + 1;
        else right = mid;
    }

    return nums[left];
}

//二分左端点：右边为基准
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    int target = nums[right];
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) left = mid + 1;
        else right = mid;
    }

    return nums[left];
}