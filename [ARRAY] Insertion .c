#include <stdio.h>
#include <stdlib.h>
#define N 50

//traverse array
void display(int arr[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}



int main(void) {
	// your code goes here
	int i,size=5;
	int arr[N],pos,data;
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("array cointains :\n");
    display(arr,size);
	// insertion
	printf("\nenter data to insert in array :\n");
	scanf("%d",&data);
	printf("\nenter position at which data is to be inserted :\n");
	scanf("%d",&pos); 
	//boundary check for size 
	if(pos<=0 && pos>=50){
	    printf("\n postion is not valid. array has a size limit of 50");
	}
	else{
	    //shift each element to right till pos-1
	    for(i=size-1;ipos-1;i--){
	        arr[i+1]=arr[i];
	    }
	    arr[pos-1]=data;
	    size=size+1;
	}
	printf("\narray cointains :\n");
	display(arr,size);
	return 0;
}

