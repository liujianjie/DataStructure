#include <stdio.h>
#include <stdlib.h> 

int *B;

// LeetCode�ķ������Ƚ���
void MergeLeetCode(char arr[], int low, int mid, int high){
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
void MergeSortLeetCode(char arr[], int low, int high){
	if(low < high){// һ�����Ͳ�Ҫ�ٷ��� 
		int mid = (low + high) / 2;// �м�ֿ�
		// �ȷ�
		MergeSortLeetCode(arr, low, mid);
		MergeSortLeetCode(arr, mid + 1, high);
		
		// �ٺ� 
		MergeLeetCode(arr, low, mid, high);
		printf("low:%d,mid:%d,high:%d\n", low, mid, high);
		for(int i = 1; i <= high; i++){
			printf("%c\t", arr[i]);
		}
		printf("\n");
	}
}
int main(){
	// 0λ�ò���Ԫ��Ϊ�˸���ʵ����ȫ�������ṹ 
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
