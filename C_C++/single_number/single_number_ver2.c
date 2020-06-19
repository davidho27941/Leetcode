#include <stdio.h>
#include <stdlib.h>

int Single(int num, int* array){
    int n = array[0];
    for(int i = 1 ; i < num ; i++){
   	n ^= array[i];
    }
    return n;
}

int main(void){
	int a;
	printf("Please input the lenght of array: \n");
	scanf("%d", &a);
   	int arr[a] ;
   	printf("Your array's lenght is : %d \n", a);
   	printf("Please input your element. \n");
   	for(int i=0;i<a;i++){
       		scanf("%d", &arr[i]);
    	}
	
	int result = Single( a, arr);
	printf("result: %d \n", result);
	return 0;
}
