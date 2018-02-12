#include <stdio.h> 
#include <stdlib.h> 
#include<time.h> 

int main() { 
	int i=0,j,tmp,a[80]; 
	srand(time(0));//每次都出現隨機 
	while(i<80) {
		tmp=rand()%100 ;//範圍0~99並且放進a陣列 
		for(j=0;j<i;j++)//檢查值是否已經存在 
			if(a[j]==tmp) 
				break; 
			if(j != i)// 表示直已經存在 從新取值 
				continue; 
			a[i++]=tmp; 
	}; 
	for(i=79;i>0;i--)//泡沫排序 
		for(j=0;j<i;j++) 
			if(a[j] > a[j+1]) { 
				tmp=a[j]; 
				a[j]=a[j+1]; 
				a[j+1]=tmp; 
			}; 
	i=0; 
	while(i<80){ 
		printf("%d",a[i++]); 
		if(i<80) 
			printf(","); 
		else 
			printf("\n"); 
	} 
	system("PAUSE"); 
	return 0;
}
