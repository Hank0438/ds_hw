#include <stdio.h>
#include <math.h>

int ackermann(int m, int n){
 int i,j,s;
 int arr[m+1][n+1];
 if(m>n){
 	s = pow(m,3);
 }else{
 	s = pow(n,3);
 }
 for(i= 0; i< s+1; i++){
 	for(j= 0; j< s+1; j++){
 		int value = 0;
		if(i==0){
			value = j+1;
		}
		if(i>0){
			if(j==0){
				value = arr[i-1][1];
			}
			if(j>0){
				int k = arr[i][j-1];
				if(k<=s){
					value = arr[i-1][k];
				}
				//�p�Gk�ȫܤj�A�W�L�ƥ��⪺�ȡA����n��s�� 
			}
		}
		printf("value(%d,%d) : %d\n",i,j,value);
		arr[i][j] = value;
	}
 }
 return arr[m][n];
};

void main()
{
 int x,y;
 printf("�п�Jm,n\n");
 scanf("%d,%d",&x ,&y);
 printf("%d\n",ackermann(x,y));
}
