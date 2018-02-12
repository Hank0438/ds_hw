#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BOARD_SIZE 22

typedef struct details {
	char type;
	int data;
	int limit;
	int x;
	int y;
	struct details *next;
} Details;

Details *computerMove(char type, char* board[BOARD_SIZE][BOARD_SIZE]){
	Details *sth;
	sth = (Details *) malloc(sizeof(Details));
	if(sth == NULL){
		printf("記憶體不足");
		return NULL;
	}
	int p;
	srand(time(0));
	int u, r, limit, count;
	int s= rand()%20 + 1;
	int t= rand()%20 + 1;
	
	if(type == 'N'){ p = rand()%3 + 1;}

	
	if(type == 'A' | p == 1){
		limit = 2;
		count = 0;
		sth->data = 4;
		sth->type = 'A';
		while(count != 25){
			srand(time(0));
			s= rand()%20 + 1;
			t= rand()%20 + 1;
			for(u=s-limit; u<=s+limit; u++){
				for(r=t-limit; r<=t+limit; r++){
					if(board[u][r] == NULL) count++;
				}
			}
			if(count < 25) count = 0;
//			printf(".");
		}
		board[s][t] = " A ";
		for(u=s-limit; u<=s+limit; u++){
			for(r=t-limit; r<=t+limit; r++){
				if(board[u][r] == NULL) board[u][r] = " 1 ";
			}
		}
	} 
	if(type == 'B' | p == 2){
		limit = 1;
		count = 0;
		sth->data = 3;
		sth->type = 'B';
		while(count != 9){
			srand(time(0));
			s= rand()%20 + 1;
			t= rand()%20 + 1;
			for(u=s-limit; u<=s+limit; u++){
				for(r=t-limit; r<=t+limit; r++){
					if(board[u][r] == NULL) count++;
				}
			}
			if(count < 9) count = 0;
//			printf(".");
		}
		board[s][t] = " B ";
		for(u=s-limit; u<=s+limit; u++){
			for(r=t-limit; r<=t+limit; r++){
				if(board[u][r] == NULL) board[u][r] = " 2 ";
			}
		}
	} 
	if(type == 'C' | p == 3){
		limit = 0;
		sth->data = 2;
		sth->type = 'C';
		while(board[s][t] != NULL){
			srand(time(0));
			s= rand()%20 + 1;
			t= rand()%20 + 1;
		}
		board[s][t] = " C ";
	}
	printf("\n");
	sth->limit = limit;
	sth->x = s;
	sth->y = t;
	sth->next = NULL;
	return sth;
} 

Details *playerMove(char* board[BOARD_SIZE][BOARD_SIZE]){
	Details *sth;
	sth = (Details *) malloc(sizeof(Details));
	if(sth == NULL){
		printf("記憶體不足");
		return NULL;
	}
	int s,t,u,r,limit;
	char type;
	do{
		char typei;
		int si,ti;
		printf("Choose A, B or C: \n");
		scanf(" %c", &typei);
		if(typei == 'A' | typei == 'B' | typei == 'C'){
			printf("Input (row, column): \n");
			scanf("%d,%d", &si, &ti);
			if(board[si][ti] == NULL & si < BOARD_SIZE-1 & ti < BOARD_SIZE-1) {
				type = typei;
				s = si;
				t = ti; 
				break;
			}else{ printf("wrong movement\n");}
		}else{ printf("wrong movement\n");}
		
	}
	while(board[s][t] != NULL | s >= BOARD_SIZE-1 | t >= BOARD_SIZE-1);
	
	if(type == 'A'){
		limit = 2;
		board[s][t] = " A ";
		for(u=s-limit; u<=s+limit; u++){
			for(r=t-limit; r<=t+limit; r++){
				if(board[u][r] == NULL) board[u][r] = " 1 ";
			}
		}
		sth->limit = limit;
		sth->data = 4;
		sth->type = 'A';
	} 
	if(type == 'B'){
		limit = 1;
		board[s][t] = " B ";
		for(u=s-limit; u<=s+limit; u++){
			for(r=t-limit; r<=t+limit; r++){
				if(board[u][r] == NULL) board[u][r] = " 2 ";
			}
		}
		sth->limit = limit;
		sth->data = 3;
		sth->type = 'B';
	} 
	if(type == 'C'){
		limit = 0;
		board[s][t] = " C ";
		sth->data = 2;
		sth->type = 'C';
	}
	sth->limit = limit;
	sth->x = s;
	sth->y = t;
	sth->next = NULL;
	return sth;
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
	int s,t,u,r,limit;
	char type;
	while(tmp != NULL){
		limit = tmp->limit;
		s = tmp->x;
		t = tmp->y;
		type = tmp->type;
		if(type == 'A'){
			tmpBoard[s][t] = " A ";
			for(u=s-limit; u<=s+limit; u++){
				for(r=t-limit; r<=t+limit; r++){
					if(tmpBoard[u][r] == "   ") tmpBoard[u][r] = " 1 ";
				}
			}
		}
		if(type == 'B'){
			tmpBoard[s][t] = " B ";
			for(u=s-limit; u<=s+limit; u++){
				for(r=t-limit; r<=t+limit; r++){
					if(tmpBoard[u][r] == "   ") tmpBoard[u][r] = " 2 ";
				}
			}
		}
		if(type == 'C'){
			tmpBoard[s][t] = " C ";
		}
		tmp = tmp->next;
	}
	free(tmp);
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
	free(p);    
} 

void printVacancy(char type, char* board[BOARD_SIZE][BOARD_SIZE]){
	int i,j,u,r,g,q,count,limit,tmp;
	for(i = 1; i < BOARD_SIZE; i++){
		for(j = 1; j < BOARD_SIZE; j++){
			if(type == 'A'){
				limit = 2;
				count = 25;
			}
            if(type == 'B'){
            	limit = 1;
				count = 9;	
			}
			if(type == 'C'){
				limit = 0;
				count = 1;
			}
			tmp = count;
			for(u=i-limit; u<=i+limit; u++){
				for(r=j-limit; r<=j+limit; r++){
					if(board[u][r] == "   " | board[u][r] == " * " | board[u][r] == NULL | u<0 | r<0){
						count--;	
					}
				}
			}
			if(count == 0){
				printf(" ( %d, %d) ",i,j);	
			}
		}
	}
	printf("\n");
}

void getInfo(char type, Details *first, char* board[BOARD_SIZE][BOARD_SIZE]){
	Details *tmp = first;
	int s,t,u,r,limit;
	
	if(type == 'A'){ //A
		// 不可以跟B相鄰，所以B的範圍會在大一圈 
		while(tmp != NULL){
			s = tmp->x;
			t = tmp->y;
			limit = tmp->limit;
			if(tmp->type == 'B'){
				for(u=s-(limit+1); u<=s+(limit+1); u++){
					for(r=t-(limit+1); r<=t+(limit+1); r++){
						if(board[u][r] == NULL) board[u][r] = " 7 ";
					}
				}
			};
			tmp = tmp->next;
		}
		printVacancy(type,board);
	}else if(type == 'B'){ //B
		// 不可以跟AB相鄰，所以A和B的範圍會在大一圈 
		while(tmp != NULL){
			s = tmp->x;
			t = tmp->y;
			limit = tmp->limit;
			if(tmp->type == 'B'){
				for(u=s-(limit+1); u<=s+(limit+1); u++){
					for(r=t-(limit+1); r<=t+(limit+1); r++){
						if(board[u][r] == NULL) board[u][r] = " 2 ";
					}
				}
			};
			if(tmp->type == 'A'){
				for(u=s-(limit+1); u<=s+(limit+1); u++){
					for(r=t-(limit+1); r<=t+(limit+1); r++){
						if(board[u][r] == NULL) board[u][r] = " 1 ";
					}
				}
			};
			tmp = tmp->next;
		}
		printVacancy(type,board);
	}else if(type == 'C'){ //C 
		printVacancy(type,board);
	}else{
		printf("wrong movement\n");
		getInfo(type,first,board);
	}
}


void main(){
	char* board[BOARD_SIZE][BOARD_SIZE] = { NULL };
//	int* info[3][BOARD_SIZE*BOARD_SIZE] = { NULL };
	int x,y,count,years;
	char option,type;
	Details *move = NULL;
	Details *first = NULL;
	// 第0回合
	first = move = computerMove('A', board);
	
	move->next = computerMove('B', board);
	move = move->next;
	
	move->next = computerMove('C', board);
	move = move->next;
	// 第0回合結束 
	printBoard(board); //印棋盤 
	display(first); //顯示Details
	depreciating(first); //折舊 
	first = sorting(first); //刪掉歸零的  
	printf("--------------------------\n"); 
	
		
	printf("Please choose a place of your shop, Y or N\n");
	scanf(" %c", &option);
	
	if(option == 'Y'){
		while(option == 'Y'){  //印出可以下的空間
			printf("which type do you want to know? A, B or C\n");
			scanf(" %c", &type);
			if(type == 'A' | type == 'B' | type == 'C'){
				getInfo(type,first,board);
	//			printBoard(board);
				printf("============above are places still empty===========\n");
				printf("Do you want to know vacancies of other types? Y or N\n");
				scanf(" %c", &option);	
			}else{
				printf("wrong movement\n");
			}
		}
		
		move->next = playerMove(board);
		move = move->next;
		
		clearBoard(board);
		readDetails(first, board);
		printBoard(board);
		display(first);
		
		depreciating(first);
		first = sorting(first);
		printf("--------------------------\n");
		option = 'N';
	}
	if(option == 'N'){
		printf("How many years for forcasting future? (years < 20)\n");
		scanf("%d", &count);
		years = count;
		while(count > 0){
			printf("==============after %d years==============\n",(years-count+1));
			move->next = computerMove('N', board);
			move = move->next;
//			printf("==============before sorting=============\n");
			
			clearBoard(board);	
			readDetails(first, board);
			printBoard(board);	
			display(first);
			
			depreciating(first);
			first = sorting(first);	
//			printf("==============after sorting==============\n");	
//			display(first);

			if(count > 1){
				printf("Continue? Y or N\n");
				scanf(" %c", &option);	
			} 
			if(option != 'Y') break;
			count--;
		}
		printf("==============result==============\n");
		clearBoard(board);	
		readDetails(first, board);
		printBoard(board);	
		display(first);
		printf("--------------------------\n");
		
	}
};

