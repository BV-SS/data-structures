#include <stdio.h>
#include <stdlib.h>
//insert in circular linked list
//time-complexity ---- insert_at_beginning --- o(1)
//                ---- insert_at_position --- o(n-p)
//                ---- insert_at_end --- o(1)
struct node{
    int data;
    struct node * next;
};

void display_list(struct node * tail){
    struct node * temp;
    temp=tail->next;
    while(temp->next != tail->next){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("%d -> ",tail->data);
}

struct node * createNode(int d){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->next=NULL;
    return newnode;
}

struct node * insert_at_beginning(struct node * tail,int d){
    struct node * newnode=createNode(d);
    
    if(tail == NULL){
        tail=newnode;
        tail->next=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
    }
    
    return tail;
}

struct node * insert_at_end(struct node * tail,int d){
    struct node * newnode=createNode(d);
    if(tail == NULL){
        tail=newnode;
        tail->next=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
    return tail;
}

struct node * insert_at_position(struct node * tail,int d,int pos){
    struct node * newnode=createNode(d);
    if(tail == NULL){
      tail= newnode;
      tail->next=newnode;
    }
    else{
        int i=1;
        struct node * temp=tail->next;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return tail;
}
int main(void) {
	// your code goes here
	struct node *tail =NULL;
	tail=insert_at_beginning(tail,5);
	tail=insert_at_beginning(tail,2);
	//display_list(tail);//2 -> 5 -> 
	tail=insert_at_end(tail,17);
	tail=insert_at_end(tail,9);
	//display_list(tail); //2 -> 5 -> 17 -> 9 -> 
	tail=insert_at_position(tail,23,3);
	tail=insert_at_position(tail,36,5);
	display_list(tail);//2 -> 5 -> 23 -> 17 -> 36 -> 9 ->
	return 0;
}

