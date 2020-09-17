#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//check if the parenthesis are BALANCED  ---- time-complexity --- o(n)
//stack structure
struct node{
    char data;
    struct node * next;
};

//function to create stack node
struct node * create_node(char d){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->next=NULL;
    return newnode;
}

//push in stack
void push(struct node ** top,char d){
    struct node * newnode=create_node(d);
    if(top==NULL){
        *top=newnode;
    }
    else{
        newnode->next=*top;
        *top=newnode;
    }
    return;
}

//compare the symbols and if no closing bracket is found return 0;
bool isMatchingPair(char a,char b){
    if( a=='(' && b==')' ){
        return 1;
    }
    else if( a=='{' && b=='}' ){
        return 1;
    }
    else if( a=='[' && b==']'){
        return 1;
    }
    else{
        return 0;
    }
}

//pop from stack
int pop(struct node ** top){
    char ele;
    struct node * temp;
    if(top==NULL){
      return 0;
    }
    else{
        temp=*top;
        ele=temp->data;
        *top=temp->next;
        free(temp);
        return ele;
    }
}

//to check if parenthesis are BALANCED
bool areParenthesisBalanced(char str[]){
    int i=0;
    struct node * top =NULL;
    while(str[i]){
        //if opening brackets are found then push in stack
        if( str[i]=='(' || str[i]=='{' || str[i]=='['){
            push(&top,str[i]);
        }
        
        //if closing brackets are found pop and check , is the poped element 
        // is a opening pair of present element then they are MatchingPair
        else if( str[i]==')' || str[i]=='}' || str[i]==']'){
            
            //if stack is empty return false
            if( top==NULL){
                return 0;
            }
            //if not a MatchingPair return false
            if( !isMatchingPair( pop(&top), str[i] )){
                return 0;
            }
        }
        //increment i;
        i++;
    }
    //if stack is empty and all MatchingPairs are found return true
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}


int main(void) {
	// your code goes here
	
	char str[100]="{[()]}";
	if(areParenthesisBalanced(str)){
	    printf("\n BALANCED");
	}
	else{
	    printf("\n NOT BALANCED");
	}
    
	return 0;
}

