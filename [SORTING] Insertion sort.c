#include <stdio.h>
#define N 5
/*insertion sort ----> takes one element from unsorted sublist and 
                       inserts that elemnt in sorted list at its correct
                       position. */
                       
// time complexity :
//worst case ---- o(n^2) -----> array sorted in reverse
//best case ---- o(n) ----->array already sorted

void display(int arr[N]){
    int i;
    for(i=0;i<=N;i++){
        printf("%d ",arr[i]);
    }
}

void insertion_sort(int arr[N]){
    int i,temp,j;
    for(i=1;i<=N;i++){
        temp=arr[i];//first element of unsorted list
        j=i-1;//first index of sorted list
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
                

int main(void) {
	// your code goes here
	int i,arr[N];
	printf("provide array elements :\n");
    //2 4 3 6 5 1	
	for(i=0;i<=N;i++){
	    scanf("%d",&arr[i]);
	}
	display(arr);//2 4 3 6 5 1
	printf("\n after sorting :\n");
	insertion_sort(arr);
	display(arr);//1 2 3 4 5 6 
	
	return 0;
}

