#pragma once
#include<iostream>
#include<thread>
using namespace std;
class Tickets
{
public:
	bool take(int i)
	{
		if (_sum - i >= 0)
		{
			_sum -= i;
			return true;
		}
		else
			return false;
	}
	const int Getsum()
	{
		return _sum;
	}
private:
	int _sum = 10;
};