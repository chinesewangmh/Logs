//#define  _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
/////**
//// * struct ListNode {
//// *	int val;
//// *	struct ListNode *next;
//// * };
//// */
//// /**
////  * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
////  *
////  *
////  * @param head ListNode��
////  * @param m int����
////  * @param n int����
////  * @return ListNode��
////  */
////struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
////    if (head == NULL || head->next == NULL) {
////        return head;
////    }
////
////    struct ListNode* rhead = (struct ListNode*)malloc(sizeof(struct ListNode));
////    rhead->next = head;
////    //�ҵ���ת������ʼλ�õ�ǰһ��
////    struct ListNode* prev = rhead;
////    for (int i = 0; i < m - 1; ++i) {
////        prev = prev->next;
////    }
////    //�ҵ���ת�����ͷ��,nhead
////    struct ListNode* nhead = prev->next;
////    struct ListNode* temp;
////    for (int i = 0; i < n - m; i++) {
////        //��������ȡ����ͷ��
////        temp = nhead->next;
////        nhead->next = temp->next;
////        temp->next = prev->next;
////        prev->next = temp;
////    }
////
////    head = rhead->next;
////    free(rhead);
////    return head;
////}
////
////struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
////    if (head == NULL || head->next == NULL) {
////        return head;
////    }
////
////    struct ListNode* rhead = (struct ListNode*)malloc(sizeof(struct ListNode));
////    rhead->next = head;
////    //�ҵ���ת������ʼλ�õ�ǰһ��
////    struct ListNode* prev = rhead;
////    for (int i = 0; i < m - 1; ++i) {
////        prev = prev->next;
////    }
////    //�ҵ���ת�����ͷ��,nhead
////    struct ListNode* nhead = prev->next;
////    struct ListNode* cur = nhead;
////    //���淴ת�����һ��Ԫ�أ������������ʣ����
////    struct ListNode* ptr, * Mhead = nhead;
////    for (int i = 0; i < n - m + 1; i++) {
////        //��������ȡ����ͷ��
////        struct ListNode* next = cur->next;
////        cur->next = ptr;
////
////        ptr = cur;
////        cur = next;
////    }
////    //��ת����ͷ������ӷ�ת����
////    prev->next = ptr;
////    //��ת����β�������ʣ����
////    Mhead->next = cur;
////    head = rhead->next;
////    free(rhead);
////    return head;
////
////}
//
//#include<math.h>
//
//typedef int SLTDataType;
// struct ListNode
//{
//    SLTDataType val;
//    struct ListNode* next;
//
//};
//struct ListNode* BuySLnode(SLTDataType x) {
//    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
//    if (newnode == NULL) {
//        perror("BuySLnode");
//        exit(-1);
//    }
//    newnode->val = x;
//    newnode->next = NULL;
//    return newnode;
//}
//void SLTPushBack(struct ListNode** pphead, SLTDataType x) {
//    struct ListNode* newnode = BuySLnode(x);
//    if (*pphead == NULL) {
//        *pphead = newnode;
//    }
//    else {
//        struct ListNode* tail = *pphead;
//        while (tail->next)
//        {
//            tail = tail->next;
//        }
//        tail->next = newnode;
//    }
//}
//
// int SUm(struct ListNode* cur){
//     int sum=0;
//     int count=0;
//     while(cur){
//         struct ListNode* next=cur->next;
//         sum = sum + cur->val * pow(10,count);
//         count++;
//         cur=next;
//     }
//     return sum;
// }
//
//
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//     struct ListNode* cur1=l1;
//     struct ListNode* cur2=l2;
//     int s1 = SUm(cur1);
//     int s2 = SUm(cur2);
//     int sum = s1 + s2;
//     struct ListNode* head= (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode*tail=head;
//     head->next=NULL;
//     if (sum == 0) {
//         struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
//         newnode->next = NULL;
//         newnode->val = 0;
//         head->next = newnode;
//         return head->next;
//
//     }
//     while(sum>0){
//         int rval=sum%10;
//         struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
//         newnode->val=rval;
//         tail->next=newnode;
//         newnode->next=NULL;
//         tail=newnode;
//         sum/=10;
//     }
//     return head->next;
//}
//void SLTPrint(struct ListNode* phead) {
//    struct ListNode* cur = phead;
//    while (cur != NULL) {
//        printf("%d->", cur->val);
//        //printf("[%d|%p]->", cur->data,cur->next);
//
//        cur = cur->next;
//    }
//    printf("NULL\n");
//}
//
//int main() {
//    struct ListNode* plist = NULL;
//    SLTPushBack(&plist, 9);
//    
//
//    struct ListNode* plist1 = NULL;
//    SLTPushBack(&plist1, 1);
//    SLTPushBack(&plist1, 9);
//    SLTPushBack(&plist1, 9);
//    SLTPushBack(&plist1, 9);
//    SLTPushBack(&plist1, 9);
//    SLTPushBack(&plist1, 9);
//    SLTPushBack(&plist1, 9);
//    SLTPushBack(&plist1, 9);
//    SLTPushBack(&plist1, 9);
//    SLTPushBack(&plist1, 9);
//    struct ListNode* rhead=addTwoNumbers(plist, plist1);
//    SLTPrint(rhead);
//    return 0;
//
//}


 ////��λ�жϣ�carry��ʾ��λ
 //    int sum=0, carry = 0;
 //    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
 //    struct ListNode* p = head;

 //    while(l1 || l2 || carry) {
 //        sum = 0;
 //        if(l1) {
 //            sum += l1->val;
 //            l1 = l1->next;
 //        }

 //        if(l2) {
 //            sum += l2->val;
 //            l2 = l2->next;
 //        }
 //        sum += carry;

 //        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
 //        newNode->val = sum >=10 ? sum%10 : sum;
 //        newNode->next = NULL;            
 //        carry = sum >=10 ? 1 : 0;

 //        p->next = newNode;
 //        p = p->next;
 //    }
 //    return head->next;
#include<stdio.h>
int main() {
	char s[] = "ssss";
	int len = strlen(s);
	printf("%d",len);
	return 0;
}

int MAx(int a, int b) {
    return a > b ? a : b;
}
int maxDepth(char* s) {
    int count = 0;
    int size = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            count++;
            size = MAx(count, size);
        }

        else if (s[i] == ')') {
            count--;
        }
    }
    return size;
}