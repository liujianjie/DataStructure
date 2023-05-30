#include <stdio.h>

int quicksort(int arr[], int i, int j){
	int pivot = arr[i];// 基准
	// 数组左边的数 < pivot < 数组右边的数
	while(i < j){// 当相等就退出 
		// 从右边开始往左边找比pivot小的数，放到左边去
		while(i < j && arr[j] >= pivot)// 注意：写上=号 
			j--;
		arr[i] = arr[j];
		// 从左边开始往右边找比pivot大的数，放到右边去
		while(i < j && arr[i] <= pivot) // 注意：写上=号 
			i++;
		arr[j] = arr[i];
	} 
	// 确定pivot
	arr[i] = pivot;
	return i;// 返回下标 
}

int partition(int arr[], int low, int high){
	if(low < high){// 当大于等于两个数的 时候才需要排 
//		int pivotpos = quicksort(arr, low, high) ;
		int pivotpos = quicksort(arr, low, high) ;
		partition(arr, low, pivotpos - 1);
		partition(arr, pivotpos + 1, high);
	}
}

int main(){
	int arr[] = {49, 27, 13, 76, 97, 65, 38, 49};
	int high = sizeof(arr)/ sizeof(arr[0]) - 1;
	partition(arr, 0, high);
	for(int i = 0; i <= high; i++){
		printf("%d\t", arr[i]);
	}
	
	return 0;
	
}
