#include <stdio.h>
#include <stdlib.h>

//define
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


//TO-DO: implement preorder traversal.
void preorder(Node *root) {
	/*write your code here*/
	if(root != NULL){
		printf("%d ", root->data);
		preorder(root->Lchild);
		preorder(root->Rchild);
	}
}

//TO-DO: implement inorder traversal.
void inorder(Node *root) {
	/*write your code here*/
	if(root != NULL){
		inorder(root->Lchild);
		printf("%d ", root->data);
		inorder(root->Rchild);
	}
}

//TO-DO: implement postorder traversal/
void postorder(Node *root) {
	/*write your code here*/
	if(root != NULL){
		postorder(root->Lchild);
		postorder(root->Rchild);
		printf("%d ", root->data);
	}
}
   
int main() {
	//create tree
	struct Node *root;
	root = create(7);
    root->Lchild=create(43);
    root->Rchild=create(9);
    root->Lchild->Lchild=create(5);
    root->Lchild->Rchild=create(21);
    root->Rchild->Lchild=create(0);
    root->Rchild->Rchild=create(4);
    root->Lchild->Lchild->Lchild=create(13);
    
    //print answer
    printf("preorder : ");
    preorder(root);
    
    printf("\ninorder : ");
    inorder(root);
    
    printf("\npostorder : ");
    postorder(root);
}
