#include <stdio.h>


int main(){
    int n;
    int count;
    int can;
    int end;
    int length, lenMax = 0;
    int i,j,k,t,a,b;
    
////    //確認幾根浮木 
//	scanf("%d",&n);
//	
//	int arr[n][2];
//	//輸入每根浮木的座標 
//	for(i=0; i<n; i++){
//		scanf("%d",&arr[i][0]);
//		scanf("%d",&arr[i][1]);
//	}
	
//testing data
	n = 8;
	int arr[8][2] = {{1,4},{8,11},{5,7},{3,6},{9,13},{2,6},{5,9},{8,14}};

//print array test	
    for(a=0; a<n; a++){
    	printf("%d ",arr[a][0]);
    	printf("%d\n",arr[a][1]);
	}
    
    printf("======================\n"); 
    
    //頭尾一起跳，如果跳到同一根則結束
	count = 0; 
	j = 0;
	while(j < n){
		end = arr[j][1];
		for(t=1; t<n; t++){ // 找跳的到，而且最長的浮板 
			length = arr[t][1] - arr[t][0];
			if(arr[t][0] < end && length > lenMax){
				lenMax = length;
				j = t;
				printf("j is %d\n",j);
			}
		}
//		printf("j = %d\n",j);
//		j = can; // 跳到下一個浮板
		count++;	
		if(j == n-1) break;
	}
    
	
	//輸出跳幾次 
    printf("%d",count);
    return 0;
}
