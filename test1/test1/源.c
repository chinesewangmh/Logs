#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main() {
//	/*char a = 101;
//	int sum = 200;
//	a += 27; sum += a;
//	printf("%d\n", sum);*/
//	int value = 1024;
//	char condition = *((char*)(&value));
//	if (condition) value += 1; condition = *((char*)(&value));
//	if (condition) value += 1; condition = *((char*)(&value));
//	printf("%d %d", value, condition);
//}
//void func(char* p) { p = p + 1; }
//int main()
//{
//	char s[] = { '1', '2', '3', '4' };
//	func(s);
//	printf("%c", *s);
//	return 0;
//}


//#include <stdio.h>
//int main() {
//    int n;
//    //计数器
//    int count = 0;
//    scanf("%d", &n);
//    int i = 0;
//    int sum = 0;
//    int X = 10;
//    for (i = 0; i <= n; i++) {
//        sum = i * i - i;
//        if (i >= X) {
//            X = X * 10;
//        }
//        if (sum % X == 0) {
//            count++;
//        }
//    }
//    printf("%d\n", count);
//    return 0;
//}
//
//
//
//
//
//#include <stdio.h>
//
//int main() {
//    int n;
//    int count = 0;
//    while (scanf("%d", &n) != EOF) { // 注意 while 处理多个 case
//        if (n == 0 || n == 1) {
//            return 0;
//        }
//        int i = 0;
//
//        for (i = 2; i < n; i++) {
//            int j = 0;
//            for (j = 2; j < i; j++) {
//                if (i % j == 0) {
//                    break;
//                }
//            }
//            if (i == j) {
//                count++;
//            }
//        }
//    }
//    printf("%d\n", count);
//    return 0;
//}

//#include <stdio.h>
//void fun(char** p)
//{
//	int i;
//	for (i = 0; i < 4; i++)
//		printf("%s", p[i]);
//}
//int main()
//{
//	char* s[6] = { "ABCD", "EFGH", "IJKL", "MNOP", "QRST", "UVWX" };
//	fun(s);
//	printf("\n");
//	return 0;
//}

//void f(int** p) {
//	;
//}
//int main() {
//
//	int a[4] = { 1,2,3,4 };
//	int b[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
//	int* q[3] = { b[0],b[1],b[2] };
//}

//void func(char para[100])
//{
//	void* p = malloc(100);
//	printf("%d, %d\n", sizeof(para), sizeof(p));
//}
//int main() {
//	char a[100];
//	printf("%d", sizeof(a));
//	func(a);
//}

//sizeof(void*) 为4， sizeof(char) 为1，那么对于 char str[sizeof("ab")]; ， sizeof(str) 的值是
//int main() {
//	char str[] = "ab";
//	printf("%d",sizeof(str));
//	printf("%d", strlen(str));
//}
//#include <stdio.h>
//
//int main()
//{
//    //数组的初始化内容有逗号表达式，实际上数组初始化的是1,3,5
//    int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//    //int a[3][2] = {{0,1}, {2,3}, {4,5}};
//
//    int* p;
//    p = a[0];  
//    printf("%d", p[0]);//?
//
//    return 0;
//}

char fun(char* a) {
	return 1;
}
int main()
{
	char* s = "one", a[5] = { 0 }, (*f1)(char*) = fun, ch;
	ch=f1(*s);
	return 0;
}