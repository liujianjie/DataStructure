#include <iostream>
using namespace std;

// ��С��������
// ��������
void InsertSort(int A[], int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		// Ҫ�ı䵱ǰi��λ��
		if (A[i - 1] > A[i]) {
			A[0] = A[i];			  // ��ʱ�洢
			// Ϊ���ҵ�i�ĺ���λ��
			for (j = i - 1; A[j] > A[0]; j--) {
				A[j + 1] = A[j]; // ����Ų
			}
			A[j + 1] = A[0];     // ȷ����ǰi������λ��
		}
	}
}
// ��������
int Partition(int A[], int low, int high) {
	int pivot = A[low];	
	while (low < high) {
		// �Ӻ���ǰɨ�裬������pivotС�ľ��˳����ŵ�ǰ��
		while (low < high && A[high] >= pivot) {
			high--;
		}
		A[low] = A[high];
		// ��ǰ����ɨ�裬������pivot��ľ��˳����ŵ�����
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
	// ��������
	cout << "������һ�����Ĵ�С��";
	cin >> n;
	cout << "������" << n << "������:" << endl;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	InsertSort(A, n);
	cout << "���������Ĵ�С����������ǣ�" << endl;
	for (int i = 1; i <= n; i++) {
		cout << A[i] << " ";
	}
	cout << endl << endl;

	// ��������
	cout << "������һ�����Ĵ�С��";
	cin >> n;
	cout << "������" << n << "������:" << endl;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	QuickSort(A, 1, n);
	cout << "���������Ĵ�С����������ǣ�" << endl;
	for (int i = 1; i <= n; i++) {
		cout << A[i] << " ";
	}
	return 0;
}