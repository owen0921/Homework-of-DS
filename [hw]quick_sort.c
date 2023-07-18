#include <stdio.h>
#include <time.h>
#define SIZE 20
#define	MAX 100 
#define SWAP(x,y) {int t; t = x; x = y; y = t;}


void genRandomIntArry(int arr[], int sizem, int max);
void printArray(int arr[], int size);
int partition(int[], int, int); 
void quickSort(int[], int, int);

int main(void){
	
    int arr[SIZE] = {0};
    genRandomIntArry(arr, SIZE, MAX);
    

	printf("before sorting\n");
	printArray(arr, SIZE);
	
	// implement the sorting algorithm
	//sorting(arr);
	quickSort(arr, 0, SIZE-1);
	
	
	printf("after sorting\n");
	printArray(arr, SIZE);
	
	return 0;
}


void genRandomIntArry(int arr[], int size, int max){
	int i; //陣列索引
	srand((unsigned)time(NULL)); //產生亂數種子

	//賦予值給陣列
	for(i =0; i< size; i++){
		arr[i] = rand() % max + 1; //指定0~MAX範圍的亂數
	}	
}

void printArray(int arr[], int size){
	int i;
	for (i = 0; i < size; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");	
}


int partition(int number[], int left, int right) { 
    // Finish your code here.
	int pivot = number[left]; //選擇最左邊的元素作為 pivot
	int i = left + 1; //從第二個元素開始向右搜尋
	int j = right; //從最右邊的元素開始向左搜尋
	
	while(1){
		//從左向右搜尋，找到第一個比 pivot 大的元素的位置
		while(i <= j && number[i] <= pivot){
			i++;
		}
		
		//從右向左搜尋，找到第一個比 pivot 小的元素的位置
		while(i <= j && number[j] > pivot){
			j--;
		}
		
		//如果左右兩個搜尋指針相遇，就停止搜尋
        if (i >= j) {
            break;
        }
        
        //將左右兩個元素交換
        SWAP(number[i], number[j]);
	}
	
	//將 pivot 元素放到左右兩半之間的位置
    SWAP(number[left], number[j]);
    
	//返回 pivot 的位置
    return j;
}


void quickSort(int number[], int left, int right) { 
    // Finish your code here.
	if(left < right){
		int pivot = partition(number, left, right);
		quickSort(number, left, pivot - 1);
		quickSort(number, pivot + 1, right);
	}
} 

