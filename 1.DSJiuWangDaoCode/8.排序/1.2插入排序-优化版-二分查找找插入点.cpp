#include <iostream> 
#include <stdio.h>

// �������ӡ����ڱ�+���� 
void insertSortBook(int arr[], int len){
	int i, j, low, high, mid;
	for(i = 2; i < len; i++){
		if(arr[i] < arr[i - 1]){
			arr[0] = arr[i];// �ŵ��ڱ�λ�� 
			// �ҵ������
			low = 1;
			high = i - 1;
			while(low <= high){
				mid = (low + high) / 2;
				if(arr[0] < arr[mid]){
					high = mid - 1;
				}else{
					low = mid + 1;
				}
			}
			// [low,i-1]�ƶ�
			for(j = i - 1; j >= low; j--){
				arr[j + 1] = arr[j];
			}
			arr[low] = arr[0];
		}
	}
} 

int main(){
	int arr2[] = {0, 98, 80, 70, 60, 50, 40, 30, 20, 10};
	int len2 = sizeof(arr2)/sizeof(arr2[0]);
	insertSortBook(arr2, len2);
	for(int i = 1; i < len2; i++){
		printf("%d\t", arr2[i]);
	}
	
	return 0;
}
