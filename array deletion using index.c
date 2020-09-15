#include <stdio.h>
#define N 50

void display(int arr[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}



int main(void) {
	// your code goes here
	int arr[N],size=5,i;
	for(i=0;i<size;i++){
	    scanf("%d",&arr[i]);
	}
	display(arr,size);
	int pos;
	printf("\n enter the position of element to delete");
	scanf("%d",&pos);
	if(pos<=0 || pos>=50){
	    printf("\n invalid position ");
	}
	else{
	    for(i=pos-1;i<size;i++){
	        arr[i]=arr[i+1];
	    }
	    size=size-1;
	}
	printf("\nafter deletion :\n");
	display(arr,size);
	return 0;
}

