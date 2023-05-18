#include <iostream>
#include <forward_list>
using namespace std;

//int main()
//{
//	/*int arr[5];
//	for (int i=0;i<5;++i)
//	{
//		cout << arr + i << endl;
//		cout << &arr[i] << endl;
//	}*/
//	int a = 0x11223344;
//
//	/*int  b = 33000;
//	char c=(char)b;
//	*/
//
//	char c=33000;
//	printf("%d",c);
//
//	return 0;
//}

//
//typedef forward_list<int> ListNode;
//
//void Reverse(ListNode& ls)
//{
//	ls.reverse();
//}
//int main()
//{
//	int arr[] = { 1,2,3,4 };
//	ListNode ls(arr, arr + 4);
//	Reverse(ls);
//	for (const auto& e:ls)
//	{
//		cout << e << " ";
//	}
//	return 0;
//}

//enum { IsUnlawful = 0, IsLawful };//判断是否是非法输入
//static  int g_state = IsUnlawful;
//class Solution {
//public:
//    int strToInt(string str) {
//
//        long long num = 0;
//        int i = 0;
//        if (str != "" && str != "\0")
//        {
//            bool flag = true;//正数
//            while (str[i] == ' ')//去空格
//            {
//                ++i;
//            }
//            if (str[i] == '+')//判断符号
//            {
//                i++;
//            }
//            else if (str[i] == '-')
//            {
//                i++;
//                flag = false;
//            }
//            if (str[i] != '\0')//+-'\0';
//            {
//                num = DigitToStr(str, i, flag);//转换
//            }
//
//        }
//        cout << g_state << endl;
//        return static_cast<int>(num);
//    }
//    long long DigitToStr(string& s, int& i, bool flag)
//    {
//        long long num = 0;
//        while (s[i] != '\0')
//        {
//            if (isdigit(s[i]))
//            {
//                int ret = flag == true ? 1 : -1;
//                num = 10 * num + (s[i] - '0') * ret;
//                //判断是否越界
//                if (num > INT_MAX && flag)
//                {
//                    return INT_MAX;
//                }
//                if (num < INT_MIN && !flag)
//                {
//                    return INT_MIN;
//                }
//            }
//            ++i;
//
//            if (!isdigit(s[i]))//异常结束；我这里把 "4193 with words"、"words and 987"看成一种情况
//            {
//                break;
//            }
//            else if (s[i] == '\0')
//            {
//                g_state = IsLawful;
//            }
//        }
//
//        return num;
//    }
//};


//int main()
//{
//    /*string s = "0";
//    Solution sl;
//    sl.strToInt(s);*/
//
//    string strText = "How are you?";
//
//    string strSeparator = " ";
//
//    string strResult;
//
//    int size_pos = 0;
//
//    int size_prev_pos = 0;
//
//    while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
//
//    {
//
//        strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//
//        cout << strResult << " ";
//
//        size_prev_pos = ++size_pos;
//
//    }
//
//    if (size_prev_pos != strText.size())
//
//    {
//
//        strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//
//        cout << strResult << " ";
//
//    }
//
//    cout << endl;
//
//    return 0;
//
//}
//
//class Solution {
//public:
//    string reverseWords(string s) {
//
//        int len = 0;
//        int i = 0;
//        size_t pos = s.find(' ');
//
//        while (pos != string::npos)
//        {
//            reverse(s.begin() + len, s.begin() + pos);
//            len = pos + 1;
//            pos = s.find(pos + 1, ' ');
//        }
//
//        reverse(s.begin() + len, s.end());
//        return s;
//    }
//};
#include <vector>

//class Solution {
//public:
//    //字符串相加
//    string addStrings(string num1, string num2) {
//        //定义两个从后往前遍历的指针
//        int end1 = num1.size() - 1, end2 = num2.size() - 1;
//        //进位
//        int crray = 0;
//        //新字符串
//        string Str;
//        //给定容量，减少扩容次数，提高效率
//        Str.reserve(max(num1.size(), num2.size()) + 1);
//        while (end1 >= 0 || end2 >= 0)
//        {
//            //提取数字
//            int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
//            int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
//            //相加
//            int sum = val1 + val2 + crray;
//
//            // //保留个位数字
//            // int ret=sum%10;
//            // //重置进位
//            // crray=sum / 10;
//            if (sum > 9)
//            {
//                sum -= 10;
//                crray = 1;
//            }
//            else
//            {
//                crray = 0;
//            }
//            //尾插置新字符串
//            //Str+=(ret+'0');
//
//            Str += (sum + '0');
//
//            --end1;
//            --end2;
//
//        }
//        if (crray == 1)
//        {
//            Str += '1';
//        }
//        reverse(Str.begin(), Str.end());
//        return Str;
//    }
//    string multiply(string num1, string num2) {
//        if (num1.size() < num2.size())
//        {
//            swap(num1, num2);
//        }
//        int carry = 0;
//        int end1 = num1.size() - 1;
//        int end2 = num2.size() - 1;
//
//        vector<string> vs(num2.size() + 1);
//        while (end2 >= 0)
//        {
//            if (num2[end2] == '0')
//            {
//                vs[num2.size() - end2 - 1] = '0';
//
//            }
//
//            //求出单个竖式
//            while (end1 >= 0 && num2[end2] != '0')
//            {
//                int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
//                int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
//
//                //相乘
//                int num = val1 * val2 + carry;
//                //保留个位数字
//                int ret = num % 10;
//                //重置进位
//                carry = num / 10;
//
//                //分解出的每个字符尾插到指定字符串
//                vs[num2.size() - end2 - 1] += ret + '0';
//                --end1;
//            }
//            //特殊处理字符串遍历完毕后还有进位
//            if (carry >= 1)
//            {
//                vs[num2.size() - end2 - 1] += carry + '0';
//            }
//
//            //迭代，处理下一层竖式
//            carry = 0;
//            end1 = num1.size() - 1;
//            end2--;
//        }
//        //对每层竖式补0
//        for (int i = 0; i < vs.size(); ++i)
//        {
//            string tmp(i, '0');
//            reverse(vs[i].begin(), vs[i].end());
//            vs[i] += tmp;
//        }
//
//        //转化为字符串相加
//        string result;
//        for (int i = 0; i < vs.size(); ++i)
//        {
//            result = addStrings(result, vs[i]);
//        }
//        return result;
//
//        //乘数为零特殊处理，已优化
//        // int i = 0;
//        // for(i=0;i<result.size();++i)
//        // {
//        //     if (result[i] != '0')
//        //         break;
//        // }
//        //return i==result.size()? "0":result;
//    }
//};

//      
//int main()
//{
//    /*string s = "33";
//    string str = "0";
//    cout<<Solution().multiply(s,str);*/
//
//    unsigned int a = 10;
//    size_t b = 10;
//    printf("%u", a);
//
//    printf("%u",b);
//    
//}



class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.size() < 2)
        {
            return nums;
        }
        int begin = 0;
        int end = nums.size() - 1;
        while (begin < end)
        {
            while (begin < end && (nums[begin] & 1) == 1)//从左往右找偶数
            {
                begin++;
            }
            while (begin < end && (nums[end] & 1) == 0)//从右往左找奇数
            {
                end--;
            }
            if (begin < end)
            {
                swap(nums[begin], nums[end]);

            }
        }
        return nums;
    }
};

int main()
{
    vector<int> v({ 2,16,3,5,13,1,16,1,12,18,11,8,11,11,5,1 });
    Solution().exchange(v);
}