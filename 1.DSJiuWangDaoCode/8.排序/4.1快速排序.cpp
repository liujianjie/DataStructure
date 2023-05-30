#include <stdio.h>

int quicksort(int arr[], int i, int j){
	int pivot = arr[i];// ��׼
	// ������ߵ��� < pivot < �����ұߵ���
	while(i < j){// ����Ⱦ��˳� 
		// ���ұ߿�ʼ������ұ�pivotС�������ŵ����ȥ
		while(i < j && arr[j] >= pivot)// ע�⣺д��=�� 
			j--;
		arr[i] = arr[j];
		// ����߿�ʼ���ұ��ұ�pivot��������ŵ��ұ�ȥ
		while(i < j && arr[i] <= pivot) // ע�⣺д��=�� 
			i++;
		arr[j] = arr[i];
	} 
	// ȷ��pivot
	arr[i] = pivot;
	return i;// �����±� 
}

int partition(int arr[], int low, int high){
	if(low < high){// �����ڵ����������� ʱ�����Ҫ�� 
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
