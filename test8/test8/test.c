#define  _CRT_SECURE_NO_WARNINGS 1
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    *returnSize = arr1Size;
    int arr[1001] = { 0 };
    //ͳ��arr1ÿ��Ԫ�س��ִ�����������
    for (int i = 0; i < arr1Size; i++) {
        arr[arr1[i]]++;
    }

    //��arr1,arr2���е�Ԫ��
    int j = 0;//����arr1����
    for (int i = 0; i < arr2Size; i++) {
        while (arr[arr2[i]] > 0) {//arr�д�����arr2��ȵ�Ԫ�أ�ȡ���Ž�arr1�У�arr�г��ֵĴ���-1
            arr1[j] = arr2[i];
            j++;
            arr[arr2[i]]--;
        }
    }

    //arr1��arr2����ȵ�Ԫ��
    for (int i = 0; i < 1001; i++) {
        while (arr[i] > 0) {
            //j=arr2Size
            arr1[j++] = i;
            arr[i]--;
        }
    }
    return arr1;
}
//��ż��
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
    //ģ�����
    struct TreeNode* qu[N];
    //����ͷ��β��
    int head = 0, tail = 0;
    //���
    qu[head++] = root;
    //�ж���ż��
    int level = 0;
    while (tail < head) {
        int size = head - tail;
        //��prev��ֵ���жϵ�����
        int prev = level % 2 == 0 ? INT_MIN : INT_MAX;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = qu[tail++];
            int value = node->val;
            //�ж��������Ƿ���ż����ż�����Ƿ�������
            if (level % 2 == value % 2) {
                return false;
            }
            //ż���㣬�ж������Ƿ�����������㣬�ж�ż���Ƿ�ݼ�
            if ((level % 2 == 0 && value <= prev) || (level % 2 == 1 && value >= prev)) {
                return false;
            }
            //�Ƚ�ͬ�㵥����ϵ
            prev = value;
            //�ӽڵ�������
            if (node->left) {
                qu[head++] = node->left;
            }
            if (node->right) {
                qu[head++] = node->right;
            }
        }
        //ȥ��һ��
        level++;
    }
    return true;
}


char* sortSentence(char* s) {
    int len = strlen(s);
    //�洢ÿ�����ʵ�ָ��
    char* arr[9];
    char* cur = s;
    //ͳ�Ƶ��ʸ���
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            count++;
            //���浥������ֵ
            char c = s[i] - '0' - 1;
            //����λ����0���и��һ�����ʣ�
            s[i] = '\0';
            //���ݵ����������ָ������
            arr[c] = cur;
            //���µ���һ������
            cur = s + i + 2;
        }
    }
    char* newarr = (char*)malloc(len + 1);
    //��ʼ��newarr
    memset(newarr, 0, len + 1);
    //����������
    for (int i = 0; i < count; i++) {
        //����Ҫ֪��ÿ�����ʴ�С�������ַ���׷�Ӻ���
        strcat(newarr, arr[i]);
        //׷�Ӻ���Ҫ���ʴ�С���ں��油 ' '
        int newlen = strlen(newarr);
        //���һ�����ʺ��治��Ҫ�ո�
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
    //����
    qsort(nums, numsSize, sizeof(int), cmp);

    int begin = 0;
    int end = 0;

    int len = 0;
    //���������������
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