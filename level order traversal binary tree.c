#include <stdio.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node * newnode(int n){
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node ));
    newnode->data=n;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}


void printthislevel(struct node * node, int level){
    if(node == NULL){
        return ;
    }
    if(level==1){
        printf(" %d ",node->data);
    }
    else if (level>1){
        printthislevel(node->left,level-1);
        printthislevel(node->right,level-1);
    }
}

int height(struct node * r){
    if(r==NULL){
        return 0;
    }
    else{
    int l_len=height(r->left);
    int r_len=height(r->right);
    
    if(l_len>r_len){
        return (l_len+1);
    }
    else{
        return(r_len+1);
    }
    
    }
}

void levelorder(struct node * root){
    int h=height(root);
    int i;
    for (i=1;i<=h;i++){
        printthislevel(root,i);
    }
}



int main(void) {
	// your code goes here
	//creating tree having 7 nodes , height -3 ;                          
	
	struct node* root;
	root=newnode(1);
	root->left=newnode(2);
	root->left->left=newnode(3);
	root->left->right=newnode(8);
	root->right=newnode(4);
	root->right->right=newnode(17);
	root->right->left=newnode(15);
	
	// level order traversal of the tree
	levelorder(root);
	
	return 0;
}

