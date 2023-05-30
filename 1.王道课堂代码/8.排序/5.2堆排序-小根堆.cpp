#include <stdio.h>

void Up(int arr[], int n, int k){
	// ����ִ�в�������Ҫ�ҵ����ڵ㣬Ȼ��һ·����������� 
	arr[0] = arr[k];
	for(int i = k / 2; i >= 1; i = i / 2){// i = i / 2д��������������� 
		if(arr[i] > arr[0]){// �������Լ��� 
			arr[k] = arr[i];// �븸��㽻��ֵ
			k = i;// k��Ϊ�����λ�� 
		}
	}
	// ����ȷ��kλ��
	arr[k] = arr[0];
}
// ����=��׹ 
void Down(int arr[], int n, int k){// n���ж��ٸ�Ԫ�أ�i�ǵ�ǰ�ڼ�����׹ 
	arr[0] = arr[k];// 0λ�ñ���k���ֵ 
	for(int i = k * 2; i <= n; i *= 2){// ��ʼiΪk�����㣬 ÿ������2���ǲ��ϵ��������������� 
		if(i + 1 <= n && arr[i] > arr[i + 1]){// �ȶ����ҽ��Աȣ�ѡ����С�����±� 
			i++;
		}
		// !---����д���--------- 
		if(arr[0] < arr[i]){// ��������С�����ҽ���ʾ����С���Ѿ��˳�����ס��Ҫ�ñ����arr[0],��Ϊk��ֵ��� 
			break; 
		}
		// �����������ӽ���ֵ���ӽ�����ϡ����Ҹ�����Ϊ�ӽ���λ�ã��������Ҫ�������Լ��ӽ����׹
		arr[k] = arr[i];// ����Ԫ�� 
		k = i;// �������±�Ϊ�ӽ����±꣬�����ٴη������� 
	}
	// ȷ����һ��ʼk���Ԫ��ֵ��λ��
	arr[k]  = arr[0];
}

// ����
void BuildMinHeap(int arr[], int n){
	// �ӷ�֧��㿪ʼ�����ڵ�������˼���
	for(int i = n / 2; i >= 1; i--){
		Down(arr, n, i);
	} 
}

// ������
void HeapSort(int arr[], int n){
	// ÿ��ѡ�������Ԫ�ص�ֵ�ٱ���С���ѣ�ֱ��n - 1�����Ƕ����� �����һ������������ 
	// ��β��㿪ʼ����ͷ��㽻��ֵ��������������Ԫ��ֵ��׹
	for(int i = n; i > 1; i--){
		int temp = arr[1];
		arr[1] = arr[i];
		arr[i] = temp;
		Down(arr, i - 1, 1);// ÿ�εĽ����-1,�Ӹ����1��ʼ��׹ 
	} 
}

// ����
void InsertValue(int arr[], int &n, int e){
	// ��ĩβ����
	n++;
	arr[n] = e;
	// ִ������ 
	Up(arr, n, n);
	// Ҳ����ִ�����ˣ�����ע���Ǵӵ����½���
//	BuildMaxHeap(arr, n);
}


// ��iλ��ɾ�� 
void DeleteValue(int arr[], int &n, int i){
	// ��ĩβ����λ��,��ִ�����˼��� 
	arr[i] = arr[n];
	arr[n] = 0;
	n--;
	Down(arr, n, i);
	
}
int main(){
	// 0λ�ò���Ԫ��Ϊ�˸���ʵ����ȫ�������ṹ 
	int arr[] = {0, 53, 17, 78, 9, 45, 65, 87, 32, 0, 0, 0};
	int n = 8;// n��Ԫ�� 
	BuildMinHeap(arr, n);
//	HeapSort(arr, n);
	InsertValue(arr, n, 13);
	InsertValue(arr, n, 46);
	DeleteValue(arr, n, 2);// ɾ��2��λ����13 
	for(int i = 1; i <= n; i++){
		printf("%d\t", arr[i]);
	}
	
	return 0;
}
