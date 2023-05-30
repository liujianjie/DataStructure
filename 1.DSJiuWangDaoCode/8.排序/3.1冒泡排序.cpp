#include <stdio.h>

// 我的写法 
void BubbleSort(int arr[], int len){
	bool flag;
	for(int i = 0; i < len - 1; i++){// n - 1次排序 
		flag = false;
		for(int j = i + 1; j < len; j++){
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				flag = true;
			}
		}
		// 没有发生变化
		if(!flag){
			return;
		} 
	}
}
// 书上写法
void BubbleSortBook(int arr[], int n){
	bool flag = false;
	for(int i = 0; i < n - 1; i++){
		flag = false;
		for(int j = n - 1; j > i; j--){
			if(arr[j - 1] > arr[j]){
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				flag = true;
			}
		}
		if(!flag){
			return;
		}
	}
} 
int main(){
	int arr[] = {49, 27, 13, 76, 97, 65, 38, 49};
	int len = sizeof(arr)/ sizeof(arr[0]);
//	BubbleSort(arr, len);
	BubbleSortBook(arr, len);
	for(int i = 0; i < len; i++){
		printf("%d\t", arr[i]);
	}
	
	return 0;
	
}
