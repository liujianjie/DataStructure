#include <stdio.h>

void partition(int arr[], int index, int high){
	// 交换第一个
	int t = arr[0] ;
	arr[0] = arr[index];
	arr[index] = t;
	int i = 0, j = high, x = arr[0];
	while(i < j){
		while(i < j && arr[j] >= x)
			j--;
		arr[i] = arr[j];
		while(i < j && arr[i] < x)
			i++;
		arr[j] = arr[i];
	}
	arr[i] = x;
}

int main(){
	int arr[] = {49, 27, 13, 76, 97, 65, 56, 38, 10};
	int high = sizeof(arr)/ sizeof(arr[0]) - 1;
	partition(arr, 6, high);
	
	for(int i = 0; i <= high; i++){
		printf("%d\t", arr[i]);
	}
	
	return 0;
	
}

//void partition(int arr[], int index, int high){
//	// 交换第一个
//	int t = arr[0] ;
//	arr[0] = arr[index];
//	arr[index] = t;
//	int i = 0, j = high, x = arr[0];
//	while(i < j){
//		while(i < j && arr[i] >= x)
//			j--;
//		if(i < j){
//			arr[i] = arr[j];
//			i++;
//		}
//		while(i < j && arr[i] < x)
//			i++;
//		if(i < j){
//			arr[j] = arr[i];
//			j--;
//		}
//	}
//	arr[i] = x;
//}


