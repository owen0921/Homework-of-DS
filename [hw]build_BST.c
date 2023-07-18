#include <stdio.h> 
#include <stdlib.h> 
  
typedef struct node { 
    int data; 
    struct node *left, *right; 
} Node;

// TO-DO: implement inorder traversal.
void inorder(Node* root){ 
	//write your code. 
	if(root != NULL){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
} 

// TO-DO: count the number of non-leaf in a binary search tree.
int countnonleaf(Node* node){
	//write your code.
	if(node == NULL || (node->left == NULL && node->right == NULL)){
		return 0;
	}
	else{
		return 1 + countnonleaf(node->left) + countnonleaf(node->right);
	}
}

// TO-DO: count the number of leaf in a binary search tree.
int countleaf(Node* node){
	//write your code.
	if(node == NULL){
		return 0;
	}
	if(node->left == NULL && node->right == NULL){
		return 1;
	}
	else{
		return countleaf(node->left) + countleaf(node->right);
	}
}

// TO-DO: calculate the height of the binary search tree.
int height(Node* node){
    //write your code.
	if(node == NULL){
		return 0;
	}
	else{
		int leftHeight = height(node->left);
		int rightHeight = height(node->right);
		
		if(leftHeight >= rightHeight){
			return 1 + leftHeight;
		}
		else{
			return 1 + rightHeight;
		}
	}
}

static Node *prev = NULL;
// TO-DO: check if this tree is a binary search tree.
int is_BST(Node* node)  {  
	//write your code.  
	if(node != NULL){
		
		// check if the left subtree is a BST
		if(!is_BST(node->left)){
			return 0;
		}
		
		 // check if the current node is greater than the previous node
		if(prev != NULL && node->data <= prev->data){
			return 0;
		}
		
		// update the previous node
		prev = node;
		
		// check if the right subtree is a BST
		return is_BST(node->right);
	}
	return 1;
}

// TO-DO: insert a node in a binary search tree.
Node* insert(Node* node, int data){ 
    //write your code. 
    if(node == NULL){
    	Node* tmp = (Node*)malloc(sizeof(Node));
    	tmp->data = data;
    	tmp->left = NULL;
    	tmp->right = NULL;
    	node = tmp;
	}
	if(data < node->data){
		node->left = insert(node->left, data);
	}
	if(data > node->data){
		node->right = insert(node->right, data);
	}
	return node;
} 

int main(){
    int insert_data[] = {8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
	Node* root = NULL; 
	int i;
    root = insert(root, insert_data[0]);
	int len = sizeof(insert_data)/sizeof(insert_data[0]); 
    for(i=1;i<len;i++){
    	insert(root, insert_data[i]);
	}
	printf("inorder traversal: ");
    inorder(root);
    printf("\nIs it a Binary Search Tree(BST)?: ");
    printf(is_BST(root)==1 ? "Yes" : "No");
	printf("\nroot data: %d\n",root->data);
	printf("the number of leaves: %d\n",countleaf(root));
	printf("the number of non-leaves: %d\n",countnonleaf(root));
	printf("height: %d\n\n",height(root));
		
	root->data = 20;
	printf("Modify Binary Search Tree(BST): \n");
	printf("inorder traversal: ");
    inorder(root);
    printf("\nIs it a Binary Search Tree(BST)?: ");
    printf(is_BST(root)==1 ? "Yes" : "No");
    return 0; 
}
