#include <stdio.h>
#include <stdlib.h> 

int *B;
// �������� �ϲ��ҵ�һ��д�ķ��� 
void Merge(int arr[], int low, int mid, int high){
	int i = low;// ���������ʼλ�ã�����λ����mid 
	int j = mid + 1;// �ұ�������ʼλ�ã�����λ����high 
	int k = low;// ����ϲ���Χ����ʼλ�� 
	while(i <= mid || j <= high){// ����ֵ��һֱ���� 
		// һ�η�һ���ȽϺã�������else����Ȼ���ܻ�Խ��!!!!!!! 
		// 1.Ҫ�������ֵ��1.Ҫô��ֵ���ˡ�2.Ҫô������û�գ�������ֵ����ֵС
		if(j > high || (i <= mid && j <= high && arr[i] <= arr[j])){// ע���� <=����ά���ȶ� 
			B[k++] = arr[i++];
		}
		// 2.Ҫ�������ֵ��1.Ҫô��ֵ���ˡ�2.Ҫô������û�գ�������ֵ����ֵС
		else if(i > mid || (i <= mid && j <= high && arr[j] < arr[i])){
			B[k++] = arr[j++];
		} 
	} 
	// ����ʱ���ź����ֵ����ԭ������
	for(int z = low; z <= high; z++){
		arr[z] = B[z];
	} 
}
// LeetCode�ķ������Ƚ���
void MergeLeetCode(int arr[], int low, int mid, int high){
	int i = low;// ���������ʼλ�ã�����λ����mid 
	int j = mid + 1;// �ұ�������ʼλ�ã�����λ����high 
	int k = low;// ����ϲ���Χ����ʼλ�� 
	while(i <= mid || j <= high){// ����ֵ��һֱ���� 
		// һ�η�һ���ȽϺã�������else����Ȼ���ܻ�Խ��!!!!!!! 
		// 1.Ҫ�������ֵ��1.Ҫô��ֵ���ˡ�2.Ҫô������û�գ�������ֵ����ֵС
		if(i <= mid && (j > high || arr[i] <= arr[j])){// ע���� <=����ά���ȶ� 
			B[k++] = arr[i++];
		}
		// 2.Ҫ�������ֵ��1.Ҫô��ֵ���ˡ�2.Ҫô������û�գ�������ֵ����ֵС
		else if(j <= high || (i > mid || arr[j] < arr[i])){
			B[k++] = arr[j++];
		} 
	} 
	// ����ʱ���ź����ֵ����ԭ������
	for(int z = low; z <= high; z++){
		arr[z] = B[z];
	} 
}
// �ֿ��������� 
void MergeSort(int arr[], int low, int high){
	if(low < high){// һ�����Ͳ�Ҫ�ٷ��� 
		int mid = (low + high) / 2;// �м�ֿ�
		// �ȷ�
		MergeSort(arr, low, mid);// ע����mid������mid-1 ����������� 
		MergeSort(arr, mid + 1, high); 
		// �ٺ� 
		printf("low:%d,mid:%d,high:%d\n", low, mid, high); 
		Merge(arr, low, mid, high);
	}
}
// �ֿ��������� 
void MergeSortLeetCode(int arr[], int low, int high){
	if(low < high){// һ�����Ͳ�Ҫ�ٷ��� 
		int mid = (low + high) / 2;// �м�ֿ�
		// �ȷ�
		MergeSortLeetCode(arr, low, mid);
		MergeSortLeetCode(arr, mid + 1, high);
		
		// �ٺ� 
		MergeLeetCode(arr, low, mid, high);
	}
}
int main(){
	// 0λ�ò���Ԫ��Ϊ�˸���ʵ����ȫ�������ṹ 
	int arr[] = {0, 38, 49, 76, 65, 49, 97, 13, 49, 27, 34, 12, 34 };
	int arr2[] = {0, 38, 49, 76, 65, 49, 97, 13, 49, 27 };
	int high = sizeof(arr)/sizeof(arr[0]) - 1;
	B = (int*)malloc(sizeof(int) * (high + 1));
	
	MergeSort(arr, 1, high);
	MergeSortLeetCode(arr2, 1, high);
	for(int i = 1; i <= high; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
	for(int i = 1; i <= high; i++){
		printf("%d\t", arr2[i]);
	}
	
	return 0;
}
