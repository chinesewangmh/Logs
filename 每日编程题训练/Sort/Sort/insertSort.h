
#include <stack>
void insetSort(int *a,int n)
{
	bool flag = true;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
				swap(a[j],a[j+1]);
			flag = false;
		}
		if (flag == true)
			break;
	}
}

//����ȡ�н��ѡ����key��������Сֵ������������
//С�����Ż�������ݹ��������
void quickSort1(int* a, int begin,int end)
{
	if (begin >= end)
		return;
	int left = begin;
	int right = end;
	int key = left;
	while(left<right)
	{
		//�ұ���С
		while(left<right && a[right]>=a[key])
		{
			--right;
		}
		//����Ҵ�
		while (left < right && a[left] <= a[key])
		{
			++left;
		}
		swap(a[left],a[right]);
	}
	swap(a[left],a[key]);
	key = left;
	quickSort1(a, begin, key - 1);
	quickSort1(a,key+1,end);

}

void quickSort2(int* a, int begin, int end)//�ڿӷ�
{
	if (begin >= end)
		return;
	int left = begin;
	int right = end;
	int hole = left;
	int key = a[hole];
	while (left < right)
	{
		//�ұ���С
		while (left < right && a[right] >= key)
		{
			--right;
		}
		//���¿�λ
		a[hole] = a[right];
		hole = right;

		//����Ҵ�
		while (left < right && a[left] <= key)
		{
			++left;
		}
		
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	
	quickSort2(a, begin, hole - 1);
	quickSort2(a, hole + 1, end);
}

void quickSort3(int* a, int begin, int end)//˫ָ�뷨
{
	if(begin >= end)
		return;
	int left = begin;
	int right = end;

	int key = begin;
	int prev = begin, cur = begin + 1;
	while (cur<=end)
	{
		/*if (a[cur] < a[key])
		{
			++prev;
			swap(a[prev],a[cur]);
		}*/
		if (a[cur] < a[key] && ++prev != cur)
		{
			swap(a[prev], a[cur]);
		}
		cur++;
	}
	swap(a[key],a[prev]);

	quickSort3(a, begin, prev - 1);
	quickSort3(a,prev+1,end);
}


int PartSort4(vector<int>& a, int begin, int end)
{
	int cur = begin;
	int key = a[end];
	int prev = begin - 1;
	while (cur < end)
	{
		if (a[cur] < key)
		{
			prev++;
			swap(a[prev], a[cur]);
		}
		cur++;

	}
	prev++;
	swap(a[prev], a[end]);
	return prev;
}

void QuickSort(vector<int>& a, int begin, int end)
{
	stack<int> s;
	s.push(begin);
	s.push(end);
	while (!s.empty())
	{
		int right = s.top();
		s.pop();
		int left = s.top();
		s.pop();
		int keyindex = PartSort4(a, left, right);
		if (left < keyindex - 1)
		{
			s.push(left);
			s.push(keyindex - 1);
		}
		if (keyindex + 1 < right)
		{
			s.push(keyindex + 1);
			s.push(right);
		}
	}

}



