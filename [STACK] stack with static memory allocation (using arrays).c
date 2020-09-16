#include <stdio.h>
#define n 5
//stack ----> last in first out 
//stack ---> LIFO or FILO 
//time-complexity ---- push --> o(1);
//                ---- pop --> o(1);
//                ---- display o(n);

int main(void) {
	// your code goes here
	int stack[n];
	int top=-1;
	
	void isEmpty(){
	    if(top==-1){
	        printf("\nthe stack is empty");
	    }
	    else{
	        printf("\nthe stack is not empty");
	    }
	}
	
	void push(int d){
	    if(top==n-1){
	        printf("\n the stack is full !");
	    }
	    else{
	        top++;
	        stack[top]=d;
	    }
	}
	
	void pop(){
	    if(top==-1){
	        printf("\n the stack is empty");
	    }
	    else{
	        printf("\n%d deleted",stack[top]);
	        top--;
	    }
	}
	
	void display(){
	    int i;
	    if(top==-1){
	        printf("\n the stack is empty");
	    }
	    else{
	         printf("\nthe stack has elements :");
	         for(i=0;i<=top;i++){
	            printf("%d ",stack[i]);
	         }
	    }
	}
	
	//calling stack functions
	push(2);
	push(5);
	push(7);
	push(17);
	push(23);
	display();
	pop();
	pop();
	pop();
	display();
	isEmpty();
	
	return 0;
}

