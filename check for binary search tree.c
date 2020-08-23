#include <stdio.h>
#include <stdbool.h>  
#include <stdlib.h> 
#include <limits.h>
//to check if a binary tree is a BST or not
struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node * newnode(int n){
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->left=newnode->right=NULL;
    return newnode;
}

bool check_bst(struct node * root){
    // we will traverse tree in inorder 
    //search for leaf node and assign prev to it ( tree's leftest leaf)
    //if root == NULL then return true --> single node is a BST
    static struct node *prev = NULL;
    
    if( root )
    { 
        if(!check_bst(root->left)){
            return false;
        }
        
        if(prev != NULL && root->data <= prev->data){
            return false;
        }
        
        prev=root;
        
        return check_bst(root->right);
    }
    
    return true;
}


int main(void) {
	// construct a BST as follows:
	/*             5
                 /   \
                3     17
               / \    / \
              1   4  15  99   
    */
	struct node * root;
	
	root=newnode(5);
	root->left=newnode(3);
	root->left->left=newnode(1);
	root->left->right=newnode(4);
	root->right=newnode(17);
    root->right->left=newnode(15);
	root->right->right=newnode(99);
	
	//check if it is BST
	if(check_bst(root)){
	    printf("\nit is a binary search tree !");
	}
	else{
	    printf("\nit is NOT a binary search tree !!!!");
	}
	
	return 0;
}

