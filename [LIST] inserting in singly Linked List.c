#include <stdio.h>
#include <stdlib.h>
// singly linked list 
// time-complexity : insert_at_beginning ----> o(1)
//                   insert_at_position----->o(n-p)
//                   insert_at_end----->o(n)
struct node{
    int data;
    struct node * next;
};

void display_list(struct node * head){
    struct node * temp;
    temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
}

struct node * insert_at_beginning(struct node * head,int d){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=d;
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
    return head;
}

struct node * insert_at_end(struct node * head,int d){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=d;
    if(head==NULL){
        head=newnode;
    }
    else{
        struct node * temp;
        temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        
        temp->next=newnode;
    }
    return head;
}

struct node * insert_at_position(struct node * head,int d,int pos){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=d;
    int i;
    struct node *temp;
    if(head == NULL){
        head=newnode;
        return head;
    }
    else{
        temp=head;
        for(i=1;i<pos-1;i++){
            temp=temp->next;
        }
        
        newnode->next=temp->next;
        temp->next=newnode;
        
        return head;
    }
    
  
}

int main(void) {
	// your code goes here
	struct node * head=NULL;
	head=insert_at_beginning(head,3);
	head=insert_at_beginning(head,6);
	head=insert_at_beginning(head,4); 
	//display_list(head);//4 -> 6 -> 3 -> 
	head=insert_at_end(head,17);
	head=insert_at_end(head,8);
	//display_list(head); //4 -> 6 -> 3 -> 17 -> 8 -> 
	head=insert_at_position(head,34,3);
	display_list(head);//4 -> 6 -> 34 -> 3 -> 17 -> 8 -> 
	return 0;
}

