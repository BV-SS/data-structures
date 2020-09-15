#include <stdio.h>
#define N 50
//deletion from array  
//time complexity ---->worst case--- o(n) {deletion from beginning}
//                ---->best case ---o(1)  {delete from end}
void display(int arr[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int search_element(int arr[],int size,int d){
    int i;
    for(i=0;i<size;i++){
        if(arr[i]==d){
            return i;
        }
    }
    return -1;
}


int main(void) {
	// your code goes here
	int arr[N],size=5,i;
	for(i=0;i<size;i++){
	    scanf("%d",&arr[i]);
	}
	display(arr,size);
	//deleting element
	int pos,element;
	printf("\n enter the element to delete");
	scanf("%d",&element);
	pos=search_element(arr,size,element);
	if(pos == -1){
	    printf("\nelement is not present in the array ");
	}
	else{
	    //shift elements to left
	    for(i=pos;i<size;i++){
	        arr[i]=arr[i+1];
	    }
	    size=size-1;
	    printf("\nafter deletion :\n");
    	display(arr,size);
	}
	
	return 0;
}

