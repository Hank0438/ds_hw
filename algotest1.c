/*
��J���� �G
��J���@���N�Ӿ�Ʋզ����ǦC�A1<=N<=100000�C
�ǦC���C�Ӿ��M�N��j�W�����פ��C��, -100 <= M <=100�CM>=0�N�����j�W�AM<0�N���Ŧ�j�W�C
��X���� �G
��X���@�����P�AP>=0�A�N��̤j���`��q�C
�d�ҿ�J �G
-1 3 -2 -3 3 2 -3 2
�d�ҿ�X �G
6
*/

#include <stdio.h>
#define N 100000


int main(){
    int seq[N];
    int sum;
    int max = -100;
    int i,j,k,t,a,b;
    
    
    //�x�s�ƦC 
//    char buf[100];
//	if (gets(buf) ){
//  		char *p = buf;
//  		int n;
//  		int i=0;
//  		while (sscanf(p, "%d %n", &seq[i], &n) == 1) {
//    		printf("%d ", seq[i]); // do something with array[i]
//    		printf("%d + %d\n",p,n);
//    		i++;  // Increment after success @BLUEPIXY
//    		p += n;
//   		}
////  		if (*p != '\0') HandleLeftOverNonNumericInput();
//	}
   
//	char buf[100];
//	gets(buf);
//	puts(buf);
//	int len;
//	len = strlen(buf);
//	printf("len : %d", len);
//	i = 0;
//	while(sscanf(buf, "%d", &seq[i]) == 1){
//		printf("%d\n", seq[i]);
//		i++;
//	} 
	
	for(i=0; i<8; i++){
		scanf("%d",&seq[i]);
	}
    
    
	
    for(j=0; j<8; j++){
    	for(k=0; k<8; k++){
    		sum = 0;
    		for(t=0; t<j+1; t++){
    			if(t+k < 8){
    				sum += seq[t+k];	
				}else{
					sum += seq[t+k-8];
				}
			}
			if(max < sum){
				max = sum;
			} 
		}
	}
	printf("max : %d", max);
    return 0;
}
