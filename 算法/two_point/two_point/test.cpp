#include <iostream>
#include <string>
#include <vector>
using namespace std;


/// <summary>
/// �ƶ���
/// </summary>
/// <param name="nums"></param>
void moveZeroes(vector<int>& nums) {
	//����˫ָ��˼��:cur�ҵ���0������++index����
	for (int cur = 0, index = -1; cur < nums.size(); ++cur)
	{
		if (nums[cur] && cur != ++index)//���ٽ�������
		{
			swap(nums[cur], nums[index]);
		}
	}
}

/// <summary>
/// ��д0
/// </summary>
/// <param name="arr"></param>

void duplicateZeros(vector<int>& arr) {
	//1.��ǰ���������һ����д����
	int cur = 0, dest = -1, n = arr.size();
	while (cur < n)
	{
		//��0destֻ��Ҫ�ƶ�һλ
		if (arr[cur]) dest++;
		//0�ƶ���λ
		else dest += 2;
		//�ҵ����һ����д��ֵ
		if (dest >= n - 1) break;
		cur++;
	}
	//2.�����������
	if (dest == n)
	{
		arr[n - 1] = 0;
		cur--;
		dest -= 2;
	}
	//3.�Ӻ���ǰ��д
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
/// ������
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
	//1.����ָ��˼�룬��������һ����������(�볲˼�룬�ض�����)
	int fast = bitSum(n);
	int slow = n;
	//2.Ѱ�ҽ���
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

	//ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
	//����ö�ٳ�ʱ
	//˼�룺
	int left = 0, right = height.size() - 1, ret = 0;
	while (left < right)
	{
		int v = min(height[left], height[right]) * (right - left);//���=�߽���Сֵ*�ո���
		ret = max(ret, v);

		//���ģ�6 2 5 4  v=h*w
		//����Сֵ4��ǰö�ٵ�ʱ�򣬳������������v�����С�����ֱ��Խ��������һ��
		//2 4 h��С w��С v��С
		//5 4 h���� w��С v��С
		if (height[left] < height[right]) left++;
		else right--;
	}
	return ret;
}
#include <algorithm>
#include <vector>
int triangleNumber(vector<int>& nums) {
	//���õ�����+˫ָ��
	//���a<=b<=c,ֻ��Ҫ֤��a+b>c�Ϳ���֤����һ��������
	//2,2,3��4,5,9,10
	//1.����
	sort(nums.begin(), nums.end());
	int cnt = 0;
	//2.�̶����ֵc
	for (int i = nums.size() - 1; i >= 2; --i)
	{
		//˫ָ��ͳ�Ʒ�����������Ԫ��
		//   a           b
		int left = 0; int right = i - 1;
		while (left < right)
		{
			//���a<=b<=c,ֻ��Ҫ֤��a+b>c�Ϳ���֤����һ��������
			//a����Сֵ����ôa�ұߵ�+b�϶�����c
			if (nums[left] + nums[right] > nums[i])
			{
				cnt += right - left;
				right--;
			}
			else//���a+b<=c,b��ߵ���������С��a��û�����ˣ��Ҹ��������a
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