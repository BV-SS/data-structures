#include <stdio.h>
//minimun and maximum node of BST

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * newnode(int n){
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node * insert(struct node * node,int data){
    if(node==NULL){
        node=newnode(data);
    }
    
    if(data > node->data){
        node->right=insert(node->right,data);
    }
    
    else if( data < node->data){
        node->left=insert(node->left,data);
    }
    return node;
}

void inorder(struct node * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int minvaluenode(struct node * root){
    struct node * current=root;
    
    while( current->left != NULL){
        current=current->left;
    }
    
    return (current->data);
}

int maximumvaluenode(struct node * root){
    struct node * current = root;
    
    while(current->right != NULL){
        current =current->right;
    }
    
    return (current->data);
}
int main(void) {
	// create tree structure :
	 /*       15 
            /    \ 
           7     17 
          / \    / \ 
         5   9  16  22    */
	struct node * root=NULL;
	root=insert(root,15);
	root=insert(root,17);
	root=insert(root,7);
	root=insert(root,5);
	root=insert(root,9);
	root=insert(root,16);
	root=insert(root,22);
	
	inorder(root);
	//5 7 9 15 16 17 22 
	
	int mx=maximumvaluenode(root);
	int mn=minvaluenode(root);
	printf("\nthe maximum node in tree : %d \nthe minimum node in tree : %d ",mx,mn);
	/*    the maximum node in tree : 22 
          the minimum node in tree : 5     */
	return 0;
}

