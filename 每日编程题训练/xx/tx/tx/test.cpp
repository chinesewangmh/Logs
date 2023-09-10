#include<iostream>
#include <vector>
#include <functional>
using namespace std;


//class Solution {
//public:
//    struct Counts {
//        int count2;
//        int count5;
//
//        Counts(int c2, int c5) : count2(c2), count5(c5) {}
//    };
//
//    struct TreeNode {
//        int val;
//        TreeNode* left;
//        TreeNode* right;
//
//        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//    };
//
//    TreeNode* getTree(TreeNode* root) {
//        /* 计算n的2和5的因子数量 */
//        auto counts = [&](int n) -> Counts {
//            int count2 = 0;
//            int count5 = 0;
//            while (n % 2 == 0) {
//                count2++;
//                n /= 2;
//            }
//            while (n % 5 == 0) {
//                count5++;
//                n /= 5;
//            }
//            return Counts(count2, count5);
//        };
//
//        /* 递归遍历树节点 */
//        function<Counts(TreeNode*)> dfs = [&](TreeNode* node) -> Counts {
//            if (!node)
//                return Counts(0, 0);
//
//            Counts cur = counts(node->val);
//            Counts left = dfs(node->left);
//            Counts right = dfs(node->right);
//
//            cur.count2 += left.count2 + right.count2;
//            cur.count5 += left.count5 + right.count5;
//
//            node->val = min(cur.count2, cur.count5);
//
//            return cur;
//        };
//
//        dfs(root);
//
//        return root;
//    }
//};

//小红的好数组：快速幂
const int MOD = 1e9 + 7;
long long fastpow(long long n, long long val) {
    if (n == 1) return val;
    if (n == 0) return 1;

    long long x = fastpow(n / 2, val);
    return n % 2 ? ((x * x) % MOD * val) % MOD : (x * x) % MOD;
}

int fun(int n) {
    return (long long)((n - 1) * fastpow(n + 1, 2)) % MOD;
}

//快速幂https://blog.csdn.net/qq_40693171/article/details/119708575
//const int MOD = 1e9 + 7;
//long long fastpow(long long n, long long val) {
//    if (n == 1) return val;
//    if (n == 0) return 1;
//
//    // long long x = fastpow(n / 2, val);
//    // return n % 2 ? ((x * x) % MOD * val) % MOD : (x * x) % MOD;
//
//    if (n % 2 == 0)//偶数
//        return fastpow(n / 2, (val * val) % MOD) % MOD;
//    else//奇数
//        return (val * fastpow((n - 1) / 2, (val * val) % MOD)) % MOD;
//}
//
//int fun(int n) {
//    return (long long)((n - 1) * fastpow(n + 1, 2)) % MOD;
//}



//小红的价值二叉树
class Solution {
public:
    
  struct TreeNode {
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
 
    struct Counts {
        int count2;
        int count5;

        Counts(int c2, int c5) : count2(c2), count5(c5) {}
    };
    // 定义 getCounts 函数，接受一个整数参数 n，返回一个 Counts 结构体
    Counts getCounts(int n) {
        int count2 = 0;
        int count5 = 0;
        while (n % 2 == 0) {
            count2++;
            n /= 2;
        }
        while (n % 5 == 0) {
            count5++;
            n /= 5;
        }
        return Counts(count2, count5);
    }
    // 在 dfs 函数中使用 getCounts 函数来计算节点的因子数量
    Counts dfs(TreeNode* node) {
        if (!node)
            return Counts(0, 0);

        Counts cur = getCounts(node->val);
        Counts left = dfs(node->left);
        Counts right = dfs(node->right);

        cur.count2 += left.count2 + right.count2;
        cur.count5 += left.count5 + right.count5;

        node->val = min(cur.count2, cur.count5);

        return cur;
    }

    TreeNode* valueOfTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};


//小红的二叉树赋值
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

//class Solution {
//public:
//    TreeNode* fun(TreeNode* root) {
//        vector<TreeNode*> odd, even;
//        cnts(root, 1, odd, even);
//
//        int n = odd.size() + even.size();
//        int diff = odd.size() - even.size();
//        int _diff = abs(diff);
//        if (_diff >= 2)
//            return nullptr;
//
//
//        if (odd.size() < even.size()) swap(odd, even);
//
//        //初始化要填充的数，n和n-1将会在初始化阶段使用
//        int i = n - 3, j = n - 2;
//
//        //sum1:偶数层总和
//        //sum2:奇数层总和
//        int sum1 = n, sum2 = n - 1;
//
//        even[0]->val = n;
//        odd[0]->val = n - 1;
//
//        //对应两个数组的下标，由于已经初始化0位置，从1位置开始
//        int index1 = 1, index2 = 1;
//        for (int i = 0; i < n - 2; ++i) {
//            if (sum1 <= sum2) {//偶数层小于奇数层
//                if (index1 >= even.size())//偶数层数组idx越界 
//                    break;
//                //填充偶数层
//                even[index1]->val = j;
//                index1++;
//                //偶数层总和增加
//                sum1 += j;
//            }
//            else {//偶数层大于奇数层
//                if (index2 >= odd.size())//奇数层数组下标越界 
//                    break;
//                sum2 += j;//奇数层和增加
//                odd[index2]->val = j;//填充奇数层
//                index2++;
//            }
//            j--;
//        }
//        while (index1 < even.size()) {
//            even[index1]->val = j;
//            j--;
//            index1++;
//        }
//        while (index2 < odd.size()) {
//            odd[index2]->val = j;
//            j--;
//            index2++;
//        }
//        return root;
//    }
//
//    void cnts(TreeNode* node, int i, vector<TreeNode*>& odd, vector<TreeNode*>& even) {
//        if (!node) return;
//        if (i % 2 == 0) even.push_back(node);
//        else odd.push_back(node);
//        cnts(node->left, i + 1, odd, even);
//        cnts(node->right, i + 1, odd, even);
//    }
//};

    //TreeNode* fun(TreeNode* root) {
    //    vector<TreeNode*> odd, even;
    //    cnts(root, 1, odd, even);

    //    int n = odd.size() + even.size();
    //    int diff = odd.size() - even.size();
    //    int _diff = abs(diff);
    //    if (_diff >= 2)
    //        return nullptr;
    //    
    //    //保证奇数层节点个数大于偶数层
    //    //if (odd.size() < even.size()) swap(odd, even);

    //    //初始化要填充的数，n和n-1将会在初始化阶段使用
    //    int  j = n - 2;

    //    //sum1:奇数层总和
    //    //sum2:偶数层总和
    //    int sum1 = n, sum2 = n - 1;
    //    int len2 = even.size()-1;
    //    int len1 = odd.size()-1;
    //    //奇数层填最大值，偶数层次大值
    //    even[len2]->val = n-1;
    //    odd[len1]->val = n;

    //    //对应两个数组的下标，由于已经初始化0位置，从1位置开始
    //    int index1 = len1-1, index2 = len2 -1;
    //    for (int i = 0; i < n - 2; ++i) {
    //        if (sum1 <= sum2) {//偶数层大于等于奇数层
    //            if (index1 <0)//偶数层数组idx越界 
    //                break;
    //            //填充偶数层
    //            odd[index1]->val = j;
    //            index1--;
    //            //偶数层总和增加
    //            sum1 += j;
    //        }
    //        else {//偶数层小于奇数层
    //            if (index2 <0)//奇数层数组下标越界 
    //                break;
    //            sum2 += j;//奇数层和增加
    //            even[index2]->val = j;//填充奇数层
    //            index2--;
    //        }
    //        j--;
    //    }
    //    while (index1 >0) {
    //        odd[index1]->val = j;
    //        j--;
    //        index1--;
    //    }
    //    while (index2 > 0) {
    //        even[index2]->val = j;
    //        j--;
    //        index2--;
    //    }
    //    return root;
    //}

    //void cnts(TreeNode* node, int i, vector<TreeNode*>& odd, vector<TreeNode*>& even) {
    //    if (!node) return;
    //    if (i % 2 == 0) even.push_back(node);
    //    else odd.push_back(node);
    //    cnts(node->left, i + 1, odd, even);
    //    cnts(node->right, i + 1, odd, even);
    //}


#include<queue>
#include<array>
TreeNode* fun(TreeNode* root) {
    
    int odd = 0, even = 0;
    int count = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        if (count & 1) odd += size;
        else even += size;

        for (int i = 0; i < size; ++i) {
            auto tmp = q.front();
            q.pop();
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
        count++;
    }

    int n = odd + even;
    int sum = n * (n + 1) / 2;
    int odd_s = (odd + 1) * odd / 2;
    if (odd_s > (sum / 2 + 1)) return nullptr;
    array<bool, 100005> arr{ false };
    for (int i = 1; i <= odd; ++i) arr[i] = true;
    int dis = n - odd;
    int oddm = 0;
    if (odd > even) oddm = (sum + 1) / 2;
    else oddm = sum / 2;

    oddm -= odd_s;
    for (int i = odd; i > 0; --i) {
        if (oddm > dis) {
            oddm -= dis;
            arr[i] = false;
            arr[i + dis] = true;
        }
        else {
            arr[i] = false;
            arr[i + oddm] = true;
            oddm = 0;
            break;
        }
    }
    if (oddm != 0) return nullptr;

    q.push(root);
    count = 0;
    odd = even = 1;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto tmp = q.front();
            q.pop();
            if (count & 1) {
                while (!arr[odd]) odd++;
                tmp->val = odd;
                odd++;
            }
            else {
                while (arr[even]) even++;
                tmp->val = even;
                even++;
            }
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
        count++;
    }

    return root;
}



/***************************************************************/
//const int MOD = 1e9 + 7;
//void fun(unordered_map<int, int>& mp)
//{
//    for (int i = 1; i <= 12; ++i)
//    {
//        int key = pow(2, i) - 1;
//        mp[key]++;
//    }
//
//}

//int cntOfTrees(int n) {
//    // write code here
//    if (n % 2 == 0)
//        return 0;
//
//
//    vector<long long> arr(n + 1);
//    arr[1] = 1;
//    arr[3] = 1;
//    unordered_map<int, int> mp;
//    fun(mp);
//    for (int i = 5; i < n + 1; i += 2)
//    {
//        //叶子节点数
//        int prev = i - 2;
//        int n0 = (prev - 1) / 2 + 1;
//
//        if (i % 2 != 0)
//            arr[i] = ((arr[i - 2]) % MOD * n0 % MOD) % MOD;
//        //如果是满二叉树节点
//        if (mp.count(i) > 0)
//        {
//            arr[i]--;
//        }
//    }
//    return arr[n];
//}


//const int MOD = 1e9 + 7;
//bool Isnum(int i)
//{
//    string str = to_string(i);
//    int count = 0;
//    for (int i = 0; i < str.size(); ++i)
//    {
//        if (str[i] != '0')
//            count++;
//    }
//    return count == 1;
//}
//int perfectPair(vector<int>& arr) {
//    int n = arr.size();
//    vector<int> v(n);
//
//    for (int i = 1; i < n; ++i)
//    {
//        for (int j = 0; j < i; ++j)
//        {
//            int num = ((arr[j] % MOD) * (arr[i] % MOD)) % MOD;
//            if (Isnum(num))
//                v[i]++;
//        }
//    }
//    int sum = 0;
//    for (auto e : v)
//    {
//        sum += e;
//    }
//    return sum;
//}
//};

//卡特兰数 1 1 2 5 14 42
///  1/(n+1)* C(n,2n)
// 
int numTrees(int m)
{
    if (m % 2 == 0) return 0;
    int n = (m - 1) / 2;
    //dp[i]:节点数为i所 组成二叉搜索树的方案数
    vector<long long> dp(n + 1);
    dp[0] = 1;


    //外层循环控制第几个节点
    for (int i = 1; i <= n; ++i)
    {
        //内层循环控制根节点是谁
        for (int j = 1; j <= i; ++j)
        {
            dp[i] = (dp[i] + dp[j - 1] * dp[i - j]) % MOD;
        }
    }
    return (int)dp[n];
}
//int numTrees(int n)
//{
//    if (n % 2 == 0) return 0;
//    
//    //dp[i]:节点数为i所 组成二叉搜索树的方案数
//    vector<long long> dp(n + 1);
//    dp[1] = 1;
//    dp[3] = 1;
//
//    //外层循环控制第几个节点
//    for (int i = 5; i <= n; i+=2)
//    {
//        //内层循环控制根节点是谁
//        for (int j = 3; j <= i; j+=2)
//        {
//            dp[i] = (dp[i] + dp[j - 2] * dp[i - j+1]) % MOD;
//        }
//    }
//    return (int)dp[n];
//}

int main()
{
    //205311759
    cout<<numTrees(91);

    return 0;
}


