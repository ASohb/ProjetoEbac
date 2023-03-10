#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>//Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings

int registro(){ //Fun��o respons�vel por cadastrar os usuarios no sistema
    //Inicio da cria��o das vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da crian��o de vari�veis.
	
	printf("Digite o CPF a ser cadastrado: ");// Coletando informa��es do usu�rio;
	scanf("%s", cpf);//o %s salva o valor dentro de uma string(n�o esquecer de adicionar a biblioteca)
	
	strcpy(arquivo, cpf);//Respons�vel por copiar os valores das strings.
	
	FILE *file; //Cria o arquivo no banco de dados
	file = fopen(arquivo, "w");//fopen abre o arquivo, w=write (porque quero escrever no arquivo).
	fprintf(file,cpf); //Salva no arquivo o cpf (o valor da variavel)
	fclose(file); //Fecha o arquivo
	
	file =  fopen(arquivo,"a");//abre o arquivo, "a" � pra atualizar informa��es
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file =  fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file =  fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file=fopen(arquivo,"a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta(){
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //r = read(ler);
	
	if(file == NULL){ //Se o arquivo n�o for encontrado, ou seja esta nulo ent�o exibe a mensagem abaixo.
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){ //Enquanto n�o pegar todos os arquivos ele se repete;
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s" ,conteudo);
		printf("\n\n");
	}
	system("pause");
	
}

int deletar(){
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
		remove(cpf); //Exlui o usu�rio com esse cpf.
	
	FILE *file;
	file= fopen(cpf,"r");
	
	if(file != NULL){ //Se o arquivo for diferente de nulo exibe a mensagem abaixo. 
		printf("O usu�rio foi deletado!\n");
		system("pause");
	
	}else{ //Sen�o, exibe que o usu�rio n�o se encontra no sistema. 
		printf("O usu�rio n�o se encontra no sistema.\n");
		system("pause");
	
	}

		
}


int main()
{
	int opcao=0; //Definindo as v�riaveis
	int laco=1; //Inicializa a variavel la�o com o valor 1.
	
	for(laco=1; laco=1;){ //Loop para, faz repetir o c�digo infinatemente porque o valor do la�o n�o sai do 1.
			
		system("cls");//Respons�vel por limpar a tela;
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n"); // /n faz pular a linha.
		printf("\t1- Registrar nomes\n"); //  /t da espa�o
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n\n");  
		printf("\t4- Sair do sistema\n\n");  
		printf("Op��o: ");//Fim do menu
		
	    scanf("%d", &opcao);  //%d para armazenar uma vari�vel do tipo inteiro
	    
	    system("cls");  //cls tem por fun��o limpar a tela.
	    
	    switch(opcao){//Inicio da sele��o do menu
	    	case 1: 
	    	registro();//Chamada de fun��es
			break; //Encerra a op��o
			
			case 2:
 	        consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
				printf("Obrigada por utilizar o sistema\n");
				return 0;
				break;
			
			default://O mesmo que else(sen�o);
			printf("Essa op��o n�o esta dispon�vel!\n");
			system("pause"); 
			break;	
		}
	}
	    	
	
}
