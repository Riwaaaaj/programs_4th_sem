
#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int h){
	int n1 = m - l + 1; // no. of items in left sub array
	int n2 = h - m; // no. of items in right sub array
	
	// temp arrays
	int L[n1];
	int R[n2];
	
	
	// copy data to temp array
	for(int i = 0; i < n1; i++){
		L[i] = arr[l + i];
	}
	for(int i = 0; i < n2; i++){
		R[i] = arr[m + 1 + i];
	}
	
	// merge temp arrays
	int i = 0;
	int j = 0;
	int k = l;
	
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			i++;
			k++;
		}
		else{
			arr[k] = R[j];
			j++;
			k++;
		}
	}
	// copying reaming items in left array
	while(i < n1){
		arr[k++] = L[i++];
	}
	// copying reaming items in right array
	while(j < n2){
		arr[k++] = R[j++];
	}
}

void merge_sort(int arr[], int l, int h){
	if(l < h){
		int mid = l + (h - l) / 2;
		merge_sort(arr, l, mid);
		merge_sort(arr, mid+1, h);
		merge(arr, l, mid, h);
	}
}

void display_array(int arr[], int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	
	int arr[] = {5, 3, 1, 4, 2};
	
	merge_sort(arr, 0, 4);
	display_array(arr, 5);
	
	
	return 0;
}
