#include <stdio.h>

int Find(int low, int high, int findv, int arr[]){
	while(low <= high){// 容易错的地方，是<=,不是< 
		int mid = (low + high) / 2;
		if(findv == arr[mid]){
			return mid;// 应该是返回mid+1是位序，mid是下标
		}else if(findv < arr[mid]){
			high = mid - 1;
		}else if(findv > arr[mid]){
			low = mid + 1;
		}
	}
	return -1;
}
int main()
{
	int arr[] = {4, 18, 29, 39, 49, 54, 65, 75, 87, 98, 129};
	int low = 0, high = sizeof(arr) / sizeof(arr[0]) - 1;
	int findv = 72;
	int pos = Find(low, high, findv, arr);
	printf("%d\n", pos);
	return 0;
}


// 测试代码
//int main()
//{
//	int ar[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//	int a = -3, m = 24;
//	int b = a % m; 
//	printf("%d\n", (a % m));
//	printf("%d\n", *(ar + 3));
//	printf("%d\n", ar[-3]);
//	printf("%d\n", *(ar - 3)); 
//	return 0;
//}
