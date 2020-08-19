#include <stdio.h>
struct node{
    int data;
    struct node * left;
    struct node * right;
   
};

//for creating nodes of tree
struct node * newnode(int n){
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->left=NULL;
    newnode->right=NULL;
    return (newnode);
}

//for traversing the tree
void inorder(struct node* root ){
    if (root==NULL){
        return;
    }
    inorder(root->left);
    printf(" %d ",root->data);
    inorder(root->right);
}

//for inverting 
void invert(struct node * node){
    if (node==NULL){
        return;
    }
    else{
        invert(node->left);
        invert(node->right);
        
        struct node* temp;
        temp=node->left;
        node->left=node->right;
        node->right=temp;
    }
}

int main(void) {
	// test the functions 
	/*  so  the tree ... 
       1 
      / \ 
     3   9 
        / \ 
       4   17 
  
 is changed to... 
       1 
      / \ 
     2   5 
    / \ 
   17   4 
*/
	struct node * root;
	root=newnode(1);
	root->left=newnode(3);
	root->right=newnode(9);
	root->right->left=newnode(4);
	root->right->right=newnode(17);
	
	//print inorder traversal of orignal tree(3  1  4  9  17 )
	inorder(root);
	
	invert(root); 
	
	//print inorder traversal for inverted tree (17  9  4  1  3 )
	inorder(root);
	return 0;
}

