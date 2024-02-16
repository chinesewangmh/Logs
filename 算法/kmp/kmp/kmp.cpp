#include<iostream>
#include <vector>
#include <cassert>
#include <cstring>
using namespace std;


void GetNext(const char* sub,int* next)
{
	//固定
	next[0] = -1;
	next[1] = 0;
	int lensub = strlen(sub);
	int i = 2;//下一项
	int k = 0;//始终表示前一项的回退位置
	while (i < lensub)//next数组还没有遍历完
	{
		if ((k == -1) || sub[k] == sub[i - 1])//k==-1表示到了最开始的位置，越界
		{
			next[i] = k + 1;
			i++;
			k++;
		} 
		else       //p[i-1] != p[k]
		{
			k = next[k];//回退，直到找到p[i-1] == p[k]
		}
	}
}


/*
str主串
sub子串
pos起始查找位置
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

	int i = pos;//遍历主字符串
	int j = 0;//遍历子串

	while (i<lenStr && j<lenSub)
	{
		if (j==-1 ||str[i]==sub[j])//特殊处理，如果j回退到-1，会越界
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];//子串j下标回退
		}
	}
	if (j>=lenSub)//找到完整的子串，返回起始位置
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