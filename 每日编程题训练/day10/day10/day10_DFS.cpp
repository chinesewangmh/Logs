

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};


//计算布尔二叉树的值
bool evaluateTree(TreeNode* root) {
    //DFS：后序遍历
    if (root->left == nullptr) return root->val == 0 ? false : true;

    bool left = evaluateTree(root->left);
    bool right = evaluateTree(root->right);

    return root->val == 2 ? left | right : left & right;
}



//求根节点到叶节点数字之和
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


//二叉树减枝
   //后序
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



//判断二叉搜索树
#include<climits>
long prev = LONG_MIN;
bool isValidBST(TreeNode* root) {
    //中序+回溯+剪枝
    if (root == nullptr) return true;

    bool left = isValidBST(root->left);
    //剪枝:当左子树已经违反规则，不需要接下来的判断了
    if (left == false) return false;

    bool cur = false;
    if (prev < root->val)
    {
        cur = true;
    }
    //剪枝:当中间节点已经违反规则，不需要接下来的判断了
    if (cur == false) return false;

    prev = root->val;
    bool right = isValidBST(root->right);

    //都符合搜索树返回true
    return left && cur && right;
}