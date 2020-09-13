#include <stdio.h>
#include <stdlib.h>
//delete from doubly linked list 
/* time-complexity ----- delete_from_beginning--->o(1)
                   ----- delete_from_position--->o(n-p)
                   ----- delete_from_end--->o(n)          */
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

// deletion
struct node * delete_from_beginning(struct node * head){
    
         struct node * temp=head;
         head=temp->next;
         head->prev=NULL;
         temp->next=NULL;
         free(temp);
    
    return head;
}

struct node * delete_from_end(struct node * head){
  
        struct node * temp,*prev_node;
        temp=head;
        while(temp->next != NULL){
            prev_node=temp;
            temp = temp->next;
        }
        prev_node->next=NULL;
        temp->prev=NULL;
        free(temp);
    
    return head;
}

struct node * delete_from_position(struct node * head,int pos){
    struct node * temp=head,*prev_node;
    int i=1;
    
    while(i<pos){
        prev_node=temp;
        temp=temp->next;
        i++;
    }
    
    prev_node->next=temp->next;
    temp->next->prev=prev_node;
   
    free(temp);
    
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
	display_list(head);///1 -> 5 -> 23 -> 9 -> 17 ->
	
	printf("\ndelete_from_beginning\n");
	head=delete_from_beginning(head);
	display_list(head);// 5 -> 23 -> 9 -> 17 ->
	
	printf("\ndelete_from_end\n");
	head=delete_from_end(head);
	display_list(head);//5 -> 23 -> 9 ->  
	
	printf("\ndelete_from_position\n");
	head=delete_from_position(head,2);
	display_list(head);//5 -> 9 -> 
	
	return 0;
}

