#include <stdio.h>


int main(){
    int n;
    int count;
    int can;
    int end;
    int length, lenMax = 0;
    int i,j,k,t,a,b;
    
////    //�T�{�X�گB�� 
//	scanf("%d",&n);
//	
//	int arr[n][2];
//	//��J�C�گB�쪺�y�� 
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
    
    //�Y���@�_���A�p�G����P�@�ګh����
	count = 0; 
	j = 0;
	while(j < n){
		end = arr[j][1];
		for(t=1; t<n; t++){ // �������A�ӥB�̪����B�O 
			length = arr[t][1] - arr[t][0];
			if(arr[t][0] < end && length > lenMax){
				lenMax = length;
				j = t;
				printf("j is %d\n",j);
			}
		}
//		printf("j = %d\n",j);
//		j = can; // ����U�@�ӯB�O
		count++;	
		if(j == n-1) break;
	}
    
	
	//��X���X�� 
    printf("%d",count);
    return 0;
}
