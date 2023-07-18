#include <stdio.h>

void printArray(int arr[], int size){
	int i;
	for(i = 0; i < size; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");	
}

void merge(int arr[], int l, int m, int r){
    // Finish your code here.
    int i = 0; int j = 0; int k = 0;
    int leftSize = m - l + 1;
    int rightSize = r - m;
    
    // 創建左子陣列和右子陣列
    int left[leftSize];
	int right[rightSize];
	
	for(i = 0; i < leftSize; i++){
		left[i] = arr[l + i];
	}
	
	for(i = 0; i < rightSize; i++){
		right[i] = arr[m + 1 + i];
	}
	
	// 將左子陣列和右子陣列合併回原陣列 arr
    i = 0; // 左子陣列的索引
    j = 0; // 右子陣列的索引
    k = l; // 原陣列 arr 的索引
    
    // 將兩個子陣列中的元素按照順序合併到原始陣列中
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            k++; 
			i++;
        }
		else {
            arr[k] = right[j];
            k++; 
			j++;
        }
    }
    
    // 將左子陣列的剩餘元素複製到原陣列 arr
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    // 將右子陣列的剩餘元素複製到原陣列 arr
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is right index of the sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        // Sortfirst and second halves
    	mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


int main(void){
    int arr[] = {8,4,12,2,6,10,14,1,3,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
	printf("Input array: \n");
	printArray(arr, n);
	printf("\n");
	
	mergeSort(arr, 0, n-1);
	
	printf("Array after Merge Sort: \n");
	printArray(arr, n);
	
	return 0;
}
