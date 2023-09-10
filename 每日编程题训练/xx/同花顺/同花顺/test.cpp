#include<iostream>
#include <vector>
#include <string>
#include<unordered_map>
using namespace std;

bool Str1andStr2(string s1,string s2)
{
    // a为大，b为小  
    if (s1.size() < s2.size()) swap(s1,s2);
    

    unordered_map<char, int> map;
    // 构造一个unordered_map  
    for (auto s:s1) 
    {
        map[s]++;
    }
    // 判断s2串  
    for (int i = 0; i < s2.size(); i++) {
        if (map.find(s2[i]) == map.end()) {
            
            return false;
        }
        else {
            map[s2[i]]--;
            if (map[s2[i]] < 0) {
                return false;
            }
        }
    }
    return true;
}
#include <stack>
int calculate(string s) {
    stack<int> ops;
    ops.push(1);
    int sign = 1;

    int ret = 0;
    int n = s.length();
    int i = 0;
    while (i < n) {
        if (s[i] == ' ') {
            i++;
        }
        else if (s[i] == '+') {
            sign = ops.top();
            i++;
        }
        else if (s[i] == '-') {
            sign = -ops.top();
            i++;
        }
        else if (s[i] == '(') {
            ops.push(sign);
            i++;
        }
        else if (s[i] == ')') {
            ops.pop();
            i++;
        }
        else {
            long num = 0;
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
                i++;
            }
            ret += sign * num;
        }
    }
    return ret;
}


int main()
{
    //cout<<Str1andStr2("acb","abb");
    string s = "1 + 2 + (3-(4+5))";
    calculate(s);
    return 0;
}