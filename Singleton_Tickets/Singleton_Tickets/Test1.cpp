#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<thread>
#include<vector>
using namespace std;
class B
{
public:
	B() {};
	void BP()
	{

	}
private:
	int b = 10;

};
class A
{
public:
	A(){}
private:
	B b;
	vector<int> v{1,2,3,4};
};

//int main()
//{
//	A a;
//
//	return 0;
//}
