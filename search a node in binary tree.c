#include <stdio.h>
#include <stdbool.h>  
#include <stdlib.h>  
//search a node in binary tree
struct node {
    int data;
    struct node * left;
    struct node * right;
};



static bool flag=false;

struct node * newnode(int d){
    struct node * newnode;
    newnode=(struct node*)malloc(sizeof(newnode));
    newnode->data=d;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void search(struct node* root , int n){
    if(root==NULL){
        printf("the tree is empty");
        return;
    }
    
    else{
        if(n==root->data){
            flag=true;
           
            return;
        }
        
        if(flag==false && root->left!=NULL){
            search(root->left,n);
        }
        
        if(flag==false && root->right!=NULL){
        
            search(root->right,n);
        }
    }
}


int main(void) {
	// your code goes here
	struct node * root;
	root=newnode(5);
	root->left=newnode(7);
	root->right=newnode(10);
	root->left->left=newnode(1);
	root->left->right=newnode(8);
	
	search(root,18);
	
	if(flag==true){
	    printf("\n the node is present in tree");
	}
	
	else{
	    printf("\nthe node is not present in the tree");
	}
	
	return 0;
}

