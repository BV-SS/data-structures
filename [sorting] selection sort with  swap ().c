#include <stdio.h>
#define n 5
//selection sort 
void display(int arr[n]){
    int i;
    for(i=0;i<=n;i++){
        printf("%d ",arr[i]);
    }
}
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void selection_sort(int arr[n]){
    int i,j,min;
    for(i=0;i<n;i++){
        min=i;
        for(j=i+1;j<=n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(&arr[i],&arr[min]);
        }
    }
}
int main(void) {
	// your code goes here
	int arr[n],i;
	for(i=0;i<=n;i++){
	    scanf("%d",&arr[i]);
	}
	display(arr);
	selection_sort(arr);
	printf("\n after sorting \n ");
	
	display(arr);
	return 0;
}

