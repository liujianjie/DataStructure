#include <stdio.h>


void selectSort(int arr[], int len){
	for(int i = 0; i < len - 1; i++){// ����Ҫn-1�� ,ÿ��ȷ��һ��λ�� 
		int min = arr[i];
		int pos = i;
		for(int j = i; j < len; j++){
			if(min > arr[j]){
				min = arr[j];
				pos = j;
			}
		}
		// ��i��λ�á�
		int temp = arr[i];
		arr[i] = arr[pos];
		arr[pos] = temp;
	}
}
// �Ż� 
void selectSort2(int arr[], int len){
	for(int i = 0; i < len - 1; i++){// ����Ҫn-1�� ,ÿ��ȷ��һ��λ�� 
		int min = i;
		for(int j = i + 1; j < len; j++){
			if(arr[min] > arr[j]){
				min = j;
			}
		}
		// ��i��λ�á�
		if(min != i){
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	
	}
}
int main(){
	int arr[] = {28, 12, 8, 98, 4, 56, 19, 38};
	int len = sizeof(arr)/sizeof(arr[0]);
	selectSort2(arr, len);
	for(int i = 0; i < len; i++){
		printf("%d\t", arr[i]);
	}
	
	return 0;
}
