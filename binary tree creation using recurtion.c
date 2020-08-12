#include <stdio.h>


struct node{
    int data;
    struct node * left;
    struct node * right;
    
};

struct node * create(){
    int d;
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf(" enter data for node ( enter -1 for no node ) ");
    scanf("%d",&d);
    if(d==-1){
        return 0;
    }
    else{
        newnode->data=d;
        
        printf("enter left child for %d",d);
        newnode->left=create();
        printf("enter right child for %d",d);
        newnode->right=create();
        return newnode;
        
    }
    
}




int main(void) {
	// your code goes here
	struct node * root;
	root=create();
	return 0;
}

