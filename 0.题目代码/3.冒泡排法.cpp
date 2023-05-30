#include <stdio.h>

void bubble(int arr[], int n){
	for(int i = 1; i <= n-1; i++){// 次数 
		for(int j = 0; j < n - i; j++){// n-i越来越小，从后往前确定的值 
			if(arr[j] > arr[j + 1]){
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main(){
	int arr[] = {49, 27, 13, 76, 97, 65, 56, 38, 10};
	int n = sizeof(arr)/ sizeof(arr[0]);
	bubble(arr, n);
	
	for(int i = 0; i < n; i++){
		printf("%d\t", arr[i]);
	}
	
	return 0;
	
}


