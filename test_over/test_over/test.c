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


//char* f(char* S)
//{
//    int count = 1;
//    int len = strlen(S);
//    if (len <= 2)
//        return S;
//    //存储新数组    
//    char* str = (char*)malloc(2 * len * sizeof(char));
//    int i = 0;
//    int p = 0;
//    for (i = 1; i < len + 1; i++) {
//        if (S[i] == S[i - 1]) {
//            count++;
//        }
//        else {
//            //遇到不相同的字符，把上一字符存储到新数组
//            str[p++] = S[i - 1];
//            //sprintf返回存储字符的个数，并在末尾补'\0'
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
    //存储每个单词的指针
    char* arr[9];
    char* cur = s;
    //统计单词个数
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            count++;
            //保存单词索引值
            char c = s[i] - '0' - 1;
            //索引位置置0，切割成一个单词；
            s[i] = '\0';
            //根据单词索引存进指针数组
            arr[c] = cur;
            //更新到下一个单词
            cur = s + i + 2;
        }
    }
    char* newarr = (char*)malloc(len + 1);
    //初始化newarr
    memset(newarr, 0, len + 1);
    //放入新数组
    for (int i = 0; i < count; i++) {
        //不需要知道每个单词大小，调用字符串追加函数
        strcat(newarr, arr[i]);
        //追加后需要单词大小，在后面补 ' '
        int newlen = strlen(newarr);
        //最后一个单词后面不需要空格
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