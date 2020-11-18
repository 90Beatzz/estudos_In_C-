#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 30

//[3x] Iago A. do Nascimento
//IFBA 2020

int main (void){
	char temp;
    int n_linhas;
    int verific_count;    
    int count_n = 0;
    int count_k = 0;
    int i;
    char *frase;
    char verificador[MAX];
    int new_line = 0;
    int contador_letras = 0;
    
    //Inicializa Vetor
    for(i = 0; i != MAX; ++i){
    	frase[i] = 0;            
    	verificador[i] = 0;      
    }

    printf("Digite o numero de linhas \n");
    scanf("%d",&n_linhas);

    do{
    	setbuf(stdin,NULL);
        printf("Digite o texto da linhas: %d \n",count_n);
        scanf("%[^\n]s",&frase[new_line]);               
        
        //Varre vetor
        for(i = 0; i != MAX; ++i){
            if(frase[i] == 0){            	
                  new_line = i;              
                  break;				
			}              				
        }
		count_n++;  
    }while(count_n != n_linhas);    
    
    setbuf(stdin,NULL);   
    printf("Digite as letras a ser contadas \n");
    scanf("%s",&verificador);   
        
    //Encontra letras
    for(i = 0; i != MAX; ++i){
    	count_k = 0;
    	while(count_k != MAX){
	    	if(frase[count_k] == verificador[i]){
	    		contador_letras++;
			}
    		count_k++;
		}
		if(verificador[i]!=0){
			printf("%c = %d \n",verificador[i],contador_letras);
		}			   	    	
    	contador_letras=0;
    }
}

//Rise Ab ...
