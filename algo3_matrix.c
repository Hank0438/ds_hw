#include <stdio.h>
#define N 100

typedef struct items {
	int a;
	int b;
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
void addQueue(QUEUE *q, int x, int y) {
    ITEM * newStuff = (ITEM *) malloc(sizeof(ITEM));
    newStuff->a = x;
    newStuff->b = y;
	newStuff->link = NULL;
    if (q->front == NULL)
        q->front = newStuff;
    else
        q->rear->link = newStuff;
    q->rear = newStuff;
    q->size++;
    
}
void deleteQueue(QUEUE *q) {
    ITEM * delStuff = q->front;
    int x = delStuff->a;
    int y = delStuff->b;
    q->front = delStuff->link;
    if (q->front == NULL)
        q->rear = NULL;
    q->size--;
//    free(delStuff);
    //printf("delete(%d,%d)",x,y);
}

int checkQueue(QUEUE *q, int x, int y){
	ITEM * stuff = q->front;
	int check=0;
	while(stuff != NULL){
		if(x==stuff->a && y==stuff->b){
			check=1;
			break;
		}
		stuff = stuff->link;
	}
//	free(stuff);
	return check;
}

void colorChange(QUEUE *q, int n, int m, int *arr[n][m], int count){
	int color = arr[n][m];
	addQueue(&q, n, m);
	count++;
//	printf("at(%d,%d),count %d",n,m,count);

	//鄰近的方塊同色 
	if(arr[n+1][m]==color && checkQueue(&q, n+1, m)==0){
		colorChange(&q, n+1, m, arr, count); 
	}
	else if(arr[n-1][m]==color && checkQueue(&q, n-1, m)==0){
		colorChange(&q, n-1, m, arr, count); 
	}
	else if(arr[n][m+1]==color && checkQueue(&q, n, m+1)==0){
		colorChange(&q, n, m+1, arr, count); 
	}
	else if(arr[n][m-1]==color && checkQueue(&q, n, m-1)==0){
		colorChange(&q, n, m-1, arr, count); 
	}
	
}

int main(){
	int n,m,i,j,a,b,c,d;
	int count;
	int countTmp;
	int countMax=0;
	
//確認
	scanf("%d %d",&n,&m);
	
	int arr[n][m];
	int tmp[n][m];
//輸入
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf("%d",&arr[i][j]);
		}
	}
//print array test	
//    for(a=0; a<n; a++){
//    	for(b=0; b<m; b++){
//    		printf("%d ",arr[a][b]);
//    		if(b == m-1) printf("\n");
//    	}
//	}
//    
//    printf("======================\n"); 
    
//每個矩陣點都是起始點    
    for(c=0; c<n; c++){
		for(d=0; d<m; d++){
			printf("%d..%d",c,d);
			count=0;
			QUEUE q;
			initQueue(&q);
			
			colorChange(&q, c, d, arr, count);
			
			

			if(count > countMax) countMax = count;
		}
	}
	printf("%d\n",countMax);
	 
	return 0;
}
