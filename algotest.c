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
    int seq[8];
    int sum[8][8] = {0};
    int max = -100;
    int i,j,k,t,a,b;
    //�x�s�ƦC 
    for(i=0; i<8; i++){
        scanf("%d", &seq[i]);
//        sum[0][i] = seq[i];
	}
    for(j=0; j<8; j++){
    	for(k=0; k<8; k++){
    		for(t=0; t<j+1; t++){
    			if(t+k < 8){
    				sum[j][k] += seq[t+k];	
				}else{
					sum[j][k] += seq[t+k-8];
				}
			}
			if(max < sum[j][k]){
				max = sum[j][k];
			} 
		}
	}
    for(a=0; a<8; a++){
		for(b=0; b<8; b++){
			printf("(%d,%d) = %d ", a, b, sum[a][b]);
			if(b == 7)  printf("\n");
		}
	}
	printf("%d", max);
    return 0;
}
