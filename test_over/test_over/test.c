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
//	//		if (i == base) base *= 10;//��λ����ʱ���Ϊ100����λ����ʱ���Ϊ1000....
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


//char* f(char* S)
//{
//    int count = 1;
//    int len = strlen(S);
//    if (len <= 2)
//        return S;
//    //�洢������    
//    char* str = (char*)malloc(2 * len * sizeof(char));
//    int i = 0;
//    int p = 0;
//    for (i = 1; i < len + 1; i++) {
//        if (S[i] == S[i - 1]) {
//            count++;
//        }
//        else {
//            //��������ͬ���ַ�������һ�ַ��洢��������
//            str[p++] = S[i - 1];
//            //sprintf���ش洢�ַ��ĸ���������ĩβ��'\0'
//            int nlen = sprintf(&str[p], "%d", count);
//            p += nlen;
//            count = 1;
//        }
//    }
//    return strlen(str) < len ? str : S;
//}
//int main() {
//    //char arr[] = "hello\0*******";
//    //char arr1[] = "word";
//    //printf("%s\n", strcat(arr+2, arr1));
//  /*  char p1[15] = "abcd", * p2 = "ABCD", str[50] = "xyz";
//    strcpy(str + 2, strcat(p1 + 2, p2 + 1));
//    printf("%s", str);
//    return 0;*/
//    char* S= "aabcccccaaa";
//    f(S);
//
//}

char* sortSentence(char* s) {
    int len = strlen(s);
    //�洢ÿ�����ʵ�ָ��
    char* arr[9];
    char* cur = s;
    //ͳ�Ƶ��ʸ���
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            count++;
            //���浥������ֵ
            char c = s[i] - '0' - 1;
            //����λ����0���и��һ�����ʣ�
            s[i] = '\0';
            //���ݵ����������ָ������
            arr[c] = cur;
            //���µ���һ������
            cur = s + i + 2;
        }
    }
    char* newarr = (char*)malloc(len + 1);
    //��ʼ��newarr
    memset(newarr, 0, len + 1);
    //����������
    for (int i = 0; i < count; i++) {
        //����Ҫ֪��ÿ�����ʴ�С�������ַ���׷�Ӻ���
        strcat(newarr, arr[i]);
        //׷�Ӻ���Ҫ���ʴ�С���ں��油 ' '
        int newlen = strlen(newarr);
        //���һ�����ʺ��治��Ҫ�ո�
        if (i < count - 1) {
            newarr[newlen] = ' ';
        }
    }
    return newarr;
}
int main()
{
    char s[] = "is2 sentence4 This1 a3";
    char* p = sortSentence(s);
    printf("%s",p);
}