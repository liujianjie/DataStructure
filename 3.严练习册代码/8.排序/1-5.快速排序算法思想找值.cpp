#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/*
题目：数组排序，负数在前，正数在后 
*/ 

// 解题
int Sort(int arr[], int low, int high, int key){
	while(low < high){
		while(low <= high && arr[high] > key){
			high--;
		}
		if(arr[high] == key){
			return high;
		}else{
			high--;
		}
		while(low <= high && arr[low] < key){
			low++;
		}
		if(arr[low] == key){
			return low;
		}else{
			low++;
		}
	}
	cout << "NOT FOUND" <<endl;
	return 0;
}
 
int main(){
	int e;
	// 前提还得排好序。。 
	int arr[] = {81, 12, 98, 45, 87, 13, 89, 9, 7, 23, 46};
//	int arr[] = {1, 3, 4, 5 ,6 ,7, 8,9, 12, 13, 45};
	int length = sizeof(arr) / sizeof(arr[0]);
	int pos = Sort(arr, 0, length - 1, 13);
	cout << pos;
}

