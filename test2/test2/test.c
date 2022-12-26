#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	char* str[3] = { "stra", "strb", "strc" };
//	char* p = str[0];
//	int i = 0;
//	while (i < 3)
//	{
//		printf("%s ", p++);
//		i++;
//	} 
//	return 0;
//}
//int main() {
//	int m[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int(*p)[4] = (int(*)[4])m;
//	printf("%d", p[1][2]);
//	return 0;
//}
#include<string.h>
//int main() {
//    char arr[20] = "hello";
//    char arr1[] = "word";
//    printf("%s\n",strcat(arr+2, arr1));
//}
//int main()
//{
//	/*char p1[15] = "abcd", * p2 = "ABCD", str[50] = "xyz";
//	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
//	printf("%s", str);
//	return 0;*/
//	char arr[] = "ab";
//	printf("%d",strlen(arr));
//	printf("%d",sizeof(arr));
//}
//
//char* f(char* str, char ch)
//{
//	char* it1 = str;
//	char* it2 = str;
//	while (*it2 != '\0')
//	{
//		while (*it2 == ch)
//		{
//			it2++;
//		} 
//		*it1++ = *it2++;
//	} 
//		return it2;
//} 
//int main() {
//	char a[10];
//	strcpy(a, "abcdcccd");
//	printf("%s", f(a, 'c'));
//	return 0;
//}

//bool canPermutePalindrome(char* s) {
//    int x = 0;
//    int len = strlen(s);
//    int arr[26] = { 0 };
//    int i = 0;
//    for (i = 0; i < len; i++) {
//        arr[s[i] - 'a']++;
//    }
//    i = 0;
//    for (i = 0; i < 26; i++) {
//        x += (arr[i] % 2);
//    }
//    return x > 1 ? false : true;
//}
//int main() {
//    char s[] = "totao";
//    canPermutePalindrome(s);
//}

//#include <stdio.h>
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
//
//bool CheckPermutation(char* s1, char* s2) {
//    int arr[26] = { 0 };
//    int len1 = strlen(s1);
//    int len2 = strlen(s2);
//    if (len1 != len2) {
//        return false;
//    }
//    int i = 0;
//    //利用ASCII码计算字符出现次数
//    for (i = 0; i < len1; i++) {
//        arr[s1[i] - 'a']++;
//    }
//    int j = 0;
//    for (j = 0; j < len2; j++) {
//        arr[s2[j] - 'a']--;
//        if (arr[s2[j] - 'a'] < 0) {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//bool canPermutePalindrome(char* s) {
//    int x = 0;
//    int len = strlen(s);
//    int arr[128] = { 0 };
//    int i = 0;
//    //记录字符出现次数
//    for (i = 0; i < len; i++) {
//        arr[s[i]]++;
//    }
//    i = 0;
//    //找到出现奇数次字符的个数
//    for (i = 0; i < 128; i++) {
//        x += (arr[i] % 2);
//    }
//    return x > 1 ? false : true;
//}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int n;
    char arr[101];
    scanf("%d", &n);
    int i = 0;
    while (i < n)
    {
        scanf("%s", arr);
        int len = strlen(arr);
        if (len < 10) {
            printf("%s\n", arr);
        }
        else {
            printf("%c%d%c\n", arr[0], len - 2, arr[len - 1]);
        }
        i++;
    }

    return 0;
}

char* replaceSpaces(char* S, int length) {
    //找空格数
    int count = 0;
    int i = 0;
    for (i = 0; i < length; i++) {
        if (S[i] == ' ') {
            count++;
        }
    }
    //从后往前遍历
    int newlen = count * 2;
    i = 0;
    for (i = length - 1; i >= 0; i--) {
        if (S[i] != ' ') {
            S[i + newlen] = S[i];
        }
        else {
            S[i + newlen] = '0';
            S[i + newlen - 1] = '2';
            S[i + newlen - 2] = '%';
            newlen -= 2;
        }
    }
    return S;
}

int main() {
    char s[] = "asd s";
    char* p;
    p=replaceSpaces(s,5);
    printf("%s",p);
}