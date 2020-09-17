#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack{
    int top;
    unsigned capacity;
    char * array;
};

struct Stack * CreateStack(int n){
    struct Stack * stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top==-1;
    stack->capacity=n;
    stack->array=(char*)malloc(stack->capacity * sizeof(char));
    return stack;
}


int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
} 

int isFull(struct Stack * stack){
    return stack->top==stack->capacity;
}

void push(struct Stack * stack,char d){
    if(isFull(stack)){
        return;
    }
   else{
       stack->array[++stack->top]=d;
   } 
}

char pop(struct Stack * stack){
    if(isEmpty(stack)){
        return 0;
    }
    else{
        return stack->array[stack->top--];
        
    }
}

void reverse_string(char str[]){
    int i;
    int n = strlen(str);
    struct Stack * stack = CreateStack(n);
    
    for(i=0;i<n;i++){
        push(stack,str[i]);
    }
    
    for(i=0;i<n;i++){
        str[i]=pop(stack);
    }
    
}
int main(void) {
	// your code goes here
   
    char str[]="abcdefghijk";
    
    reverse_string(str);
    printf("\nthe reversed string is: %s",str);
	
	
	return 0;
}

