

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};


//���㲼����������ֵ
bool evaluateTree(TreeNode* root) {
    //DFS���������
    if (root->left == nullptr) return root->val == 0 ? false : true;

    bool left = evaluateTree(root->left);
    bool right = evaluateTree(root->right);

    return root->val == 2 ? left | right : left & right;
}



//����ڵ㵽Ҷ�ڵ�����֮��
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int sum)
    {
        sum = sum * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr)
            return sum;

        int res = 0;
        if (root->left) res += dfs(root->left, sum);
        if (root->right) res += dfs(root->right, sum);

        return res;
    }
    //int dfs(TreeNode* root, int sum)
    //{
    //    if (root == nullptr) return 0;
    //    sum = sum * 10 + root->val;

    //    if (root->left == nullptr && root->right == nullptr)
    //        return sum;

    //    // int res=0;
    //    // if(root->left) res+=dfs(root->left,sum);
    //    // if(root->right) res+=dfs(root->right,sum);
    //    int left = dfs(root->left, sum);
    //    int right = dfs(root->right, sum);
    //    return left + right;
    //}
};


//��������֦
   //����
TreeNode* pruneTree(TreeNode* root) {
    if (root == nullptr) return nullptr;

    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);

    if (root->left == nullptr && root->right == nullptr && root->val == 0)
    {
        return nullptr;
    }

    return root;
}



//�ж϶���������
#include<climits>
long prev = LONG_MIN;
bool isValidBST(TreeNode* root) {
    //����+����+��֦
    if (root == nullptr) return true;

    bool left = isValidBST(root->left);
    //��֦:���������Ѿ�Υ�����򣬲���Ҫ���������ж���
    if (left == false) return false;

    bool cur = false;
    if (prev < root->val)
    {
        cur = true;
    }
    //��֦:���м�ڵ��Ѿ�Υ�����򣬲���Ҫ���������ж���
    if (cur == false) return false;

    prev = root->val;
    bool right = isValidBST(root->right);

    //����������������true
    return left && cur && right;
}


//�����������е�KС��Ԫ��

class Solution {
    int count;//ÿ�α���һ���ڵ㣬��1��ֱ��Ϊ0
    int res;//��¼countΪ0��ʱ��ڵ�ֵ
public:
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        dfs(root);
        return res;
    }
    void dfs(TreeNode* root)
    {
        //��֦��count==0
        if (root == nullptr || count == 0) return;
        dfs(root->left);
        if (count == 0) return;
        count--;
        if (count == 0) res = root->val;
        dfs(root->right);
    }
};

//������������·��
class Solution {
    vector<string> res;

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        dfs(root, path);
        return res;
    }
    //ע�⣬���ﲻ����string& path��������൱��ȫ�ֱ���
    void dfs(TreeNode* root, string path)
    {
        path += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            res.push_back(path);
            return;
        }
        path += "->";

        //��֦+����
        if (root->left) dfs(root->left, path);//��path�Ĳ�����Ӱ��������

        //����һ����ʼ���ֳ����ָ��ֳ���
        if (root->right) dfs(root->right, path);


    }
};