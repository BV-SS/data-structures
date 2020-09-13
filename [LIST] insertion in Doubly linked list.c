#include <stdio.h>
#include <stdlib.h>
//doubly linked lists
/* time-complexity ----- insert_at_beginning--->o(1)
                   ----- insert_at_position--->o(n-p)
                   ----- insert_at_end--->o(n)        */

struct node{
    int data;
    struct node * next;
    struct node * prev;
};

struct node * create_newnode(int data){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

struct node * display_list(struct node * head){
    struct node * temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
}
struct node * insert_at_beginning(struct node * head,int d){
    struct node * newnode = create_newnode(d);
  
    if(head == NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    return head;
}

struct node * insert_at_end(struct node * head,int d){
    struct node * newnode=create_newnode(d);
    struct node * temp;
    if(head == NULL){
        head-newnode;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        newnode->prev=temp;
        temp->next=newnode;
    }
    return head;
}

struct node * insert_at_position(struct node * head,int d,int pos){
    struct node * newnode=create_newnode(d);
    if(head == NULL){
        head=newnode;
    }
    else{
        int i =1;
        struct node * temp,*prev_node;
        temp=head;
        while(i<pos){
            prev_node=temp;
            temp=temp->next;
            i++;
        }
        newnode->next=temp;
        newnode->prev=prev_node;
        prev_node->next=newnode;
        temp->prev=newnode;
    }
    return head;
}
int main(void) {
	// your code goes here
	struct node * head=NULL;
	head=insert_at_beginning(head,8);
	head=insert_at_beginning(head,2);
	//display_list(head); 2 -> 8 ->
	head=insert_at_end(head,15);
	head=insert_at_end(head,17);
	//display_list(head); 2 -> 8 -> 15 -> 17 -> 
	head=insert_at_position(head,35,3);
	display_list(head);
	//2 -> 8 -> 35 -> 15 -> 17 -> 
	
	return 0;
}

