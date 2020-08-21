#include <stdio.h>
// BST without recursion
struct node{
    int data;
    struct node * left;
    struct node * right;
};



struct node * insert(struct node * root,int n){
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->left=NULL;
    newnode->right=NULL;
    struct node * parent;
    struct node * current;
    
    if(root==NULL){
        root=newnode;
        return root;
    }
    
    else{
        parent=NULL;
        current=root;
        
        while(1){
            parent=current;
            
            if (n<parent->data){
                current=current->left;
                
                if(current==NULL){
                    parent->left=newnode;
                    return root;
                }
            }
            
            else{
                current=current->right;
                
                if(current==NULL){
                    parent->right=newnode;
                    return root;
                }
            }
        }
    }
}

void inorder(struct node * root){
    if(root==NULL){
        return;
    }
    
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main(void) {
	// tree structure :
	
/*  tree structure:
                  15
                 / \
                3   25
               /   / \
              2   17   108
                  
        inorder:2 3 15 17 25 108 */
        
	struct node * root=NULL;
	
	root=insert(root,15);
	root=insert(root,25);
	root=insert(root,3);
	root=insert(root,2);
	root=insert(root,108);
	root=insert(root,17);
	
	//check the inorder traversal of created tree
	inorder(root);
	
	return 0;
}

