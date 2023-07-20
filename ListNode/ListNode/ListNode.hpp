//#include <iostream>
//#include <initializer_list>
//using namespace std;
//
//
//template<class T=int>
//struct ListNode
//{
//	ListNode<T>* _next;
//	T _data;
//
//	ListNode(const T& x)
//		:_next(nullptr)
//		, _data(x)
//	{}
//	
//};
//
//template<class T=int, class Tcal=int, class Ptr=int *>
//struct _list_iterator
//{
//	typedef ListNode<T> node;
//	typedef _list_iterator<T, Tcal, Ptr> Self;
//
//	node* _pnode;
//
//	_list_iterator(node* p)
//		:_pnode(p)
//	{}
//
//	Ptr operator->()
//	{
//		return &_pnode->_data;
//	}
//	Tcal operator*()
//	{
//		return _pnode->_data;
//	}
//	Self& operator++()
//	{
//		_pnode = _pnode->_next;
//		return *this;
//	}
//	
//	
//	bool operator!=(const Self& it) const
//	{
//		return _pnode != it._pnode;
//	}
//	bool operator==(const Self& it) const
//	{
//		return _pnode == it._pnode;
//	}
//};
//
//
//template <class T=int>
//class List
//{
//	typedef ListNode<T> node;
//public:
//	typedef _list_iterator<T, T&, T*> iterator;
//	iterator begin()
//	{
//		return iterator(_head->_next);
//	}
//	iterator end()
//	{
//		node* end = _head;
//		while(end)
//		{
//			end = end->_next;
//		}
//		return iterator(end);
//	}
//
//	//空构造
//	void empty_initialize()
//	{
//		_head = new node(T());
//		_head->_next = nullptr;
//	}
//	List()
//	{
//		empty_initialize();
//	}
//	List(node* NODE)
//	{
//		empty_initialize();
//		_head->_next = NODE;
//
//	}
//	//利用迭代器构造对象
//	template <class InputIterator>
//	List(InputIterator first, InputIterator last)
//	{
//		empty_initialize();
//		while (first != last)
//		{
//			push_back(*first);
//			++first;
//		}
//	}
//	//initializer_list{}构造
//	List(initializer_list<T> il)
//	{
//		empty_initialize();
//		for (auto& e : il)
//		{
//			push_back(e);
//		}
//	}
//
//	~List()
//	{
//		clear();
//		delete _head;
//		_head = nullptr;
//	}
//
//	
//	
//
//	void clear()
//	{
//		node* cur = _head->_next;
//		while (cur) {
//			node* next = cur->_next;
//			delete cur;
//			cur = next;
//		}
//	}
//	void push_back(const T& x)
//	{
//		node* newnode = new node(x);
//		
//		node* tail = _head;
//		while (tail->_next)
//		{
//			tail = tail->_next;
//		}
//		tail->_next = newnode;
//		
//		
//	}
//	node* _head;
//	
//};
// 
//
#include <iostream>

template<typename T>
class ListNode {
public:
    T data;
    ListNode<T>* next;

    ListNode(const T& value)
        : data(value), next(nullptr)
    {}
};

template<typename T>
class LinkedList {

    

public:
    ListNode<T>* head;

    LinkedList()
        : head(nullptr)
    {}

    ~LinkedList()
    {
        ListNode<T>* current = head;
        while (current != nullptr) {
            ListNode<T>* next = current->next;
            delete current;
            current = next;
        }
    }
    LinkedList(initializer_list<int> il)
    {
        for (auto& e : il)
        {
            insert(e);
        }
    }
    void insert(const T value)
    {
        ListNode<T>* newNode = new ListNode<T>(value);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            ListNode<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void remove(const T& value)
    {
        ListNode<T>* current = head;
        ListNode<T>* prev = nullptr;

        while (current != nullptr) {
            if (current->data == value) {
                if (prev == nullptr) {
                    head = current->next;
                }
                else {
                    prev->next = current->next;
                }
                delete current;
                break;
            }
            prev = current;
            current = current->next;
        }
    }

    void display()
    {
        ListNode<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

