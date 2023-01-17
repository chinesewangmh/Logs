#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//int main() {
//
//	return 0;
//}


#include <math.h>
//int main()
//{
//	//int n;
//	//while (~scanf("%d", &n)) {
//	//	long count = 0, base = 10;
//	//	for (int i = 0; i <= n; i++) {
//	//		long pow_n = pow(i, 2);
//	//		if (i == base) base *= 10;//两位数的时候成为100，三位数的时候成为1000....
//	//		if (pow_n % base == i) count++;
//	//		/*
//	//		int tmp = i;
//	//		while(tmp){
//	//		if (tmp%10 != pow_n%10) break;
//	//		tmp/=10;
//	//		pow_n/=10;
//	//		} if
//	//		(tmp == 0)count++;
//	//		*/
//	//	}
//	//	printf("%d\n", count);
//	//} 
//	//return 0;
//
//	/*int k[10];
//	printf("%d\n", sizeof(&k+1));
//	return 0;*/
//
//	/*char* p[10];
//	scanf("%s",p);*/
//	/*char* p;
//	p = "wwww";
//	return 0;*/
//
//	//static char* s[] = { "black", "white", "pink", "violet" };
//	//char** ptr[] = { s + 3, s + 2, s + 1, s }, *** p;
//	//p = ptr;
//	//++p;
//	////printf("%s", *(&(**p) + 1));
//	//printf("%s", *s);
//
//	printf("%d ",sizeof("ab"));
//
//	return 0;
//}


int main()
{
	char* s = "one", a[5] = { 0 }, ch=0;
	char(*p)[5] = &a;
	return 0;
}