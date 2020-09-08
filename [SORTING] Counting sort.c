#include <stdio.h>
#define N 15
/* count sort ---- it is not a comparision sort
                   we take count of the numbers present and append that element to proper place  */
// time complexity -----
//worst case ----> o(n+k)
//best case ----> o(n+k)

void display(int arr[]){
    int i;
    for(i=0;i<N;i++){
        printf("%d ",arr[i]);
    }
}

//n = number of elements in arr ; mx = maximun element
void count_sort(int arr[],int n, int mx){
    int i,count[mx+1],b[n];
    //creating count array of size mx with all elements 0   
    for(i=0;i<=mx;++i){
        count[i]=0;
    }
    //incrementing the count of the ith element of the array
    for(i=0;i<n;i++){
        count[arr[i]]=count[arr[i]]+1;
    }
    
    //calculating the position of the elements
    for(i=1;i<=mx;i++){
        count[i]=count[i]+count[i-1];
    }
    //appending the element at proper place in array b
    for(i=n-1;i>=0;i--){
         b[count[arr[i]]] = arr[i];  
        count[arr[i]] = count[arr[i]] - 1;  
    }
    //copying the element to array
    for(i=0;i<n;i++){
        //b have 0 to 9 elements we, will put from index 1
        arr[i]=b[i+1];
    }
}

int main(void) {
	// your code goes here
	int i,arr[N];
	for(i=0;i<N;i++){
	    scanf("%d",&arr[i]);
	}
	
	display(arr);
	count_sort(arr,N,9);
	
	printf("\n after sorting\n");
	
	display(arr);
	return 0;
}

