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
//        /* ����n��2��5���������� */
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
//        /* �ݹ�������ڵ� */
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

//С��ĺ����飺������
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

//������https://blog.csdn.net/qq_40693171/article/details/119708575
//const int MOD = 1e9 + 7;
//long long fastpow(long long n, long long val) {
//    if (n == 1) return val;
//    if (n == 0) return 1;
//
//    // long long x = fastpow(n / 2, val);
//    // return n % 2 ? ((x * x) % MOD * val) % MOD : (x * x) % MOD;
//
//    if (n % 2 == 0)//ż��
//        return fastpow(n / 2, (val * val) % MOD) % MOD;
//    else//����
//        return (val * fastpow((n - 1) / 2, (val * val) % MOD)) % MOD;
//}
//
//int fun(int n) {
//    return (long long)((n - 1) * fastpow(n + 1, 2)) % MOD;
//}



//С��ļ�ֵ������
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
    // ���� getCounts ����������һ���������� n������һ�� Counts �ṹ��
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
    // �� dfs ������ʹ�� getCounts ����������ڵ����������
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


//С��Ķ�������ֵ
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
//        //��ʼ��Ҫ��������n��n-1�����ڳ�ʼ���׶�ʹ��
//        int i = n - 3, j = n - 2;
//
//        //sum1:ż�����ܺ�
//        //sum2:�������ܺ�
//        int sum1 = n, sum2 = n - 1;
//
//        even[0]->val = n;
//        odd[0]->val = n - 1;
//
//        //��Ӧ����������±꣬�����Ѿ���ʼ��0λ�ã���1λ�ÿ�ʼ
//        int index1 = 1, index2 = 1;
//        for (int i = 0; i < n - 2; ++i) {
//            if (sum1 <= sum2) {//ż����С��������
//                if (index1 >= even.size())//ż��������idxԽ�� 
//                    break;
//                //���ż����
//                even[index1]->val = j;
//                index1++;
//                //ż�����ܺ�����
//                sum1 += j;
//            }
//            else {//ż�������������
//                if (index2 >= odd.size())//�����������±�Խ�� 
//                    break;
//                sum2 += j;//�����������
//                odd[index2]->val = j;//���������
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
    //    //��֤������ڵ��������ż����
    //    //if (odd.size() < even.size()) swap(odd, even);

    //    //��ʼ��Ҫ��������n��n-1�����ڳ�ʼ���׶�ʹ��
    //    int  j = n - 2;

    //    //sum1:�������ܺ�
    //    //sum2:ż�����ܺ�
    //    int sum1 = n, sum2 = n - 1;
    //    int len2 = even.size()-1;
    //    int len1 = odd.size()-1;
    //    //�����������ֵ��ż����δ�ֵ
    //    even[len2]->val = n-1;
    //    odd[len1]->val = n;

    //    //��Ӧ����������±꣬�����Ѿ���ʼ��0λ�ã���1λ�ÿ�ʼ
    //    int index1 = len1-1, index2 = len2 -1;
    //    for (int i = 0; i < n - 2; ++i) {
    //        if (sum1 <= sum2) {//ż������ڵ���������
    //            if (index1 <0)//ż��������idxԽ�� 
    //                break;
    //            //���ż����
    //            odd[index1]->val = j;
    //            index1--;
    //            //ż�����ܺ�����
    //            sum1 += j;
    //        }
    //        else {//ż����С��������
    //            if (index2 <0)//�����������±�Խ�� 
    //                break;
    //            sum2 += j;//�����������
    //            even[index2]->val = j;//���������
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
//        //Ҷ�ӽڵ���
//        int prev = i - 2;
//        int n0 = (prev - 1) / 2 + 1;
//
//        if (i % 2 != 0)
//            arr[i] = ((arr[i - 2]) % MOD * n0 % MOD) % MOD;
//        //��������������ڵ�
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

//�������� 1 1 2 5 14 42
///  1/(n+1)* C(n,2n)
// 
int numTrees(int m)
{
    if (m % 2 == 0) return 0;
    int n = (m - 1) / 2;
    //dp[i]:�ڵ���Ϊi�� ��ɶ����������ķ�����
    vector<long long> dp(n + 1);
    dp[0] = 1;


    //���ѭ�����Ƶڼ����ڵ�
    for (int i = 1; i <= n; ++i)
    {
        //�ڲ�ѭ�����Ƹ��ڵ���˭
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
//    //dp[i]:�ڵ���Ϊi�� ��ɶ����������ķ�����
//    vector<long long> dp(n + 1);
//    dp[1] = 1;
//    dp[3] = 1;
//
//    //���ѭ�����Ƶڼ����ڵ�
//    for (int i = 5; i <= n; i+=2)
//    {
//        //�ڲ�ѭ�����Ƹ��ڵ���˭
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


