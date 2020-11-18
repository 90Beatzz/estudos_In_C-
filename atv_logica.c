#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define fileiras_x 3
#define fileiras_y 4
#define TOTAL_ 20

//[3x] Iago A. do Nascimento
//IFBA 2020

char cpf[14];
char* fileiras[fileiras_x][fileiras_y];
int estudante = 0;
int resp = 0;
int count_i = 0;
int count_a = 0;
int init = 0;
int venda_count = 0;


struct venda{
    char nome[30];
    char cpf[14];
    char telefone[14];
	char estudante[2];
};

struct venda vetor_vendas[20];

int FileiraParaInteiro(char *fileira){
		
	if(strcmp(fileira,"A") == 0){
    	return 0;
	}
	if(strcmp(fileira,"B") == 0){
    	return 1;
	}
	if(strcmp(fileira,"C") == 0){
    	return 2;
	}
	if(strcmp(fileira,"D") == 0){
    	return 3;
	}
}
int FileiraParaCalc(char *fileira){
		
	if(strcmp(fileira,"A") == 0){
    	return 0;
	}
	if(strcmp(fileira,"B") == 0){
    	return 5;
	}
	if(strcmp(fileira,"C") == 0){
    	return 10;
	}
	if(strcmp(fileira,"D") == 0){
    	return 15;
	}
}

char Venda(void){
	
	if(venda_count == 0){
  	venda_count = 1;
  	ZerarVenda();  	
  }
		
    int verified;
    int cadeira = 0;
    char fileira[10];
    int fileira_int =0;
    int user_id = 0;
    char nome[30];
    char cpf[14];
    char telefone[14];
    char estudante[2];
    
    system("cls");        
    printf("Digite o Seu CPF \n");    
    scanf("%s",&cpf);
    verified = VerificarCpf(cpf);

    if(verified == 0){        
    	printf("CPF NAO CADASTRADO... \n");    	
    	//setbuf(stdin,NULL);
    	fflush(stdin);
    	printf("Digite o Nome \n");

    	gets(nome);
    	printf("Digite o Telefone \n");
    	scanf("%s",&telefone); 
    	printf("Digite S para Estudante e N Para nao estudante \n");
    	scanf("%s",&estudante);
		printf("Apresentando Cadeiras Disponiveis... \n");
    	MostrarCadeirasDisponiveis(0);
 		
    	printf("Digite o numero da cadeira \n");
    	scanf("%d",&cadeira);


    	printf("Digite a Letra da fileira \n");
    	scanf("%s",&fileira);

    	fileira_int = FileiraParaInteiro(fileira); 
		user_id = FileiraParaCalc(fileira);		
		   	
    	//Preenche cadeira    	
		fileiras[fileira_int][cadeira] = "X";
		
		//Calculo de Posicao no vetor
		cadeira++;		 		 	
		user_id = cadeira+user_id;	
		
		printf("%d %d \n",fileira_int,cadeira); //3 4 19
		
		//Registra dados do Usuario
		strcpy(vetor_vendas[user_id].cpf,cpf);
		strcpy(vetor_vendas[user_id].nome,nome); 
		strcpy(vetor_vendas[user_id].telefone,telefone);	
		strcpy(vetor_vendas[user_id].estudante,estudante);
    	
    	printf("Cadastro UserID: %d \n",user_id);
  	
    	printf("Usuario Cadastrado Com Sucesso...\n");    	
		CallMenu();
    }else{
    	printf("CPF JA CADASTRADO \n");
    	CallMenu();
    }
}

int CallMenu(){
	printf("Pressione Qualquer tecla para continuar... \n");
    getch();
	main();	
}

int CancelarVenda(){
	int cadeira = 0;
    char fileira[10];
    int fileira_int = 0;
    int user_id = 0;
    
		system("cls");
		printf("Cancelar Venda... \n");
		printf("Apresentando Cadeiras Ocupadas... \n \n");
	    MostrarCadeirasindisponiveis();
 		setbuf(stdin,NULL);
    	printf("Digite o numero da cadeira \n");
    	scanf("%d",&cadeira);
    	printf("Digite a Letra da fileira \n");
    	scanf("%s",&fileira);
		
		fileira_int = FileiraParaInteiro(fileira);
		fileiras[fileira_int][cadeira] = "0";
		
		//Calcula ID do Usuario
		user_id = FileiraParaCalc(fileira);
		user_id = cadeira+user_id;
		user_id++;
		
		//Deleta Dados
		strcpy(vetor_vendas[user_id].cpf,"0");
		strcpy(vetor_vendas[user_id].nome,"0");
		strcpy(vetor_vendas[user_id].telefone,"0");
		strcpy(vetor_vendas[user_id].estudante,"0");
		
		
		
		CallMenu();
			
}

int TrocarCadeira(){
int cadeira = 0;
    char fileira[10];
    int fileira_int = 0;
    int user_id = 0;
    char new_fileira[10];
    int new_cadeira = 0;
    int new_user_id = 0;
    int new_fileira_int = 0;
    
		system("cls");
		printf("Cancelar Venda... \n");
		printf("Apresentando Cadeiras Ocupadas... \n \n");
	    MostrarCadeirasindisponiveis();
 		setbuf(stdin,NULL);
    	printf("Digite o numero da cadeira ATUAL \n");
    	scanf("%d",&cadeira);
    	printf("Digite a Letra da fileira ATUAL \n");
    	scanf("%s",&fileira);
    			
		//Calcula ID Antigo do Usuario
		fileira_int = FileiraParaInteiro(fileira);
		user_id = FileiraParaCalc(fileira);
		user_id = cadeira+user_id;
		user_id++;
    	    	
		printf("Digite o numero da cadeira NOVA \n");
    	scanf("%d",&new_cadeira);
    	printf("Digite a Letra da fileira NOVA \n");
    	scanf("%s",&new_fileira);
    	
    	//Calcula NOVO ID do Usuario
		new_fileira_int = FileiraParaInteiro(new_fileira);
		new_user_id = FileiraParaCalc(new_fileira);
		new_user_id = new_cadeira+new_user_id;
		new_user_id++;		

			
		//Salva dados Novos
		fileiras[new_fileira_int][new_cadeira] = "X";	

		strcpy(vetor_vendas[new_user_id].cpf,vetor_vendas[user_id].cpf);
		strcpy(vetor_vendas[new_user_id].nome,vetor_vendas[user_id].nome);
		strcpy(vetor_vendas[new_user_id].telefone,vetor_vendas[user_id].telefone);
		strcpy(vetor_vendas[new_user_id].estudante,vetor_vendas[user_id].estudante);
		
		printf("NEW_USER_ID: %d \n",new_user_id);
		printf("%s \n",vetor_vendas[new_user_id].cpf);
		
		//Deleta Dados
		fileiras[fileira_int][cadeira] = "0";
		
		
		strcpy(vetor_vendas[user_id].cpf,"0");
		strcpy(vetor_vendas[user_id].nome,"0");
		strcpy(vetor_vendas[user_id].telefone,"0");
		strcpy(vetor_vendas[user_id].estudante,"0");
		
		printf("OLD_USER_ID: %d \n",user_id);		
		printf("%s \n",vetor_vendas[user_id].cpf);
		printf("%d %d \n",fileira_int,cadeira);
		
		//Menu
		CallMenu();
}

int MostrarCadeirasDisponiveis(by_menu){
	count_a = 0; 
	count_i = 0;


	for (count_i = 0; count_i <= fileiras_x; count_i++){
	count_a = 0;  
  	
        while (count_a <= fileiras_y ){
        	//Cadeiras Disponiveis
        	if(strcmp(fileiras[count_i][count_a],"0") == 0 && count_i == 0){
            printf("[DISPONIVEL] Cadeira %d Fileira A \n",count_a); 
        	}
        	if(strcmp(fileiras[count_i][count_a],"0") == 0 && count_i == 1){
            printf("[DISPONIVEL] Cadeira %d Fileira B \n",count_a); 
        	}
        	if(strcmp(fileiras[count_i][count_a],"0") == 0 && count_i == 2){
            printf("[DISPONIVEL] Cadeira %d Fileira C \n",count_a); 
        	}
        	if(strcmp(fileiras[count_i][count_a],"0") == 0 && count_i == 3){
            printf("[DISPONIVEL] Cadeira %d Fileira D \n",count_a); 
        	}
   
            count_a++;
        }                
    }   
    
	count_a = 0;
	count_i = 0; 
	
	if(by_menu == 1){
			CallMenu();
	}
}

int MostrarCadeirasindisponiveis(){
	count_a = 0; 
	count_i = 0;
	int first = 0;

	for (count_i = 0; count_i <= fileiras_x; count_i++){
	count_a = 0;  
  	
        while (count_a <= fileiras_y ){
        	//Opcoes de Exclusão
			if(strcmp(fileiras[count_i][count_a],"X") == 0 && count_i == 0){
				printf("[INDISPONIVEL] Cadeira %d Fileira A \n",count_a);
				first = 1;
			} 
			
			if(strcmp(fileiras[count_i][count_a],"X") == 0 && count_i == 1){
				printf("[INDISPONIVEL] Cadeira %d Fileira B \n",count_a);
				first = 1;
			} 
			if(strcmp(fileiras[count_i][count_a],"X") == 0 && count_i == 2){
				printf("[INDISPONIVEL] Cadeira %d Fileira C \n",count_a);
				first = 1;
			} 
			if(strcmp(fileiras[count_i][count_a],"X") == 0 && count_i == 3){
				printf("[INDISPONIVEL] Cadeira %d Fileira D \n",count_a);
				first = 1;
			} 
   
            count_a++;
        }                
    }   
    
    if(first == 0){
    	printf("Nenhuma Cadeira foi Preenchida! \n");
    	CallMenu();
	}
    
	count_a = 0;
	count_i = 0; 
}

int GetCadeira(int cadeira){
	
	
	if(cadeira < 5){
		cadeira--;		
		printf("Cadeira %d Fileira A \n",cadeira);
		CallMenu();
	}
	if(cadeira >= 5 && cadeira < 10){
		cadeira = cadeira-6;
		printf("Cadeira %d Fileira B \n",cadeira);		
	}
	if(cadeira >= 10 && cadeira < 15){
		cadeira = cadeira-11;
		printf("Cadeira %d Fileira C \n",cadeira);
	}
	if(cadeira >= 15){
		cadeira = cadeira-16;
		printf("Cadeira %d Fileira D \n",cadeira);
	}	
}

int VerificarCpf(char *cpf){
	
	count_a = 0;
	count_i = 0;
	int verified;
	   
    for (count_i = 0; count_i <= TOTAL_; count_i++){
    	if(strcmp(cpf,vetor_vendas[count_i].cpf) == 0){
            return 1;
		}   
    }   
    return 0;
    
}

int VerificarCpfMenu(){
	count_a = 0;
	count_i = 0;
	int verified;
	
	printf("Digite o CPF \n");
	scanf("%s",&cpf);
	   
    for (count_i = 0; count_i <= TOTAL_; count_i++){
    	if(strcmp(cpf,vetor_vendas[count_i].cpf) == 0){
			system("cls");    		
            printf("Usuario Encontrado \n");
            printf("ID: %d \n",count_i);
            printf("Nome: %s \n",vetor_vendas[count_i].nome);
            printf("CPF: %s \n",vetor_vendas[count_i].cpf);
            printf("Telefone: %s \n",vetor_vendas[count_i].telefone);
            printf("Estudante: %s \n",vetor_vendas[count_i].estudante);			            
            GetCadeira(count_i);
			CallMenu();	
		}   
    }
	printf("Usuario Não Encontrado \n");  
	CallMenu(); 

    return 0;
}

int ZerarVenda(){
		for (count_i = 0; count_i <= TOTAL_; count_i++){
		strcpy(vetor_vendas[count_i].cpf,"0");
		strcpy(vetor_vendas[count_i].nome,"0");
		strcpy(vetor_vendas[count_i].telefone,"0");
    } 
}

int ZerarCadeiras(){
	for (count_i = 0; count_i <= fileiras_x; count_i++){
	count_a = 0;  
  	
        while (count_a <= fileiras_y ){ 
			fileiras[count_i][count_a] = "0";   
			      
            count_a++;
        }                
    }
    
    
	for (count_i = 0; count_i <= TOTAL_; count_i++){
		strcpy(vetor_vendas[count_i].cpf,"0");
		strcpy(vetor_vendas[count_i].nome,"0");
		strcpy(vetor_vendas[count_i].telefone,"0");
    }    
    
    
	count_a = 0;
	count_i = 0;   
	
	return 1;      
};

int TotalVendas(){
 
	int total_vendas = 0;
	for (count_i = 0; count_i <= fileiras_x; count_i++){
	count_a = 0;   	
        while (count_a <= fileiras_y ){ 
			if(strcmp(fileiras[count_i][count_a],"X") == 0){
			    total_vendas++;
			}
			count_a++;
			
        }                
    }
    
    printf("Total de Vendas: %d \n",total_vendas);
    CallMenu();
}

int TotalVendasEstudantes(){
	int user_id = 0;
	int fileira = 0;
	int cadeira = 0;
	int estudante = 0;
	int n_estudante = 0;
 
	int total_vendas = 0;
	for (count_i = 0; count_i <= fileiras_x; count_i++){
	count_a = 0;   	
        while (count_a <= fileiras_y ){ 
        	
        	//Lógica ID de Usuario
			if(strcmp(fileiras[count_i][count_a],"X") == 0){
				if(count_i == 0){
					user_id = count_a;					
				}else if(count_i == 1){
					user_id = count_a+5;
				}else if(count_i == 2){
					user_id = count_a+10;
				}else if(count_i == 3){
					user_id = count_a+15;
				}				
				user_id++;
				
				//Se Estudante
				if(strcmp(vetor_vendas[user_id].estudante,"S") == 0){
					estudante++;	
				}else{
					n_estudante++;				
				}

				
			}
				count_a++;			
        }                
    }
    
    printf("Vendas: Não Estudante %d \n",n_estudante);
    printf("Vendas: Estudante %d \n",estudante);
    CallMenu();
}

int main(void){  
   system("cls");  
  if(init == 0){
  	init = 1;
  	ZerarCadeiras();  	
  }  
  resp = 0;    
    do{
        printf("digite 1 Para realizar uma venda \n");
        printf("digite 2 Para verificar CPF \n");
        printf("digite 3 Para cancelar uma venda \n");
        printf("digite 4 Para trocar cadeira \n");
        printf("digite 5 Para mostrar cadeiras disponiveis \n");
        printf("digite 6 Para mostrar total de venda \n");
        printf("digite 7 Para mostrar vendas  para estudantes e nao estudante \n");
        scanf("%d",&resp);

        switch (resp)
        {
        case 1:
        	Venda();        
            break;
        case 2:
        	VerificarCpfMenu();
        	break;
        case 3:
        	CancelarVenda();
        	break;
        case 4:
        	TrocarCadeira();
        	break;
        case 5:
        	MostrarCadeirasDisponiveis(1);
        	break;
		case 6:
        	TotalVendas();
        	break;
		case 7:
        	TotalVendasEstudantes();
        	break;
        default:
            break;
        }        
    } while(resp == 0);
}

//Rise Ab ...




