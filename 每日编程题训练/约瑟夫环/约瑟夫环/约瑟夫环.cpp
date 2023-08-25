#include<iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> v(n);
    for (int i = 1; i <= n; ++i) v[i - 1] = i;
    int count = 0, exit = 0;
    while (1)
    {
        for (int i = 0; i < n; ++i)
        {
            if (v[i] != 0) count++;

            if (count == 3)
            {
                v[i] = 0;
                count = 0;
                exit++;
            }
        }
        if (exit + 1 == v.size()) break;
    }
    for (int i = 0; i < n; ++i)
    {
        if (v[i] != 0) cout << v[i] << endl;;
    }

}

#include <iostream>
#include <vector>
using namespace std;

int func() {//数据过多会超时
    int n, m;
    cin >> n;
    vector<int> v(n);
    for (int i = 1; i <= n; ++i) v[i - 1] = i;
    int idx = 0;
    while (v.size() > 1)
    {
        idx = (idx + 3 - 1) % v.size();
        v.erase(v.begin() + idx);
    }

    cout << v[0] << endl;

}

//方案三
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; ++i) q.push(i);

    int count = 0;
    while (q.size() > 1)
    {
        int front = q.front();//取出队头元素
        count++;
        q.pop();
        if (count == 3)
        {
            count = 0;
        }
        else
        {
            q.push(front);//插入到队尾
        }
    }
    cout << q.front() << endl;

}

//公式法
#include <stdio.h>
int main()
{
    int n, m, i, s = 0;
    scanf("%d%d", &n, &m);
    for (i = 2; i <= n; i++)
    {
        s = (s + m) % i;
    }
    printf("%d\n", s + 1);
    return 0;
}

