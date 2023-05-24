/*
 ============================================================================
 Name        : Leerescribir.c
 Author      : ezequiel zelaya
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define direccion "/home/lp1-2023/Escritorio/csv nuevo.csv"

void copiar (FILE *a, FILE *b)
{
int c,cont;
char *filename=NULL;
printf("ingrese la direccion del archivo a leer: \n");
scanf("%s",filename);
if ((b=fopen(direccion,"w"))==NULL)
{
	printf("error en archivo b\n");
}
if ((a=fopen(filename,"r"))==NULL)
{
	printf("error en archivo a\n");
}else{
	for (cont=0;(c=fgetc(a))!=EOF;cont++){}
	if (c==',')
	{
		cont+=1;
		while(cont>3 && cont<5)
		{
			fputc(c,b);
		}
	}
	}
fclose(a);
fclose(b);
}

int main()
{
FILE *a=NULL;
FILE *b=NULL;
copiar(a,b);
}
