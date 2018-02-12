#include <stdio.h>
#define N 100

void Enqueue(int *queue, int item){
	rear = (rear+1)%n;
	if(rear==front){
		rear = (rear-1)%n;
		printf("Full\n");	
	} 
	else{
		Q[rear] = item;
	}
}

int Dequeue(int *queue){
	if(front==rear) printf("Empty\n");
	else{
		front = (front+1)%n;
		item = Q[front];
		return item;
	}
}

int isFull(int *queue){
	
}

int isEmpty(int *queue){
	
}

void main(){
	int queue[N];//0 ~ (N-1)
	int front = 0;
	int rear = 0;
}  
