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
	
    for(k=0; k<8; k++){ // �q�ĴX�Ӷ}�l
    	if(seq[k] < 0) continue;
    	for(j=0; j<8; j++){ // ���X��
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
