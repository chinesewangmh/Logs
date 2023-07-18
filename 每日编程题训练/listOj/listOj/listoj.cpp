#include <iostream>
#include <forward_list>
using namespace std;
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
// 
////1.ɾ��������ֵΪval�����нڵ�
//ListNode * removeElements(ListNode * head, int val) {//ԭ��ɾ��
//
//    while (head && head->val == val)
//    {
//        head = head->next;
//    }
//    ListNode* prev = nullptr;
//    ListNode* cur = head;
//    while (cur)
//    {
//        if (cur->val == val)
//        {
//            prev->next = cur->next;
//            cur = cur->next;
//        }
//        else
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//    }
//    return head;
//}
//
//ListNode* removeElements(ListNode* head, int val) {//���
//    ListNode* newhead = new ListNode();
//    ListNode* cur = head;
//    ListNode* tail = newhead;
//    while (cur)
//    {
//        ListNode* next = cur->next;
//        if (cur->val != val)
//        {
//            tail->next = cur;
//            tail = cur;
//        }
//
//        cur = next;
//    }
//    tail->next = nullptr;
//    return newhead->next;
//}
//
//
//ListNode* removeElements(ListNode* head, int val) {//ԭ��ͷ���
//    ListNode* newhead = new ListNode();
//    newhead->next = head;
//    ListNode* cur = newhead;
//    while (cur->next)
//    {
//        if (cur->next->val == val)
//        {
//            cur->next = cur->next->next;
//        }
//        else
//        {
//            cur = cur->next;
//        }
//
//    }
//    return newhead->next;
//}
//
//
///*��ת����*/
//ListNode* reverseList(ListNode* head) {
//    ListNode* newhead = nullptr;
//    ListNode* cur = head;
//    while (cur)
//    {
//        ListNode* next = cur->next;
//        cur->next = newhead;
//        newhead = cur;
//        cur = next;
//
//    }
//    return newhead;
//}
////���鷳
//ListNode* reverseList(ListNode* head) {
//    ListNode* newhead = new ListNode();
//    ListNode* tail = newhead->next;
//    tail = nullptr;
//    ListNode* cur = head;
//    while (cur)
//    {
//        ListNode* next = cur->next;
//        cur->next = tail;
//        newhead->next = cur;
//        tail = cur;
//        cur = next;
//
//    }
//    return newhead->next;
//}
//
//ListNode* reverseList(ListNode* head) {//ԭ�ط�ת
//    ListNode* cur = head;
//    ListNode* prev = nullptr;
//    while (cur)
//    {
//        ListNode* next = cur->next;
//        cur->next = prev;
//        prev = cur;
//        cur = next;
//    }
//    return prev;
//}

//������м�ڵ㣺��ϣ
ListNode* middleNode(ListNode* head) {
    unordered_map<int, ListNode*> ump;
    ListNode* cur = head;
    int i = 1;
    while (cur)
    {
        ump.insert(make_pair(i, cur));
        cur = cur->next;
        i++;
    }
    int mid = (i - 1) / 2 + 1;
    ListNode* res = ump[mid];
    return res;
}
//*/����ָ�

ListNode* partition(ListNode* pHead, int x) {
    ListNode* headS = new ListNode(-1);
    ListNode* headB = new ListNode(-1);
    ListNode* tailS = headS;
    ListNode* tailB = headB;
    ListNode* cur = pHead;
    while (cur)
    {
        if (cur->val < x)
        {
            tailS->next = cur;
            tailS = tailS->next;
        }
        else {
            tailB->next = cur;
            tailB = tailB->next;
        }
        cur = cur->next;
    }
    tailS->next = headB->next;
    tailB->next = nullptr;
    return headS->next;
}

//����Ļ��Ľṹ
 bool chkPalindrome(ListNode* A) {
    ListNode* cur = A;
    stack<int> st;
    while (cur)
    {
        st.push(cur->val);
        cur = cur->next;
    }
    cur = A;
    while (cur)
    {
        //int res=st.pop();
        if (cur->val != st.top())
            return false;
        st.pop();
        cur = cur->next;
    }
    return true;
}

 /*������ཻ�ڵ�*/

 ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
     ListNode* cura = headA;
     ListNode* curb = headB;
     int cnta = 0;
     int cntb = 0;
     while (cura->next)
     {
         ++cnta;
         cura = cura->next;
     }
     while (curb->next)
     {
         ++cntb;
         curb = curb->next;
     }
     if (cura->next != curb->next)
         return nullptr;


     int num = abs(cnta - cntb);
     ListNode* longlist = headA;
     ListNode* shortlist = headB;
     if (cnta < cntb)
     {
         longlist = headB;
         shortlist = headA;
     }
     while (num--) longlist = longlist->next;
     while (longlist != shortlist)
     {
         longlist = longlist->next;
         shortlist = shortlist->next;
     }
     return shortlist;
 }

 /*�ж������Ƿ��л�*/
 bool hasCycle(ListNode* head) {
     ListNode* slow = head;
     ListNode* fast = head;
     while (fast && fast->next)
     {
         slow = slow->next;
         fast = fast->next->next;
         if (slow == fast)
             return true;
     }
     return false;
 }

 ListNode* detectCycle(ListNode* head) {
     ListNode* slow = head;
     ListNode* fast = head;
     ListNode* meet;
     while (fast && fast->next)
     {
         slow = slow->next;
         fast = fast->next->next;
         if (slow == fast)
         {
             meet = fast;
             ListNode* cur = head;
             while (meet != cur)
             {
                 meet = meet->next;
                 cur = cur->next;
             }
             return meet;
         }
     }
     return nullptr;
 }

 /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

 class Solution {
 public:
     void CopyNode(Node* head)
     {
         Node* cur = head;
         while (cur)
         {
             Node* next = cur->next;
             Node* copy = new Node(cur->val);
             copy->next = cur->next;
             cur->next = copy;
             cur = next;
         }
     }
     void CopyRandom(Node* head)
     {
         Node* cur = head;
         while (cur)
         {
             Node* pCopy = cur->next;
             if (cur->random != nullptr)
                 pCopy->random = cur->random->next;
             cur = pCopy->next;
         }
     }

     Node* split_list(Node* head)
     {
         // Node* copyHead=nullptr;
         // Node* CopyNode=nullptr;
         // Node* oldcur=head;
         // if(oldcur!=nullptr)
         // {
         //     copyHead=CopyNode=oldcur->next;
         //     oldcur->next=CopyNode->next;
         //     oldcur=oldcur->next;
         // }
         // while(oldcur)
         // {
         //     CopyNode->next=oldcur->next;
         //     CopyNode=CopyNode->next;
         //     oldcur->next=CopyNode->next;
         //     oldcur=CopyNode->next;

         // }
         // return copyHead;
         Node* newhead = new Node(-1);
         Node* tail = newhead;
         Node* cur = head;
         while (cur)
         {
             Node* CopyNode = cur->next;
             Node* oldnext = CopyNode->next;
             tail->next = CopyNode;
             tail = tail->next;
             cur->next = oldnext;
             cur = oldnext;
         }
         return newhead->next;
     }

     Node* copyRandomList(Node* head) {
         CopyNode(head);
         CopyRandom(head);
         return split_list(head);
     }
 };












//#include <unordered_map>
//
//forward_list<int> middleNode(forward_list<int> head) {
//    unordered_map<int, forward_list<int>> ump;
//    int i = 1;
//    for (auto& e:head)
//    {
//        ump.insert(make_pair(i++,e));
//    }
//    
//    int mid = i % 2 + 1;
//    forward_list<int> res = ump[mid];
//    return res;
//}
//int main()
//{
//    forward_list<int> sl{1,2,3,4,5};
//    middleNode(sl);
//}