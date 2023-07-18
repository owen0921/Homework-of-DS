#include <stdio.h>
#define MAX_ERXTICES 8
#define FALSE 0
#define TRUE 1
#define INT_MAX 9999999

void shortestpath(int v, int cost[][MAX_ERXTICES], int distance[], int n, short int found[]);
int choose(int distance[], int n, short int found[]);
void printPath(int path[], int v);
void main(){
	//���V�� 
	// Adjacency Matrix                0        1        2        3        4        5        6        7
	int cost[][MAX_ERXTICES] = {{      0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},	// 0
								{    300,       0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},	// 1
								{    600,     100,       0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},	// 2
								{INT_MAX, INT_MAX,     120,       0, INT_MAX, INT_MAX, INT_MAX, INT_MAX},	// 3
								{INT_MAX, INT_MAX, INT_MAX,    1500,       0,     150, INT_MAX, INT_MAX},	// 4
								{INT_MAX, INT_MAX, INT_MAX,     900, INT_MAX,       0,     700,    1400},	// 5
								{INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX,       0,     100},	// 6
								{    170, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX,       0}};	// 7
								
	int n = MAX_ERXTICES;			// Number of nodes.
	int v = 4;						// Starting vertex.
	int distance[MAX_ERXTICES];		// record the shortest distance.
	short int found[MAX_ERXTICES];	// record the node visited.
					
	shortestpath(v, cost, distance, n, found);
}

void shortestpath(int v, int cost[][MAX_ERXTICES], int distance[], int n, short int found[]){
	int i, u, w;
	
	// �n��X������|����k : �t�}�@�Ӫ��A�����L�O�z�L�֧�s���{�b���� 
	int path[MAX_ERXTICES]; //�����̵u���|
	 
	for(i = 0; i < n; i++){
		found[i] = FALSE;
		distance[i] = cost[v][i];
	}
	
	found[v] = TRUE;
	distance[v] = 0;
	/*-------------------------------------------------
	Hint: Declare the array of shortest path.
	Hint: Using For-loop to set the array.
	Finish your code below.
	---------------------------------------------------*/
	
	// �Npath��l�ơA�����]��-1�A��ܩ|�����̵u���| 
	for(i = 0; i < MAX_ERXTICES; i++){
		path[i] = -1;
	}
	
	int node;
	
	for(i = 0; i < n - 2; i++){
		u = choose(distance, n, found);
		found[u] = TRUE;
		for(w = 0; w < n; w++){
			if (distance[u] + cost[u][w] < distance[w]){
				distance[w] = distance[u] + cost[u][w];
				/*-----------------------------------------
				Hint: Record the shortest path.
				Finish your code below.
				-------------------------------------------*/
				path[w] = u; // path[w]�O��distance[w]�Ȯɳ̵u���|���̫�@�Ӥ��~�`�I
			}
		}
	}
	
	printf("Vertex %d to all shortest distances: ", v);
	for(i = 0; i < MAX_ERXTICES; i++)
		printf("%d ", distance[i]);
	printf("\n");
	/*-------------------------------------------------
	Hint: Using For-loop to print the path.
	Finish your code below.
	---------------------------------------------------*/
	// �L�Xpath 
    for (i = 0; i < MAX_ERXTICES; i++){
        printPath(path, i);
        printf("%5d\n", distance[i]);
        printf("\n");
    }
}

int choose(int distance[], int n, short int found[]){
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for(i = 0; i < n; i++){
		if (distance[i] < min && !found[i]){
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void printPath(int path[], int destination){
	// path[destination] == -1 ��ܰ_�I 
    if(path[destination] == -1) {
        printf(" 4 -> %d", destination);
        return;
    }
    printPath(path, path[destination]);
    printf(" -> %d ", destination);
}
