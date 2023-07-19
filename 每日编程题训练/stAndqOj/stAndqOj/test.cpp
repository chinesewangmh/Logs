#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<int> st;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            if (st.empty() || st.top() != '(')
                return false;
            else
                st.pop();
        }
        else if (s[i] == ']')
        {
            if (st.empty() || st.top() != '[')
                return false;
            else
                st.pop();
        }
        else if (s[i] == '}')
        {
            if (st.empty() || st.top() != '{')
                return false;
            else
                st.pop();
        }
    }
    return st.empty();
}
bool isValid(string s) {//使用哈希表
    if (s.size() % 2 != 0) return false;
    unordered_map<char, char> ump = { {')','('},{']','['},{'}','{'} };
    stack<int> st;
    for (auto e : s)
    {
        if (ump.count(e))
        {
            if (st.empty() || st.top() != ump[e])
                return false;
            else
                st.pop();
        }
        else
            st.push(e);
    }
    return st.empty();
}

/*两个队列实现栈*/
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {

    }

    void push(int x) {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);//经过此次转化，q1队列队头就相当于栈顶
    }

    int pop() {
        int del = 0;
        if (!q1.empty())
        {
            del = q1.front();
            q1.pop();
        }
        return del;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty() && q2.front();
    }
};
/*用两个栈实现队列*/
class MyQueue {
public:
    stack<int> stpush;
    stack<int> stpop;
    MyQueue() {

    }

    void push(int x) {
        stpush.push(x);
    }

    int pop() {
        if (empty()) return -1;
        if (stpop.empty())
        {
            while (!stpush.empty())
            {
                stpop.push(stpush.top());
                stpush.pop();
            }

        }
        int popnum = stpop.top();
        stpop.pop();
        return popnum;

    }

    int peek() {
        if (stpop.empty())
        {
            while (!stpush.empty())
            {
                stpop.push(stpush.top());
                stpush.pop();
            }
        }
        return stpop.top();
    }

    bool empty() {
        return stpop.empty() && stpush.empty();

    }
};
int main()
{
    string s = "]";
    isValid(s);
}