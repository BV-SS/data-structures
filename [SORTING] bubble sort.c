#include <stdio.h>
#include <stdbool.h>
#define n 5
//bubble sort --> compares 2 adjacent elements
//time complexity-----
//worst case : o(n^2) -----> when array is sorted in reverse
//best case  : o(n)   -----> when array is already sorted

void display(int arr[n]){
    int i;
    for(i=0;i<=n;i++){
        printf("%d ",arr[i]);
    }
}

void bubble_sort(int arr[n]){
    int i,j,temp;
    bool flag;
    
    for(i=0;i<n-1;i++){
        flag=0;
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                //swaping
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        //if no swapping in any pass break the loop
        if(flag==0){
            break;
        }
    }
    
}
int main(void) {
	// main driver function
	int arr[n],i;
	printf("provide array elements\n");//3 2 4 5 1 6 
	for(i=0;i<=n;i++){
	    scanf("%d",&arr[i]);
	}
	display(arr);//3 2 4 5 1 6 
	printf("\nelements after sorting\n");
	bubble_sort(arr);
	display(arr);//1 2 3 4 5 6
	
	return 0;
}

