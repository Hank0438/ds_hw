#include <stdio.h> 
#include <stdlib.h> 
#include<time.h> 

int main() { 
	int i=0,j,tmp,a[80]; 
	srand(time(0));//�C�����X�{�H�� 
	while(i<80) {
		tmp=rand()%100 ;//�d��0~99�åB��ia�}�C 
		for(j=0;j<i;j++)//�ˬd�ȬO�_�w�g�s�b 
			if(a[j]==tmp) 
				break; 
			if(j != i)// ��ܪ��w�g�s�b �q�s���� 
				continue; 
			a[i++]=tmp; 
	}; 
	for(i=79;i>0;i--)//�w�j�Ƨ� 
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
