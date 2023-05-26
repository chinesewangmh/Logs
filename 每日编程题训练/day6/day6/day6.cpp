#include <iostream>
using namespace std;

//int main() {
//    int n;
//    while (cin >> n)
//    {
//        if (n == 0) break;
//
//        int cnt = 0;
//        // while (n>=2)
//        // {
//        //     if(n%3)//可能1,2，把多的分给其他堆，保证只加1个
//        //     {
//        //         n=n/3+1;
//        //     }
//        //     else //3的倍数，直接除，得到重量最小的
//        //     {
//        //         n/=3;
//        //     }
//        //     cnt++;
//        // }
//        while (n > 1)
//        {
//            cnt++;
//            n = n / 3 + (n % 3 > 0);
//        }
//        cout << cnt << endl;
//    }
//}
#include <vector>
#include <set>
//int getFirstUnFormedNum(vector<int> arr, int len) {
//    set<int> S;
//    vector<int> tmp;
//    int mi = 0x7fffffff;
//    for (int i = 0; i < len; ++i) {
//        if (arr[i] < mi) mi = arr[i];
//        for (set<int>::iterator it = S.begin(); it != S.end();++it)
//            tmp.push_back(*it + arr[i]);
//        for (unsigned int i = 0; i < tmp.size(); ++i)
//            S.insert(tmp[i]);
//        S.insert(arr[i]);
//        tmp.clear();
//    }
//    for (int i = mi; ; ++i) if (S.find(i) == S.end()) return i;
//    return -1;
//}

//int main()
//{
//    vector<int> v{ 2,3,5 };
//    getFirstUnFormedNum(v,3);
//}


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void subsetSums(vector<int>& nums, int start, int sum, unordered_set<int>& res) {
    res.insert(sum);  // 将当前子集的和加入到结果集中

    for (int i = start; i < nums.size(); i++) {
        subsetSums(nums, i + 1, sum + nums[i], res); // 递归处理下一个元素
    }
}

unordered_set<int> subsetSums(vector<int>& nums) {
    unordered_set<int> res;
    subsetSums(nums, 0, 0, res);

    return res;
}



int getFirstUnFormedNum(vector<int> arr, int len) {
    int min = arr[0];
    int max = 0;
    for (int i = 0; i < len; ++i)
    {
        max += arr[i];
        if (min > arr[i]) min = arr[i];
    }
    vector<int> v(max + 1, 0);

    for (int i = 0; i < len; ++i)
    {
        for (int j = max; j >= arr[i]; --j)
        {
            //01背包问题
            //如果放入当前物品背包的质量大于原本的，更新
            if (v[j] < v[j - arr[i]] + arr[i])
            {
                v[j] = v[j - arr[i]] + arr[i];
            }
        }
    }

    for (int i = min; i <= max; ++i)
    {
        if (v[i] != i) return i;
    }
    return max + 1;
}
int test() {
    
    //getFirstUnFormedNum({3,2,5},3);

     char s1[20] = "aadddd";
     char t1[] = "dddd";
     char* tmp = s1;
     char* s = s1;
     char* t = t1;
    while (*s++=*t++)
    {
        ;
    }

    return 0;
}

char* my_strcpy(char* arr, char* arr1) {
    //assert(arr);
    //assert(arr1);
    char* ret = arr;
    while (*arr++ = *arr1++) {
        ;
    }
    //*arr = *arr1;
    //arr1++;
    //arr++;
    return ret;
}
int main() {
    /*char arr[20] = "hello";
    char arr1[] = "word";
    printf("%s\n", my_strcpy(arr, arr1));*/
    test();
}