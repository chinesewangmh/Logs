//#include<iostream>
//#include <vector>
//#include<queue>
//using namespace std;
//
////�Թ�����
//vector<vector<int>> nums(100,vector<int>(100));
////�õ��Ƿ񱻷��ʹ�
//vector<vector<bool>> Serch(100, vector<bool>(100,false));
//
////��չ�����ҡ��¡�����
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
//	//���
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
//	//������
//	point start(beginx,beginy,0);
//	q.push(start);
//	//���÷���״̬
//	Serch[beginx][beginy] = true;
//
//	//
//	bool flag = 0;
//	while (!q.empty())
//	{
//		//�ж��Ƿ񵽴��յ�
//		int x = q.front()._x;
//		int y = q.front()._y;
//		if (x == endx && y == endy)
//		{
//			flag = 1;
//			cout << q.front()._step << endl;
//			break;
//		}
//
//		//û�е����ʼ���ĸ������ң��£����ϣ���չ
//		for(int i=0;i<=3;++i)
//		{
//			int nextX, nextY;
//			nextX = x + dx[i];
//			nextY = y + dy[i];
//
//			//�����չ��δ�����ʲ����ǿյأ��ڵ����
//			if(Serch[nextX][nextY]==false && nums[nextX][nextY]==1)
//			{
//				//��ӣ��������ѷ���
//				point tmp(nextX,nextY,q.front()._step+1);
//				q.push(tmp);
//				Serch[nextX][nextY]=true;
//			}
//		}
//
//		//������ڵ㣬��ͷ����
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
//// �Թ�����  
//vector<vector<int>> nums(100, vector<int>(100));
//// �õ��Ƿ񱻷��ʹ�  
//vector<vector<bool>> Serch(100, vector<bool>(100, false));
//
//// ��չ�����ҡ��¡�����  
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
//    pair<int,int> _prev; // ǰһ���������  
//};
//
//queue<point> q;
//// �洢ÿ���ڵ���Ϣ
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
//    // ���  
//    for (int i = 1; i <= row; ++i) {
//        for (int j = 1; j <= col; ++j) {
//            cin >> nums[i][j];
//        }
//    }
//
//    // BFS  
//
//    // ������  
//    point start(beginx, beginy, 0, make_pair(0,0)); // ��ʼ��ǰһ����Ϊ�յĵ�  
//    q.push(start);
//    // ���÷���״̬  
//    Serch[beginx][beginy] = true;
//    path[beginx][beginy]=start; // �������ӵ�·����  
//
//    // bool flag = 0; // ������Ҫ�����־����Ϊ����ʹ��·����¼������Ƿ񵽴��յ�  
//    while (!q.empty()) {
//        // �ж��Ƿ񵽴��յ�  
//        int x = q.front()._x;
//        int y = q.front()._y;
//        if (x == endx && y == endy) {
//            cout << "Steps: " << q.front()._step << endl;
//            cout << "Path: ";
//            
//            while (x != beginx || y != beginy) { // ����·��ֱ�����  
//                
//                cout << "(" << x << ", " << y << ") "; // �����ǰ�������  
//                point curr = path[x][y]; //���ʵ�ǰ�ڵ�  
//                x = curr._prev.first; // ���ݵ�ǰһ���������  
//                y = curr._prev.second; // ���ݵ�ǰһ��������� 
//            }
//            break; // �����յ㣬�˳�ѭ��  
//        }
//
//        // û�е����ʼ���ĸ������ң��£����ϣ���չ  
//        for (int i = 0; i <= 3; ++i) {
//            int nextX, nextY;
//            nextX = x + dx[i];
//            nextY = y + dy[i];
//
//            // �����չ��δ�����ʲ����ǿյأ��ڵ����  
//            if (Serch[nextX][nextY] == false && nums[nextX][nextY] == 1) {
//                // ��ӣ��������ѷ��ʣ�ͬʱ��¼��ǰ���ǰһ�������꣨����ǰ�㣩��·����  
//                // �����_prev�ǵ�ǰ�㣬��Ϊ��û�н��г���
//                point tmp(nextX, nextY, q.front()._step + 1, make_pair(q.front()._x, q.front()._y)); 
//                q.push(tmp);
//                Serch[nextX][nextY] = true; // �����ѷ���  
//                path[nextX][nextY]=tmp; // ����չ����ӵ�·����  
//            }
//        }
//
//        // ������ڵ㣬��ͷ����  
//        q.pop();
//    }
//
//    // ���û���ҵ�·�������"no"  
//    if (path.empty()) {
//        cout << "no" << endl;
//    }
//
//    return 0;
//}







//�ö�������ô���·��������������
//Ϊ�˸��õļ�¼·�����������ȡ����д���еķ�ʽ������Ƶ�еĴ�������
//˼·��ÿ�ν������е�ĸ��׽ڵ��¼�����������ӾͿ���֪��ĳ������ͨ���ĸ�����չ���������������·����ʱ�򣬲��õݹ�Ϳ��Խ���ˣ��������£�

//struct note {
//	int x;//��¼����(x,y)
//	int y;
//	int f; //��¼����˭��չ�����������׽ڵ���˭
//	int s;//��¼����
//};
//
//struct note que[2501];
//
////·��������õݹ���
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
//	//���ĸ��׽ڵ�����Ϊ0
//	que[tail].f = 0;
//	que[tail].s = 0;
//	tail++;
//	book[startx][starty] = 1;
//	flag = 0;
//	//��д���У�Ӧ��Ҳ����д����
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
//				//������չ�ĵ���ӣ���������д���У��������ʱ����tail++
//				que[tail].x = tx;
//				que[tail].y = ty;
//
//				//��¼��ǰ��ӵ�ĸ��׽ڵ㣬����·�����,��Ϊ���ɶ�����չ�õ������Ը��׽ڵ���head
//				que[tail].f = head;
//				que[tail].s = que[head].s + 1;
//				tail++;
//			}
//
//			//����ӵĵ㵽�����յ㣬�ͽ���
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
//		//�����β�Ĳ������������յĴ�
//
//		printf("%d\n", que[tail - 1].s);
//
//		//�Ӷ�β����Ѱ��·�����õݹ�Ϳ��Խ����
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

//�У��У���ʼλ�ã�����λ��
int n, m, startx, starty, p, q;
struct node {
    int x;
    int y;
};

//ģ��ջ
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
