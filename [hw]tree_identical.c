#include <stdio.h> 
#include <stdlib.h> 
#include<math.h>

static int search_flag = 0;

typedef struct Node {
    struct Node *Lchild;
    int data;
    struct Node *Rchild;
} Node; 

//create node
Node* create(int data) {
	struct Node *new_node;
	new_node = (Node* )malloc(sizeof(new_node));
	new_node->Lchild = NULL;
	new_node->Rchild = NULL;
	new_node->data = data;
} 

// TO-DO: check if two binary trees are identical
int identical(Node *T, Node *T2) {
	/*write your code here*/
	return ((!T && !T2) || (T && T2 && (T->data == T2->data) && identical(T->Lchild, T2->Lchild) && identical(T->Rchild, T2->Rchild)));
}

//TO-DO: check whether one value is present in BT 
int search(Node *root, int search_val) {
	/*write your code here*/
	if(root == NULL){
		return 0;
	}
	if(search_val == root->data){
		return 1;
	}
	if(search_val < root->data){
		return search(root->Lchild, search_val);
	}
	if(search_val > root->data){
		return search(root->Rchild, search_val);
	}
}


int main() {
	//tree 
	struct Node *root;
	root = create(7);
    root->Lchild=create(43);
    root->Rchild=create(9);
    root->Lchild->Lchild=create(5);
    root->Lchild->Rchild=create(21);
    root->Rchild->Rchild=create(4);
    root->Lchild->Lchild->Lchild=create(13);
	//tree 1
	struct Node *root1;
	root1 = create(7);
    root1->Lchild=create(43);
    root1->Rchild=create(9);
    root1->Lchild->Lchild=create(5);
    root1->Lchild->Rchild=create(21);
    root1->Rchild->Rchild=create(4);
    root1->Lchild->Lchild->Lchild=create(13);
	//tree 2
	struct Node *root2;
	root2 = create(7);
    root2->Lchild=create(2);
    root2->Rchild=create(9);
    root2->Lchild->Lchild=create(5);
    root2->Lchild->Rchild=create(21);
    root2->Rchild->Lchild=create(0);
    root2->Rchild->Rchild=create(4);
    
//    printf("Does tree and tree1 identical ?  %d\n",identical(root,root1));
//    printf("Does tree and tree2 identical ?  %d\n",identical(root,root2));
	printf("Does tree and tree1 identical ? ");
	printf(identical(root, root1) ? "true" : "false");
    printf("\nDoes tree and tree2 identical ? ");
	printf(identical(root, root2) ? "true" : "false");
    
    
    printf("\nsearch : ");
	printf(" \nDoes 2 exist in tree?: ");
	printf(search(root,2) ? "true" : "false");
	printf(" \nDoes 2 exist tree2?: ");
	printf(search(root2,2) ? "true" : "false");
}
