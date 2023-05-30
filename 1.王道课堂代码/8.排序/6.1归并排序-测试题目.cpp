#include <stdio.h>
#include <stdlib.h> 

int *B;

// LeetCode的方法，比较稳
void MergeLeetCode(char arr[], int low, int mid, int high){
	int i = low;// 左边数组起始位置，结束位置是mid 
	int j = mid + 1;// 右边数组起始位置，结束位置是high 
	int k = low;// 数组合并范围的起始位置 
	while(i <= mid || j <= high){// 有数值就一直继续 
		// 一次放一个比较好，所以用else，不然可能会越界!!!!!!! 
		// 1.要想放入左值。1.要么右值空了。2.要么两个都没空，但是左值比右值小
		if(i <= mid && (j > high || arr[i] <= arr[j])){// 注意是 <=才能维护稳定 
			B[k++] = arr[i++];
		}
		// 2.要想放入右值。1.要么左值空了。2.要么两个都没空，但是右值比左值小
		else if(j <= high || (i > mid || arr[j] < arr[i])){
			B[k++] = arr[j++];
		} 
	} 
	// 将临时的排好序的值放入原数组中
	for(int z = low; z <= high; z++){
		arr[z] = B[z];
	} 
}
// 分开两个序列 
void MergeSortLeetCode(char arr[], int low, int high){
	if(low < high){// 一个数就不要再分了 
		int mid = (low + high) / 2;// 中间分开
		// 先分
		MergeSortLeetCode(arr, low, mid);
		MergeSortLeetCode(arr, mid + 1, high);
		
		// 再和 
		MergeLeetCode(arr, low, mid, high);
		printf("low:%d,mid:%d,high:%d\n", low, mid, high);
		for(int i = 1; i <= high; i++){
			printf("%c\t", arr[i]);
		}
		printf("\n");
	}
}
int main(){
	// 0位置不放元素为了更好实现完全二叉树结构 
	char arr[] = {0, 'Q', 'D', 'F', 'X', 'A', 'P', 'N', 'B', 'Y', 'M', 'C', 'W' };
	int high = sizeof(arr)/sizeof(arr[0]) - 1;
	B = (int*)malloc(sizeof(int) * (high + 1));
	
	MergeSortLeetCode(arr, 1, high);
	printf("\n");
	for(int i = 1; i <= high; i++){
		printf("%c\t", arr[i]);
	}
	printf("\n");
	
	return 0;
}
