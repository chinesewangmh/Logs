#define  _CRT_SECURE_NO_WARNINGS 1

///给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。


int searchInsert(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] < target) {
            low = mid + 1;
        }
        else if (nums[mid] > target) {
            high = mid - 1;
        }
        else
            return mid;
    }
    //找不到返回low，此时的low>high
    return low;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* newnode = (int*)malloc(sizeof(int) * numsSize);
    int i = 0;
    for (i = 0; i < numsSize; i++) {
        if (i == 0) {
            newnode[i] = nums[i];
        }
        else {
            newnode[i] = newnode[i - 1] + nums[i];
        }
    }
    //作为返回值，不能释放
    return newnode;
}


/////////////10

//搜索旋转排序数组
int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    int mid = 0;
    while (left <= right) {
        mid = (right + left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        //前半段是否有序
        if (nums[0] <= nums[mid]) {
            if (nums[0] <= target && target < nums[mid]) {//t在前半段
                right = mid - 1;
            }
            else {//t在后半段
                left = mid + 1;
            }
        }
        else {//后半段
            if (nums[mid] < target && target <= nums[numsSize - 1]) {//t在nums[mid]右边
                left = mid + 1;
            }
            else {//t在后半段，且t在nums[mid]左边，或者t在前半段
                right = mid - 1;
            }
        }
    }
    return -1;
}


//
// 
// 二进制链表转整数
//反转链表
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* rhead = NULL;
    while (cur) {
        struct ListNode* next = cur->next;
        cur->next = rhead;
        rhead = cur;
        cur = next;
    }
    return rhead;
}

int getDecimalValue(struct ListNode* head) {
    struct ListNode* rhead = reverseList(head);
    struct ListNode* cur = rhead;
    int sum = 0;
    int count = 0;
    while (cur) {
        sum += (cur->val) * pow(2, count);
        count++;
        cur = cur->next;
    }
    return sum;
}