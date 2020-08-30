#include <stdio.h>
struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * newnode(int d){
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node * insert(struct node * root, int d){
    if(root==NULL){
        root=newnode(d);
    }
    if(d<root->data){
        root->left=insert(root->left,d);
    }
    else if( d>root->data){
        root->right=insert(root->right,d);
    }
    return root;
}

void inorder(struct node * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int LCA(struct node * root,int val_1,int val_2){
    while(root!=NULL){
        
        if(val_1<root->data && val_2<root->data){
            root=root->left;
        }
        
        else if(val_1>root->data && val_2>root->data){
            root=root->right;
        }
        
        else{
            break;
        }
    }
    
    return root->data;
}

int main(void) {
	// tree structure :
	/*        15 
            /    \ 
           9      17 
          / \    / \ 
         2  10  16  67    */
	struct node * root=NULL;
	root=insert(root,15);
	root=insert(root,17);
	root=insert(root,67);
	root=insert(root,9);
	root=insert(root,10);
	root=insert(root,2);
	root=insert(root,16);
	
	//inorder(root);
	
	int lca = LCA(root,16,67);
	printf("\n\nThe lowest common ancestor is %d ",lca);
	return 0;
}

