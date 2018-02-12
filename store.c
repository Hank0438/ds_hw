#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BOARD_SIZE 12
typedef struct items {
    char type;
	int data;
	int x;
	int y;
    struct items *link; // points to next element
} ITEM;

typedef struct queue {
    int size;
    ITEM *front, *rear;
} QUEUE;

void initQueue(QUEUE *q) {
    q->size = 0;
    q->front = q->rear = NULL;
}
int queueIsEmpty(QUEUE *q) {
    return q->front == NULL;
}
int queueLength(QUEUE *q) {
    return q->size;
}
void addQueue(int s, int t, QUEUE *q, int y, char type) {
    ITEM * x = (ITEM *) malloc(sizeof(ITEM));
    x->type = type;
	x->data = y;
	x->x = s;
	x->y = t;
	x->link = NULL;
    if (q->front == NULL)
        q->front = x;
    else
        q->rear->link = x;
    q->rear = x;
    q->size++;
}

void deleteQueue(QUEUE *q) {
    ITEM* x = q->front;
    q->front = x->link;
    if (q->front == NULL)  
        q->rear = NULL;
    q->size--;
    printf("%c(%d,%d) :",x->type,x->x,x->y);
    printf("year is %d\n",x->data);
    free(x);
}

int deleteZeroQueue(QUEUE *q){
	ITEM* x = q->front;
//	while(x->data == 1){ //²Ä¤@­Ó 
//		x->data--;
//		q->front = x->link;
//		x = x->link;
//	}
	while(x->link != NULL){
		x->data--;
//		if(x->link->data == 0){
//			x->link = x->link->link;
//		}
//		x = x->link;
//		
//		if(x->data == 0 && q->front == x){ 
//			q->front = x->link;
//		}
//		else if(x->link->data == 1 && x->link->link == NULL){  
//			q->rear = x;
//		}else{
//			x->link = x->link->link;
//		}
		x = x->link;	
	}
	free(x);
}


void computerMove(QUEUE *q, int type, char* board[BOARD_SIZE][BOARD_SIZE]){
	
	srand(time(0));
	int p,u,r;
	int s= rand()%10 + 1;
	int t= rand()%10 + 1;

	while(board[s][t] != NULL){
		srand(time(0));
		s= rand()%10 + 1;
		t= rand()%10 + 1;
	}
	if(type == 0){
		p = rand()%3 + 1;
	}
	else{
		p = type;
	} 
	if(p == 1){
		board[s][t] = " A ";
		addQueue(s, t, q, 4, 'A');
		for(u=s-2; u<s+3; u++){
			for(r=t-2; r<t+3; r++){
				if(board[u][r] == NULL) board[u][r] = " 1 ";
			}
		}	
	} 
	if(p == 2){
		board[s][t] = " B ";
		addQueue(s, t, q, 3, 'B');
		for(u=s-1; u<s+2; u++){
			for(r=t-1; r<t+2; r++){
				if(board[u][r] == NULL) board[u][r] = " 2 ";
			}
		}	
	} 
	if(p == 3){
		board[s][t] = " C ";
		addQueue(s, t, q, 2, 'C');
	} 
} 


void playerMove(char* board[BOARD_SIZE][BOARD_SIZE]){
	int s,t,sign;
	printf("Choose A(1), B(2) or C(3): \n");
	scanf("%d", &sign);
	printf("Input (row, column): \n");
	scanf("%d,%d", &s, &t);
	if(board[s][t] != NULL | s >= BOARD_SIZE-1 | t >= BOARD_SIZE-1){
		printf("wrong movement\n");
		playerMove(board);
	}else{
		if(sign == 1) board[s][t] = " A ";	
		if(sign == 2) board[s][t] = " B ";
		if(sign == 3) board[s][t] = " C ";
	}
} 
 
void printBoard(char* board[BOARD_SIZE][BOARD_SIZE]){
	int i,j;
	for(i = 0; i < BOARD_SIZE; i++){
		for(j = 0; j < BOARD_SIZE; j++){
			if( i == 0 | j == 0 | i == BOARD_SIZE-1 | j == BOARD_SIZE-1 ){ 
				board[i][j] = " * ";
			}  
			if(board[i][j]){
				printf(board[i][j]);
			} 	
			else{
				printf("   ");
			} 	
			if(j == BOARD_SIZE-1){
				printf("\n\n");	
			}
		}
	}
	printf("=====================================================\n");
}

void main(){
	char* board[BOARD_SIZE][BOARD_SIZE] = { NULL };
	int x,y,count;
	QUEUE q;
	char option;
	initQueue(&q);
	computerMove(&q, 1, board);
	computerMove(&q, 2, board);
	computerMove(&q, 3, board);
	printBoard(board);
	printf("Please choose a place of your shop, Y or N:\n");
	scanf(" %c", &option);
	if(option == 'Y'){
		playerMove(board);
		printBoard(board);
	}else{
		printf("Do you want to forecast future? Y or N:\n");
		scanf(" %c", &option);
		if(option == 'Y'){
			printf("how many years? (years < 20)\n");
			scanf("%d", &count);
			while(count > 0){
				computerMove(&q, 0, board);
				count--;
//				deleteZeroQueue(&q);
			}
			printBoard(board);
//			printf("%d\n",queueLength(&q));
			while (!queueIsEmpty(&q)) {
		        deleteQueue(&q);
		    }
		}else{
			
		}
	}
}
