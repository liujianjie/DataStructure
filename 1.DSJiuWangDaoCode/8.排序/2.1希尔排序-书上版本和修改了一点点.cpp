#include <iostream> 
#include <stdio.h>


int ct=0;
// �������ӡ����ڱ�
void ShellSortBook(int arr[], int len){
	int n = len - 1, j;
	// ���������
	for(int d = n / 2; d >= 1; d /= 2){
		// �����ÿ�����ٸ���һ���ӱ�������ʵ�ֲ����������ķָ�һ�����ӱ�i++���ǽ���Ľ����л��ӱ� 
		for(int i = 1 + d; i <= n; i++){// i = i+d��Ϊ�˷���Ӻ���ǰ�Ա� 
			if(arr[i - d] > arr[i]){// ���ӱ������Ԫ�ش���������Ҫ����֮ǰ����Ԫ��Ҳ����á� 
				ct++;
				arr[0] = arr[i];// �������ڱ� 
				//������ӱ�������� ,�ֶ�����d������
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
	// ���������
	for(int d = n / 2; d >= 1; d /= 2){
		// �����ÿ�����ٸ���һ���ӱ�������ʵ�ֲ����������ķָ�һ�����ӱ�i--���ǽ���Ľ����л��ӱ� 
		for(int i = n; i >= 1; i--){// i = i+d��Ϊ�˷���Ӻ���ǰ�Ա� 
			if(arr[i - d] > arr[i]){// ���ӱ������Ԫ�ش���������Ҫ����֮ǰ����Ԫ��Ҳ����á� 
				ct++;
				arr[0] = arr[i];// �������ڱ� 
				//������ӱ�������� ,�ֶ�����d������
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
