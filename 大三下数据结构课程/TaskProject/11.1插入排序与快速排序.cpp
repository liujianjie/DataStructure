#include <iostream>
using namespace std;

// 从小到大排序
// 插入排序
void InsertSort(int A[], int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		// 要改变当前i的位置
		if (A[i - 1] > A[i]) {
			A[0] = A[i];			  // 临时存储
			// 为了找到i的合适位置
			for (j = i - 1; A[j] > A[0]; j--) {
				A[j + 1] = A[j]; // 往后挪
			}
			A[j + 1] = A[0];     // 确定当前i的最终位置
		}
	}
}
// 快速排序
int Partition(int A[], int low, int high) {
	int pivot = A[low];	
	while (low < high) {
		// 从后往前扫描，遇到比pivot小的就退出，放到前面
		while (low < high && A[high] >= pivot) {
			high--;
		}
		A[low] = A[high];
		// 从前往后扫描，遇到比pivot大的就退出，放到后面
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
	int A[100];
	int n = 0;
	// 插入排序
	cout << "请输入一组数的大小：";
	cin >> n;
	cout << "请输入" << n << "个数据:" << endl;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	InsertSort(A, n);
	cout << "插入排序后的从小到大的序列是：" << endl;
	for (int i = 1; i <= n; i++) {
		cout << A[i] << " ";
	}
	cout << endl << endl;

	// 快速排序
	cout << "请输入一组数的大小：";
	cin >> n;
	cout << "请输入" << n << "个数据:" << endl;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	QuickSort(A, 1, n);
	cout << "快速排序后的从小到大的序列是：" << endl;
	for (int i = 1; i <= n; i++) {
		cout << A[i] << " ";
	}
	return 0;
}