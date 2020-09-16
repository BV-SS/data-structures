#include <stdio.h>
#include <stdlib.h>
//reverse circular linked list  ---- time-complexity -----> o(n)
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

//reverse circular linked list
struct node * reverse_CLL(struct node * tail){
    struct node *prev_node,*next_node,* current ;
    if(tail==NULL){
        return tail;
    }
    else{
        //start from 2nd element;
        prev_node=tail->next;
        next_node=prev_node->next;
        current=prev_node->next;
    
        while(prev_node != tail){
            next_node=current->next;
            current->next=prev_node;
            prev_node=current;
            current=next_node;
        }
        current->next=prev_node;
        tail=current;
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
	printf("\nAfter reverse\n");
	tail=reverse_CLL(tail);
	display_list(tail);
	//17 -> 23 -> 13 -> 5 -> 34 -> 4 -> 
	
	return 0;
}

