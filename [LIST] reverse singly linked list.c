#include <stdio.h>
#include <stdlib.h>
//reverse singly linked list ---- time complexity ----> o(n)
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

struct node * createNode(int d){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->next=NULL;
    return newnode;
}

struct node * create_linked_list(struct node * head,int d){
    struct node * temp,* newnode;
    newnode=createNode(d);
    if(head == NULL){
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return head;
}

struct node * reverse_SLL(struct node * head){
    struct node *prevNode,*nextNode,*current;
    current=head;
    prevNode=NULL;
    while(current!=NULL){
        nextNode=current->next;
        current->next=prevNode;
        prevNode=current;
        current=nextNode;
    }
    head=prevNode;
    return head;
}

int main(void) {
	// your code goes here
	//create_linked_list
	struct node * head=NULL;
	head=create_linked_list(head,9);
	head=create_linked_list(head,5);
	head=create_linked_list(head,17);
	head=create_linked_list(head,2);
	head=create_linked_list(head,10);
	head=create_linked_list(head,23);
	display_list(head);
	//9 -> 5 -> 17 -> 2 -> 10 -> 23 -> 
	printf("\nAfter reverse\n");
	head=reverse_SLL(head);
	display_list(head);
	//23 -> 10 -> 2 -> 17 -> 5 -> 9 -> 
	return 0;
}

