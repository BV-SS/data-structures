#include <stdio.h>
# define N 5
//binary search ---- time complexity -> o(log n) for worst case
//                                   -> o(1) for best case
//calculate mid value 
int binary_search(int item,int arr[N]){
    int front=0,last=N+1;
    int m;
    while(front!=last){
        
        m=front+(last-front)/2;
        
        if(arr[m]==item){
            return m;
        }
        if(item>arr[m]){
            front=m+1;
        }
        else{
            last=m-1;
        }
    }
    
    return -1;
}
int main(void) {
	// your code goes here
	int i,arr[N];
	for(i=0;i<=N;i++){
	    scanf("%d",&arr[i]);
	}
	int item;
	printf("enter element to search");
	scanf("%d",&item);
	
	int n=binary_search(item,arr);
	if(n==-1){
	    printf("\nthe elemnet was not found in the array");
	}
	else{
	    printf("\nelement found at index %d ",n);
	}
	
	
	
	return 0;
}

