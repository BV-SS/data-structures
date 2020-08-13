#include <stdio.h>


struct node{
    int data;
    struct node * left;
    struct node * right;
    
};
//creation of tree
struct node * create(){
    int d;
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->left=NULL;
    newnode->right=NULL;
    
    printf("\n enter data for node ( enter -1 for no node ) ");
    scanf("%d",&d);
    if(d==-1){
        return 0;
    }
    else{
        newnode->data=d;
        
        printf("\n \n enter left child for %d",d);
        newnode->left=create();
        printf("\n\n enter right child for %d",d);
        newnode->right=create();
        return newnode;
        
    }
    
}
//preorder traversal (root-left-right)
void preorder(struct node * localroot){
    if(localroot==NULL){
        return ;
        
    }
    printf(" %d ",localroot->data);
    preorder(localroot->left);
    preorder(localroot->right);
}

//inorder traversal(left-root-right)
void inorder(struct node * localroot){
    if(localroot==NULL){
        return;
    }
    inorder(localroot->left);
    printf(" %d ",localroot->data);
    inorder(localroot->right);
}

//postorder traversal(left-right-root)
void postorder(struct node * localroot){
    if(localroot==NULL){
        return;
    }
    postorder(localroot->left);
    postorder(localroot->right);
    printf(" %d ",localroot->data);
}

int main(void) {
	// your code goes here
	// sample input 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1 
	//inorder----3  2  4  1  6  5  7 
	//preorder----1  2  3  4  5  6  7 
	//postorder---3  4  2  6  7  5  1 
	
	struct node * root;
	root=create();
	
	printf("\n\n ----------preorder for tree -------------");
	preorder(root);
	printf("\n\n ----------inorder for tree -------------");
	inorder(root);
	printf("\n\n ----------postorder for tree -------------");
	postorder(root);
	
	
	
	return 0;
}

