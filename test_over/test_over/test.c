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


//int main()
//{
//	char* s = "one", a[5] = { 0 }, ch=0;
//	char(*p)[5] = &a;
//	return 0;
//}


char* f(char* S)
{
    int count = 1;
    int len = strlen(S);
    if (len <= 2)
        return S;
    //存储新数组    
    char* str = (char*)malloc(2 * len * sizeof(char));
    int i = 0;
    int p = 0;
    for (i = 1; i < len + 1; i++) {
        if (S[i] == S[i - 1]) {
            count++;
        }
        else {
            //遇到不相同的字符，把上一字符存储到新数组
            str[p++] = S[i - 1];
            //sprintf返回存储字符的个数，并在末尾补'\0'
            int nlen = sprintf(&str[p], "%d", count);
            p += nlen;
            count = 1;
        }
    }
    return strlen(str) < len ? str : S;
}
int main() {
    //char arr[] = "hello\0*******";
    //char arr1[] = "word";
    //printf("%s\n", strcat(arr+2, arr1));
  /*  char p1[15] = "abcd", * p2 = "ABCD", str[50] = "xyz";
    strcpy(str + 2, strcat(p1 + 2, p2 + 1));
    printf("%s", str);
    return 0;*/
    char* S= "aabcccccaaa";
    f(S);

}