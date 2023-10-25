#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int TableCache[256];
float hit = 0,miss = 0;
int cacheblock[4][4];
int cachetag[4] = {999,999,999,999};

int ran(){
	int r;
	r = ((rand() / (float)RAND_MAX ) * 255);
	return r;
}

int displaytable(){
	int i;
	printf("      0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f  \n");
	printf("    __________________________________________________\n  0 |");
	for(i=0;i<256;i++){
		if(i%16 == 0 && i != 0){
			printf("|\n %2x |",i/16);
		}
		printf("%.2x ",TableCache[i]);
	}
	printf("|\n");
	printf("    |________________________________________________|\n");
	
}

int displaycache(){
	int i;
	printf("    ___________________________\n");
	printf("    | TAG |        DATA       |\n");
	printf("    |-----|-------------------|\n");
	for(i=0;i<4;i++){
		if(cachetag[i] == 999)
			printf("    |     |    |    |    |    |\n");
		else
			printf("    |  %.2x | %.2x | %.2x | %.2x | %.2x |\n",cachetag[i],cacheblock[i][0],cacheblock[i][1],cacheblock[i][2],cacheblock[i][3]);
	}
	printf("    |_____|____|____|____|____|");
}

int missaddhit(int num){
	int tag,line,an = 252,data,temp = 0;
	int i;
	data = num & an;
	tag = data/16;
	line = data%16;
	if(line < 4){
		line = 0;
	}
	else if(line < 8){
		line = 1;
	}
	else if(line < 12){
		line = 2;
	}
	else{
		line = 3;
	}
	for(i=0;i<4;i++){
		if(cachetag[i] == tag){
			hit++;
			temp = 1;
			return 0;
		}
	}
	if(temp != 1){
		miss++;
	}
	cachetag[line] = tag;
	int j = 0;
	for(i=data;i<data+4;i++){
		cacheblock[line][j++] = TableCache[i];
	}
	
}

int main(){
	srand(time(NULL));
	int i,num;
	for(i=0;i<256;i++){
		TableCache[i] = ran();
	}
	while(1){
		system("cls");
		displaytable();
		printf("\n");
		displaycache();	
		printf("\n\n");
		if(miss+hit == 0){
			printf("Hit  = 0    Hit ratio  = 0%% \n");
			printf("Miss = 0    Miss ratio = 0%% \n");
		}
		else{
			printf("Hit  = %.0f    Hit ratio  = %.0f%% \n",hit,(hit/(miss+hit))*100);
			printf("Miss = %.0f    Miss ratio = %.0f%% \n",miss,(miss/(miss+hit))*100);
		}
		printf("Enter Address : ");
		scanf("%x",&num);
		missaddhit(num);
	}
	
}
