#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct SubTerra{
	
	char nome[10];
	float densidade;
	float visao;
} SubTerra;

void insertionSort(SubTerra *subterra, int n);
void preencheStruct(SubTerra *subterra);
char* zerar(char *string);

int main(int argc, char** argv) {
	
	SubTerra subterra[10];
	
	preencheStruct(subterra);
	insertionSort(subterra, 10);
	
	for(int i = 0; i < 10; i++){
		
		printf("%s\n",subterra[i].nome);
		printf("%.2f\n",subterra[i].densidade);
		printf("%.2f\n\n",subterra[i].visao);
	}
	return 0;
}

void insertionSort(SubTerra *subterra, int n){
	
	char *aux = (char*)malloc(10*sizeof(char));
	
	float densidade;
	float visao;
	float auxD;
	float auxV;
	
	int k, j;
	
	for(int i = 1; i < n; i++){
	
		zerar(aux);
		strcat(aux, subterra[i].nome);		
		densidade = subterra[i].densidade;
		visao = subterra[i].visao;
		
		k = 0;
		j = i-1;
		
		while((j >= 0) && (k == 0)){
			
			if(strcmp(aux,subterra[j].nome) < 0){
				
				zerar(subterra[j+1].nome);
				strcat(subterra[j+1].nome, subterra[j].nome);
				
				auxD = subterra[j+1].densidade;
				subterra[j+1].densidade = subterra[j].densidade;
				subterra[j].densidade = auxD;
				
				auxV = subterra[j+1].visao;
				subterra[j+1].visao = subterra[j].visao;
				subterra[j].visao = auxV;
				
				j = j-1;
				
			}else if(strcmp(aux,subterra[j].nome) == 0){
				
				if(densidade < subterra[j].densidade){
					
					subterra[j+1].densidade = subterra[j].densidade;	
					
					zerar(subterra[j+1].nome);
					strcat(subterra[j+1].nome, subterra[j].nome);
				
					auxV = subterra[j+1].visao;
					subterra[j+1].visao = subterra[j].visao;
					subterra[j].visao = auxV;
					
					j = j-1;
				
				}else if(densidade == subterra[j].densidade){
					
					if (visao < subterra[j].visao){
						
						subterra[j+1].visao = subterra[j].visao;
							
						zerar(subterra[j+1].nome);
						strcat(subterra[j+1].nome, subterra[j].nome);	
				
						auxD = subterra[j+1].densidade;	
						subterra[j+1].densidade = subterra[j].densidade;
						subterra[j].densidade = auxD;
						
						j = j-1;
						
					}else{
						k = j+1;
					}
				} else{
					k = j+1;
				}
			}else{
				k = j+1;
			}
		}
		zerar(subterra[k].nome);
		strcat(subterra[k].nome,aux);	
		subterra[k].densidade = densidade;
		subterra[k].visao = visao;
	}
}

void preencheStruct(SubTerra *subterra){
	
	float vetDensidade[10] = {1.8, 2.4, 1.3, 8.9, 2.1, 3.4, 8.1, 6.5, 0.8, 5.9};
	float vetVisao[10] = {5.7, 4.7, 3.7, 5.8, 9.8, 6.3, 4.1, 2.8, 3.8, 1.9};
	
	for(int i = 0; i < 10; i++){
		
		subterra[i].densidade = vetDensidade[i];
		subterra[i].visao = vetVisao[i];
	}
	
	zerar(subterra[0].nome);
	zerar(subterra[1].nome);
	zerar(subterra[2].nome);
	zerar(subterra[3].nome);
	zerar(subterra[4].nome);
	zerar(subterra[5].nome);
	zerar(subterra[6].nome);
	zerar(subterra[7].nome);
	zerar(subterra[8].nome);
	zerar(subterra[9].nome);
	
	
	strcat(subterra[0].nome, "ana");
	strcat(subterra[1].nome, "carla");
	strcat(subterra[2].nome, "luiza");
	strcat(subterra[3].nome, "maria");
	strcat(subterra[4].nome, "jordana");
	strcat(subterra[5].nome, "raquel");
	strcat(subterra[6].nome, "elieni");
	strcat(subterra[7].nome, "samara");
	strcat(subterra[8].nome, "valeria");
	strcat(subterra[9].nome, "silvana");
}	

char* zerar(char *string){
	
	string[0] = '\0';
}




























