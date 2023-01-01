#define  _CRT_SECURE_NO_WARNINGS 1

///����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�


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
    //�Ҳ�������low����ʱ��low>high
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
    //��Ϊ����ֵ�������ͷ�
    return newnode;
}


/////////////10

//������ת��������
int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    int mid = 0;
    while (left <= right) {
        mid = (right + left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        //ǰ����Ƿ�����
        if (nums[0] <= nums[mid]) {
            if (nums[0] <= target && target < nums[mid]) {//t��ǰ���
                right = mid - 1;
            }
            else {//t�ں���
                left = mid + 1;
            }
        }
        else {//����
            if (nums[mid] < target && target <= nums[numsSize - 1]) {//t��nums[mid]�ұ�
                left = mid + 1;
            }
            else {//t�ں��Σ���t��nums[mid]��ߣ�����t��ǰ���
                right = mid - 1;
            }
        }
    }
    return -1;
}


//
// 
// ����������ת����
//��ת����
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