#include <iostream>
#include <initializer_list>
using namespace std;




struct ListNode
{
	ListNode* _next;
	int _data;

	ListNode(const int& x)
		:_next(nullptr)
		, _data(x)
	{}
	

	ListNode(initializer_list<int> il, ListNode** pphead)
	{
		for (auto& e : il)
		{
			push_back(pphead,e);
		}
	}

	void push_back(ListNode**pphead, const int x)
	{
		ListNode* newnode = new ListNode(x);
		if (*pphead == nullptr) {
			*pphead = newnode;
		}
		else {
			ListNode* tail = *pphead;
			while (tail->_next)
			{
				tail = tail->_next;
			}
			tail->_next = newnode;
		}

	}
};

