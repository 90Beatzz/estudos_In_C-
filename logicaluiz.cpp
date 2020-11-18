#include <stdio.h>
#include <stdlib.h>




int main(void){
//Cada fileira sera preenchida com o CPF
char* fileiras[4][5];
float ingresso[4] = { 50.00, 60.00, 70.00, 80.00 };
int estudante = 0;
int resp = 0;


struct Venda{
    char nome[30];
    char cpf[14];
    int est = 0;
    char telefone[14];    
};

do{
	
	printf("digite 1 Para realizar uma venda \n");
	/*
    printf("digite 1 Para realizar uma venda \n");
    Printf("digite 2 Para verificar CPF \n");
    Printf("digite 3 Para cancelar uma venda \n");
    Printf("digite 4 Para trocar cadeira \n ");
    Printf("digite 5 Para mostrar cadeiras disponiveis \n");
    Printf("digite 6 Para mostrar total de venda \n");
    Printf("digite 7 Para mostrar vendas  para estudantes e nao estudante \n");
    */
        
} while(resp == 0);


}




