#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *listPtr;
typedef struct listNode{
	int data;
	listPtr link;
};

int main(){
	listPtr first,last;
	
	first = (listPtr)malloc(sizeof(struct listNode));
	last = (listPtr)malloc(sizeof(struct listNode));

	last->link=NULL;
	last->data=20;
	
	first->link=last;
	first->data=10;
	
	printf("first's addr is %d\n",first); 
	printf("first's data is %d\n",first->data); 
	printf("first's next is %d\n",first->link); 
	
	printf("last's addr is %d\n",last); 
	printf("last's data is %d\n",last->data); 
	printf("last's next is %d\n",last->link);
	
	return 0;	
}
