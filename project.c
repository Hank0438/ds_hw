#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 21

void printBoard(int board_size, char* board[board_size][board_size]){
	int i,j;
	for(i = 0; i < board_size; i++){
		for(j = 0; j < board_size; j++){
			if((i == 0 | j == 0)){ 
				board[i][j] = " * ";
			}  
			if(board[i][j]){
				printf(board[i][j]);
			} 	
			else{
				printf("   ");
			} 	
			if(j == board_size-1){
				printf("\n");	
			} 
		}
	}
	printf("=============================\n");
}
void playerMove(int board_size, char* board[board_size][board_size]){
	int s,t;
	int type;
	printf("Input (row, column) to place chess: \n");
	scanf("%d,%d", &s, &t);
	sa++;
	ta++;
	sb++;
	tb++;
	sc++;
	tc++;
	if(type=0){
		if(board[sa][ta] != NULL | sa >= board_size | ta >= board_size){//下到已有的空間或是不存在的空間 
			printf("wrong movement\n");
			playerMove(board_size ,board);
		}else{ 
			board[sa][ta] = " X ";
			board[sa+1][ta] = " X ";
			board[sa-1][ta] = " X ";
			board[sa][ta+1] = " X ";
			board[sa][ta-1] = " X ";
			board[sa+1][ta+1] = " X ";
			board[sa+1][ta-1] = " X ";
			board[sa-1][ta+1] = " X ";
			board[sa-1][ta-1] = " X ";
			printBoard(board_size ,board);
		}
	} else if(type=1){
		if(board[sb][tb] != NULL | sb >= board_size | tb >= board_size){//下到已有的空間或是不存在的空間 
			printf("wrong movement\n");
			playerMove(board_size ,board);
		}else{ 
			board[sb][tb] = " X ";
			board[sb-1][tb] = " X ";
			board[sb][tb-1] = " X ";
			board[sb-1][tb-1] = " X ";
			printBoard(board_size ,board);
		}
	}else{
		if(board[sc][tc] != NULL | sc >= board_size | tc >= board_size){//下到已有的空間或是不存在的空間 
			printf("wrong movement\n");
			playerMove(board_size ,board);
		}else{ 
			board[sc][tc] = " X ";
			printBoard(board_size ,board);	
		}
	}
}
	
void computerMove(int wait, int board_size, char* board[board_size][board_size]){
	//電腦隨機給1-20的值 
	srand(time(0));
	int type;
	int sa= rand()%20 + 1;
	int ta= rand()%20 + 1;
	int sb= rand()%20 + 1;
	int tb= rand()%20 + 1;
	int sc= rand()%20 + 1;
	int tc= rand()%20 + 1;
	if(type=0){
		if(board[sa][ta] != NULL | sa >= board_size | ta >= board_size){//下到已有的空間或是不存在的空間 
			if(wait == 0) printf("computer is thinking...");
			printf(".");
			wait++;
			computerMove(wait, board_size ,board);
		} 		
		else{
			board[sa][ta] = " X ";
			board[sa+1][ta] = " X ";
			board[sa-1][ta] = " X ";
			board[sa][ta+1] = " X ";
			board[sa][ta-1] = " X ";
			board[sa+1][ta+1] = " X ";
			board[sa+1][ta-1] = " X ";
			board[sa-1][ta+1] = " X ";
			board[sa-1][ta-1] = " X ";
			printBoard(board_size ,board);	
		}
	}
	else if(type=1){
		if(board[sb][tb] != NULL | sb >= board_size | tb >= board_size){//下到已有的空間或是不存在的空間 
			if(wait == 0) printf("computer is thinking...");
			printf(".");
			wait++;
			computerMove(wait, board_size ,board);
		} 	
		else{
			board[sb][tb] = " X ";
			board[sb-1][tb] = " X ";
			board[sb][tb-1] = " X ";
			board[sb-1][tb-1] = " X ";
			printBoard(board_size ,board);	
		} 
	}
	else{	
		if(board[sc][tc] != NULL | sc >= board_size | tc >= board_size){//下到已有的空間或是不存在的空間 
			if(wait == 0) printf("computer is thinking...");
			printf(".");
			wait++;
			computerMove(wait, board_size ,board);
		} 	
		else{
			board[sc][tc] = " X ";
			printBoard(board_size ,board);	
		} 
	}
}

void main(){
	char* board[BOARD_SIZE][BOARD_SIZE] = { NULL };
	char* x[10] = { NULL };
	int m = 1;
	printf("Input the type of store you want to know: \n");
	scanf("%s",&x);
	
	if(m%5 == 1){
		//這裡想要設計成每五局電腦會自己淘汰掉一間店 
	}

}

