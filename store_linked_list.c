#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BOARD_SIZE 12
/* 定義結構型態 */  
typedef struct link_node{ 
	char type;
	int data;
	int x;
	int y;
	struct link_node *link;  
} LINK_NODE;  

/* 產生新節點 */  
LINK_NODE *new_node(int data, int x, int y, char type){  
   LINK_NODE *node;  
   node=(LINK_NODE *) malloc(sizeof(LINK_NODE));/*<stdlib.h>*/  
     
   // 記憶體不足  
   if(node == NULL){ return NULL;}  
     
   node->data=data;
   node->x=x;
   node->y=y;
   node->type=type;    
   node->link=NULL;       
   return node;  
}  
  
  
  
/* 排序插入新節點 */  
LINK_NODE *sort_insert(LINK_NODE *list, int data, int x, int y, char type){  
   // 加入第一筆資料  
   // 產生新節點  
   LINK_NODE *node=new_node(data, x, y, type);      
   if(list==NULL){ list=node; }    
  
   // 尋找大於資料(data)的位址  
   LINK_NODE *r=list,*q=list;      
   while(r!=NULL && r->data<data){ q=r; r=r->link; }  
  
   if(r==list){ // 首節點  
       node->link=list; list=node;   
   }else{ // 加入新節點於中間  
       node->link=q->link;   
       q->link=node;   
   } 
   return list;
}    
  
/* 印出所有串列的所有資料 */  
int display(LINK_NODE *list){  
   LINK_NODE *p=list;  
   while(p!=NULL){   
       printf("%d\n",p->data);/*<stdio.h>*/  
       p=p->link;    
   }  
   return 1;  
}  




void computerMove(int type, char* board[BOARD_SIZE][BOARD_SIZE]){
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
		for(u=s-2; u<s+3; u++){
			for(r=t-2; r<t+3; r++){
				if(board[u][r] == NULL) board[u][r] = " 1 ";
			}
		}	
	} 
	if(p == 2){
		board[s][t] = " B ";
		for(u=s-1; u<s+2; u++){
			for(r=t-1; r<t+2; r++){
				if(board[u][r] == NULL) board[u][r] = " 2 ";
			}
		}	
	} 
	if(p == 3){
		board[s][t] = " C ";
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
	char option;
	LINK_NODE *list = NULL;
	int s=7;
	int t=7;
	
	computerMove(1, board);
	list = sort_insert(list, s, t, 4, 'A');
	computerMove(2, board);
	list = sort_insert(list, s, t, 3, 'B');
	computerMove(3, board);
	list = sort_insert(list, s, t, 2, 'C');
	printBoard(board);
//	display(list);
	LINK_NODE *p = list;
	while(p!=NULL){   
       printf("%d\n",p->type);/*<stdio.h>*/  
       p=p->link;    
   }  
	printf("--------------------------\n"); 
	
	
}




  

