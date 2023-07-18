/*
 Max Heap implementation in c
 */
#include<stdio.h>
#include<stdlib.h>
/*
 Array Implementation of MaxHeap data Structure
 */

HEAP_SIZE = 20;

struct Heap{
    int *arr;
    int count;
    int capacity;
    int heap_type; // for min heap , 1 for max heap
};
typedef struct Heap Heap;

Heap *CreateHeap(int capacity,int heap_type);
void insert(Heap *h, int key);
void print(Heap *h);
void heapify_bottom_top(Heap *h,int index);
void heapify_top_bottom(Heap *h, int parent_node);
int PopMax(Heap *h);

int main(){
    int i;
    Heap *heap = CreateHeap(HEAP_SIZE, 1); 
    if( heap == NULL ){
        printf("__Memory Issue____\n");
        return -1;
    }
    
    for(i =9;i>0;i--)
        insert(heap, i);
    
    print(heap);
    
    for(i=9;i>0;i--){
        int temp = PopMax(heap);
        printf("Pop Max : %d\n", temp);
        print(heap);
    }
    return 0;
}

Heap *CreateHeap(int capacity,int heap_type){
    Heap *h = (Heap * ) malloc(sizeof(Heap)); //one is number of heap
    
    //check if memory allocation is fails
    if(h == NULL){
        printf("Memory Error!");
        return NULL;
    }
    h->heap_type = heap_type;
    h->count=0;
    h->capacity = capacity;
    h->arr = (int *) malloc(capacity*sizeof(int)); //size in bytes
    
    //check if allocation succeed
    if ( h->arr == NULL){
        printf("Memory Error!");
        return NULL;
    }
    return h;
}

void insert(Heap *h, int key){
    if( h->count < h->capacity){
        h->arr[h->count] = key;
        heapify_bottom_top(h, h->count);
        h->count++;
    }
}

void heapify_bottom_top(Heap *h,int index){
    int temp;
    int parent_node = (index-1)/2;
    
    if(h->arr[parent_node] < h->arr[index]){
        //swap and recursive call
        temp = h->arr[parent_node];
        h->arr[parent_node] = h->arr[index];
        h->arr[index] = temp;
        heapify_bottom_top(h,parent_node);
    }
}

void heapify_top_bottom(Heap *h, int parent_node){
    // Finish your code here.
    int left = parent_node * 2 + 1;
    int right = parent_node * 2 + 2;
    int max = parent_node;
    int temp;
    
    if(left < h->count && h->arr[left] > h->arr[max]){
    	max = left;
	}
	
	if(right < h->count && h->arr[right] > h->arr[max]){
		max = right;
	}
	
	if(max != parent_node){
		temp = h->arr[parent_node];
		h->arr[parent_node] = h->arr[max];
		h->arr[max] = temp;
		heapify_top_bottom(h, max);
	}
}

int PopMax(Heap *h){
    int pop;
    if(h->count==0){
        printf("\n__Heap is Empty__\n");
        return -1;
    }
    // replace first node by last and delete last
    pop = h->arr[0];
    h->arr[0] = h->arr[h->count-1];
    h->count--;
    heapify_top_bottom(h, 0);
    return pop;
}
void print(Heap *h){
    int i;
    printf("==============Print Heap===============\n");
    if(h->count){
        for(i=0;i< h->count-1;i++){
            printf("%d -> ",h->arr[i]);
        }
        printf("%d\n",h->arr[h->count-1]);
    }
    else
        printf("__Heap is Empty__\n");
}
