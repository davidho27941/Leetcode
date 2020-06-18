#include <stdio.h>
#include <stdlib.h>

int Single(int num, int array[]){
    int i=0, j=0;
    num=num;
    for(i=0;i<num;i++){
    	int count = 0; 
	for(j=0;j<num;j++){
		if(array[j] == array[i]){
			count++;
		}		
		if (count == 0){
			return array[j];
		}
	}
    }	
    return 0;
}

int main(void){
	int i, j, a;
	printf("Please input the lenght of array: \n");
	scanf("%d", &a);
   	int arr[a] ;
   	printf("Your array's lenght is : %d \n", a);
   	printf("Please input your element. \n");
   	for(i=0;i<a;i++){
       		scanf("%d", &arr[i]);
    	}
	
	int result = Single( a, arr);
	printf("result: %d \n", result);
	return 0;
}
