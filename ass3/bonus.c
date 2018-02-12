#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 4
//先宣告function 
//檢查是否有人勝利
int checkWinner(char* name[10], int who, int counter, int board_size, char* board[board_size][board_size]){
	char* winner = NULL;
	//勝利條件:直的、橫的、斜的有出現三個一樣就是勝利 
	if((board[1][1] == board[1][2] & board[1][1] == board[1][3] & board[1][3] != winner) |
		(board[2][1] == board[2][2] & board[2][1] == board[2][3] & board[2][3] != winner) |
		(board[3][1] == board[3][2] & board[3][1] == board[3][3] & board[3][3] != winner) |
		(board[1][1] == board[2][1] & board[2][1] == board[3][1] & board[3][1] != winner) |
 		(board[1][2] == board[2][2] & board[2][2] == board[3][2] & board[3][2] != winner) |
		(board[1][3] == board[2][3] & board[2][3] == board[3][3] & board[3][3] != winner) |
 		(board[1][1] == board[2][2] & board[2][2] == board[3][3] & board[3][3] != winner) |
		(board[1][3] == board[2][2] & board[2][2] == board[3][1] & board[3][1] != winner)
	){//who == 1表示玩家， who == 0表示電腦 
		if(who == 1){
			printf("%s WIN\n", name);
		}else{
			printf("YOU LOSE\n");
			printf("WINNER IS %s\n", name);	
			}
		//回傳m = 9讓while loop結束 
		counter = 9;
	}else{//沒有人勝利則回傳m+1，如果和局則回傳m = 100 
		counter++; 
		if(counter == 9) counter = 100;
	}
	return counter;
}
//印出棋盤 
void printBoard(int board_size, char* board[board_size][board_size]){
	int i,j;
	for(i = 0; i < board_size; i++){
		for(j = 0; j < board_size; j++){
			if((i == 0 | j == 0)){//*表示邊界 
				board[i][j] = " * ";
			}  
			if(board[i][j]){//有值就印 
				printf(board[i][j]);
			} 	
			else{//沒值就空白 
				printf("   ");
			} 	
			if(j == board_size-1){//最後一列要換行 
				printf("\n");	
			} 
		}
	}//印出分隔線 
	printf("=============================\n");
}
//玩家下棋 
void playerMove(int board_size, char* board[board_size][board_size]){
	int s,t;
	printf("Input (row, column) to place chess: \n");
	scanf("%d,%d", &s, &t);
	s++;
	t++;
	if(board[s][t] != NULL | s >= board_size | t >= board_size){//下到已有的空間或是不存在的空間 
		printf("wrong movement\n");
		playerMove(board_size ,board);
	}else{//玩家代表O 
		board[s][t] = " O ";
		printBoard(board_size ,board);
	}
} 
//笨電腦下棋，無求勝意志 
void computerMove(int wait, int board_size, char* board[board_size][board_size]){
	//電腦隨機給1-3的值 
	srand(time(0));
	int s= rand()%3 + 1;
	int t= rand()%3 + 1;
	if(board[s][t] != NULL | s >= board_size | t >= board_size){//下到已有的空間或是不存在的空間 
		if(wait == 0) printf("computer is thinking...");
		printf(".");
		wait++;
		computerMove(wait, board_size ,board);
	} 	
	else{//電腦代表X，wait表示電腦重新下棋次數，wait == 0為預設，表示沒有重來 
//		printf("\n waiting time : %d\n",wait);
		board[s][t] = " X ";
		printBoard(board_size ,board);
	} 
} 
void main(){
	//宣告x[]和y[]來裝玩家和電腦的姓名，board[][]是棋盤 
	char* x[10] = { NULL };
	char* y[10] = { NULL };
	char* board[BOARD_SIZE][BOARD_SIZE] = { NULL };
	int m = 1;
	printf("Input your name: \n");
	scanf("%s",&x);
	printf("Input opponent's name: \n");
	scanf("%s",&y);
	printf("%s V.S. %s\n", x, y);
	
    while(m < 9){//有九回合 
		if(m%2 == 1){//一開始m == 1，m是奇數回合時電腦下棋 
			computerMove(0, BOARD_SIZE, board);
			m = checkWinner(y, 0, m, BOARD_SIZE, board);
		}else{//m是偶數回合時玩家下棋 
			playerMove(BOARD_SIZE ,board);
			m = checkWinner(x, 1, m, BOARD_SIZE, board);
		}
		//如果下到第九局還沒人贏，checkWinner會回傳100，表示和局 
		if(m == 100) printf("This game is even.\n");
	}
	
}
