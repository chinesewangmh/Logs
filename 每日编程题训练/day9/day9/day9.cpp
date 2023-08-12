#include <iostream>
#include <vector>
using namespace std;

https://leetcode.cn/problems/peak-index-in-a-mountain-array/description/
int peakIndexInMountainArray(vector<int>& arr) {//���ֲ����Ҷ˵�
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

int findPeakElement(vector<int>& nums) {//������˵�
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        //���ұ���-�ޣ��������ұ�һ�����ڷ嶥
        if (nums[mid] < nums[mid + 1]) left = mid + 1;

        //nums[mid]>nums[mid+1],��Ϊ�������-�ޣ�����һ�����ڷⶥ���ұ߲�һ��
        else right = mid;
    }
    return left;
}



//������˵㣺���Ϊ��׼
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

//������˵㣺�ұ�Ϊ��׼
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