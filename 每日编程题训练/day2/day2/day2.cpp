#include <iostream>

using namespace std;

class A
{
public:
	virtual void par() = 0
	{
		cout << "Sdada" << endl;
	}
};



class B :public A
{
public:
	void par()
	{
		cout << "sda" << endl;
	}
};


int main()
{
	
	B b;
	A* a = &b;
	a->A::par();
}

class CQueue {
public:
    CQueue() {

    }

    void appendTail(int value) {
        pushS.push(value);
    }

    int deleteHead()
    {
        if (popS.empty())
        {
            if (pushS.empty())
            {
                return -1;
            }
            while (!pushS.empty())
            {
                int top = pushS.top();
                pushS.pop();
                popS.push(top);
            }
        }
        int Del = popS.top();
        popS.pop();
        return Del;

    }
    stack<int> pushS;//进数据
    stack<int> popS;//出数据
};


class MyStack {
public:
    queue<int>  q1;
    queue<int> q2;
    MyStack() {

    }

    void push(int x) {
        if (q1.empty() && q2.empty())
        {
            q1.push(x);
            return;
        }
        else if (!q1.empty())
        {
            q1.push(x);
        }
        else if (!q2.empty())
        {
            q2.push(x);
        }
    }

    int pop() {
        int Pop;
        if (q2.empty())
        {
            while (q1.size() > 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            Pop = q1.front();
            q1.pop();
            return Pop;
        }
        if (q1.empty())
        {
            while (q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            Pop = q2.front();
            q2.pop();
            return Pop;
        }

        return Pop;

    }

    int top() {
        if (!q1.empty())
            return q1.back();
        else if (!q2.empty())
            return q2.back();

        return 0;

    }

    bool empty() {
        return q1.empty() && q2.empty();
    }
};



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


class Solution {
public:
    string reverseWords(string s) {
        stack<string> wordStack;  // 用栈存储单词
        string word = "";  // 存储当前单词
        string result = "";  // 存储结果

        // 遍历字符串
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {  // 遇到空格，把当前单词入栈
                if (word != "") {
                    wordStack.push(word);
                    word = "";
                }
            }
            else {  // 不是空格，把字符添加到当前单词
                word += s[i];
            }
        }

        // 把最后一个单词入栈
        if (word != "") {
            wordStack.push(word);
        }

        // 把单词出栈，拼接成结果字符串
        while (!wordStack.empty()) {
            result += wordStack.top();
            wordStack.pop();
            if (!wordStack.empty()) {
                result += " ";
            }
        }

        return result;
    }
};

