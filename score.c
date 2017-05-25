#include<stdio.h>
#include<stdlib.h>
//prototype || protótipos
int getScore(int *array);
void removeScore(int *array);
void addScore(int *array);
void printArray(int *array);
void startArray(int *array);
void printOptions();
void getOption(int *array,int option);
//End prototype || fim dos protótipos
void main(){
	int array[10];
	int option=99;
	startArray(array);
	while(option!=0){
		printf("!-----Scores-----!\n");
		printArray(array);
		printOptions();
		scanf("%d", &option);
		getOption(array,option);
		system("cls");
	}
}
//functions || funções
void getOption(int *array,int option){
	switch(option){
			case 0:printf("Exiting!");
							break;
			case 1:addScore(array);
							break;
			case 2:removeScore(array);
							break;
			case 3:startArray(array);
							break;
			default:printf("Invalid");
							break;
	}
}
int getScore(int *array){
	int position;
	printf("insert a position:");
	scanf("%d",&position);
	return array[position-1];
}
void removeScore(int *array){
	int position;
	printf("insert a position:");
	scanf("%d",&position);
	int i;
	for(i=position-1;(i<9);i++){
		array[i]=array[i+1];
	}
	array[9]=0;
}
void addScore(int *array){
	int value;
	printf("Insert Score:");
	scanf("%d",&value);
	int i;
	if(value<=array[9]){
			return;
	}
	for(i=9;(i>0)&&(value>array[i-1]);i--){
			array[i] = array[i-1];
	};
	array[i]=value;
}
void printArray(int *array){
	int i;
	for(i=0;i<10;i++){
			printf("|        %d\n",array[i] );
	}
	printf("!-----------------!\n\n\n");
}
void startArray(int *array){
	int i;
	for(i=0;i<10;i++){
		array[i]=0;
	}
}
void printOptions(){
    printf("Insert one option:\n");
        printf("1 - Insert score \n");
        printf("2 - Remove score\n");
        printf("3 - Clear scores \n");
        printf("0 - Exit \n");
}
