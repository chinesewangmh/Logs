#define  _CRT_SECURE_NO_WARNINGS 1
//5
#include<stdio.h>
#include<stdlib.h>
//union D
//{
//	int d1;
//	float d2;
//}d;
//int main() {
//	printf("%d\n",sizeof(d));
//	printf("%p\n",&d);
//	printf("%p\n", &d.d1);
//	printf("%p\n", &d.d2);
//	d.d2 = 10;
//	printf("%d",d.d1);
//	return 0;
//}

//enum weekday
//{
//	sun,
//	mon = 3,
//	tue,
//	wed
//};
//int main() {
//	enum weekday workday;
//	workday = wed;
//	printf("%d\n", workday);
//}

//int main()
//{
//	char arr[2][4];
//	strcpy(arr[0], "you");
//	strcpy(arr[1], "me");
//	arr[0][3] = '&';
//	printf("%s \n", arr);
//	return 0;
//}




///6


#include<stddef.h>
//struct st
//{
//	int* p;
//	int i;
//	char a;
//};
//int main() {
//	printf("%d\n", offsetof(struct st, p));
//	printf("%d\n", offsetof(struct st, i));
//	printf("%d\n", offsetof(struct st, a));
//	int sz = sizeof(struct st);
//	printf("%d",sz);
//}
#include<stddef.h>
//typedef struct List_t
//{
//	struct List_t* next;
//	struct List_t* prev;
//	char data[0];
//}list_t;
//int main()
//{	printf("%d\n", offsetof(struct List_t, next));
//	printf("%d\n", offsetof(struct List_t, prev));
//	printf("%d\n", offsetof(struct List_t, data));
//	printf("%d", sizeof(list_t));
//	return 0;
//}

//void fut(int** s, int p[2][3])
//{
//	**s = p[1][1];
//} 
//int main()
//{
//	int a[2][3] = { 1,3,5,7,9,11 }, * p;
//	p = (int*)malloc(sizeof(int));
//	fut(&p, a);
//	printf("%d", *p);
//	return 0;
//}

//char* compressString(char* S) {
//    int count = 1;
//    int len = strlen(S);
//    if (len <= 2)
//        return S;
//    //存储新数组    
//    char* str = (char*)malloc((2 * len) * sizeof(char));
//    int i = 0;
//    int p = 0;
//    for (i = 1; i < len + 1; i++) {
//        if (S[i] == S[i - 1]) {
//            count++;
//        }
//        else {
//            str[p++] = S[i - 1];
//            //sprintf返回存储字符的个数
//            int nlen = sprintf(&str[p], "%d", count);
//            p += nlen;
//            count = 1;
//        }
//    }
//    str[p] = '\0';
//    return strlen(str) < len ? str : S;
//
//}
//
//int main() {
//    char s[] = "aabbbbbbbbbbbbbbbbccc";
//    char* p = compressString(s);
//}
//
//int main()
//{
//	char* buffer = (char*)malloc(sizeof(40));
//	int n, a = 5, b = 20;
//	n = sprintf(&buffer[5], "%d", a + b);
//	printf("%s %d\n", buffer, n);
//	return 0;
//}

//int exchangeBits(int num) {
//    //取奇数位
//    int num1 = num & 0xaaaaaaaa;
//    //取偶数位
//    int num2 = num & 0x55555555;
//    //奇数位右移
//    num1 = num1 >> 1;
//    //偶数位左移
//    num2 = num2 << 1;
//    //合并
//    return num1 | num2;
//}



///6
//int multiply(int A, int B) {
//    if (A == 1) {
//        return B;
//    }
//    if (B == 1) {
//        return A;
//    }
//    return multiply(A, B - 1) + A;
//
//    //int res = 0;
//    //while (B != 0) {//B的最后一位不为0
//    //    if ((B & 1) != 0) {
//    //        res += A;
//    //    }
//    //    A <<= 1;//A左移1位
//    //    B >>= 1;//B右移1位(无符号右移)
//    //}
//    //return res;
//}
//int main() {
//    int A = 3, B = 4;
//    printf("%d\n", multiply(A, B));
//
//}

#include <stdio.h>

int main() {
    int n;
    int count = 0;
    scanf("%d", &n);
    int i = 0;
    for (i = 1; i <= n; i++) {
        //7的整数倍
        int tmp = i;
        if (tmp % 7 == 0) {
            count++;
            continue;
        }
        //位置含7
        while (tmp > 0) {
            if (tmp % 10 == 7) {
                count++;
                break;
            }
            tmp /= 10;
        }
    }
    printf("%d\n", count);
    return 0;
}