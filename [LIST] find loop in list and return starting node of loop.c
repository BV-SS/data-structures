#include <stdio.h>
struct node {
    int data;
    struct node * next;
};

void display(struct node * head){
    struct node * temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
}

void push(struct node ** head,int data){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(*head == NULL){
        *head=newnode;
    }
    else{
        newnode->next=(*head);
        *head=newnode;
    }
    
}
int detect_loop(struct node * head ){
    //set 2 pointers at head
    struct node * slow_p,*fast_p;
    slow_p = fast_p = head;
    int loop=0;//to indicate if loop is present
    
    //step-1 find loop
    while(slow_p && fast_p && fast_p->next){
        slow_p=slow_p->next;
        fast_p=fast_p->next->next;
        if(slow_p == fast_p){
           loop=1;
            break;
          }
    }
    
    //if loop exists
    if(loop==1){
        //redefine slow_p (reset it from start)
        slow_p=head;
        //if slow_p and fast_p meet, this is the beginning of loop
        while(slow_p && fast_p && fast_p->next){
            if(slow_p == fast_p ){
                return slow_p->data;
            }
            slow_p=slow_p->next;
            fast_p=fast_p->next;
          }
       
        }
        
   
    return NULL;

}

int main(void) {
	// your code goes here
	struct node * head=NULL;
	push(&head,5);
	push(&head,9);
	push(&head,8);
	push(&head,17);//17 -> 8 -> 9 -> 5 -> 
	
	//create a loop in list to test 
	head->next->next->next->next=head->next;//17 -> 8 -> 9 -> 5 ->(8)
	
	int node=detect_loop(head);
	if(node != 0){
	    printf("\nLoop detected at node %d",node);
	}
	else{
	    printf("\nNO loop found");
	}
	
	return 0;
}

