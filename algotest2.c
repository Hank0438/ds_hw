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
#include <string.h>
#define N 100000


int main(){
//    int seq[N] = {-1,3,-2,-3,3,2,-3,2};
	int seq[N];
    int sum;
    int max = -100;
    int i,j,k,t,a,b,idx;
	int skip;
	
    char buf[100];
	if (gets(buf) ){
  		i = 0;
  		a = 0;
  		while(buf[i] != 0){
  			idx = buf[i] - 0;
  			printf("%d\n", &idx);
  			if(idx == 32){
  				a++;	
  				printf("aaa\n");
			}else if(idx == 45){
				seq[a] = -(idx - 48);
				printf("bbb\n");
			}else seq[a] = idx - 48;
//  			printf("i_c:%c\n", buf[i]);
//  			printf("i_d:%d\n", buf[i]);	
			i++;
		}
//  		int n;
//  		int i=0;
//  		while (sscanf(p, "%d %n", &seq[i], &n)) {
//    		printf("%d ", seq[i]); // do something with array[i]
//    		printf("%d + %d\n",p, n);
//    		i++;  // Increment after success @BLUEPIXY
//    		p += n;
//   		}
	}
//	for(b=0; b<=a; b++) printf("%d\n", &seq[b]);
	
    for(k=0; k<8; k++){ // 從第幾個開始
    	if(seq[k] < 0) continue;
    	for(j=0; j<8; j++){ // 取幾個
			if( (seq[k+j] < 0 && (k+j) < 8 ) || (seq[k+j-8] < 0 && (k+j) >= 8) ) continue;
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
