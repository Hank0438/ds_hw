#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *listPtr;
typedef struct listNode{
	int data;
	listPtr link;
};

int main(){
	int nodeNum=5;

	listPtr first,last;
	first=last=(listPtr)malloc(sizeof(struct listNode));
	int count=1;
	
	while((count-1)/2 <=nodeNum){
		last->link=(listPtr)malloc(sizeof(struct listNode));
		last=last->link;
		last->data=count;	
		count+=2;
	}

	last->link=NULL;
	
	listPtr tmp;
	tmp=first;
	first=first->link;
	free(tmp);
	
	tmp=first;
	for(count=1;count<=nodeNum;count++){
		printf("Node %d is %d\n",count,tmp->data);
		tmp=tmp->link;
	}
	//there is a list {1,3,5,7,9} where head is 1 and the last is 9
	
	
	tmp=first;
	while(tmp->link!=NULL&&tmp->data!=5){
		tmp=tmp->link;
	}
	if(tmp->data==5){
		listPtr ins=(listPtr)malloc(sizeof(struct listNode));
		ins->data=2;
		ins->link=tmp->link;
		tmp->link=ins;
		nodeNum++;
	}else{
		printf("\nnode not found!\n");
	}
	
	printf("\nNew Nodes are\n");
	tmp=first;
	for(count=1;count<=nodeNum;count++){
		printf("Node %d is %d\n",count,tmp->data);
		tmp=tmp->link;
	}
		
	return 0;
}





