#include "ListNode.hpp"
//#include "oj.hpp"
#include <vector>

//ListNode* reverseList(ListNode* head) {
//    ListNode* newhead = nullptr;
//    ListNode* cur = head;
//
//
//    while (cur)
//    {
//        ListNode* next = cur->_next;
//        cur->_next = newhead;
//        newhead = cur;
//        cur = next;
//    }
//    return newhead;
//}

int main()
{
	//vector<int> v{ 1,2,3,4,5 };
	//List<int> ls(v.begin(),v.end());
	//List<int> l();
	/*List<int> v{ 1,2,3,4,5 };
	for (auto& e:v)
	{
		cout << e << " ";
	}
    ListNode<int>* head= reverseList(v);
    List<int> rever(head);
    for (auto e: rever)
    {
        cout << e << " ";
    }*/
   /* ListNode* pphead = nullptr;
    ListNode ls({1,2,3,4,5},&pphead);
    reverseList(pphead);*/

    LinkedList<int> ls;
    ls.insert(1);
    ls.insert(1);
    ls.insert(1);
    ListNode<int>* cur = ls.head;
    

   
}