#include <stdio.h>
#define N 10000

int bubSort(int n, int m, int A[n][m]){
    int i,j,k,Temp,sp;
    for(k=0; k<n; k++){
		for (i=m-1; i>0; i--){
	        sp=1;
	        for (j=0; j<i; j++){
	            if (A[k][j] > A[k][j+1]){  //兩數交換位置
	               Temp = A[k][j];
	               A[k][j] = A[k][j+1];
	               A[k][j+1] = Temp;
	               sp=0;
	            }
	    	}
	        if (sp==1) break;          
	    }
	}
    return 0;
}

int calculate(int count, int arr[N], int length, int crr[N],int max){
	int a,b,c,i,j,master,slave;
	
	//Q: 1 2 vs 4 5 6 7 8 
	b=0;
	for(a=0; a<count; a+=2){
		master = arr[a];
		slave = arr[a+1];
		arr[a] = 0;
		arr[a+1] = 0;
		printf("m=%d, s=%d\n",master,slave);
		if(crr[0]==0 && crr[1]==0){//一開始第一第二複製過去 
			crr[0] = master;
			crr[1] = slave;
			length+=2;
		}else if(master == crr[length-1]){ // 4-1 + 1-2 = 4-1-2
			crr[length] = slave;
			length++;
		}else if(slave == crr[0]){ // 4-1 + 5-4 = 5-4-1
			for(c=length; c>0; c--){
				 crr[c] = crr[c-1];
			}
			crr[0] = master;
			length++;
		}else{//沒用到的放回arr 
			arr[b] = master;
			arr[b+1] = slave;
			b+=2;
		}
	}
	
	
	printf("======print=======\n");
	printf("arr\n");
	for(i=0; i<b; i++){
    	printf("%d ",arr[i]);
    }
    printf("\n");
	printf("crr\n");
	for(j=0; j<length; j++){
    	printf("%d ",crr[j]);
    }
    printf("\n");
    printf("==================\n");
    
	if(max < length) max = length;
	
	if(b == 0){
		return max;
	}else if(b == count){
		int brr[N] = {0,0};
		return calculate(b, arr, 0, brr, max); //把crr歸零 
		
	}else{
		return calculate(b, arr, length, crr, max); // 1 5 1 3 3 4 4 5	
	} 
}

int check(int n, int m, int A[n][m]){
	int i,j,k,a,b,c,d,pos=0,count=0,Max=0,master,slave;
	int arr[N],crr[N]={0,0};
	
	a=0;
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			k=0;
			//一開始確認pos後就不會變了 
			if(A[i][0] > A[j][0]){
				pos=0;
				k++;
			}else if(A[i][0] < A[j][0]){
				pos=1;
				k++;
			}else{
				k=m;
			}
			while(k<m){
				if(pos==0 && A[i][k] > A[j][k]){
					k++;
					if(k==m){
						printf("%d > %d\n",i+1,j+1);
						arr[a] = i+1;
						arr[a+1] = j+1;
						a+=2;
						count+=2;
					} 	
				}else if(pos==1 && A[i][k] < A[j][k]){
					k++;
					if(k==m){
						printf("%d > %d\n",j+1,i+1);
						arr[a] = j+1;
						arr[a+1] = i+1;
						a+=2;
						count+=2;
					}
				}else{
					break;
				}				
			}
		}
	}
	printf("======print=======\n");
	printf("arr\n");
	for(i=0; i<count; i++){
    	printf("%d ",arr[i]);
    }
    printf("\n");
    printf("======print=======\n");
	Max = calculate(count, arr, 0, crr, 0);
	
	return Max;	
}

int main(){
	int n,m,i,j,a,b,c,d;
	int count;
	int countTmp;
	int countMax=0;
	
//確認
	scanf("%d %d",&n,&m);
	
	int A[n][m];
//輸入
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf("%d",&A[i][j]);
		}
	}
	bubSort(n, m, A);	
	printf("%d",check(n, m, A));
	

	return 0;
	
	
}


