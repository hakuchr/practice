// calc_s_test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>    
#include <algorithm>   
using namespace std;

void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void swap(int arr[], int i, int j);


void quickSort(int arr[], int left, int right){
	
	int len = sizeof(arr) / sizeof(arr[0]);
	if (left < right){
		int partitionIndex = partition(arr, left, right);
		quickSort(arr, left, partitionIndex-1);
		quickSort(arr, partitionIndex+1, right);
	}

}

int partition(int arr[], int left, int right){
	int pivot = left;
	int index = pivot + 1;
	for (int i = index; i <= right; i++){
		if (arr[i] < arr[pivot]){
			swap(arr, i, index);
			index++;
		}
	}
	swap(arr, pivot, index - 1);
	return index-1;
}

void swap(int arr[], int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int main(){	
	int x;
	int arr[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
	int len = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = len - 1;
	quickSort(arr, left, right);
	for (int i = 0; i < len; i++){
		cout << arr[i] <<' ';
	}
	cout << endl;
	cin >> x;
	return 0;
}

