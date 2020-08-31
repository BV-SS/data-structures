#include <stdio.h>
# define N 5
//binary search ---- time complexity -> o(log n) for worst case
//                                   -> o(1) for best case
//calculate mid value -- recursive approach 
int binary_search(int item,int arr[N],int f,int l){
    
    if(l>=f){
        int m=f+(l-f)/2;
        
        if(arr[m]==item){
            return m;
        }
        if(arr[m]<item){
            return(binary_search(item,arr,m+1,l));
        }
        
        else{
            return(binary_search(item,arr,f,m-1));
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
	
	int n=binary_search(item,arr,0,N+1);
	if(n==-1){
	    printf("\nthe elemnet was not found in the array");
	}
	else{
	    printf("\nelement found at index %d ",n);
	}
	
	
	
	return 0;
}

