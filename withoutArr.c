#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BOARD_SIZE 12

typedef struct details {
	char type;
	int data;
	int x;
	int y;
	struct details *next;
} Details;


Details *computerMove(int p, Details *first){
	Details *tmp = first;
	Details *sth;	
	sth = (Details *) malloc(sizeof(Details));
	if(sth == NULL){
		printf("°O¾ÐÅé¤£¨¬");
		return NULL;
	}
	srand(time(0));
	int u,r;
	int s= rand()%10 + 1;
	int t= rand()%10 + 1;
	while(tmp != NULL & tmp->x != s & tmp->y != t){
		srand(time(0));
		s= rand()%10 + 1;
		t= rand()%10 + 1;
		if(tmp->x != s & tmp->y != t){
			tmp = tmp->next;
		}
	}
	
	if(p == 0){ p = rand()%3 + 1;}

	
	if(p == 1){
//		board[s][t] = " A ";
//		for(u=s-2; u<s+3; u++){
//			for(r=t-2; r<t+3; r++){
//				if(board[u][r] == NULL) board[u][r] = " 1 ";
//			}
//		}
		sth->data = 4;
		sth->type = 'A';
	} 
	if(p == 2){
//		board[s][t] = " B ";
//		for(u=s-1; u<s+2; u++){
//			for(r=t-1; r<t+2; r++){
//				if(board[u][r] == NULL) board[u][r] = " 2 ";
//			}
//		}
		sth->data = 3;
		sth->type = 'B';
	} 
	if(p == 3){
//		board[s][t] = " C ";
		sth->data = 2;
		sth->type = 'C';
	}
	sth->x = s;
	sth->y = t;
	sth->next = NULL;
	return sth;
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

void clearBoard(char* board[BOARD_SIZE][BOARD_SIZE]){
	int i,j;
	for(i = 0; i < BOARD_SIZE; i++){
		for(j = 0; j < BOARD_SIZE; j++){
			if(board[i][j] != NULL){
				board[i][j] = "   ";
			}	
		}
	}
}

void readDetails(Details *first, char* tmpBoard[BOARD_SIZE][BOARD_SIZE]){
	Details *tmp = first;
	int s,t,u,r;
	char type;
	while(tmp != NULL){
		s = tmp->x;
		t = tmp->y;
		type = tmp->type;
		if(type == 'A'){
			tmpBoard[s][t] = " A ";
			for(u=s-2; u<s+3; u++){
				for(r=t-2; r<t+3; r++){
					if(tmpBoard[u][r] == "   ") tmpBoard[u][r] = " 1 ";
				}
			}
		}
		if(type == 'B'){
			tmpBoard[s][t] = " B ";
			for(u=s-1; u<s+2; u++){
				for(r=t-1; r<t+2; r++){
					if(tmpBoard[u][r] == "   ") tmpBoard[u][r] = " 2 ";
				}
			}
		}
		if(type == 'C'){
			tmpBoard[s][t] = " C ";
		}
		tmp = tmp->next;
	}
}

Details *sorting(Details *first){
	Details *tmp = first;
	Details *prev = first;
	while(tmp != NULL){
		if(tmp == first & tmp->data == 0){
			first = tmp->next;
			prev = tmp->next;
		}else{
			if(tmp->data == 0){
				prev->next = tmp->next;
				if(tmp->next->data != 0) prev = tmp->next;
			}else{
				prev = tmp;
			}
		}
		tmp = tmp->next;
	}
	free(tmp);
	return first;
}

void depreciating(Details *first){
	Details *tmp = first;
	while(tmp != NULL){
		tmp->data--;
		tmp = tmp->next;
	}
	free(tmp);
}

void display(Details *first){  
	Details *p = first;  
	while(p!=NULL){   
		printf("%c(%d,%d) :",p->type,p->x,p->y);
		printf("year is %d\n",p->data);  
		p=p->next;    
	}    
}  

void main(){
	char* board[BOARD_SIZE][BOARD_SIZE] = { NULL };
	int x,y,count;
	char option;
	Details *move = NULL;
	Details *first = NULL;
	first = move = computerMove(1, board);
	
	move->next = computerMove(2, board);
	move = move->next;
	
	move->next = computerMove(3, board);
	move = move->next;
	
	printBoard(board);
	depreciating(first);
	first = sorting(first);
	
	display(first);
	printf("--------------------------\n"); 
	
	
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
//				printf("/////////////Round %d///////////////\n",count);
				move->next = computerMove(0, board);
				move = move->next;
//				printf("==============before sorting=============\n");
				depreciating(first);
//				display(first);
//				printf("==============after sorting==============\n");
				first = sorting(first);
//				display(first);
				count--;
			}	
			clearBoard(board);	
			readDetails(first, board);
			printBoard(board);	
			display(first);
			printf("--------------------------\n");
		}else{
			
		}
	}
};

