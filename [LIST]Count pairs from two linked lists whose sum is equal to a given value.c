#include <stdio.h>
#include <stdlib.h>
//to  Count pairs from two linked lists whose sum is equal to a given value
//time - complexity o(n1*n2) ---> n1 and n2 = no.of elements in first and second linked lists respectively
struct Node 
{ 
  int data; 
  struct Node* next; 
}; 
  
// function to insert a node at the 
// beginning of the linked list 
void push(struct Node** head_ref, int new_data) 
{ 
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
   
  new_node->data  = new_data; 
  new_node->next = (*head_ref); 
  (*head_ref)    = new_node; 
} 
  
// function to count all pairs from both the linked lists 
// whose sum is equal to a given value 
int countPairs(struct Node* head1, struct Node* head2, int x) 
{ 
    int count = 0; 
      
    struct Node *p1, *p2; 
      
    // traverse the 1st linked list 
    for (p1 = head1; p1 != NULL; p1 = p1->next) 
  
        // for each node of 1st list 
        // traverse the 2nd list 
  
        for (p2 = head2; p2 != NULL; p2 = p2->next) 
  
            // if sum of pair is equal to 'x' 
            // increment count 
            if ((p1->data + p2->data) == x) 
                count++;             
          
    // required count of pairs      
    return count; 
} 
  
// Driver program to test above 


int main(void) {
	// your code goes here
	struct Node* head1 = NULL; 
    struct Node* head2 = NULL; 
      
    // create linked list1 3->1->5->7 
    push(&head1, 7); 
    push(&head1, 5); 
    push(&head1, 1); 
    push(&head1, 3);     
      
    // create linked list2 8->2->5->3 
    push(&head2, 3); 
    push(&head2, 5); 
    push(&head2, 2); 
    push(&head2, 8); 
      
    int x = 10; 
    printf("\nCount pairs = %d",countPairs(head1,head2,x));//Count pairs = 2

	return 0;
}

