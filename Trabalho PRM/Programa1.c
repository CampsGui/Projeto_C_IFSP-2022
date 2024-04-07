#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <locale.h>
#include <time.h>

struct atletas
{
	int codigo, idade;
	float altura;
	char mod[40];
	char nome[40];
	char pos[40];
} Atl[40];

int indice=0;

void inclusao();
void visualizar();
void consulta();
void pesquisa();
void alterar();
void excluir();
void gravarDadosArquivo();
void lerDadosArquivo();

FILE *arq;

void menu()
{
	char opcao;
    do {
   	  system("CLS");
   	  printf("        Cadastro de Atletas\n\n\n");
	  printf("I - Incluir\n");
      printf("V - Visualizar todos os atletas cadastrados\n");
      printf("P - Pesquisar um atleta individual\n");
	  printf("A - Alterar\n");
	  printf("E - Excluir\n");
      printf("G - Gravar dados no arquivo\n");
      printf("L - Ler dados do arquivo\n");
      printf("F - Fim do Programa\n");
	  printf("\nDigite a opção desejada: ");
	  scanf("%c%*c", &opcao);
	  switch(opcao) {
		case 'i':
		case 'I': inclusao(); break;
		case 'v':
		case 'V': visualizar(); break;
		case 'p':
		case 'P': pesquisa(); break;
		case 'a':
		case 'A': alterar(); break;
		case 'e':
		case 'E': excluir(); break;
		case 'g':
	  	case 'G': gravarDadosArquivo(); break;
	  	case 'l':
	  	case 'L': lerDadosArquivo(); break;
	  	case 'f':
	  	case 'F': printf("\nFim do programa\n"); break;
	  	default : printf("Opção Inválida!!\n");
	  	          getch(); break;
	  }
    } while (opcao != 'f' && opcao != 'F');
	getch();
}

void inclusao()
{
	if(indice < 40)
	{
		fseek(arq, 0, SEEK_SET);
			
		printf("Nome do atleta: ");
		gets(Atl[indice].nome);
		printf("Idade do atleta: ");
		scanf("%i%*c", &Atl[indice].idade);
		printf("Altura do atleta: ");
		scanf("%f%*c", &Atl[indice].altura);
		printf("Modalidade praticada: ");
		gets(Atl[indice].mod);
		printf("Posição em jogo (caso não tenha digite N/A): ");
		gets(Atl[indice].pos);
		cod();
		fwrite(&Atl[indice], sizeof(Atl[indice]), 1, arq);
		printf("\nAtleta cadastrado com sucesso!!\n");
		indice++;
		getch();
	}
	else
	{
		printf("Espaço reservado cheio.\nNão é possível cadastrar novos atletas.\n");
	}
}

int cod()
{
 int codigo;
 srand((unsigned)time(NULL) );
 codigo = (rand() % 101) + 1;
 Atl[indice].codigo=codigo;
}

void visualizar()
{
	if(indice==0)
	    printf("\nNão existem atletas cadastrados!!\n");
	else
	{   
		int ordem;
		printf("\nDigite 1 para exibição em ordem crescente ou 2 para exibição em ordem decrescente: ");
        scanf("%i",&ordem);
        if (ordem == 1)
        {
		  int i, j, tmp;
		  cod();
		  for (i = 1; i < indice; i++) 
		  {
		    j = i;
		    while (j > 0 && Atl[j - 1].codigo  > Atl[j].codigo)
		    {  
		        tmp = Atl[j].codigo;
		        Atl[j].codigo = Atl[j - 1].codigo;
		        Atl[j - 1].codigo = tmp;
		        j--;
		    }
		  }
	      printf("\nVetor em ordem crescente: ");
		  printf ("\n\nDados do registro\n");
		  for(i = 0; i<indice; i++)
		  {
		    printf("\nProntuário: %i\n", Atl[i].codigo);
			printf("Nome: %s\n", Atl[i].nome);
			printf("Idade: %i\n", Atl[i].idade);
			printf("Altura: %.2f\n", Atl[i].altura);
			printf("Modalidade: %s\n", Atl[i].mod); 
			printf("Posição em jogo: %s\n", Atl[i].pos);
		  }
	    }
	    else
		{
		 if (ordem ==2)
		  {
			int i, j, tmp;
		    for (i = 1; i < indice; i++)
			{
		        j = i;
		        while (j > 0 && Atl[j - 1].codigo < Atl[j].codigo)
				{
		            tmp = Atl[j].codigo;
		            Atl[j].codigo = Atl[j - 1].codigo;
		            Atl[j - 1].codigo = tmp;
		            j--;
		        }
		    }
		    printf("\nVetor em ordem decrescente: ");
		    printf ("\nDados do registro\n");
			for(i = 0; i<indice; i++)
			{
			    printf("\nProntuário: %i\n", Atl[i].codigo);
				printf("Nome: %s\n", Atl[i].nome);
				printf("Idade: %i\n", Atl[i].idade);
				printf("Altura: %.2f\n", Atl[i].altura);
				printf("Modalidade: %s\n", Atl[i].mod); 
				printf("Posição em jogo: %s\n", Atl[i].pos);
			}
		  }
	   }
    }
	getch();
}

void pesquisa()
{
   int prontuario, achou=0;
   system("cls");
   printf("\n*********Atletas Cadastrados********\n");
   fseek(arq, 0, SEEK_SET);
   printf("Digite o prontuário do atleta:");
   scanf("%i", &prontuario);
   
   while(fread(&Atl[indice], sizeof(Atl[indice]), 1, arq))
   {
        if(Atl[indice].codigo==prontuario && Atl[indice].codigo!=9999)
        {
		   printf( "\n\n\nImprimindo os dados do Atleta\n");
		   printf ("\n\nDados do registro\n");
		   printf("\nProntuário: %i\n", Atl[indice].codigo);
		   printf("Nome: %s\n", Atl[indice].nome);
		   printf("Idade: %i\n", Atl[indice].idade);
		   printf("Altura: %.2f\n", Atl[indice].altura);
		   printf("Modalidade: %s\n", Atl[indice].mod); 
		   printf("Posição em jogo: %s\n", Atl[indice].pos);
		   getch();
	       achou=1;
	       break;
	    }
   }
    if(achou!=1)
    {
   	    printf( "\n\n\nAtleta não encontrado\n\n");
        getch();
    }
}

void alterar()
{
   int prontuario, achou=0;
   char resp;
   system("cls");
   printf("\n*********Alterar Atletas********\n");
   fseek(arq, 0, SEEK_SET); 
   printf("Digite o prontuário do atleta:");
   scanf("%i%*c", &prontuario);
      
   while(fread(&Atl[indice], sizeof(Atl[indice]), 1, arq))
   {
        if(Atl[indice].codigo==prontuario)
        {
	       achou=1;
	       break;
	    }
   }
   
   if(achou==1)
   {
   	    printf( "\n\n\nAlterando os dados do atleta\n\n");
		printf ("Dados do registro\n");
		printf("\nProntuário: %i\n", Atl[indice].codigo);
		printf("Nome: %s\n", Atl[indice].nome);
		printf("Idade: %i\n", Atl[indice].idade);
		printf("Altura: %.2f\n", Atl[indice].altura);
		printf("Modalidade: %s\n", Atl[indice].mod); 
		printf("Posição em jogo: %s\n", Atl[indice].pos);
        printf("\nDeseja realmente alterar? (S/N): ");
        scanf("%c%*c",&resp);
	    if((resp=='s') || (resp == 'S'))
	    {
	       inclusao();
		   fseek(arq, sizeof(Atl[indice]) * -1, SEEK_CUR);
	       fwrite(&Atl[indice], sizeof(Atl[indice]), 1, arq);
	       printf("\nDados foram alterados\n");    
        }
	    else
	      printf("\nDados não foram alterados\n");      
   }
   else
     printf("\nAtleta não cadastrado\n"); 
   getch();  
}

void excluir()
{
   int prontuario, achou=0;
   char resp;
   system("cls");
   printf("\n*********Excluir Atletas********\n");
   fseek(arq, 0, SEEK_SET); 
   printf("Digite o prontuário do atleta:");
   scanf("%i%*c", &prontuario);
      
   while(fread(&Atl[indice], sizeof(Atl[indice]), 1, arq))
   {
        if(Atl[indice].codigo==prontuario)
        {
	       achou=1;
	       break;
	    }
   }
   
   if(achou==1)
   {
   	    printf( "\n\n\nExcluindo os dados do atleta\n\n");
       	printf ("Dados do registro\n");
		printf("\nProntuário: %i\n", Atl[indice].codigo);
		printf("Nome: %s\n", Atl[indice].nome);
		printf("Idade: %i\n", Atl[indice].idade);
		printf("Altura: %.2f\n", Atl[indice].altura);
		printf("Modalidade: %s\n", Atl[indice].mod); 
		printf("Posição em jogo: %s\n", Atl[indice].pos);
        printf("\nDeseja realmente excluir ? (S/N): ");
        scanf("%c%*c",&resp);
	    if((resp=='s') || (resp == 'S'))
	    {
	       Atl[indice].codigo=9999;
		   fseek(arq, sizeof(Atl[indice]) * -1, SEEK_CUR);
	       fwrite(&Atl[indice], sizeof(Atl[indice]), 1, arq);
	       printf("\nDados foram excluidos com sucesso\n");
        }
	    else
	      printf("\nDados não foram excluidos!!!\n");    
   }
   else
     printf("\nAtleta não cadastrado\n");  
   getch();
}

void gravarDadosArquivo()
{		
    if (( arq = fopen("dados.txt", "w"))==NULL)														
    {
          printf("O arquivo %s não pode ser aberto... \n ","dados.txt");
          printf("O programa termina aqui... \n\n");
          getch();
          exit(0);
    }
	
	if(indice==0)
	    printf("\nNão existem atletas cadastrados!!\n");
	else
	{
		int i;
		printf("\n\n********** gravando dados no arquivo************\n");
		for(i=0; i<indice; i++)
		{
			fwrite(&Atl[i], sizeof(Atl), 1, arq);
		}
	}
	getch();
	fclose(arq);
}

void lerDadosArquivo()
{		
    if (( arq = fopen("dados.txt", "r"))==NULL)														
    {
          printf("O arquivo %s não pode ser aberto... \n ","dados.txt");
          printf("O programa termina aqui... \n\n");
          system("pause");
          exit(0);
    }
	
    while(fread(&Atl[indice], sizeof(Atl), 1, arq))
    {
      indice++;
    }
    getch();
	fclose(arq);
}

void exclusaoDefinitiva()
{
    FILE *arqAux;
	char nome_arquivo[]="CadastroAtleta.dat";		
    if (( arq = fopen(nome_arquivo , "r"))==NULL)
	{												
 	   printf("O arquivo %s não pode ser aberto... \n ",nome_arquivo);
       printf("O programa termina aqui... \n\n");
       system("pause");
       exit(0);
    }
    
    arqAux = fopen("ArquivoAuxiliar.dat", "w");
    while (fread(&Atl[indice], sizeof(Atl[indice]), 1, arq))
    {
       if(Atl[indice].codigo!=9999)
          fwrite(&Atl[indice], sizeof(Atl[indice]), 1, arqAux);
    }
    fclose(arq);
    fclose(arqAux);
    system("del CadastroAtleta.dat");
    system("ren ArquivoAuxiliar.dat CadastroAtleta.dat");
}

int main ()
{
	setlocale(LC_ALL, "Portuguese");
    char nome_arquivo[]="CadastroAtleta.dat";
    			
    if (( arq = fopen( nome_arquivo, "r+b"))==NULL)
		{													
 	   if (( arq = fopen( nome_arquivo, "w+b")) == NULL)
       {
          printf("O arquivo %s não pode ser aberto... \n ",nome_arquivo);
          printf("O programa termina aqui... \n\n");
          getch();
          exit(0);
        }
    }
    menu();
        
	printf("\nFechando o arquivo e saindo do programa ...");
    fclose(arq);
    exclusaoDefinitiva();
    printf ("\n");
	getch();
	return 0;
}
