#ifndef __MERGESORT__H__
#define __MERGESORT__H__

#include<iostream>
#include<vector>
using namespace std;


//≈≈–Ú
template<typename T>
void merge(vector<T>& arr, int L, int M, int R) {
	int mid = M + 1;
	int start = L;
	int len = R - L + 1;
	vector<T> help(len);
	int j = 0;

	while (start <= M && mid <= R) {
		if (arr[start] <= arr[mid]) {
			help[j] = arr[start];
			start++;
		}
		else help[j] = arr[mid++];
		j++;
	}
	while (start <= M) {
		help[j++] = arr[start++];
	}
	while (mid <= R) {
		help[j++] = arr[mid++];
	}
	for (int i = 0; i < len; ++i) {
		arr[L++] = help[i];
	}
}


//«–∑÷
template<typename T>
void process(vector<T>& arr, int l, int r) {
	if (l >= r)
		return;
	int mid = l + ((r - l) >> 1);
	process(arr, l, mid);
	process(arr, mid + 1, r);
	merge(arr, l, mid, r);
}


template<typename T>
void mergeSort(vector<T>& arr) {
	process(arr, 0, arr.size() - 1);
}


#endif