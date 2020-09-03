#include <stdio.h>
#define N 5
/* quick-sort --- selests a pivot element first.
                 all the elements that are less than pivot element goes to left of pivot element.
                 all elements that are greator that the pivot element occurs at right of pivot element   */
//time complexity ---
//worst case ---- o(n^2)
//best case ---- o(n log n)
void display(int arr[N]){
    int i;
    for(i=0;i<=N;i++){
        printf("%d ",arr[i]);
    }
}

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[N],int lb,int ub){
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    //while start is less than end (atleast 2 elements)
    while(start<end){
        //increment start if value is less than pivot element
        while(arr[start]<=pivot){
            start++;
        }
        //decrement end if the value is greator than pivot elemnt 
        while(arr[end]>pivot){
            end--;
        }
        //if start is greator than pivot and end is smaller than pivot
        if(start<end){
            swap(&arr[start],&arr[end]);
        }
    }
    
    swap(&arr[lb],&arr[end]);
    return end;
}

void quick_sort(int arr[N],int lb,int ub){
    int loc;
    if(lb<ub){
        loc=partition(arr,lb,ub);
        quick_sort(arr,lb,loc);
        quick_sort(arr,loc+1,ub);
    }
}

int main(void) {
	// your code goes here
	int i,arr[N];
	for(i=0;i<=N;i++){
	    scanf("%d",&arr[i]);
	}
	display(arr);
	printf("\n after sorting \n");
	
	quick_sort(arr,0,N);
	display(arr);
	return 0;
}

