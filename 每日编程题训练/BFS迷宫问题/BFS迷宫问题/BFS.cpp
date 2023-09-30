//#include<iostream>
//#include <vector>
//#include<queue>
//using namespace std;
//
////迷宫数组
//vector<vector<int>> nums(100,vector<int>(100));
////该点是否被访问过
//vector<vector<bool>> Serch(100, vector<bool>(100,false));
//
////扩展数组右、下、左、上
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { 1,0,-1,0 };
//
//struct point
//{
//	point(int x,int y,int step)
//		:_x(x),_y(y),_step(step)
//	{}
//
//	int _x;
//	int _y;
//	int _step;
//};
//
//queue<point> q;
//
//int main()
//{
//	/*
//	5 4
//	1 1 4 3
//
//	1 1 2 1
//	1 1 1 1
//	1 1 2 1
//	1 2 1 1
//	1 1 1 2
//
//	*/
//	int row, col;
//	int beginx, beginy, endx, endy;
//
//	cin >> row >> col;
//	cin>> beginx>>beginy>> endx>> endy;
//	//填表
//	for(int i=1;i<=row;++i)
//	{
//		for(int j=1;j<=col;++j)
//		{
//			cin >> nums[i][j];
//		}
//	}
//
//	//BFS
//	
//	//起点入队
//	point start(beginx,beginy,0);
//	q.push(start);
//	//设置访问状态
//	Serch[beginx][beginy] = true;
//
//	//
//	bool flag = 0;
//	while (!q.empty())
//	{
//		//判断是否到达终点
//		int x = q.front()._x;
//		int y = q.front()._y;
//		if (x == endx && y == endy)
//		{
//			flag = 1;
//			cout << q.front()._step << endl;
//			break;
//		}
//
//		//没有到达，开始朝四个方向（右，下，左，上）扩展
//		for(int i=0;i<=3;++i)
//		{
//			int nextX, nextY;
//			nextX = x + dx[i];
//			nextY = y + dy[i];
//
//			//如果扩展点未被访问并且是空地，节点入队
//			if(Serch[nextX][nextY]==false && nums[nextX][nextY]==1)
//			{
//				//入队，并设置已访问
//				point tmp(nextX,nextY,q.front()._step+1);
//				q.push(tmp);
//				Serch[nextX][nextY]=true;
//			}
//		}
//
//		//更新完节点，队头出队
//		q.pop();
//	}
//	if (flag == 0) cout << "no" << endl;
//	return 0;
//}


//#include <iostream>  
//#include <vector>  
//#include <queue>  
//#include <unordered_map>
//
//using namespace std;
//
//// 迷宫数组  
//vector<vector<int>> nums(100, vector<int>(100));
//// 该点是否被访问过  
//vector<vector<bool>> Serch(100, vector<bool>(100, false));
//
//// 扩展数组右、下、左、上  
//int dx[4] = { 0, 1, 0, -1 };
//int dy[4] = { 1, 0, -1, 0 };
//
//struct point {
//    point(int x, int y, int step, pair<int, int > prev)
//        : _x(x), _y(y), _step(step)
//    {
//        _prev.first = prev.first;
//        _prev.second = prev.second;
//    }
//    point(){}
//
//    int _x;
//    int _y;
//    int _step;
//    pair<int,int> _prev; // 前一个点的坐标  
//};
//
//queue<point> q;
//// 存储每个节点信息
//vector<vector<point>> path(100, vector<point>(100));
//
//int main() {
//    /*
//    5 4
//    1 1 4 3
//
//    1 1 2 1
//    1 1 1 1
//    1 1 2 1
//    1 2 1 1
//    1 1 1 2
//    */
//    int row, col;
//    int beginx, beginy, endx, endy;
//
//    cin >> row >> col;
//    cin >> beginx >> beginy >> endx >> endy;
//    // 填表  
//    for (int i = 1; i <= row; ++i) {
//        for (int j = 1; j <= col; ++j) {
//            cin >> nums[i][j];
//        }
//    }
//
//    // BFS  
//
//    // 起点入队  
//    point start(beginx, beginy, 0, make_pair(0,0)); // 初始化前一个点为空的点  
//    q.push(start);
//    // 设置访问状态  
//    Serch[beginx][beginy] = true;
//    path[beginx][beginy]=start; // 将起点添加到路径中  
//
//    // bool flag = 0; // 不再需要这个标志，因为我们使用路径记录来检查是否到达终点  
//    while (!q.empty()) {
//        // 判断是否到达终点  
//        int x = q.front()._x;
//        int y = q.front()._y;
//        if (x == endx && y == endy) {
//            cout << "Steps: " << q.front()._step << endl;
//            cout << "Path: ";
//            
//            while (x != beginx || y != beginy) { // 回溯路径直到起点  
//                
//                cout << "(" << x << ", " << y << ") "; // 输出当前点的坐标  
//                point curr = path[x][y]; //访问当前节点  
//                x = curr._prev.first; // 回溯到前一个点的坐标  
//                y = curr._prev.second; // 回溯到前一个点的坐标 
//            }
//            break; // 到达终点，退出循环  
//        }
//
//        // 没有到达，开始朝四个方向（右，下，左，上）扩展  
//        for (int i = 0; i <= 3; ++i) {
//            int nextX, nextY;
//            nextX = x + dx[i];
//            nextY = y + dy[i];
//
//            // 如果扩展点未被访问并且是空地，节点入队  
//            if (Serch[nextX][nextY] == false && nums[nextX][nextY] == 1) {
//                // 入队，并设置已访问，同时记录当前点的前一个点坐标（即当前点）到路径中  
//                // 这里的_prev是当前点，因为还没有进行出队
//                point tmp(nextX, nextY, q.front()._step + 1, make_pair(q.front()._x, q.front()._y)); 
//                q.push(tmp);
//                Serch[nextX][nextY] = true; // 设置已访问  
//                path[nextX][nextY]=tmp; // 将扩展点添加到路径中  
//            }
//        }
//
//        // 更新完节点，队头出队  
//        q.pop();
//    }
//
//    // 如果没有找到路径，输出"no"  
//    if (path.empty()) {
//        cout << "no" << endl;
//    }
//
//    return 0;
//}







//好多人问怎么输出路径，现在来讲解
//为了更好的记录路径，我这里采取了手写队列的方式，跟视频中的代码类似
//思路：每次将队列中点的父亲节点记录下来，这样子就可以知道某个点是通过哪个点扩展而来，当我们输出路径的时候，采用递归就可以解决了，代码如下：

//struct note {
//	int x;//记录坐标(x,y)
//	int y;
//	int f; //记录是由谁扩展而来，即父亲节点是谁
//	int s;//记录步数
//};
//
//struct note que[2501];
//
////路径输出，用递归解决
//void f(int h)
//{
//	if (h == 0)return;
//	f(que[h].f);
//	cout << que[h].x << "," << que[h].y << endl;
//}
//
//void ttt()
//{
//	int a[51][51] = { 0 }, book[51][51] = { 0 };
//	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
//	int head, tail;
//	int i, j, k, n, m, startx, starty, p, q, tx, ty, flag;
//	scanf("%d%d", &n, &m);
//
//	for (int i = 1; i <= n; i++)
//		for (j = 1; j <= m; j++)
//			scanf("%d", &a[i][j]);
//	scanf("%d%d%d%d", &startx, &starty, &p, &q);
//
//	head = 1;
//	tail = 1;
//	que[tail].x = startx;
//	que[tail].y = starty;
//
//	//起点的父亲节点设置为0
//	que[tail].f = 0;
//	que[tail].s = 0;
//	tail++;
//	book[startx][starty] = 1;
//	flag = 0;
//	//手写队列，应该也容易写出吧
//	while (head < tail)
//	{
//		for (k = 0; k <= 3; k++)
//		{
//			tx = que[head].x + next[k][0];
//			ty = que[head].y + next[k][1];
//			if (tx<1 || tx>n || ty<1 || ty>m)
//				continue;
//			if (a[tx][ty] == 1 && book[tx][ty] == 0)
//			{
//				book[tx][ty] = 1;
//				//将可扩展的点入队，这里是手写队列，所以入队时，是tail++
//				que[tail].x = tx;
//				que[tail].y = ty;
//
//				//记录当前入队点的父亲节点，便于路径输出,因为是由队首扩展得到，所以父亲节点是head
//				que[tail].f = head;
//				que[tail].s = que[head].s + 1;
//				tail++;
//			}
//
//			//当入队的点到达了终点，就结束
//			if (tx == p && ty == q)
//			{
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 1)break;
//		head++;
//	}
//
//	if (flag == 1)
//	{
//		//输出队尾的步数，就是最终的答案
//
//		printf("%d\n", que[tail - 1].s);
//
//		//从队尾反向寻找路径，用递归就可以解决了
//		f(tail - 1);
//	}
//
//}


//DFS
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<iostream>
using namespace std;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int ans = 99999999;
int a[100][100];
int v[100][100];

//列，行，开始位置，结束位置
int n, m, startx, starty, p, q;
struct node {
    int x;
    int y;
};

//模拟栈
struct node s[100];
int top = 0;
int cnt = 1;

void dfs(int x, int y, int step)
{
    if (x == p && y == q)
    {
        cnt++;
        
        if (step < ans)
            ans = step;
        for (int i = 0; i <= top; i++)
        {
            cout << s[i].x << " " << s[i].y << endl;
        }

        return;
    }
    for (int k = 0; k < 4; k++)
    {
        int tx = x + dir[k][0];
        int ty = y + dir[k][1];

        if (tx<1 || tx>n || ty<1 || ty>m)
            continue;
        if (a[tx][ty] == 0 && v[tx][ty] == 0)
        {
            v[tx][ty] = 1;
            top++;
            s[top].x = tx;
            s[top].y = ty;

            dfs(tx, ty, step + 1);
            v[tx][ty] = 0;
            top--;
        }
    }
}
int main()
{

    scanf("%d%d%d%d%d%d", &n, &m, &startx, &starty, &p, &q);


    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);

    v[startx][starty] = 1;
    s[0].x = startx;
    s[0].y = starty;

    dfs(startx, starty, 0);
    printf("%d", ans);
    return 0;

}
