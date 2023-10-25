#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int ran(int max,int min){
	int r;
		r = ((rand() / (float)RAND_MAX ) * max)+min;
	return r;
}

void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

struct student{
    float score;
    char name[60],id[30];
    struct student *next;
};

struct student *letgo = NULL;
struct student *createlist(struct student *);
struct student *display(struct student *);
struct student *delete_data(struct student *);
struct student *edit_data(struct student *);
struct student *load_data(struct student *);
struct student *save_data(struct student *);
struct student *export_data(struct student *);
struct student *loadall_data(struct student *);
struct student *saveall_data(struct student *);
struct student *random_data(struct student *);


struct student *random_data(struct student *letgo){
	struct student *newdata, *p;
	int i,lop,idint,len,l;
	char id[30],name[60];
	float score;
	srand(time(NULL));
	printf("Enter count create ID : ");
	scanf("%d",&lop);
	for(i=0;i<lop;i++){
		idint = ran(999999999,1);
		sprintf(id,"%.13d",idint);
		len = ran(20,1);
		for(l=0;l<len;l++){
			name[l] = 'a'+ran(23,1);
		}
		score = ran(99,1);
		newdata = (struct student *)malloc(sizeof(struct student));
    	newdata->score = score;
    	strcpy(newdata->id,id);
    	strcpy(newdata->name,name);
    	if(letgo == NULL){
    		letgo = newdata;
    		letgo->next = NULL;
		}
		else{
			p = letgo;
			while(1){
				if(p->next == NULL){
					p->next = newdata;
					newdata->next = NULL;
					break; 
				}
				else{
					p = p->next;
				}
			}

		}
		for(l=0;l<20;l++){
			name[l] = '\0';
		}
	}
	return letgo;
}

struct student *loadall_data(struct student *letgo){
	struct student *newdata, *p;
	char rowcha[10],namefile[20] = "Data_",files[10] = ".FILEGUU";
	char text[10000],dataa[10000][100];
	int h,len,v,f,row = 0,i = 0,erro = 0;
	float tmp;
	letgo = NULL;
	dataa[0][0] = '\0';
	p = letgo;
	FILE *file;
	while(1){
		h = 1;
		for(f=5;f<20;f++){
			namefile[f] = '\0';
		}
		sprintf(rowcha,"%d",row);
		strcat(namefile,rowcha);
		strcat(namefile,files);
		file = fopen(namefile,"r");
		for(v=0;v<10000;v++){
			if(!feof(file)){
				fgets(text,100,file);
				len = strlen(text);
				text[len-1] = '\0';
				strcpy(dataa[v],text); 
			}
			else{
				strcpy(dataa[v-1],"");
				break;
			}
		}
		fclose(file);
		for(i=0;i<v/3;i++){
		if(strcmp(dataa[0],"FILEGUU") != 0){
			erro = 1;
			break;
		}
    	newdata = (struct student *)malloc(sizeof(struct student));
    	strcpy(newdata->id,dataa[h]);
    	h++;
    	strcpy(newdata->name,dataa[h]);
    	h++;
    	tmp = atof(dataa[h]);
		newdata->score = tmp;
		h++;
    	if(letgo == NULL){
    		letgo = newdata;
    		letgo->next = NULL;
		}
		else{
			p = letgo;
			while(1){
				if(p->next == NULL){
					p->next = newdata;
					newdata->next = NULL;
					break; 
				}
				else{
					p = p->next;
				}
			}
		}
	}
	if(h==1){
		return letgo;
		break;
	}
	row++;
	}
	return letgo;
}

struct student *saveall_data(struct student *letgo){
	struct student *p;
	char rowcha[10],namefile[20] = "Data_",files[10] = ".FILEGUU";
	int f,row = 0,oversave = 0,i = 0;
	p = letgo;
	FILE *file;
	while(1){
		for(f=5;f<20;f++){
			namefile[f] = '\0';
		}
	sprintf(rowcha,"%d",row);
	strcat(namefile,rowcha);
	strcat(namefile,files);
	file = fopen(namefile,"w");
	fprintf(file,"FILEGUU\n");
	i = 0;
	while(i == 0){
	while(p != NULL && oversave < 3000){
		fprintf(file,"%s\n%s\n%f\n",p->id,p->name,p->score);
		p = p->next;
		oversave++;
		if(oversave == 3000){
			oversave = 0;
			row++;
			i = 1;
			fclose(file);
			break;
		}
	}
	if(p == NULL){
		fclose(file);
		return letgo;
		break;
	}
}
}
}


struct student *export_data(struct student *letgo){
	struct student *newdata, *p;
	char namefile[20],files[10] = ".FILEGUU";
	int h = 1;
	float tmp;
	int v,i,len;
	char dataa[10000][100];
	dataa[0][0] = '\0';
	FILE *fl;
	char text[10000];
	printf("\nEnter NameFile : ");
	scanf("%s",namefile);
	strcat(namefile,files);
	fl = fopen(namefile,"r");
	for(v=0;v<10000;v++){
		if(!feof(fl)){
			fgets(text,100,fl);
			len = strlen(text);
			text[len-1] = '\0';
			strcpy(dataa[v],text);
		}
		else{
			strcpy(dataa[v-1],"");
			break;
		}
	}
	for(i=0;i<v/3;i++){
		if(strcmp(dataa[0],"FILEGUU") != 0){
			break;
		}
    	newdata = (struct student *)malloc(sizeof(struct student));
    	strcpy(newdata->id,dataa[h]);
    	h++;
    	strcpy(newdata->name,dataa[h]);
    	h++;
    	tmp = atof(dataa[h]);
		newdata->score = tmp;
		h++;
    	if(letgo == NULL){
    		letgo = newdata;
    		letgo->next = NULL;
		}
		else{
			p = letgo;
			while(1){
				if(p->next == NULL){
					p->next = newdata;
					newdata->next = NULL;
					break; 
				}
				else{
					p = p->next;
				}
			}
		}
	}
	fclose(fl);
	return letgo;
}

struct student *load_data(struct student *letgo){
	struct student *newdata, *p;
	char namefile[20],files[10] = ".FILEGUU";
	int h = 1;
	float tmp;
	letgo = NULL;
	int v,i,len;
	char dataa[10000][100];
	dataa[0][0] = '\0';
	FILE *fl;
	char text[10000];
	printf("\nEnter NameFile : ");
	scanf("%s",namefile);
	strcat(namefile,files);
	fl = fopen(namefile,"r");
	for(v=0;v<10000;v++){
		if(!feof(fl)){
			fgets(text,100,fl);
			len = strlen(text);
			text[len-1] = '\0';
			strcpy(dataa[v],text);
		}
		else{
			strcpy(dataa[v-1],"");
			break;
		}
	}
	for(i=0;i<v/3;i++){
		if(strcmp(dataa[0],"FILEGUU") != 0){
			break;
		}
    	newdata = (struct student *)malloc(sizeof(struct student));
    	strcpy(newdata->id,dataa[h]);
    	h++;
    	strcpy(newdata->name,dataa[h]);
    	h++;
    	tmp = atof(dataa[h]);
		newdata->score = tmp;
		h++;
    	if(letgo == NULL){
    		letgo = newdata;
    		letgo->next = NULL;
		}
		else{
			p = letgo;
			while(1){
				if(p->next == NULL){
					p->next = newdata;
					newdata->next = NULL;
					break; 
				}
				else{
					p = p->next;
				}
			}
		}
	}	
	fclose(fl);
	return letgo;
}

struct student *save_data(struct student *letgo){
	struct student *p;
	char namefile[20],files[10] = ".FILEGUU";
	int i;
	FILE *file;
	printf("\nEnter NameFile : ");
	scanf("%s",namefile);
	strcat(namefile,files);
	file = fopen(namefile,"w");
	fprintf(file,"FILEGUU\n");
	p = letgo;
	while(p != NULL){
		fprintf(file,"%s\n",p->id);
		fprintf(file,"%s\n",p->name);
		fprintf(file,"%f\n",p->score);
		p = p->next;
	}
	fclose(file);
	return letgo;
}

struct student *edit_data(struct student *letgo){
    struct student *p, *tmp;
    char rename[50],reid[16];
    char search[16];
    float rescore;
    printf("\nEnter Student ID to Edit Data : ");
    scanf("%s", search);
    printf("\n Edit ID to ;");
    scanf("%s", reid);
    printf("\n Edit Name to ;");
    scanf("%s", rename);
    printf("\n Edit Score to :");
    scanf("%f",&rescore);
    
    p = letgo;
    {
        while (strcmp(p->id,search)!=0)
        {
            tmp = p;
            p = p->next;
        }
    }
    p->score = rescore;
    strcpy(p->name,rename);
    strcpy(p->id,reid);
    return letgo;
}

struct student *delete_data(struct student *letgo){
	struct student *p;
	struct student *tmp;
	char search[16];
	printf("Enter Student ID to Deleta Data : ");
	scanf("%s",search);
	p = letgo;
	while(strcmpi(search,p->id) != 0){
		tmp = p;
		p = p->next;
	}
	if(p==letgo){
        letgo=letgo->next;
    }
    if(strcmpi(p->id,search)==0){
        tmp->next = p->next;
    }
    if(p->next==NULL){
    	tmp->next = NULL;
	}
	return letgo;
}

struct student *display(struct student *letgo){
	system("cls");
	struct student *p;
	int i,len;
	p = letgo;
	printf("\n");
		SetColor(15);
		printf("|------------------|-------------------------------|------------------------|\n");
		printf("|        ID        |               NAME            |         SCORE          |\n");
		printf("|------------------|-------------------------------|------------------------|\n");
	while(p != NULL){
		printf("|");
		len = strlen(p->id);
		SetColor(12);
		printf("%s",p->id);
		SetColor(15);
		for(i=0;i<18-len;i++){
			printf(" ");
		}
		printf("|");
		len = strlen(p->name);
		SetColor(1);
		printf("%s",p->name);
		SetColor(15);
		for(i=0;i<31-len;i++){
			printf(" ");
		}
		printf("|");
		char show[10];
		sprintf(show,"%.2f",p->score);
		len = strlen(show);
		SetColor(10);
		printf("%s",show);
		SetColor(15);
		for(i=0;i<23-len;i++){
			printf(" ");
		}
		SetColor(15);
		printf(" |\n");
		p = p->next;
	}
	printf("|------------------|-------------------------------|------------------------|\n");
	getch();
	return letgo;
}

struct student *createlist(struct student *letgo){
	struct student *newdata, *p;
	float score;
    char id[16];
    char name[50];
    while(1){
    	printf("\nEnter your ID : ");
    	scanf("%s",id);
    	printf("\nEnter your Name : ");
    	scanf("%s",name);
    	printf("\nEnter your Score : ");
    	scanf("%f",&score);
    	newdata = (struct student *)malloc(sizeof(struct student));
    	newdata->score = score;
    	strcpy(newdata->id,id);
    	strcpy(newdata->name,name);
    	if(letgo == NULL){
    		letgo = newdata;
    		letgo->next = NULL;
		}
		else{
			p = letgo;
			while(1){
				if(p->next == NULL){
					p->next = newdata;
					newdata->next = NULL;
					break; 
				}
				else{
					p = p->next;
				}
			}

		}
		char y;
		while(1){
			printf("\nEnter more data? (y/n) : ");
    		scanf(" %c",&y);
    		if(y == 'y' || y == 'Y'){
    			y = '\0';
    			break;
			}
			else if(y == 'n' || y == 'N'){
				y = 'n';
				break;
			}
			else{
				printf("\nError Agian !!!");
			}
		}
		if(y == 'n'){
			y = '\0';
			break;
		}
	}
	return letgo;
    
}

int main(){
	int choic;
	while(1){
		system("cls");
    	printf("\n 1 : Create a list");
    	printf("\n 2 : Display the list");
		printf("\n 3 : Delete data with student ID");
		printf("\n 4 : Edit data with student ID");
		printf("\n 5 : Load data");
		printf("\n 6 : Save data");
		printf("\n 7 : Export data");
		printf("\n 8 : Random data");
		printf("\n 9 : Saveall data");
		printf("\n10 : Loadall data");
    	printf("\n 0 : EXIT");
    	printf("\n\n Enter your choic: ");
    	scanf("%d", &choic);
    	if(choic == 1){
    		letgo = createlist(letgo);
		}
		else if(choic == 2){
			letgo = display(letgo);
		}
		else if(choic == 3){
			letgo = delete_data(letgo);
		}
		else if(choic == 4){
			letgo = edit_data(letgo);
		}
		else if(choic == 5){
			letgo = load_data(letgo);
		}
		else if(choic == 6){
			letgo = save_data(letgo);
		}
		else if(choic == 7){
			letgo = export_data(letgo);
		}
		else if(choic == 8){
			letgo = random_data(letgo);
		}
		else if(choic == 9){
			letgo = saveall_data(letgo);
		}
		else if(choic == 10){
			letgo = loadall_data(letgo);
		}
		else if(choic == 0){
			break;
		}
		else{
			main();
		}
	}
}
