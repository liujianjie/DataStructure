#include <iostream> 
#include <stdio.h>

using namespace std;

int BinarySearch(int arr[], int val, int n){
	int low = 0, high = n - 1, mid;
	while(low <= high){
		mid = (low + high) / 2;
		if(arr[mid] < val){
			low = mid + 1;
		}else if(arr[mid] > val){
			high = mid - 1;
		}else{
			return mid + 1;
		}
	}
	return -1;
}
int main(){
	int arr[] = {1, 4, 6, 8, 9, 10, 12, 18, 19, 29, 39, 49};
	int n = sizeof(arr) / sizeof(arr[0]);
	int val = 3;
	int i = BinarySearch(arr, val, n);
	cout<<val<<"ËùÔÚÎ»ÖÃ:"<<i<<endl;
}
