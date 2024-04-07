#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void pausa(int nseg);
int Temp();
int tempo;
char dateStr[9];
char timeStr[9];
FILE *arq;
int main () 
{
  printf("Digite aqui o caractere 't'para finalizar o programa.\n");
  srand(time(NULL)); 
  for(; ;)
  { 
     pausa(1);
     Temp();
 if(kbhit()&& getch()=='t')
    {
       break;
    }
}
printf("Tecla para finalizar digitada.\n");
fclose(arq);
return 0;
}
int Temp()
{              
   _strtime( timeStr );
   _strdate( dateStr);
   int aleat = rand() % 1023;
   int temp = (aleat*500)/1023; 
   printf("Temp:%d\n",temp);
   FILE *arq;
   arq = fopen("Temperatura.dat", "a");
   if(temp>=60)
   { 
     fprintf(arq, "%d %s %s\n", temp,dateStr,timeStr);
    }
}


void pausa(int nseg) 
{   
   int milli = 1000 * nseg;
   clock_t start_time = clock();
   while (clock() < start_time + milli);
}
