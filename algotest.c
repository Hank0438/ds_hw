/*
輸入說明 ：
輸入為一行由N個整數組成的序列，1<=N<=100000。
序列中每個整數M代表磚柱的高度及顏色, -100 <= M <=100。M>=0代表紅色磚柱，M<0代表藍色磚柱。
輸出說明 ：
輸出為一正整數P，P>=0，代表最大的總能量。
範例輸入 ：
-1 3 -2 -3 3 2 -3 2
範例輸出 ：
6
*/

#include <stdio.h>
#define N 100000


int main(){
    int seq[8];
    int sum[8][8] = {0};
    int max = -100;
    int i,j,k,t,a,b;
    //儲存數列 
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
