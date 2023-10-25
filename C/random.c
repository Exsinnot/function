#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,r;
	srand(243353279);
	for(i=0;i<46;i++){
		r = ((rand() / (float)RAND_MAX ) * 999999);
		printf("%d. %d\n",i+1,r);
	}
	
}