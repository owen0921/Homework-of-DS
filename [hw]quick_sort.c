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
	int i; //�}�C����
	srand((unsigned)time(NULL)); //���Ͷüƺؤl

	//�ᤩ�ȵ��}�C
	for(i =0; i< size; i++){
		arr[i] = rand() % max + 1; //���w0~MAX�d�򪺶ü�
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
	int pivot = number[left]; //��̥ܳ��䪺�����@�� pivot
	int i = left + 1; //�q�ĤG�Ӥ����}�l�V�k�j�M
	int j = right; //�q�̥k�䪺�����}�l�V���j�M
	
	while(1){
		//�q���V�k�j�M�A���Ĥ@�Ӥ� pivot �j����������m
		while(i <= j && number[i] <= pivot){
			i++;
		}
		
		//�q�k�V���j�M�A���Ĥ@�Ӥ� pivot �p����������m
		while(i <= j && number[j] > pivot){
			j--;
		}
		
		//�p�G���k��ӷj�M���w�۹J�A�N����j�M
        if (i >= j) {
            break;
        }
        
        //�N���k��Ӥ����洫
        SWAP(number[i], number[j]);
	}
	
	//�N pivot ������쥪�k��b��������m
    SWAP(number[left], number[j]);
    
	//��^ pivot ����m
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

