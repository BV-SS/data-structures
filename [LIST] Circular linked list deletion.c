#include <stdio.h>
#include <stdlib.h>
// delete from circular linked list 
// time-complexity   --- delete_from_beginning ----> o(1)
//                   --- delete_from_position ----> o(n-p)
//                   --- delete_from_end ----> o(n)

struct node{
    int data;
    struct node * next;
};

void display_list(struct node * tail){
    struct node * temp=tail->next;
    while(temp->next != tail->next){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("%d -> ",tail->data);
}

struct node * createNode(int d){
    struct node * newnode =(struct node *)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->next=NULL;
    return newnode;
}

struct node * create_CLL(struct node * tail,int d){
    struct node * newnode = createNode(d);
    if(tail == NULL){
        tail=newnode;
        tail->next=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
    return newnode;
}

struct node * delete_from_beginning(struct node *tail){
    struct node * temp =tail->next;
    if(tail==NULL){
        return tail;
    }
    else{
        tail->next=temp->next;
        temp->next=NULL;
        free(temp);
        return tail;
    }
}

struct node * delete_from_end(struct node * tail){
    struct node * temp=tail->next;
    if(tail == NULL){
        return tail;
    }
    else{
        struct node * node;
        while(temp->next != tail->next){
            node=temp;
            temp=temp->next;
        }
        node->next=tail->next;
        tail=node;
        temp->next=NULL;
        free(temp);
        return tail;
    }
}

struct node * delete_from_position(struct node * tail,int pos){
    struct node * temp,*prev;
    int i=1;
    if(tail == NULL){
        return tail;
    }
    else{
        temp=tail->next;
        while(i<pos){
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=temp->next;
        temp->next=NULL;
        free(temp);
        return tail;
    }
}
int main(void) {
	// your code goes here
	struct node * tail=NULL;
	tail=create_CLL(tail,4);
	tail=create_CLL(tail,34);
	tail=create_CLL(tail,5);
	tail=create_CLL(tail,13);
	tail=create_CLL(tail,23);
	tail=create_CLL(tail,17);
	display_list(tail);
	//4 -> 34 -> 5 -> 13 -> 23 -> 17 -> 
	printf("\ndelete_from_beginning\n");
	tail=delete_from_beginning(tail);
	display_list(tail);//34 -> 5 -> 13 -> 23 -> 17 -> 
	
	printf("\ndelete_from_end\n");
	tail=delete_from_end(tail);
	display_list(tail);//34 -> 5 -> 13 -> 23 -> 
	
	printf("\ndelete_from_position\n");
	tail=delete_from_position(tail,3);
	display_list(tail);//34 -> 5 -> 23 ->
	
	return 0;
}

