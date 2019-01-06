#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

 typedef struct{
  char nome [100];
  float horas;
  int preco;
  int x;
}produto;

produto p[10];
int escolha;


int apresentacao ()
	{
 	
		 	
	strcpy (p[1].nome,"Ajuste");
	p[1].horas = 1;
	p[1].preco = 12;

	strcpy (p[2].nome, "Vestido Simples");
	p[2].horas = 4;
	p[2].preco = 60;

	strcpy (p[3].nome, "Vestido Festa");
	p[3].horas = 6;
	p[3].preco = 150;
	
	strcpy (p[4].nome, "Saia");
	p[4].horas = 2;
	p[4].preco = 40;

	strcpy (p[5].nome, "Camisa Masculina (Manga Curta)");
	p[5].horas = 2;
	p[5].preco = 35;
	
	strcpy (p[6].nome,"Camisa Masculina (Manga Comprida)");
	p[6].horas = 2.5;
	p[6].preco = 50;

	strcpy (p[7].nome,"Bermuda Masculina");
	p[7].horas = 2.5;
	p[7].preco = 50;

	strcpy (p[8].nome,"Calça Comprida");
	p[8].horas = 4;
	p[8].preco = 75;
	
	strcpy (p[9].nome, "Blusa Simples");
	p[9].horas = 1.5;
	p[9].preco = 30;

	strcpy (p[10].nome,"Blusas Trabalhadas");
	p[10].horas = 2.5;
	p[10].preco = 50;
		
		
	int x=0;
	while (x!=10){
		
		x++;
		cout << "Digite " << x << " Para " << p[x].nome << "\n";
		printf ("\n");
							
	}
	return(0);
}


 int main (void) {
 	
 	float totalhoras=0;
	int totalpreco=0;

 	
	printf ("Calculo de Horas trabalhadas e Ganhos por servicos. \n");
	
	printf ("\n");
	inicio:
	apresentacao();
	printf ("\n");
	scanf ("%d",&escolha);
	
	totalpreco=p[escolha].preco+totalpreco;
	totalhoras=p[escolha].horas+totalhoras;
	
	
	int escolha2=0;
	system ("cls");
	printf ("Digite 1 Para adicionar outro serviço \n");
	printf ("Ou Digite Qualquer tecla Para Resultados \n");
	scanf ("%d",&escolha2);
	
	if (escolha2==1) {
	system ("cls");
	goto inicio;
	}
	
	if (escolha2==2)
	{
	system ("cls");
	cout << "Lucro Total: " << totalpreco << "R$ \n";
	cout << "Horas Trabalhadas: " << totalhoras << " Hrs";
	}
				
	}
	


