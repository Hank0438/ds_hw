#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct items {
    char type;
	int data;
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
void addQueue(QUEUE *q, int y, char t) {
    ITEM * x = (ITEM *) malloc(sizeof(ITEM));
    x->type = t;
	x->data = y;
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
    char rel = x->type;
    q->front = x->link;
    if (q->front == NULL)
        q->rear = NULL;
    q->size--;
    free(x);
    return rel;
}
void main() {
    QUEUE q;
    int i;
    char t;
    initQueue(&q);
    for (i = 1; i < 10; i++) {
    	if(i%2 == 1) t = 'A';
    	else t = 'B';
        addQueue(&q, i, t);
    }
    while (!queueIsEmpty(&q)) {
        printf("%c\n", deleteQueue(&q));
    }
}
