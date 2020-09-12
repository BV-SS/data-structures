#include <stdio.h>
#include <stdlib.h>
// singly linked list 
// time-complexity : delete_from_beginning ----> o(1)
//                   delete_from_position----->o(n-p)
//                   delete_from_end----->o(n)
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

// deletion
struct node * delete_from_beginning(struct node * head){
    if(head==NULL){
        return head;
    }
    else{
        struct node * temp;
        temp=head;
        head=temp->next;
        free(temp);
        return head;
    }
}

struct node * delete_from_end(struct node * head){
    struct node * temp,*prev;
    if(head == NULL){
        return head;
    }
    else{
        temp=head;
        while(temp->next != NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
        return head;
    }
}

struct node * delete_from_position(struct node * head, int pos){
    int i;
    struct node * temp,*prev;
    if(head==NULL){
        return head;
    }
    else{
        temp=head;
        for(i=1;i<pos;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        temp->next=NULL;
        free(temp);
        return head;
    }
}

int main(void) {
	// your code goes here
	struct node * head=NULL;
	// creating a linked list
	head=insert_at_beginning(head,3);
	head=insert_at_beginning(head,6);
	head=insert_at_beginning(head,4); 
	head=insert_at_end(head,17);
	head=insert_at_end(head,8);
	head=insert_at_position(head,34,3);
	display_list(head);//4 -> 6 -> 34 -> 3 -> 17 -> 8 -> 
	
	// deletion 
	printf("\ndelete_from_beginning\n");
	head=delete_from_beginning(head);
	display_list(head); //6 -> 34 -> 3 -> 17 -> 8 -> 
	
	printf("\ndelete_from_end\n");
	head=delete_from_end(head);
	display_list(head);//6 -> 34 -> 3 -> 17 -> 
	
	printf("\ndelete_from_position\n");
	head=delete_from_position(head,3);
	display_list(head);//6 -> 34 -> 17 -> 
	
	return 0;
}

