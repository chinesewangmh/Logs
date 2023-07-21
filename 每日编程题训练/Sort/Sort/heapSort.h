#include <iostream>
#include <vector>
#include <functional>
using namespace std;

template< class Compare = less<int>>
class Headsort
{
public:
	Headsort(vector<int> v)
		:arr(v)
	{}
	void adjustdown(int parent, int n)
	{
		Compare com;
		int child = parent * 2 + 1;
		while (child < n)
		{
			if (child + 1 < n && com(arr[child], arr[child + 1]))
				child++;
			if (com(arr[parent], arr[child]))
			{
				swap(arr[parent], arr[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				break;
		}
	}
public:
	void headsort()
	{
		for (int i = (arr.size() - 1 - 1) / 2; i >= 0; --i)
		{
			adjustdown(i, arr.size());
		}
		int end = arr.size() - 1;
		while (end > 0)
		{
			swap(arr[0], arr[end]);
			adjustdown(0, end);
			end--;
		}
	}
	void print()
	{
		for (auto e : arr)
		{
			cout << e << " ";
		}
	}
private:
	vector<int> arr;
};
