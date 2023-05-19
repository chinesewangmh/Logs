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
    stack<int> pushS;//������
    stack<int> popS;//������
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
        swap(q1, q2);//�����˴�ת����q1���ж�ͷ���൱��ջ��
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
        stack<string> wordStack;  // ��ջ�洢����
        string word = "";  // �洢��ǰ����
        string result = "";  // �洢���

        // �����ַ���
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {  // �����ո񣬰ѵ�ǰ������ջ
                if (word != "") {
                    wordStack.push(word);
                    word = "";
                }
            }
            else {  // ���ǿո񣬰��ַ���ӵ���ǰ����
                word += s[i];
            }
        }

        // �����һ��������ջ
        if (word != "") {
            wordStack.push(word);
        }

        // �ѵ��ʳ�ջ��ƴ�ӳɽ���ַ���
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

