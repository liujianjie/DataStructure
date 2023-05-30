#include <iostream> 
#include <stdio.h>


int ct=0;
// 书上例子。有哨兵
void ShellSortBook(int arr[], int len){
	int n = len - 1, j;
	// 外层是增量
	for(int d = n / 2; d >= 1; d /= 2){
		// 这层是每隔多少个是一个子表。但这里实现并不是真正的分割一个个子表，i++而是交替的进行切换子表 
		for(int i = 1 + d; i <= n; i++){// i = i+d，为了方便从后向前对比 
			if(arr[i - d] > arr[i]){// 这子表的两个元素存在逆序，需要把这之前逆序元素也处理好。 
				ct++;
				arr[0] = arr[i];// 保存在哨兵 
				//对这个子表进行排序 ,手动控制d的序列
				for(j = i - d; j >= 1 && arr[j] > arr[0];j -= d){
					arr[j + d] = arr[j];
				}
				arr[j + d] = arr[0];
			}
		}
	}
} 
void ShellSortMy(int arr[], int len){
	int n = len - 1, j;
	// 外层是增量
	for(int d = n / 2; d >= 1; d /= 2){
		// 这层是每隔多少个是一个子表。但这里实现并不是真正的分割一个个子表，i--而是交替的进行切换子表 
		for(int i = n; i >= 1; i--){// i = i+d，为了方便从后向前对比 
			if(arr[i - d] > arr[i]){// 这子表的两个元素存在逆序，需要把这之前逆序元素也处理好。 
				ct++;
				arr[0] = arr[i];// 保存在哨兵 
				//对这个子表进行排序 ,手动控制d的序列
				for(j = i - d; j >= 1 && arr[j] > arr[0];j -= d){
					arr[j + d] = arr[j];
				}
				arr[j + d] = arr[0];
			}
		}
	}
} 
int main(){
	int arr2[] = {0, 49, 38, 65, 97, 76, 13, 27, 49};
	int len2 = sizeof(arr2)/sizeof(arr2[0]);
	ShellSortBook(arr2, len2);
	for(int i = 1; i < len2; i++){
		printf("%d\t", arr2[i]);
	}
	printf("\n");
	printf("%d\t", ct);
	return 0;
}
