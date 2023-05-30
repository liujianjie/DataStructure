#include <stdio.h>

// 下坠
void Down(int arr[], int n, int k){// k是第几个下坠 
	arr[0]  = arr[k];
	for(int i = k * 2; i <= n; i = i * 2){
		if(i + 1 <= n && arr[i] > arr[i + 1]){
			i++;
		}
		if(arr[i] > arr[0]){
			break;
		}
		arr[k] = arr[i];
		k = i;
	}
	arr[k] = arr[0];
} 
// 上滤
void Up(int arr[], int n, int k){
	arr[0] = arr[k];
	for(int i = k / 2; i >= 1; i /= 2){
		if(arr[i] > arr[0]){
			arr[k] = arr[i];
			k = i;
		}
	}
	arr[k] = arr[0];
}


// 建堆 
void BuildMinHeap(int arr[], int n){
	for(int i = n / 2; i >= 1; i--){// 从最后一个叶子结点开始下坠 
		Down(arr, n, i);
	}
}	
// 堆排序
void HeapSort(int arr[], int n){
	for(int i = n; i > 1; i--){
		int t = arr[1];
		arr[1] = arr[i];
		arr[i] = t;
		Down(arr, i - 1, 1);//
	}
} 
// 增加
void Insert(int arr[], int &n, int e) {
	n++;
	arr[n] = e;
	Up(arr, n, n);
}

// 删除
void Delete(int arr[], int &n, int k){
	arr[k] = arr[n];
	arr[n] = 0;
	n--;
	Down(arr, n, k);
} 


void Print(int arr[], int n){
	for(int i = 1; i <= n; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
int main(){
	// 0位置不放元素为了更好实现完全二叉树结构 
	int arr[] = {0, 53, 17, 78, 9, 45, 65, 87, 32, 0, 0, 0};
	int n = 8;// n个实际元素 
	BuildMinHeap(arr, n); 
	Print(arr, n);
	
	HeapSort(arr, n);
	Print(arr, n);
//	Insert(arr, n, 2);
//	Print(arr, n);
//	Delete(arr, n, 2);
//	Print(arr, n);
	
	return 0;
}

