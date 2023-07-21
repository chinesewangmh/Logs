#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include "heapSort.h"
#include "insertSort.h"
#include "MergeSort.hpp"
using namespace std;



int main()
{
	/*vector<int> v{ 9,1,4,6,5,2 };*/
	//Headsort<greater<int>> hs(v);
	//hs.headsort();
	//hs.print();
	/*int a[] = { 9,1,4,6,5,2 };
	heapSortC(a,6);*/


	//int  a[]={ 6, 1, 2, 7,6, 9, 3, 4, 5, 6, 8 };
	//int n = sizeof(a) / sizeof(a[0]);
	//insetSort(a,n);
	//quickSort3(a,0,n-1);
	int  a[] = { 10,6,7,1,3,9,4,2 };
	int n = sizeof(a) / sizeof(a[0]);

	MergeSort(a, n);
}