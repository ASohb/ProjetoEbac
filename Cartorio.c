#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h>//Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings

int registro(){ //Função responsável por cadastrar os usuarios no sistema
    //Inicio da criação das variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da crianção de variáveis.
	
	printf("Digite o CPF a ser cadastrado: ");// Coletando informações do usuário;
	scanf("%s", cpf);//o %s salva o valor dentro de uma string(não esquecer de adicionar a biblioteca)
	
	strcpy(arquivo, cpf);//Responsável por copiar os valores das strings.
	
	FILE *file; //Cria o arquivo no banco de dados
	file = fopen(arquivo, "w");//fopen abre o arquivo, w=write (porque quero escrever no arquivo).
	fprintf(file,cpf); //Salva no arquivo o cpf (o valor da variavel)
	fclose(file); //Fecha o arquivo
	
	file =  fopen(arquivo,"a");//abre o arquivo, "a" é pra atualizar informações
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
	
	if(file == NULL){ //Se o arquivo não for encontrado, ou seja esta nulo então exibe a mensagem abaixo.
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){ //Enquanto não pegar todos os arquivos ele se repete;
		printf("\nEssas são as informações do usuário: ");
		printf("%s" ,conteudo);
		printf("\n\n");
	}
	system("pause");
	
}

int deletar(){
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
		remove(cpf); //Exlui o usuário com esse cpf.
	
	FILE *file;
	file= fopen(cpf,"r");
	
	if(file != NULL){ //Se o arquivo for diferente de nulo exibe a mensagem abaixo. 
		printf("O usuário foi deletado!\n");
		system("pause");
	
	}else{ //Senão, exibe que o usuário não se encontra no sistema. 
		printf("O usuário não se encontra no sistema.\n");
		system("pause");
	
	}

		
}


int main()
{
	int opcao=0; //Definindo as váriaveis
	int laco=1; //Inicializa a variavel laço com o valor 1.
	
	for(laco=1; laco=1;){ //Loop para, faz repetir o código infinatemente porque o valor do laço não sai do 1.
			
		system("cls");//Responsável por limpar a tela;
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n"); // /n faz pular a linha.
		printf("\t1- Registrar nomes\n"); //  /t da espaço
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n\n");  
		printf("\t4- Sair do sistema\n\n");  
		printf("Opção: ");//Fim do menu
		
	    scanf("%d", &opcao);  //%d para armazenar uma variável do tipo inteiro
	    
	    system("cls");  //cls tem por função limpar a tela.
	    
	    switch(opcao){//Inicio da seleção do menu
	    	case 1: 
	    	registro();//Chamada de funções
			break; //Encerra a opção
			
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
			
			default://O mesmo que else(senão);
			printf("Essa opção não esta disponível!\n");
			system("pause"); 
			break;	
		}
	}
	    	
	
}
