#include <stdio.h>
#define N 5
/* Selection sort --- selects the smallest value from unsorted sub list and appends that in unsorted sublist
                      at starting unsorted sublist is empty.*/
//time complexity ---
//worst case --- o(n^2)
//best case --- o(n^2)

void display(int arr[N]){
    int i;
    for(i=0;i<=N;i++){
        printf("%d ",arr[i]);
    }
}

void selection_sort(int arr[N]){
    int i, j,min;
    for(i=0;i<N;i++){
        min=i;
        for(j=i+1;j<=N;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp;
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}


int main(void) {
	// main driver program
	int arr[N],i;
	printf("enter elements of array\n");
	//3 2 4 5 6 1 
	for(i=0;i<=N;i++){
	    scanf("%d",&arr[i]);
	}
	display(arr);
	printf("\nafter sorting\n");
	selection_sort(arr);
	display(arr);
	//1 2 3 4 5 6
	
	return 0;
}

