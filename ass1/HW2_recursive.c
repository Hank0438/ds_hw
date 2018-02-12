#include <stdio.h>
int ackermann(int m, int n){
 if(m==0){
 	return n+1;
 };
 if(m>0){
 	if(n==0){
		ackermann(m-1,1);	 
	};
 	if(n>0){
		ackermann(m-1,ackermann(m,n-1));
	};
 };
};
void main()
{
 int x,y,i,j,s;
 printf("½Ð¿é¤Jm,n\n");
 scanf("%d,%d",&x ,&y);
 if(x>y){
 	s = x+1;
 }else{
 	s = y+1;
 }
 //for test
 for(i= 0; i< s; i++){
 	for(j= 0; j< s; j++){
 		printf("value(%d,%d) : %d\n",i,j,ackermann(i,j));
 	}
 }
// printf("%d\n",ackermann(x,y));
}
