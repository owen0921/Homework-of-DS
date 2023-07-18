#include <stdio.h>
#define SIZE 10
#define ROW 4
#define COL 5
#define DEPTH 2

int main(void)
{
	int i, j, k = 0;

	int matrix_3d[ROW][COL][DEPTH] = {{{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}},
									  {{11, 12}, {13, 14}, {15, 16}, {17, 18}, {19, 20}},
									  {{21, 22}, {23, 24}, {25, 26}, {27, 28}, {29, 30}},
									  {{31, 32}, {33, 34}, {35, 36}, {37, 38}, {39, 40}}};

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf(" {");
			for (k = 0; k < DEPTH; k++)
			{
				printf("%3d", matrix_3d[i][j][k]);
			}
			printf("}");
		}
		printf("\n");
	}

	/*TO-DO*/
	/*actual memory address*/
	/*matrix_3d[0:3, 0:4, 0:1] is a row-major array. 
	Identify the memory location of the array element matrix_3d[3][1][1].*/
	int unit = (&matrix_3d[0][0][1] - &matrix_3d[0][0][0]);
	
	printf("Matrix(3,1,1) is located at %p\n", &matrix_3d[3][1][1]);
	
	printf("%p + ((3-0) * %d * %d + (1-0) * %d + 1) * %d = ", &matrix_3d[0][0][0], COL, DEPTH, DEPTH, unit);
		
	printf("%p", &matrix_3d[0][0][0] + (3 * COL * DEPTH + 1 * DEPTH + 1) * unit);
	return 0;
}
