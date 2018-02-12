#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 4
//���ŧifunction 
//�ˬd�O�_���H�ӧQ
int checkWinner(char* name[10], int who, int counter, int board_size, char* board[board_size][board_size]){
	char* winner = NULL;
	//�ӧQ����:�����B��B�ת����X�{�T�Ӥ@�˴N�O�ӧQ 
	if((board[1][1] == board[1][2] & board[1][1] == board[1][3] & board[1][3] != winner) |
		(board[2][1] == board[2][2] & board[2][1] == board[2][3] & board[2][3] != winner) |
		(board[3][1] == board[3][2] & board[3][1] == board[3][3] & board[3][3] != winner) |
		(board[1][1] == board[2][1] & board[2][1] == board[3][1] & board[3][1] != winner) |
 		(board[1][2] == board[2][2] & board[2][2] == board[3][2] & board[3][2] != winner) |
		(board[1][3] == board[2][3] & board[2][3] == board[3][3] & board[3][3] != winner) |
 		(board[1][1] == board[2][2] & board[2][2] == board[3][3] & board[3][3] != winner) |
		(board[1][3] == board[2][2] & board[2][2] == board[3][1] & board[3][1] != winner)
	){//who == 1��ܪ��a�A who == 0��ܹq�� 
		if(who == 1){
			printf("%s WIN\n", name);
		}else{
			printf("YOU LOSE\n");
			printf("WINNER IS %s\n", name);	
			}
		//�^��m = 9��while loop���� 
		counter = 9;
	}else{//�S���H�ӧQ�h�^��m+1�A�p�G�M���h�^��m = 100 
		counter++; 
		if(counter == 9) counter = 100;
	}
	return counter;
}
//�L�X�ѽL 
void printBoard(int board_size, char* board[board_size][board_size]){
	int i,j;
	for(i = 0; i < board_size; i++){
		for(j = 0; j < board_size; j++){
			if((i == 0 | j == 0)){//*������ 
				board[i][j] = " * ";
			}  
			if(board[i][j]){//���ȴN�L 
				printf(board[i][j]);
			} 	
			else{//�S�ȴN�ť� 
				printf("   ");
			} 	
			if(j == board_size-1){//�̫�@�C�n���� 
				printf("\n");	
			} 
		}
	}//�L�X���j�u 
	printf("=============================\n");
}
//���a�U�� 
void playerMove(int board_size, char* board[board_size][board_size]){
	int s,t;
	printf("Input (row, column) to place chess: \n");
	scanf("%d,%d", &s, &t);
	s++;
	t++;
	if(board[s][t] != NULL | s >= board_size | t >= board_size){//�U��w�����Ŷ��άO���s�b���Ŷ� 
		printf("wrong movement\n");
		playerMove(board_size ,board);
	}else{//���a�N��O 
		board[s][t] = " O ";
		printBoard(board_size ,board);
	}
} 
//�¹q���U�ѡA�L�D�ӷN�� 
void computerMove(int wait, int board_size, char* board[board_size][board_size]){
	//�q���H����1-3���� 
	srand(time(0));
	int s= rand()%3 + 1;
	int t= rand()%3 + 1;
	if(board[s][t] != NULL | s >= board_size | t >= board_size){//�U��w�����Ŷ��άO���s�b���Ŷ� 
		if(wait == 0) printf("computer is thinking...");
		printf(".");
		wait++;
		computerMove(wait, board_size ,board);
	} 	
	else{//�q���N��X�Await��ܹq�����s�U�Ѧ��ơAwait == 0���w�]�A��ܨS������ 
//		printf("\n waiting time : %d\n",wait);
		board[s][t] = " X ";
		printBoard(board_size ,board);
	} 
} 
void main(){
	//�ŧix[]�My[]�Ӹ˪��a�M�q�����m�W�Aboard[][]�O�ѽL 
	char* x[10] = { NULL };
	char* y[10] = { NULL };
	char* board[BOARD_SIZE][BOARD_SIZE] = { NULL };
	int m = 1;
	printf("Input your name: \n");
	scanf("%s",&x);
	printf("Input opponent's name: \n");
	scanf("%s",&y);
	printf("%s V.S. %s\n", x, y);
	
    while(m < 9){//���E�^�X 
		if(m%2 == 1){//�@�}�lm == 1�Am�O�_�Ʀ^�X�ɹq���U�� 
			computerMove(0, BOARD_SIZE, board);
			m = checkWinner(y, 0, m, BOARD_SIZE, board);
		}else{//m�O���Ʀ^�X�ɪ��a�U�� 
			playerMove(BOARD_SIZE ,board);
			m = checkWinner(x, 1, m, BOARD_SIZE, board);
		}
		//�p�G�U��ĤE���٨S�HĹ�AcheckWinner�|�^��100�A��ܩM�� 
		if(m == 100) printf("This game is even.\n");
	}
	
}
