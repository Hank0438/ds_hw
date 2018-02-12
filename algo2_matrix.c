#include <stdio.h>
#define N 100

typedef struct items {
	int board;
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
void addQueue(QUEUE *q, int y) {
    ITEM * x = (ITEM *) malloc(sizeof(ITEM));
    x->board = y;
	x->link = NULL;
    if (q->front == NULL)
        q->front = x;
    else
        q->rear->link = x;
    q->rear = x;
    q->size++;
}
int deleteQueue(QUEUE *q) {
    ITEM * x = q->front;
    int b = x->board;
    q->front = x->link;
    if (q->front == NULL)
        q->rear = NULL;
    q->size--;
    free(x);
    return b;
}

int main(){
    int n;
    int end;
    int length;
    int jump;
    int i,k,j,t,a,b,c;
    
//確認幾根浮木 
	scanf("%d",&n);
	
	int arr[n][2];
//輸入每根浮木的座標 
	for(i=0; i<n; i++){
		scanf("%d",&arr[i][0]);
		scanf("%d",&arr[i][1]);
	}
	
////testing data
//	n = 8;
//	int arr[8][2] = {{1,4},{8,11},{5,7},{3,6},{9,13},{2,6},{5,9},{8,14}};

////print array test	
//    for(a=0; a<n; a++){
//    	printf("%d ",arr[a][0]);
//    	printf("%d\n",arr[a][1]);
//	}
//    
//    printf("======================\n"); 
    
    int matrix[N][N];

//製作matrix 
	j = 0;
	for(j=0; j<n; j++){
		end = arr[j][1];
		for(t=0; t<n; t++){ // 找跳的到，而且往終點 
			if(arr[t][0] < end && arr[t][1] > end){ //確定跳的到 
				matrix[j][t] = 1;
			}else{
				matrix[j][t] = 0;
			}
		}
	}
	
////印出matrix 
//	for(i=0; i<n; i++){
//		for(k=0; k<n; k++){
//    		printf("%d ",matrix[i][k]);
//    	}
//    	printf("\n");
//	}

//bfs traversal
	QUEUE q;
	initQueue(&q);
	int boolean[N]; //判斷有沒有被呼叫過 
    int level[N];
    int countLevel = 0;
    i = 0;
    boolean[0] = 1;
    level[0] = countLevel;
	while(i<n){
		if(level[i] == countLevel) countLevel++;
		for(k=0; k<n; k++){
//			printf("%d,%d\n",i,k);
			if(matrix[i][n-1] == 1){
				i = n-1;
//				printf("I found it\n");
				break;
			}
    		if(matrix[i][k] == 1 && boolean[k] != 1){
    			boolean[k] = 1;
    			level[k] = countLevel;
				addQueue(&q, k);
//				printf("addQ: %d\n",k);
			}
    	}
    	if(i == n-1) break;
    	if(queueIsEmpty(&q) == 1){ //error handler
//    		printf("not found\n");
    		break;
		}
    	i = deleteQueue(&q);
//    	printf("deleteQ: %d\n",i);
	}
//	printf("jump: %d\n",countLevel);
	printf("%d\n",countLevel);

    
    return 0;
}
