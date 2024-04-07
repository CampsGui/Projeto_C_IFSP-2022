#include<stdio.h> 
#include <stdlib.h> 
#include <locale.h>

FILE*file;
void MENU (), REGISTRO(), MAIOR(), MENOR(),INSERT();
char horario[9], data[9];
int i;
int temp,maior_t=0, menor_t=1023,indice=0;; 
int *compara;
int main ()
{
	file = fopen ("Temperatura.dat","r");
	setlocale(LC_ALL, "Portuguese");
	MENU();
	fclose(file);
	return (0);
}

void MENU()
{
	int opcao;
	do {
		
		system ("cls");
		printf("Escolha uma das opções\n\n");
		printf("1 – Todas as temperaturas\n");
		printf("2 – Maior temperatura \n");
		printf("3 – Menor temperatura \n");
		printf("4 – Finalizar o programa\n ");
		printf("Digite a opção escolhida: ");
		scanf("%d%*c", &opcao);
		switch (opcao)
		{
			case 1: REGISTRO();break;	
			case 2: MAIOR();break;
			case 3: MENOR();break;
			case 4: printf ("Programa finalizado\n");break;
			default:printf ("Opção invalida...\n");	system ("pause");break;
		}

	}while (opcao !=4);
}

void REGISTRO ()
{
    fseek(file, 0, SEEK_SET);
	i=0;
	system ("cls");
	if (file==NULL)
	{
		printf ("O arquivo não foi encontrado\n");
	}
	printf ("Temperaturas registradas:\n ");
	while (fscanf(file,"%d %s %s",&temp,data,horario ) !=EOF)
	{
		printf ("Temperatura:%d \n",temp);
		printf ("Data: %s\n",data);
		printf ("Horario: %s\n\n",horario);
		i=i+1;			
	}
	system("pause");
}
void INSERT()
{
fseek(file, 0, SEEK_SET);
	int idx=0;
	compara=(int*)malloc(i*sizeof(int));
	if(compara==NULL){
		printf("ERRO\n");
	}
	else
	{
	  while (fscanf(file,"%d %s %s",&temp,data,horario) !=EOF)
	  {
	  	compara[idx]=temp;
	  	idx=idx+1;
      }	
	}
}
void MAIOR()
{
	INSERT();
	for(indice=0; indice<i; indice+=1)
	{
		if(compara[indice]>maior_t)
		{
		   maior_t=compara[indice];
		}	
	}
	printf("A maior temperatura é:%d\n", maior_t);
	system("pause");

}
void MENOR()
{
	INSERT();
	for(indice=0; indice<i; indice+=1)
	{
		if(compara[indice]<menor_t)
		{
		   menor_t=compara[indice];
		}	
	}
	printf("A menor temperatura é:%d\n", menor_t);
	system("pause");
}



