#include <stdio.h>

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

//inserting in BST
struct node * insert(struct node * root,int data){
    if(root==NULL){
        root=newnode(data);
        return root;
    }
    
    if (data>root->data){
        root->right=insert(root->right,data);
    }
    
    else if ( data< root->data){
        root->left=insert(root->left,data);
    }
    
    return root;
}

//for inorder traversal
void inorder(struct node * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

//finding minimum value of subtree
struct node * minvaluenode(struct node * node){
    struct node * current=node;
    while(current && current->left!=NULL){
        current=current->left;
    }
    
    return current;
}

//delete the given node and return the new root
struct node * deletenode(struct node * root, int d){
    //base case
    if (root==NULL){
        return root;
    }
    //if data value is larger that current node go to right subtree
    if(d>root->data){
        root->right=deletenode(root->right,d);
    }
    //if data value is smaller that current node go to left subtree
    else if (d<root->data){
        root->left=deletenode(root->left,d);
    }
    
    //if the data is equal to the current node 
    else{
        
        //root with one or no child 
        if (root->left==NULL){
            struct node * temp;
            temp=root->right;
            free(root);
            return temp;
        }
    
        else if(root->right==NULL){
            struct node * temp;
            temp=root->left;
            free(root);
            return temp;
        }
        
        // root with two children:
        //find min in right subtree and return to temp
    
        struct node * temp;
        temp=minvaluenode(root->right);
        
        //copy the inorder successors content to this node
        root->data=temp->data;
        
        //delete the minimum inorder successor node
        root->right=deletenode(root->right,temp->data);
    }
        
    return root;
    
}

int main(void) {
	// tree structure :
	/*        15 
            /    \ 
           5     18 
          / \    / \ 
         1  10  17  22    */
          
          
	struct node * root;
	root=insert(root,15);
	root=insert(root,18);
	root=insert(root,5);
	root=insert(root,1);
	root=insert(root,17);
	root=insert(root,10);
	root=insert(root,22);
	
	inorder(root);
	//1 5 10 15 17 18 22
	root=deletenode(root,22);
	printf("\n after deleting node 22\n");
	inorder(root);
	//1 5 10 15 17 18 
	
	root=deletenode(root,18);
	printf("\n after deleting node 18\n");
	inorder(root);
	//1 5 10 15 17 

	return 0;
}

