#include <iostream>
#include <stdio.h>

using namespace std;


void Change(int arr[], int n){
	int i = 0, j = n-1;
	while(i < j){
		while(i < j && arr[j] % 2 == 0){
			j--;
		}
		while(i < j && arr[i] % 2 == 1){
			i++;
		}
		if(i < j){
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}
}
int main(){
	int arr[] = {2, 14, 5, 6, 7, 12, 28, 13, 17, 86, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	Change(arr, n); 
	for(int i = 0; i < n; i++){
		cout<<arr[i] <<" ";
	}
}
