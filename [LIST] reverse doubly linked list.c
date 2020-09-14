#include <stdlib.h>
//delete from doubly linked list 

struct node{
    int data;
    struct node * next;
    struct node * prev;
};

struct node * display_list(struct node * head){
    struct node * temp=head;
    
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
        
}

struct node * create_newnode(int data){
    struct node * newnode=(struct node *) malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

struct node * create_linked_list(struct node * head,int d){
    struct node * newnode = create_newnode(d);
    if(head == NULL){
        head=newnode;
    }
    else{
        struct node * temp;
        temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
    return head;
}
struct node * reverse_DLL(struct node * head){
    struct node * current,*prevNode=NULL;
    current=head;
    while(current!=NULL){
        current->prev=current->next;
        current->next=prevNode;
        prevNode=current;
        current=current->prev;
    }
    head=prevNode;
    return head;
}

int main(void) {
	// your code goes here
	struct node * head=NULL;
	head=create_linked_list(head,1);
	head=create_linked_list(head,5);
	head=create_linked_list(head,23);
	head=create_linked_list(head,9);
	head=create_linked_list(head,17);
	printf("-------before reverse-----------\n");
	display_list(head);
	///1 -> 5 -> 23 -> 9 -> 17 ->
	struct node * temp=head;
	int i;
	for(i=1;i<3;i++){
	    temp=temp->next;
	}
	//check links between nodes
	printf("\nthe %d node have prev = %d and next = %d",temp->data,temp->prev->data,temp->next->data);
	printf("\n-------after reverse----------\n");
	//reverse the list
	head=reverse_DLL(head);
	display_list(head);
	//17 -> 9 -> 23 -> 5 -> 1 -> 
	//check the links again
    temp=head;
	for(i=1;i<3;i++){
	    temp=temp->next;
	}
	printf("\nthe %d node have prev = %d and next = %d",temp->data,temp->prev->data,temp->next->data);
	return 0;
}


