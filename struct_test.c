#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Shop{
	char type;
	int years;
};

void main(){
	int arr[30];
	struct Shop a,b,c;
	int i=0;
	for(i=0; i<5; i++){
		printf("%d\n", arr[i]);
	}
	printf("---------------------------\n");
	arr[1] = 0;
	while(i < 5){
		printf("test\n");
		int tmp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = tmp;
		i++;
	}
	
	for(i=0; i<5; i++){
		printf("%d\n", arr[i]);
	}
	
}
