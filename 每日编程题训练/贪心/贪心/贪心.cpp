#include<iostream>
#include <vector>
#include <queue>
using namespace std;

//柠檬水找零
bool lemonadeChange(vector<int>& bills)
{
    int five = 0, ten = 0;
    for (auto e : bills)
    {
        if (e == 5) five++;
        else if (e == 10)
        {
            if (five == 0)
            {
                return false;
            }
            else
            {
                ten++;
                five--;
            }
        }
        else//20
        {
            if (ten && five)//贪心策略
            {
                ten--;
                five--;
            }
            else if (five >= 3)
            {
                five -= 3;
            }
            else
                return false;
        }
    }

    return true;
}

//数组减到一半需要的最少次数
int halveArray(vector<int>& nums)
{
    priority_queue<double> pq;
    double sum = 0;
    for (auto e : nums) pq.push(e),sum+=e;

    int cnt = 0;
    double cur = sum;
    while (cur>=sum/2.0)
    {
        int top = pq.top();
        pq.pop();
        pq.push(top / 2.0);
        cur -= top / 2.0;
        cnt++;
    }
    return cnt;
}

#include <string>
//最大数
string largestNumber(vector<int>& nums)
{
    vector<string> vs;
    for (auto& s : nums)
        vs.push_back(to_string(s));
    sort(vs.begin(), vs.end(), [](const string& s1 ,const string& s2) 
        {
            return s1 + s2 > s2 + s1;
        });

    string str;
    for (auto& s : vs) str += s;
    if (str[0] == '0') return "0";
    return str;
}
int main()
{

	return 0;
}