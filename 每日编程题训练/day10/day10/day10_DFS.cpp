


计算布尔二叉树的值
bool evaluateTree(TreeNode* root) {
    //DFS：后序遍历
    if (root->left == nullptr) return root->val == 0 ? false : true;

    bool left = evaluateTree(root->left);
    bool right = evaluateTree(root->right);

    return root->val == 2 ? left | right : left & right;
}



求根节点到叶节点数字之和
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

