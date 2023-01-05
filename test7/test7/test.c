#define  _CRT_SECURE_NO_WARNINGS 1
//整理字符串
char* makeGood(char* s) {
    int len = strlen(s);
    char* str = (char*)malloc(sizeof(char) * (len + 1));
    int top = 0;
    for (int i = 0; i < len; i++) {
        //大、小写字母入栈
        str[top++] = s[i];
        //判断相邻两个字符是否互为大小写
        if (top >= 2 && (str[top - 1] + 32 == str[top - 2] || str[top - 1] - 32 == str[top - 2])) {
            top -= 2;
        }

    }
    str[top] = '\0';
    return str;
}
//开幕式焰火
//开幕式开始了，空中绽放了一颗二叉树形的巨型焰火。给定一棵二叉树 root 代表焰火，节点值表示巨型焰火这一
//位置的颜色种类。请帮小扣计算巨型焰火有多少种不同的颜色

int arr[1001];
void PrevOrder(struct TreeNode* root) {
    if (root) {
        arr[root->val]++;
        PrevOrder(root->left);
        PrevOrder(root->right);
    }
}


int numColor(struct TreeNode* root) {
    //初始化数组
    memset(arr, 0, sizeof(arr));
    //遍历
    PrevOrder(root);
    int count = 0;
    //查找不为0的个数
    for (int i = 0; i < 1001; i++) {
        if (arr[i] != 0) {
            count++;
        }
    }
    return count;
}

//从根到叶的二进制数之和
void  sumOrder(struct TreeNode* root, int i, int* sum) {
    if (root == NULL) {
        return NULL;
    }

    //不为空,存储当前结点值
    i = root->val + (i << 1);
    //如果是叶节点

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


//二叉树的坡度
void  sumOrder(struct TreeNode* root, int i, int* sum) {
    if (root == NULL) {
        return NULL;
    }

    //不为空,存储当前结点值
    i = root->val + (i << 1);
    //如果是叶节点

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