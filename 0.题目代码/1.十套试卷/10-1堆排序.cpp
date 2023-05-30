#include <stdio.h>

// ��׹
void Down(int arr[], int n, int k){// k�ǵڼ�����׹ 
	arr[0]  = arr[k];
	for(int i = k * 2; i <= n; i = i * 2){
		if(i + 1 <= n && arr[i] > arr[i + 1]){
			i++;
		}
		if(arr[i] > arr[0]){
			break;
		}
		arr[k] = arr[i];
		k = i;
	}
	arr[k] = arr[0];
} 
// ����
void Up(int arr[], int n, int k){
	arr[0] = arr[k];
	for(int i = k / 2; i >= 1; i /= 2){
		if(arr[i] > arr[0]){
			arr[k] = arr[i];
			k = i;
		}
	}
	arr[k] = arr[0];
}


// ���� 
void BuildMinHeap(int arr[], int n){
	for(int i = n / 2; i >= 1; i--){// �����һ��Ҷ�ӽ�㿪ʼ��׹ 
		Down(arr, n, i);
	}
}	
// ������
void HeapSort(int arr[], int n){
	for(int i = n; i > 1; i--){
		int t = arr[1];
		arr[1] = arr[i];
		arr[i] = t;
		Down(arr, i - 1, 1);//
	}
} 
// ����
void Insert(int arr[], int &n, int e) {
	n++;
	arr[n] = e;
	Up(arr, n, n);
}

// ɾ��
void Delete(int arr[], int &n, int k){
	arr[k] = arr[n];
	arr[n] = 0;
	n--;
	Down(arr, n, k);
} 


void Print(int arr[], int n){
	for(int i = 1; i <= n; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
int main(){
	// 0λ�ò���Ԫ��Ϊ�˸���ʵ����ȫ�������ṹ 
	int arr[] = {0, 53, 17, 78, 9, 45, 65, 87, 32, 0, 0, 0};
	int n = 8;// n��ʵ��Ԫ�� 
	BuildMinHeap(arr, n); 
	Print(arr, n);
	
	HeapSort(arr, n);
	Print(arr, n);
//	Insert(arr, n, 2);
//	Print(arr, n);
//	Delete(arr, n, 2);
//	Print(arr, n);
	
	return 0;
}

