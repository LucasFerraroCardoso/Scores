#include<Stdio.h>
//prototype || protótipos
int pushScore();
void popScore();
void insertScore();
void printArray(int *array);
void startArray(int *array);
//End prototype || fim dos protótipos

void main(){
	int array[10];
	startArray(array);
	printArray(array);
}

//functions || funções


int pushScore(int *array,int position){
	return array[position-1];
}
void popScore(int *array, int position){
	int i=position-1;
	for(;(i<9);i++){
		array[i]=array[i+1];
	}
	array[9]=NULL;
}
void insertScore(int *array, int value){
	int i,aux;
	if(value>array[9]){
		array[9] = value;
		for(i=9;i>0;i--){
			if(array[i]>array[i-1]){
				aux = array[i];
				array[i] = array[i-1];
				array[i-1] = aux;
			}
		}
		printf("Sucess\n");
	}else{
		printf("Low score\n");
		return;	
	}
}
void printArray(int *array){
	int i;
	for(i=0;i<10;i++){		
		printf("Score %d: %d\n",i+1,array[i]);
	}
}
void startArray(int *array){
	int i;
	for(i=0;i<10;i++){
		array[i]=NULL;
	}
	printf("Array Start\n");
}
