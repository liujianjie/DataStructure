#include <stdio.h>
#include <iostream> 
using namespace std;

void Bubble(int arr[], int n){
	bool b;
	for(int i = 0; i < n; i++){
		b = true;
		for(int j = n - 1; j > i; j--){
			if(arr[j - 1] > arr[j]){
				int t = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = t;
				b = false;
			}
		}
		if(b)
			return;
	}
}

void Print(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
int main(){
	// 0λ�ò���Ԫ��Ϊ�˸���ʵ����ȫ�������ṹ 
	int arr[] = {53, 17, 78, 9, 45, 65, 87, 32};
	int n = sizeof(arr) / sizeof(arr[0]);// n��ʵ��Ԫ�� 
	Bubble(arr, n);
	Print(arr, n);
	return 0;
}

