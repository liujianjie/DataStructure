#include <stdio.h>
#include <stdlib.h>
/*
��Ŀ���������򣬸�����ǰ�������ں� 
*/ 

// ����
void Sort(int arr[], int length){
	// ����ָ�룬i�ǿ�ָ�룬j����ָ�� 
	for(int i = 0, j = 0; i < length; i++){
		if(arr[i] < 0){
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			j++;
		}
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

