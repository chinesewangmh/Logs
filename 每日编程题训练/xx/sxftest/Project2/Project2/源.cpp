#pragma warning(disable:4996)
#include<iostream>
#include <vector>
using namespace std;

string get_substr(string st)
{
    string tmp;
    int n = st.size();
    bool flag = true;
    while (1) {
        int left = 0, right = 0;
        while (right < n) {
            while (right < n && st[right] == st[left]) {
                right++;
            }
            if (right - left >= 3) {
                left = right;
                continue;
            }
            else {
                tmp += st.substr(left, right - left);
                left = right;
            }
        }
        st = tmp;
        n = st.size();
        for (int i = 1; i < n - 1; ++i) {
            if (st[i - 1] == st[i] && st[i] == st[i + 1]) {
                flag = false;
                break;
            }
        }
        tmp.clear();
        if (st.size()<3 ||flag == true) break;

    }
    return st;
}
//string myDelete(string S)
//{
//    stack<char> st;
//    int sLen = S.length();
//    for (int i = 0; i < sLen; i++)
//    {
//
//        if (st.size() >= 2)
//        {
//            //��ȡջ����ջ��ǰһ��Ԫ�ص�ֵ
//            int element1 = st.top();
//            st.pop();
//            int element2 = st.top();
//            st.push(element1);
//            if (S[i] == element1 && S[i] == element2)// ������������� 
//            {
//                st.pop();
//                st.pop();
//            }
//            else // �޷����� ѹ��ջ
//            {
//                st.push(S[i]);
//            }
//        }
//        else // �޷����� ѹ��ջ
//        {
//            st.push(S[i]);
//        }
//    }
//    // ��ջ��Ԫ�طŵ�ans�ַ���
//    string ans = "";
//    while (!st.empty())
//    {
//        ans += st.top();
//        st.pop();
//    }
//    reverse(ans.begin(), ans.end()); // ��ʱ�ַ�����Ҫ��תһ��
//    return ans;
//}


#include <string>
#include <sstream>
//int main()
//{
//    /*string s = "222BCC111CB";
//    cout<<get_substr(s);
//
//    string str;*/
//    
//    //"lias","lias","lisa","da","da"
//    //"12:10","11:20","13:00","15:00","16:00"
//    //��C++������������ϼ������뷽ʽ�����ʵ�ִ�����ȷ��ȡ
//    //std::string input;
//    //std::vector<std::string> tokens;
//
//    //std::cout << "������һ���Զ���Ϊ�ָ������ַ�����";
//    //std::getline(std::cin, input);
//
//    //std::stringstream ss(input);
//    //std::string token;
//    //while (std::getline(ss, token, ',')) {
//    //    tokens.push_back(token);
//    //}
//
//    //// ��ӡ������ַ���  
//    //std::cout << "��������ַ���Ϊ��" << input << std::endl;
//
//    //// ��ӡ�ָ�����ַ���  
//    //std::cout << "�ָ�����ַ���Ϊ��";
//    //for (const auto& t : tokens) {
//    //    std::cout << t << " ";
//    //}
//    //std::cout << std::endl;
//
//    //char string[10], str1[10];
//
//    //for (int i=0;i<9;++i)
//    //{
//    //    str1[i] = 'x';
//    //}
//    //str1[9] = '\0';
//    //strcpy(string,str1);
//	return 0;
//}

//char* my_strcpy(char* arr, char* arr1) {
//
//    char* ret = arr;
//    while (*arr++ = *arr1++) {
//        ;
//    }
//    //*arr = *arr1;
//    //arr1++;
//    //arr++;
//    return ret;
//}


