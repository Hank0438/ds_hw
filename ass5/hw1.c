#include <stdio.h>
#include <stdlib.h>


int main(void){//�]�w�narray�ƥX���b�A�o��ĤG�p���ƭ� 
	int i, a[9]= {14, 2, 7, 3, 8, 9, 5, 6, 9};
	quick_sort(&a, 0, 8);
	for(i = 0; i < 9; i++){
		printf("The second smallest element is /n ", a[1]);
	}
}

int partition(int a[], int left, int right){
	int i=left+1, j=right, tmp, pivot;
	pivot = a[left];
	while(i<=j){
		while(i<=j&&a[i]<=pivot){
			i++;
		}
		while(i<=j&&a[j]>pivot){
			j--;
		}
		if(i<j){
			swap(a[i],a[j]);
		}
	}
	swap(a[left],a[j]);
	return j;
}
void quick_sort(int a[], int left, int right){
	int mid;
	if(left<right){
		mid=partition(&a, left, right);
		quick_sort(&a, left, mid-1); //��quicksort�u�����b�A���αƧ����� 
	}
}

void swap(int* x, int* y){
	int tmp;
	tmp=x;
	x=y;
	y=tmp;
}


