#include <stdio.h>

void Up(int arr[], int n, int k){
	// 向上执行操作，需要找到父节点，然后一路上升到根结点 
	arr[0] = arr[k];
	for(int i = k / 2; i >= 1; i = i / 2){// i = i / 2写错过！！！！！！ 
		if(arr[i] > arr[0]){// 父结点比自己大 
			arr[k] = arr[i];// 与父结点交换值
			k = i;// k变为父结点位置 
		}
	}
	// 最终确定k位置
	arr[k] = arr[0];
}
// 下滤=下坠 
void Down(int arr[], int n, int k){// n是有多少个元素，i是当前第几个下坠 
	arr[0] = arr[k];// 0位置保存k结点值 
	for(int i = k * 2; i <= n; i *= 2){// 初始i为k的左结点， 每次增长2倍是不断的往子树下面下滤 
		if(i + 1 <= n && arr[i] > arr[i + 1]){// 先对左右结点对比，选出更小结点的下标 
			i++;
		}
		// !---这里写错过--------- 
		if(arr[0] < arr[i]){// 如果父结点小于左右结点表示满足小根堆就退出，记住需要用保存的arr[0],因为k的值会变 
			break; 
		}
		// 交换父结点和子结点的值，子结点往上。并且父结点变为子结点的位置，父结点需要继续往自己子结点下坠
		arr[k] = arr[i];// 交换元素 
		k = i;// 父结点的下标为子结点的下标，即可再次发生下滤 
	}
	// 确定了一开始k结点元素值的位置
	arr[k]  = arr[0];
}

// 建堆
void BuildMinHeap(int arr[], int n){
	// 从分支结点开始到根节点进行下滤即可
	for(int i = n / 2; i >= 1; i--){
		Down(arr, n, i);
	} 
}

// 堆排序
void HeapSort(int arr[], int n){
	// 每次选出根结点元素的值再保持小根堆，直至n - 1个就是堆排序 ，最后一个不用排序了 
	// 从尾结点开始，与头结点交换值，再让新上来的元素值下坠
	for(int i = n; i > 1; i--){
		int temp = arr[1];
		arr[1] = arr[i];
		arr[i] = temp;
		Down(arr, i - 1, 1);// 每次的结点数-1,从根结点1开始下坠 
	} 
}

// 插入
void InsertValue(int arr[], int &n, int e){
	// 在末尾插入
	n++;
	arr[n] = e;
	// 执行上滤 
	Up(arr, n, n);
	// 也可以执行下滤，不过注意是从得重新建堆
//	BuildMaxHeap(arr, n);
}


// 在i位置删除 
void DeleteValue(int arr[], int &n, int i){
	// 与末尾交换位置,再执行下滤即可 
	arr[i] = arr[n];
	arr[n] = 0;
	n--;
	Down(arr, n, i);
	
}
int main(){
	// 0位置不放元素为了更好实现完全二叉树结构 
	int arr[] = {0, 53, 17, 78, 9, 45, 65, 87, 32, 0, 0, 0};
	int n = 8;// n个元素 
	BuildMinHeap(arr, n);
//	HeapSort(arr, n);
	InsertValue(arr, n, 13);
	InsertValue(arr, n, 46);
	DeleteValue(arr, n, 2);// 删除2的位置是13 
	for(int i = 1; i <= n; i++){
		printf("%d\t", arr[i]);
	}
	
	return 0;
}
