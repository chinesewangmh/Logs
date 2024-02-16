#include<iostream>
#include <vector>
#include <cassert>
#include <cstring>
using namespace std;


void GetNext(const char* sub,int* next)
{
	//�̶�
	next[0] = -1;
	next[1] = 0;
	int lensub = strlen(sub);
	int i = 2;//��һ��
	int k = 0;//ʼ�ձ�ʾǰһ��Ļ���λ��
	while (i < lensub)//next���黹û�б�����
	{
		if ((k == -1) || sub[k] == sub[i - 1])//k==-1��ʾ�����ʼ��λ�ã�Խ��
		{
			next[i] = k + 1;
			i++;
			k++;
		} 
		else       //p[i-1] != p[k]
		{
			k = next[k];//���ˣ�ֱ���ҵ�p[i-1] == p[k]
		}
	}
}


/*
str����
sub�Ӵ�
pos��ʼ����λ��
*/

int KMP(const char* str,const char* sub,int pos)
{
	assert(str!=nullptr || sub!=nullptr);
	int lenStr = strlen(str);
	int lenSub = strlen(sub);

	if (lenStr == 0 || lenSub == 0) return -1;
	if (pos < 0 || pos >= lenStr) return -1;

	int* next = (int*)malloc(sizeof(int) * lenSub);
	assert(next != nullptr);
	GetNext(sub,next);

	int i = pos;//�������ַ���
	int j = 0;//�����Ӵ�

	while (i<lenStr && j<lenSub)
	{
		if (j==-1 ||str[i]==sub[j])//���⴦�����j���˵�-1����Խ��
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];//�Ӵ�j�±����
		}
	}
	if (j>=lenSub)//�ҵ��������Ӵ���������ʼλ��
	{
		return i - j;
	}

	return -1;
}

int main()
{
	printf("%d\n", KMP("ababcabcdabcde", "abcd", 0));
	printf("%d\n", KMP("ababcabcdabcde", "abcdf", 0));
	printf("%d\n", KMP("ababcabcdabcde","ab",0));
	return 0;
}