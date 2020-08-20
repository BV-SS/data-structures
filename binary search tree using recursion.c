#include <stdio.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node * create(struct node * root,int d){
    if (root==NULL){
        struct node * newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=d;
        root=newnode;
        return root;
    }
    
    else{
        if(d>root->data){
            root->right=create(root->right,d);
        }
        else if(d<=root->data){
            root->left=create(root->left,d);
        }
        
        return root;
    }
}

void inorder(struct node * root){
    if (root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
/*  tree structure:
                  5
                 / \
                4   16 
               /   / \
              1   7   97
                  
        inorder:1 4 5 7 16 97 */
        
        
int main() {
    struct node * root=NULL;
    int i;
    // creating tree using create() manually
   /* root=create(root,5);
    root=create(root,4);
    root=create(root,16);
    root=create(root,97);
    root=create(root,1);
    root=create(root,7);*/
    
    //creating tree with for loop
    for (i=0;i<6;i++){
        int n;
        scanf("%d",&n); // 5 4 16 97 1 7
        root=create(root,n);
    }
    
    //traverse and check the binary tree
    inorder(root);
	return 0;
}
