#include <stdio.h>
#define N 8
/* shell sort ---- takes a gap (distance) between elements and compare the distant elements
                    after every pass the gap variable decreases and when gap becomes one 
                    it works same like insertion sort  */
//time complexity -----
//worst case ---- o(n*(logn)^2) or o(n^2)
//best case ---- o(n*log n)

void display(int arr[]){
    int i;
    for(i=0;i<N;i++){
        printf("%d ",arr[i]);
    }
}

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void shell_sort(int arr[],int n){
    int i,j,gap;
    
    for(gap=n/2;gap>=1;gap=gap/2){
        
        for(j=gap;j<=n;j++){
            
            for(i=j-gap;i>=0;i=i-gap){
                if(arr[i+gap]>arr[i]){
                    break;
                }
                else{
                    swap(&arr[i+gap],&arr[i]);
                }
            }
        }
    }
    
}
int main(void) {
	// your code goes here
	int i,arr[N];
	for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
	display(arr);
	printf("\n n after sorting \n");
	shell_sort(arr,N-1);
	display(arr);
	return 0;
}

