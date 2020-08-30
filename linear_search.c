#include <stdio.h>
//linear search

void  linear_search(int item, int arr[6]){
    int i;
    for(i=0;i<=6;i++){
        if(arr[i]==item){
            
            printf("\nthe element found at position %d and at index %d",i+1,i);
            break;
        }
        else if(i==6){
                printf("\nelement not found");
            }
    }
}


int main(void) {
	// your code goes here
    int i,arr[6];
	for(i=0;i<=5;i++){
	    scanf("%d",&arr[i]);
	}
	
	int item;
	printf("enter number to search in array:");
	scanf("%d",&item);
	linear_search(item,arr);
	 
	return 0;
}

