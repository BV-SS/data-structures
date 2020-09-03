#include <stdio.h>
#define N 5
/* merge sort --- divide and counquer 
                  divides the array until single element is left in the sublist
                  then merges two sublists in a way that new sublist is a sorted array.*/
//time complexity ----
//worst case ---- o(n log n)
//best case ---- o(n log n)

void display(int arr[N]){
    int i;
    for(i=0;i<=N;i++){
        printf("%d ",arr[i]);
    }
}

void merge(int arr[N],int lb,int mid,int ub){
    int i=lb;
    int j=mid+1;
    int k=lb;
    int b[N];
    while(i<=mid && j<=ub){
        if(arr[i]<=arr[j]){
            b[k]=arr[i];
            i++;
            k++;
        }
        else{
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    if(i>mid){
        while(j<=ub){
            b[k]=arr[j];
            j++; k++;
        }
    }
    
    else{
        while(i<=mid){
            b[k]=arr[i];
            i++; k++;
        }
    }
    
    for(k=lb;k<=ub;k++){
        arr[k]=b[k];
    }
    
}

void merge_sort(int arr[N],int lb, int ub){
    if(lb<ub){
        int mid=(ub+lb)/2;
        merge_sort(arr,lb,mid);
        merge_sort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

int main(void) {
	// main driver code 
	int arr[N],i;
	//4 6 5 3 2 1
	for(i=0;i<=N;i++){
	    scanf("%d",&arr[i]);
	}
	display(arr);
	printf("\n after sorting \n");
	merge_sort(arr,0,N);
	display(arr);//1 2 3 4 5 6 
	return 0;
}

