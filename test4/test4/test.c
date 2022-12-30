#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//void fun(char* fname, char* st)
//{
//	FILE* myf;
//	int i;
//	myf = fopen(fname, "w");
//	for (i = 0; i < strlen(st); i++) fputc(st[i], myf);
//	fclose(myf);
//} 
//int main()
//{
//	fun("test.txt", "new world");
//	fun("test.txt", "hello,");
//	return 0;
//}

//#define Mul(x,y) ++x*++y
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = 3;
//	printf("%d", Mul(a + b, b + c));
//	return 0;
//}

//#define a 10
//void foo();
//int main()
//{
//	printf("%d..", a);
//	foo();
//	printf("%d", a);
//	return 0;
//} 
//void foo() {
//#undef a
//#define a 50
//}
//

//long int f(n) {
//    if (n <= 1) {
//        return 1;
//    }
//    return n * f(n - 1);
//}
//int trailingZeroes(int n) {
//    long int a = f(n);
//    int count = 0;
//    while (a > 0) {
//        if (a % 10 == 0) {
//            count++;
//        }
//        else {
//            break;
//        }
//        a /= 10;
//
//    }
//    return count;
//}
//int main() {
//    int x = f(10);
//    printf("%d\n",x);
//}
//
//int main() {
//    float n;
//    scanf("%f", &n);
//    int b = (int)n;
//    if (n * 2 < 2 * b + 1) {
//        printf("%d\n", b);
//    }
//    else {
//        printf("%d\n", b + 1);
//    }
//    return 0;
//}


//#include <stdio.h>
//int arr[1000001] = { -1 };
//int f(n) {
//    if (n == 1) {
//        arr[n] = 0;
//        return 1;
//    }
//    else if (n == 2) {
//        arr[n] = 0;
//        return 2;
//    }
//    if (arr[n] > 0) {
//        return arr[n];
//    }
//    arr[n] = 2 * f(n - 1) + f(n - 2);
//    return arr[n];
//}
//int main() {
//    int n;
//    scanf("%d", &n);
//    while (n) {
//        int x;
//        scanf("%d", &x);
//        arr[1] = 1;
//        int d = f(x) % 32764;
//        printf("%d\n", d);
//    }
//
//    return 0;
//}


#include <stdio.h>

int main() {
    //×ÖÄ¸
    int Scount=0;
    //¿Õ¸ñ
    int Spcnt=0;
    //Êý×Ö
    int Ncount=0;
    //ÆäÓà×Ö·û
    int othercnt=0;
    int c;
    while((c=getchar())!= '\n'){
        if(c>='A'&&c<='Z'||c>='a'&&c<='z'){
            Scount++;
        }
        else if(c==' '){
            Spcnt++;
        }
        else if ('0'<=c&&c<='9'){
            Ncount++;
        }
        else{
            othercnt++;
        }
    }
    printf("%d\n",Scount);
    printf("%d\n",Spcnt);
    printf("%d\n",Ncount);
    printf("%d\n",othercnt);
    return 0;
}