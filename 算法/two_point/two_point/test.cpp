#include <iostream>
#include <string>
#include <vector>
using namespace std;


/// <summary>
/// 移动零
/// </summary>
/// <param name="nums"></param>
void moveZeroes(vector<int>& nums) {
	//快排双指针思想:cur找到非0的数与++index交换
	for (int cur = 0, index = -1; cur < nums.size(); ++cur)
	{
		if (nums[cur] && cur != ++index)//减少交换次数
		{
			swap(nums[cur], nums[index]);
		}
	}
}

/// <summary>
/// 复写0
/// </summary>
/// <param name="arr"></param>

void duplicateZeros(vector<int>& arr) {
	//1.从前往后找最后一个复写的数
	int cur = 0, dest = -1, n = arr.size();
	while (cur < n)
	{
		//非0dest只需要移动一位
		if (arr[cur]) dest++;
		//0移动两位
		else dest += 2;
		//找到最后一个复写的值
		if (dest >= n - 1) break;
		cur++;
	}
	//2.处理特殊情况
	if (dest == n)
	{
		arr[n - 1] = 0;
		cur--;
		dest -= 2;
	}
	//3.从后往前复写
	while (cur >= 0)
	{
		if (arr[cur])
			arr[dest--] = arr[cur--];
		else
		{
						arr[dest--] = 0;
						arr[dest--] = 0;
						cur--;
		}
	}
}




/// <summary>
/// 快乐数
/// </summary>
/// <param name="n"></param>
/// <returns></returns>

int bitSum(int n)
{
	int sum = 0;
	while (n)
	{
		int mod = n % 10;
		sum += mod * mod;
		n /= 10;
	}
	return sum;
}

bool isHappy(int n) {
	//1.快慢指针思想，将其抽象成一个带环链表(鸽巢思想，必定带环)
	int fast = bitSum(n);
	int slow = n;
	//2.寻找交点
	while (fast != slow)
	{
		fast = bitSum(bitSum(fast));
		slow = bitSum(slow);
	}
	if (fast == 1) return true;
	else return false;
}


class A
{
protected:
	virtual void t1()=0;
	virtual void t2()=0;
	virtual void t3()=0;
public:
	virtual void  tem() final
	{
		t1();
		t2();
		t3();
	}
};

class B :public A
{
protected:
	void t1()
	{
		cout << 1 << endl;
	}
	void t2()
	{
		cout << 1 << endl;
	}
	void t3()
	{
		cout << 1 << endl;
	}
};

int maxArea(vector<int>& height) {

	//时间复杂度O(n),空间复杂度O(1)
	//暴力枚举超时
	//思想：
	int left = 0, right = height.size() - 1, ret = 0;
	while (left < right)
	{
		int v = min(height[left], height[right]) * (right - left);//体积=边界最小值*空格数
		ret = max(ret, v);

		//核心：6 2 5 4  v=h*w
		//当最小值4向前枚举的时候，出现两种情况，v都会减小，因此直接越过计算下一个
		//2 4 h减小 w减小 v减小
		//5 4 h不变 w减小 v减小
		if (height[left] < height[right]) left++;
		else right--;
	}
	return ret;
}
#include <algorithm>
#include <vector>
int triangleNumber(vector<int>& nums) {
	//利用单调性+双指针
	//如果a<=b<=c,只需要证明a+b>c就可以证明是一个三角形
	//2,2,3，4,5,9,10
	//1.排序
	sort(nums.begin(), nums.end());
	int cnt = 0;
	//2.固定最大值c
	for (int i = nums.size() - 1; i >= 2; --i)
	{
		//双指针统计符合条件的三元组
		//   a           b
		int left = 0; int right = i - 1;
		while (left < right)
		{
			//如果a<=b<=c,只需要证明a+b>c就可以证明是一个三角形
			//a是最小值，那么a右边的+b肯定大于c
			if (nums[left] + nums[right] > nums[i])
			{
				cnt += right - left;
				right--;
			}
			else//如果a+b<=c,b左边的数都比他小，a就没意义了，找更大的数做a
			{
				left++;
			}
		}
	}
	return cnt;
}
int main()
{
	////isHappy(3);
	//A* a = new B();
	//a->tem();
	vector<int> nums = { 2,2,3,4,5,9,10 };
	triangleNumber(nums);

}