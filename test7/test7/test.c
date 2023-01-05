#define  _CRT_SECURE_NO_WARNINGS 1
//�����ַ���
char* makeGood(char* s) {
    int len = strlen(s);
    char* str = (char*)malloc(sizeof(char) * (len + 1));
    int top = 0;
    for (int i = 0; i < len; i++) {
        //��Сд��ĸ��ջ
        str[top++] = s[i];
        //�ж����������ַ��Ƿ�Ϊ��Сд
        if (top >= 2 && (str[top - 1] + 32 == str[top - 2] || str[top - 1] - 32 == str[top - 2])) {
            top -= 2;
        }

    }
    str[top] = '\0';
    return str;
}
//��Ļʽ���
//��Ļʽ��ʼ�ˣ�����������һ�Ŷ������εľ�����𡣸���һ�ö����� root ������𣬽ڵ�ֵ��ʾ���������һ
//λ�õ���ɫ���ࡣ���С�ۼ����������ж����ֲ�ͬ����ɫ

int arr[1001];
void PrevOrder(struct TreeNode* root) {
    if (root) {
        arr[root->val]++;
        PrevOrder(root->left);
        PrevOrder(root->right);
    }
}


int numColor(struct TreeNode* root) {
    //��ʼ������
    memset(arr, 0, sizeof(arr));
    //����
    PrevOrder(root);
    int count = 0;
    //���Ҳ�Ϊ0�ĸ���
    for (int i = 0; i < 1001; i++) {
        if (arr[i] != 0) {
            count++;
        }
    }
    return count;
}

//�Ӹ���Ҷ�Ķ�������֮��
void  sumOrder(struct TreeNode* root, int i, int* sum) {
    if (root == NULL) {
        return NULL;
    }

    //��Ϊ��,�洢��ǰ���ֵ
    i = root->val + (i << 1);
    //�����Ҷ�ڵ�

    if (root->left == NULL && root->right == NULL) {
        *sum += i;
        return;
    }

    sumOrder(root->left, i, sum);
    sumOrder(root->right, i, sum);
}

int sumRootToLeaf(struct TreeNode* root) {
    int sum = 0;
    sumOrder(root, 0, &sum);

    return sum;
}


//���������¶�
void  sumOrder(struct TreeNode* root, int i, int* sum) {
    if (root == NULL) {
        return NULL;
    }

    //��Ϊ��,�洢��ǰ���ֵ
    i = root->val + (i << 1);
    //�����Ҷ�ڵ�

    if (root->left == NULL && root->right == NULL) {
        *sum += i;
        return;
    }

    sumOrder(root->left, i, sum);
    sumOrder(root->right, i, sum);
}

int sumRootToLeaf(struct TreeNode* root) {
    int sum = 0;
    sumOrder(root, 0, &sum);

    return sum;
}