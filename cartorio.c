#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço de memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> //Biblioteca que cuida da parte de strings

int registrar() //Função do registro
{
	
	setlocale(LC_ALL, "Portuguese"); //Define a linguagem
	
	char arquivo[40]; //String de nome do arquivo
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("  -Digite o CPF à ser registrado-\n>");
	scanf("%s", cpf); //Armazenamento do valor da string "cpf"
	
	strcpy(arquivo, cpf); //Copia valor da string "cpf" para a string "arquivo"
	
	FILE *file; //Busca na biblioteca o arquivo
	file = fopen(arquivo, "w"); //Abre e cria arquivo novo com nome da string "arquivo"
	fprintf(file, "=CPF: "); //Deixa bonitinho
	fclose(file); //Fecha arquivo 
	
	file = fopen(arquivo, "a"); //Abre o arquivo já existente e modifica ele
	fprintf(file, cpf); //Salva valor do "cpf" no arquivo
	fclose(file); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file, "\n=Nome: "); 
	fclose(file);
	
	system("cls");
	
	printf("  -Digite nome à ser cadastrado-\n>");
	scanf("%s", nome); //Armazena o valor da string "nome"
	
	file = fopen(arquivo, "a");
	fprintf(file, nome); //Salva valor do "nome" no arquivo
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, "\n=Sobrenome: "); 
	fclose(file); 
	
	system("cls");
	
	printf("  -Digite o sobrenome à ser cadastrdado-\n>");
	scanf("%s", sobrenome); //Armazena valor da string "sobrenome"
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome); //Salva valor do "sobrenome" no arquivo
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, "\n=Cargo: "); 
	fclose(file);
	
	system("cls");
	
	printf("  -Digite o cargo à ser cadastrado-\n>");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo); //Salva valor do "cargo" no arquivo
	fclose(file);
	
	printf("\n");
	system("pause");
	
}

int consultar() //Função de consulta
{
	
	char cpf[40];
	char consulta[200];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf(" -Digite o CPF para ser consultado-\n>");
	scanf("%s", cpf); //Pega valor digitado e armazenar na string "cpf"
	
	FILE *file; //Busca na biblioteca o arquivo
	file = fopen(cpf, "r"); //Abre arquivo já existente para ler seus dados
	
	if(file == NULL) //Se não for encontrado o CPF...
	{
		printf("Dados do CPF não localizados. \n");
	}
	else //Se for encontrado...
		printf("\nEsses são os dados do usuário:\n\n");
	
	while(fgets(consulta, 200, file) != NULL) //Enquanto os dados no arquivo estão sendo transferidos e o "cpf" existe...
	{
		printf("%s", consulta); //Coloca na tela os valores da string "consulta", pegos no arquivo
	}
	
	printf("\n\n");
	fclose(file); //Fecha o arquivo depois de verificar e mostrar suas informações
	system("pause");
	
}

int deletar() //Função de Deletar
{
	
	char cpf[40];
	
	printf(" -Digite o CPF do usuário que será deleltado-\n>");
	scanf("%s", cpf); //Armazena valor digitado na string "cpf"
	
	FILE *file;
	file = fopen(cpf, "r"); //Abre e lê arquivo para ver se o cpf existe ou não
	
	if(file == NULL)
	{
		printf("Esse usuário não está registrado.\n\n");
	}
	else
		printf("Esse usuário foi deletado com sucesso!\n\n");
		
	fclose(file); //Fecha arquivo antes de deletar	
	system("pause");		
	remove(cpf); //Deleta o arquivo	
		
}

int main() //Função Principal
{
	
	int opcao = 0; //Variável da Escolha de Telas
	int laco = 1; //Variável para Repetição
	
	for(laco = 1; laco = 1;) //Linha de Código para Retorno de Menu
	{

    	system("cls"); //Apaga as Outras Telas ao Retornar ao Menu

		setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
		printf("\t================Cartório da EBAC================\n\n"); //Início do Menu
		printf("\t  Escolha a opção desejada do menu:\n\n");
		printf("\t\t1 - Inserir Nomes\n");
		printf("\t\t2 - Consultar Nomes\n");
		printf("\t\t3 - Deletar Nomes\n");
		printf("\t\t4 - Sair do Sistema\n\n");
		printf("\t > "); //Fim do Menu
	
		scanf("%d", &opcao); //Armazenando o Valor de Opção
	
		system("cls"); //Apaga Menu ao Ir à Outra Tela
	
		switch(opcao) //Seleção de Telas
			{
				case 1: //Tela 1 - Inserir Nomes
					registrar();
				break;
		
				case 2: //Tela 2 - Colsultar Nomes 
					consultar();
				break;
		
				case 3: //Tela 3 - Deletar Nomes
					deletar();
				break;
		
				case 4: //Sair do Sistema
					printf(" -Obrigado por ultilizar o sistema!-\n");
					return 0;
				break;
					
				default: //Tela 4 - Opção Inexistente
					printf("Está opção não está disponível\n\n"); 
					system("pause");
				break;
    		}

    }     

}

