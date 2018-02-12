#include <stdio.h>
#include <string.h>

int main(void){
	char *string = "abod";
	char *pat = "daaboid";
	
	int i,j,start = 0;
	int lasts = strlen(string);//5
	int lastp = strlen(pat);//7
	//aboi
	//daaboid
	for(i=0; i<lastp; i++){
		int count = 0;
		int temp = i;
		for(j=0; j<lasts; j++){
			if(pat[temp] == string[j]){
				count++;
				temp++;
				if(count == lasts){
					start = 1;
					break;
				}
			}
		}
		if(count == lasts) break;
	}
	
	if(start == 1){
		printf("yes");
	}
	else{
		printf("no");
	}
}


