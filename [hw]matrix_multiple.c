#include <stdio.h>
#define ROW 4
#define COL 3

int main(void)
{
	int i, j, k, sum;
	int m1[ROW][2] = {{1, 2},
					  {3, 4},
					  {5, 6},
					  {7, 8}};
	int m2[2][COL] = {{1, 2, 3},
					  {4, 5, 6}};

	/*TO-DO*/
	/*You are given two input matrices, m1 and m2.
	Please implement matrix multiplication.*/
	int ans[ROW][COL] = {0};
	for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            for(k = 0; k < 2; k++) {
                ans[i][j] = ans[i][j] + m1[i][k] * m2[k][j];
            }
            printf("%4d ", ans[i][j]);
        }
        printf("\n");
    }
	return 0;
}
