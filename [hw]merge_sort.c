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
    
    // �Ыإ��l�}�C�M�k�l�}�C
    int left[leftSize];
	int right[rightSize];
	
	for(i = 0; i < leftSize; i++){
		left[i] = arr[l + i];
	}
	
	for(i = 0; i < rightSize; i++){
		right[i] = arr[m + 1 + i];
	}
	
	// �N���l�}�C�M�k�l�}�C�X�֦^��}�C arr
    i = 0; // ���l�}�C������
    j = 0; // �k�l�}�C������
    k = l; // ��}�C arr ������
    
    // �N��Ӥl�}�C�����������Ӷ��ǦX�֨��l�}�C��
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
    
    // �N���l�}�C���Ѿl�����ƻs���}�C arr
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    // �N�k�l�}�C���Ѿl�����ƻs���}�C arr
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
