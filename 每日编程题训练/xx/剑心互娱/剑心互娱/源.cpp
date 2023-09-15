#include<iostream>
#include <vector>
using namespace std;


const int MOD = 1e9 + 7;
int Calc(int nNum) {
    /*int cnt = 0;
    int sum = 0;
    for (int left = 0, right = 1; left < right && right * 2 - 1 < nNum;) {
        if (sum == nNum) {
            cnt++;
            left = right - 1;
            sum = 2 * left - 1;
        }

        while (right * 2 - 1 < nNum && sum < nNum) {
            sum += (2 * right)-1;
            right++;
        }
        if (2 * left - 1 + 2 * (right-1) - 1 > nNum) {
            break;
        }
        while (left < right && sum > nNum) {
            left++;
            sum -= 2 * left - 1;
        }

    }
    return cnt;*/

    int left = 1;
    int ncount = 0;
    int sum = 0;
    for (int i = 1; i < nNum; i += 2) {
        sum += i;
        while (sum > nNum) {
            sum -= left;
            left += 2;
        }
        if (sum == nNum) {
            ncount++;
        }
    }

    return ncount;

}


int main()
{
    cout << Calc(12);
	return 0;
}