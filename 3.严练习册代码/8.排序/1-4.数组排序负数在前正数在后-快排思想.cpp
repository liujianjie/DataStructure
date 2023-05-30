#include <stdio.h>
#include <stdlib.h>
/*
��Ŀ���������򣬸�����ǰ�������ں� 
�ÿ���˼�� 
*/ 

// ����
void Sort(int arr[], int length){
	int low = 0, high = length - 1; 
	while(low < high){
		while(low < high && arr[high] > 0){
			high--;
		}
		while(low < high && arr[low] < 0){
			low++;
		}
		int t = arr[low];
		arr[low] = arr[high];
		arr[high] = t;
		// ǰ��
		low++;
		high--; 
	}
}
 
int main(){
	int e;
	int arr[] = {12, 8, 9, -1, 2, -4, 4, 6, -5, 8, 9, -7, 1, -4};
	int length = sizeof(arr) / sizeof(arr[0]);
	Sort(arr, length);
	for(int i = 0; i < length; i++){
		printf("%d\t", arr[i]);
	}
}

