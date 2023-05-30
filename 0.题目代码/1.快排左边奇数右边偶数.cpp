#include <stdio.h>

//int quicksort(int arr[], int i, int j){
//	int pivot = arr[i];// 基准
//	// 数组左边的数 < pivot < 数组右边的数
//	while(i < j){// 当相等就退出 
//		// 从右边开始往左边找比pivot小的数，放到左边去
//		while(i < j && arr[j] >= pivot)// 注意：写上=号 
//			j--;
//		arr[i] = arr[j];
//		// 从左边开始往右边找比pivot大的数，放到右边去
//		while(i < j && arr[i] <= pivot) // 注意：写上=号 
//			i++;
//		arr[j] = arr[i];
//	} 
//	// 确定pivot
//	arr[i] = pivot;
//	return i;// 返回下标 
//}

int quicksort(int arr[], int i, int j){
	// 数组左边的数 < pivot < 数组右边的数
	while(i < j){// 当相等就退出 
		// 从右边开始往左边找比pivot小的数，放到左边去
		while(i < j && arr[i] % 2 != 0)// 注意：写上=号 
			i++;
		// 从左边开始往右边找比pivot大的数，放到右边去
		while(i < j && arr[j] % 2 != 1) // 注意：写上=号 
			j--;
		if(i < j){
			int val = arr[i];
			arr[i] = arr[j];
			arr[j] = val;
			i++;
			j--;
		} 
	} 
	return i;// 返回下标 
}

int main(){
	int arr[] = {1, 2, 3, 7, 9, 24, 12, 5, 4, 8, 13, 10};
	int high = sizeof(arr)/ sizeof(arr[0]) - 1;
	quicksort(arr, 0, high);
	for(int i = 0; i <= high; i++){
		printf("%d\t", arr[i]);
	}
	
	return 0;
	
}

