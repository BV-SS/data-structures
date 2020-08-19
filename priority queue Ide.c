#include <stdio.h>

#define N 5
int pqueue[N];
int f=-1,r=-1;
int count=0;

// input for priority queue
void enqueue(int n){
    if (r==N-1){
        printf("queue is full");
    }
    
    else if (r==-1 && f==-1){
        r=f=0;
        pqueue[r]=n;
        count++;
    }
    
    else {
        int i;
        for (i=count-1;i>=0;i--){
            
            if(n<pqueue[i]){
                pqueue[i+1]=pqueue[i];
            }
            else{
                break;
            }
            
	}
            pqueue[i+1]=n;
            count++;
            r=count-1;  
  }
}

//delete from queue
void dequeue(){

    if (f==-1 && r==-1){
        printf("\n the queue is empty");
        
    }
    
    else if(f==r){
        printf("\n %d deleted",pqueue[f]);
        f=r=-1;
      }
    
    else{
        printf("\n %d deleted",pqueue[f]);
        f++;
    }
}

//display function
void display(){
    int i=f;
    while(i<=r){
        printf(" %d ",pqueue[i]);
        i++;
    }
}

int main(void) {
    
//code test
    enqueue(1);
    enqueue(7);
    enqueue(15);
    enqueue(2);
    enqueue(4);
    
    printf("\n");
	
    display();
    dequeue();
    printf("\n after dequeue");
    display();
    
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
	
	return 0;
}

