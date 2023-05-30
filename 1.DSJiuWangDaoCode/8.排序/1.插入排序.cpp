#include <iostream> 
#include <stdio.h>

// �������򣺺�һ���Ƿ��ǰ���С��С���ǾͲ��뵽ǰ�棬ǰ�����Ѿ�������� 
//void insertSort(int arr[], int len){
//	int j;
//	for(int i = 1; i < len; i++){
//		if(arr[i - 1] > arr[i]){// �Ƿ����� ��ǰһ�����ں�һ�� 
//			int temp = arr[i];
//			for(j = i; j > 0 && arr[j - 1] > temp; j--){// �Ӻ��濪ʼ������λ ��ע�������temp��������arr[j]�� 
//				arr[j] = arr[j - 1];
//			}
//			// ��j��λ�÷���temp 
//			arr[j] = temp;
//		}
//	}
//}

void insertSort(int arr[], int len){
	int j;
	for(int i = 1; i < len; i++){
		if(arr[i - 1] > arr[i]){
			int temp = arr[i];
			for(j = i; j > 0 && arr[j - 1] > temp; j--){
				arr[j] = arr[j - 1];
			}
			arr[j] = temp;
		}
	}
}
// �������ӡ����ڱ� 
void insertSortBook(int arr[], int len){
	int i, j;
	for(i = 2; i < len; i++){
		if(arr[i] < arr[i - 1]){
			arr[0] = arr[i];
			for(j = i - 1; arr[0] < arr[j]; j--){
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = arr[0];
		}
	}
} 

int main(){
	int arr[] = {23, 12, 4, 6, 34, 65, 45, 43};
	int len = sizeof(arr)/sizeof(arr[0]);
	insertSort(arr, len);
	for(int i = 0; i < len; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
	
	int arr2[] = {0, 23, 12, 4, 6, 34, 65, 45, 43};
	int len2 = sizeof(arr2)/sizeof(arr2[0]);
	insertSortBook(arr2, len2);
	for(int i = 1; i < len2; i++){
		printf("%d\t", arr2[i]);
	}
	
	return 0;
}
