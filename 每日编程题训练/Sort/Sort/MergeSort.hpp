void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end) {
		return;
	}
	int mid = (begin + end) / 2;
	//[begin, mid] [mid+1, end] 递归让子区间有序
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//归并[begin,mid],[mid+1,end]
	int begin1 = begin, end1 = mid;

	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2) {
		//等同于尾插
		if (a[begin1] <= a[begin2]) {
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	//如果前半组没走完
	while (begin1 <= end1) {
		tmp[i++] = a[begin1++];
	}
	//如果后半组没走完
	while (begin2 <= end2) {
		tmp[i++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}
void MergeSort(int* a, int n) {
	//动态开辟内存空间
	int* tmp = new int[n];

	_MergeSort(a, 0, n - 1, tmp);
	//释放内存空间
	delete[] tmp;
	tmp = NULL;
}
