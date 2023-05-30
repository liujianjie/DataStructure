#include <iostream>
using namespace std;

// 插入排序
void InsertSort(int A[], int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		if (A[i - 1] > A[i]) {
			A[0] = A[i];			  
			for (j = i - 1; A[j] > A[0]; j--) {
				A[j + 1] = A[j]; 
			}
			A[j + 1] = A[0];     
		}
	}
}
// 快速排序
int Partition(int A[], int low, int high) {
	int pivot = A[low];
	while (low < high) {
		while (low < high && A[high] >= pivot) {
			high--;
		}
		A[low] = A[high];
		while (low < high && A[low] <= pivot) {
			low++;
		}
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}
void QuickSort(int A[], int low, int high) {
	if (low < high) {
		int pivotPos = Partition(A, low, high);
		QuickSort(A, low, pivotPos - 1);
		QuickSort(A, pivotPos + 1, high);
	}
}

int main() {
	int A[] = { 0, 44, 12, 67, 21, 95, 98 };
	InsertSort(A, 6);
	cout << "插入排序后：" << endl;
	for (int i = 1; i <= 6; i++) {
		cout << A[i] << " ";
	}
	cout << endl;

	int A2[] = { 0, 12, 33, 30, 31, 15, 26 };
	QuickSort(A, 1, 6);
	cout << "快速排序后：" << endl;
	for (int i = 1; i <= 6; i++) {
		cout << A[i] << " ";
	}

	return 0;
}