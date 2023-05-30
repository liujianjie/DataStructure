#include <stdio.h>

//int quicksort(int arr[], int i, int j){
//	int pivot = arr[i];// ��׼
//	// ������ߵ��� < pivot < �����ұߵ���
//	while(i < j){// ����Ⱦ��˳� 
//		// ���ұ߿�ʼ������ұ�pivotС�������ŵ����ȥ
//		while(i < j && arr[j] >= pivot)// ע�⣺д��=�� 
//			j--;
//		arr[i] = arr[j];
//		// ����߿�ʼ���ұ��ұ�pivot��������ŵ��ұ�ȥ
//		while(i < j && arr[i] <= pivot) // ע�⣺д��=�� 
//			i++;
//		arr[j] = arr[i];
//	} 
//	// ȷ��pivot
//	arr[i] = pivot;
//	return i;// �����±� 
//}

int quicksort(int arr[], int i, int j){
	// ������ߵ��� < pivot < �����ұߵ���
	while(i < j){// ����Ⱦ��˳� 
		// ���ұ߿�ʼ������ұ�pivotС�������ŵ����ȥ
		while(i < j && arr[i] % 2 != 0)// ע�⣺д��=�� 
			i++;
		// ����߿�ʼ���ұ��ұ�pivot��������ŵ��ұ�ȥ
		while(i < j && arr[j] % 2 != 1) // ע�⣺д��=�� 
			j--;
		if(i < j){
			int val = arr[i];
			arr[i] = arr[j];
			arr[j] = val;
			i++;
			j--;
		} 
	} 
	return i;// �����±� 
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

