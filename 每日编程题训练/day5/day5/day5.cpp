#include <iostream>
using namespace std;

void printBinary(int num) {
	cout << "Binary representation of " << num << " is: ";
	for (int i = 31; i >= 0; i--) {
		if (num & (1 << i))
			cout << "1";
		else
			cout << "0";
	}
}
int add(int a, int b) {
	/*size_t carry = (size_t)(a & b) << 1;
	int num = a ^ b;*/
	//if (carry) num = add(num, carry);
	//return num;

	while (b)
	{
		size_t carry = (size_t)(a & b) << 1;
		int num = a ^ b;
		a = num;
		b = carry;
	}
	return a;
}
int subtract(int a, int b) {
	int borrow;
	while (b != 0) {
		borrow = (~a) & b; // 计算a和b的不进位相减结果
		a ^= b; // 计算a和b的不考虑进位的加法结果
		b = borrow << 1; // b左移一位作为进位
	}
	return a;
}
//int multipli(int a, int b)
//{
//	if (a == 0 || b == 0) return 0;
//	bool flag = true;
//	if (a > 0 && b > 0) flag = false;
//	int result = 0;
//	while (b)
//	{
//		if (b & 1)
//		{
//			result = add(a, result);
//		}
//		a <<= 1;
//		b >>= 1;
//	}
//	return 1;
//}
int multipli(int a, int b)
{
	if (a == 0 || b == 0) return 0;
	bool flag = true;
	if (a > 0 && b > 0) flag = false;
	int result = 0;
	while (b)
	{
		if (b & 1)
		{
			result = add(a, result);
		}
		/*a <<= 1;
		b >>= 1;*/
		size_t tmpa = (size_t)a << 1;
		size_t tmpb = (size_t)b >> 1;
		a = tmpa;
		b = tmpb;
	}
	return result;
}
int test()
{
	int a = -2;
	int n = 4;
	unsigned int ua = static_cast<unsigned int>(a); // 转换为无符号整数
	int res = static_cast<int>(ua << n); // 左移，并转换为有符号整数
	return res;
}

//int main()
//{
//	/*cout << test() << endl;
//	int a = 1;
//	int b = -2;*/
//	/*int c = a & b;*/
//	/*printBinary(-1);
//	printBinary(~(-1));*/
//	//cout << del(a, b) << endl;;/
//	//cout<<add(a,b);
//	//cout << subtract(-2,1) << endl;
//	cout << multipli(3,-5) << endl;
//
//	cout<<sizeof("张三丰111111");
//	cout << strlen("张三丰111111");
//	return 0;
//}
//
//#include <iostream>
//using namespace std;
//
//bool isTriangle(double a, double b, double c)
//{
//
//	if (a + b > c && a + c > b && b + c > a)
//		return true;
//	return false;
//}

//int main()
//{
//	double a, b, c;
//	//while (cin >> a >> b >> c)
//	//{
//	//	if (isTriangle(a, b, c))
//	//		cout << "Yes" << endl;
//	//	else
//	//		cout << "No" << endl;
//	//}
//	cout << sizeof(double) << endl;
//	cout << sizeof(long) << endl;
//	cout << sizeof(long long) << endl;
//	return 0;
//}


//int subtract(int a, int b)
//{
//	int subtrahend = add(~b, 1);
//
//	int sub = add(a, subtrahend);
//
//	return sub;
//}
int multiply(int a, int b)
{
	//将乘数和被乘数都取绝对值
	int left = a < 0 ? add(~a, 1) : a;
	int right = b < 0 ? add(~b, 1) : b;

	//计算绝对值的乘积
	int product = 0;
	while (right)
	{
		if (right & 1)
		{
			product = add(left, product);
		}

		//被乘数左移一位
		left = left << 1;
		//乘数右移一位
		right = right >> 1;
	}

	//计算乘积的符号
	if ((a ^ b) < 0)
	{
		product = add(~product, 1);
	}

	return product;
}

//int main()
//{
//	cout<<multiply(3,-5);
//	return 0;
//}

//int main()
//{
//	void  action1(int, int), action2(int,int);
//	char ch;
//	int a = 15, b = 2;
//	ch = getchar();
//	switch (ch)
//	{
//	case 'A':
//	case 'a':
//		{
//			action1(a,b);
//		}
//		break;
//	case 'b':
//		{
//			action2(a,b);
//		}
//		break;
//	default:
//		putchar('\a');
//		break;
//	}
//	return 0;
//}

//# include <bits/stdc++.h>
#include<cstdio>
#pragma warning(disable:4996)

using namespace std;

struct list_node {
	int val;
	struct list_node* next;
};

list_node* input_list(void)
{
	int n, val;
	list_node* phead = new list_node();
	list_node* cur_pnode = phead;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &val);
		if (i == 1) {
			cur_pnode->val = val;
			cur_pnode->next = NULL;
		}
		else {
			list_node* new_pnode = new list_node();
			new_pnode->val = val;
			new_pnode->next = NULL;
			cur_pnode->next = new_pnode;
			cur_pnode = new_pnode;
		}
	}
	return phead;
}

list_node* ReverseList(list_node* head)
{
	list_node* cur = head;
	list_node* newhead = nullptr;
	while (cur)
	{
		list_node* nextnode = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = nextnode;
	}
	return newhead;
}

list_node* reverse_list(list_node* head, int L, int R)
{
	//////在下面完成代码
	list_node* headL, * headR, * Rnext;
	list_node* newhead = new list_node();
	newhead->next = head;
	list_node* cur = newhead;

	//找左端
	while (L--)
	{
		cur = cur->next;
	}
	headL = cur;

	//找右端
	int num = R - L;
	while (num--)
	{
		cur = cur->next;
	}
	headR = cur;
	Rnext = headR->next;
	headR->next = nullptr;
	//局部翻转
	list_node* reverseHead = ReverseList(headL);
	//连接
	newhead->next = reverseHead;
	headL->next = Rnext;
	return newhead->next;
}

void print_list(list_node* head)
{
	while (head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
	puts("");
}


int main()
{
	int L, R;
	list_node* head = input_list();
	scanf("%d%d", &L, &R);
	list_node* new_head = reverse_list(head, L, R);
	print_list(new_head);
	return 0;
}

#include <iostream>
#include <math.h>
using namespace std;


int main() {
	int n;
	while (cin >> n)
	{
		if (n == 0) break;
		long num = pow(5, n) - 4;//桃子总数
		long result = pow(4, n) + n - 4;//老猴子的桃
		cout << num << " " << result << endl;
	}
}
// 64 位输出请用 printf("%lld")