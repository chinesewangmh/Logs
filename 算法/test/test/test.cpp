#include <iostream>
#include <vector>
using namespace std;
  struct ListNode {
 	int val;
 	struct ListNode *next;
 	ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution {
public:

    ListNode* Listmer(ListNode* l1, ListNode* l2)
    {
        ListNode* newnode = new ListNode(-1);
        ListNode* tail = newnode;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while (cur1 && cur2)
        {
            if (cur1->val < cur2->val)
            {
                tail->next = cur1;
                cur1 = cur1->next;
            }
            else
            {
                tail->next = cur2;
                cur2 = cur2->next;
            }
            tail = tail->next;
        }
        if (cur1)
        {
            tail->next = cur1;
        }
        if (cur2)
        {
            tail->next = cur2;
        }
        ListNode* head = newnode->next;
        delete newnode;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* head = nullptr;
        for (int i = 0; i < n; ++i)
        {
            head = Listmer(head, lists[i]);
        }
        return head;
    }
};

// ��������Ŀ�Ͱ汾�����ο� ������˵����
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

///**
// * @param n ������Ϸ����
// * @param m ��m��Ҫ��Ȧ
// * @return ����
// */
//int solution(int n, int m) {
//    vector<int> v(n);
//    for (int i = 1; i <= n; ++i)
//    {
//        v[i-1]=i;
//    }
//    int cnt = 0;
//    int exitnum = 0;
//    while (1)
//    {
//        for (int i = 0; i < v.size(); ++i)
//        {
//            if (v[i] != 0)
//                cnt++;
//            if (cnt == m)
//            {
//                v[i] = 0;
//                cnt = 0;
//                exitnum++;
//            }
//        }
//        if (exitnum + 1 == v.size()) break;
//    }
//    for (auto e : v)
//    {
//        if (e!=0)
//        {
//            return e;
//        }
//    }
//    return -1;
//}
//int getLastRemaining(int n) {
//    list<int> circle;
//    // ��ʼ��Χ��һȦ����
//    for (int i = 1; i <= n; i++) {
//        circle.push_back(i);
//    }
//
//    auto it = circle.begin();
//    while (circle.size() > 1) {
//        // ����1
//        it++;
//        // ����2
//        if (it == circle.end()) {
//            it = circle.begin();
//        }
//        it++;
//        // ����3
//        if (it == circle.end()) {
//            it = circle.begin();
//        }
//        // ������3���˴�Ȧ�����Ƴ�
//        it = circle.erase(it);
//        if (it == circle.end()) {
//            it = circle.begin();
//        }
//    }
//
//    // ����������µ��˵ı��
//    return circle.front();
//}

int getLastRemaining(int n, int m) {
    vector<int> circle;
    // ��ʼ��Χ��һȦ����
    for (int i = 1; i <= n; i++) {
        circle.push_back(i);
    }

    int idx = 0;
    while (circle.size() > 1) {
        // �ҵ�����m���˵�����
        idx = (idx + m - 1) % circle.size();

        // ������m���˴�Ȧ�����Ƴ�
        circle.erase(circle.begin() + idx);
    }

    // ����������µ��˵ı��
    return circle.front();
}

int solution(int n, int m) {
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(i);
    }
    int cnt = 0;
    while (v.size()>1)
    {
        for (int i = 0; i < v.size(); ++i)
        {
            if (cnt != m)
            {
                cnt++;
            }
            if(cnt==m)
            {
                v.erase(v.begin()+i);
                --i;
                cnt = 0;
            }
        }
    }
    return v.front();
}

string convertToTitle(int columnNumber) {
   /* string ans;
    while (columnNumber > 0) {
        --columnNumber;
        ans += columnNumber % 26 + 'A';
        columnNumber /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;*/

////A = a_n * 26^n + ... + a_1 * 26^1 + a_0 * 26^0
//    int dividend = columnNumber;
//    vector<char> tmpRst;
//    while (dividend > 0)
//    {
//        int remainder = dividend % 26;
//        if (remainder == 0)  // a_0 == 26
//        {
//            tmpRst.push_back('Z');
//            dividend -= 26;
//            dividend /= 26;
//        }
//        else
//        {
//            tmpRst.push_back('A' + remainder - 1);
//            dividend /= 26;
//        }
//    }
//    return string(tmpRst.rbegin(), tmpRst.rend());

    string row;
    while (columnNumber)
    {
        int remainder = columnNumber % 26;
        if (remainder == 0)//���������0��������һλ���1��26��������������ǿ�е���26
        {
            remainder = 26;
            columnNumber -= 26;
        }
        row.push_back(remainder + 'A');
        columnNumber /= 26;
    }
    reverse(row.begin(), row.end());
    return row;
}

int main()
{
    cout<< convertToTitle(701);
}







