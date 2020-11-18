#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

//[3 x] Iago A. do Nascimento 
//IFBA 2020


int main(void){
	int n_days;
	int fruit_multip[5];
	float v_price[5];
	char fruit[255];
	float kg_total;
	float price_total;
	char temp;

	//Tools
	int count;
	int count2;
	int count3 = 0;
	int i;
	int cont;
	int this_mult = 0;

	//Results
	float kg_p_day;
	float price_p_day;	
	
	printf("\n Informe os Dias \n");
	scanf("%d",&n_days);

	do{	
		printf("\n Informe o Preco: %d \n",count);
		scanf("%f",&v_price[count]);

		printf("\n Informe as Frutas: %d \n",count);
		scanf("%s",&temp);
    	scanf("%[^\n]",&fruit);			
		
		//Conta quantas frutas são
		for(cont = 0; cont <= 255; cont++){			
			if(fruit[cont] == 32){						
				//printf("%c",fruit[cont]);
				this_mult++;				
			}
  		}		 				
  		this_mult--;  		
  		fruit_multip[count] = this_mult;  		
  		
		count++;
		this_mult = 0;
		fruit_multip[count] = 0;
	}while(count!=n_days);

	//Laço para cada dia da semana em Kgs
	for(count2 = 0; count2 != n_days; count2++){	
		kg_total += fruit_multip[count2];
		price_total += v_price[count2];
		printf("Dia %d: %d Kg \n",count2,fruit_multip[count2]);
	}

	kg_p_day = kg_total/n_days;
	price_p_day = price_total/n_days;

	printf("%f Kg por Dia \n",kg_p_day);
	printf("R$ %.2f por Dia \n",price_p_day);

//Salut Ab.
}


