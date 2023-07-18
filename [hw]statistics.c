#include <stdio.h>
#include <math.h>
#define SIZE 99 //陣列大小 

void printArray(int array[]);
void bubblesort(int array[]);
int mode(int array[]);

int main(void){
	//宣告一個99個元素的整數陣列，數值範圍介於1-9之間 
	int values[SIZE] = {6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
						7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
						6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
						7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
						6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
						7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
						5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
						7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
						7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
						4, 5, 6, 1, 6, 5, 7, 8, 7};
	printf("[values]\n");
	printArray(values);
	printf("\n***** Statistical Results *****\n");

	/*TO-DO*/
	
	//總和 
	float sum = 0;
	int i = 0;
	for(i = 0; i < SIZE; i++){
		sum += values[i];
	}
	printf("The sum is %f\n", sum);
	
	//平均
	float average = 0;
	average = sum / SIZE;
	printf("The average is %f\n", average);
	
	//標準差
	float sigma = 0;
	float sd = 0;
	float sd_sum = 0;
	for(i = 0; i < SIZE; i++){
		sd_sum += pow((values[i] - average), 2);
	}
	sigma = sd_sum / SIZE;
	sd = sqrt(sigma);
	printf("The standard is %f\n", sd);
	
	//最大值
	int max = values[0];
	for(i = 1; i < SIZE; i++){
		if(values[i] > max){
			max = values[i];
		}
	}
	printf("The Max is %d\n", max);
	
	//最小值
	int min = values[0];
	for(i = 1; i < SIZE; i++){
		if(values[i] < min){
			min = values[i];
		}
	}
	printf("The Min is %d\n", min);
	
	//中位數
	int ans[SIZE] = {0}; //複製到新的陣列，並對新的陣列進行操作
	for(i = 0; i < SIZE; i++){
		ans[i] = values[i];
	}
	bubblesort(ans);
	printf("The median is %d\n", ans[49]);
	 
	//眾數
	int Mode = 0;
	Mode = mode(values);
	printf("The mode is %d\n", Mode);
	return 0;
}

//將陣列內容在螢幕顯示出來
void printArray(int array[]){
	int i;
	for (i = 0; i < SIZE; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void bubblesort(int ans[]) {
	int i;
	int j;
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE-i-1; j++) {
            if (ans[j] > ans[j + 1]) {
                int temp = ans[j];
				ans[j] = ans[j + 1];
				ans[j + 1] = temp;
            }
        }
    }
}

int mode(int ans[]){
	int count[9] = {0};
	int i = 0;
	for(i = 0; i < SIZE; i++){
		if(ans[i] == 1){
			count[0]++;
		}
		if(ans[i] == 2){
			count[1]++;
		}
		if(ans[i] == 3){
			count[2]++;
		}
		if(ans[i] == 4){
			count[3]++;
		}
		if(ans[i] == 5){
			count[4]++;
		}
		if(ans[i] == 6){
			count[5]++;
		}
		if(ans[i] == 7){
			count[6]++;
		}
		if(ans[i] == 8){
			count[7]++;
		}
		if(ans[i] == 9){
			count[8]++;
		}
	}
	int Mode = count[0];
	int flag = 0;
	for(i = 0; i < 9; i++){
		if(count[i] > Mode){
			Mode = count[i];
			flag = i;
		}
	}
	return flag + 1;
}
