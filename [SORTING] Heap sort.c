#include <stdio.h>
#define N 10
/* heap sort --- 1. make a max heap using heapify function
                 2. delete from maxheap (root element is the largest in max heap)
                    - swap the first and last elements of the array and decrese the size by one. */
//time complexity ----
//worst case ---- o(n log n)
//best case ---- o(n log n)
//heapify function ---o(n)


void display(int arr[]){
    int i;
    for(i=0;i<N;i++){
        printf("%d ",arr[i]);
    }
}

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int arr[],int n,int i){
    int largest=i;
    int l=2*i;
    int r=2*i+1;
    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}


void heap_sort(int arr[],int n){
    int i,s=n/2;
    //create max heap
    for(i=s-1;i>=0;i--){
        heapify(arr,n,i);
    }
    //delete from max heap and append that element at the end of arr
    for(i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

int main(void) {
	// your code goes here
	int i, arr[N];
	for(i=0;i<N;i++){
	    scanf("%d",&arr[i]);
	}
	display(arr);
	printf("\nafter sorting \n");
	heap_sort(arr,N);
	display(arr);
	return 0;
}

