#define  _CRT_SECURE_NO_WARNINGS 1
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    *returnSize = arr1Size;
    int arr[1001] = { 0 };
    //统计arr1每个元素出现次数，并排序
    for (int i = 0; i < arr1Size; i++) {
        arr[arr1[i]]++;
    }

    //找arr1,arr2都有的元素
    int j = 0;//更新arr1数组
    for (int i = 0; i < arr2Size; i++) {
        while (arr[arr2[i]] > 0) {//arr中存在与arr2相等的元素，取出放进arr1中，arr中出现的次数-1
            arr1[j] = arr2[i];
            j++;
            arr[arr2[i]]--;
        }
    }

    //arr1与arr2不相等的元素
    for (int i = 0; i < 1001; i++) {
        while (arr[i] > 0) {
            //j=arr2Size
            arr1[j++] = i;
            arr[i]--;
        }
    }
    return arr1;
}
//奇偶树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define N 100001
bool isEvenOddTree(struct TreeNode* root) {
    //模拟队列
    struct TreeNode* qu[N];
    //定义头部尾部
    int head = 0, tail = 0;
    //入队
    qu[head++] = root;
    //判断奇偶层
    int level = 0;
    while (tail < head) {
        int size = head - tail;
        //，prev赋值，判断单调性
        int prev = level % 2 == 0 ? INT_MIN : INT_MAX;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = qu[tail++];
            int value = node->val;
            //判断奇数层是否是偶数，偶数层是否是奇数
            if (level % 2 == value % 2) {
                return false;
            }
            //偶数层，判断奇数是否递增；奇数层，判断偶数是否递减
            if ((level % 2 == 0 && value <= prev) || (level % 2 == 1 && value >= prev)) {
                return false;
            }
            //比较同层单调关系
            prev = value;
            //子节点进入队列
            if (node->left) {
                qu[head++] = node->left;
            }
            if (node->right) {
                qu[head++] = node->right;
            }
        }
        //去下一层
        level++;
    }
    return true;
}


char* sortSentence(char* s) {
    int len = strlen(s);
    //存储每个单词的指针
    char* arr[9];
    char* cur = s;
    //统计单词个数
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            count++;
            //保存单词索引值
            char c = s[i] - '0' - 1;
            //索引位置置0，切割成一个单词；
            s[i] = '\0';
            //根据单词索引存进指针数组
            arr[c] = cur;
            //更新到下一个单词
            cur = s + i + 2;
        }
    }
    char* newarr = (char*)malloc(len + 1);
    //初始化newarr
    memset(newarr, 0, len + 1);
    //放入新数组
    for (int i = 0; i < count; i++) {
        //不需要知道每个单词大小，调用字符串追加函数
        strcat(newarr, arr[i]);
        //追加后需要单词大小，在后面补 ' '
        int newlen = strlen(newarr);
        //最后一个单词后面不需要空格
        if (i < count - 1) {
            newarr[newlen] = ' ';
        }
    }
    return newarr;
}



int cmp(const void* p1, const void* p2) {
    return *(int*)p1 - *(int*)p2;
}

int findLHS(int* nums, int numsSize) {
    //排序
    qsort(nums, numsSize, sizeof(int), cmp);

    int begin = 0;
    int end = 0;

    int len = 0;
    //遍历查找最大序列
    for (int end = 1; end < numsSize; end++) {
        if (nums[end] - nums[begin] > 1) {
            begin++;
        }
        if (nums[end] - nums[begin] == 1) {
            len = len > end - begin + 1 ? len : end - begin + 1;
        }
    }
    return len;
}