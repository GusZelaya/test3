#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * ALGORITMO
 * pasos:
 * -permitir al usuario ingresar vectores L y S
 * --crear funcion que revice si contenido==AGCT
 * ---si si retornar valido,si no retornar invalido
 * ---dentro de la funcion controlar que len(s)<=len(t)
 * ---si si retornar valido,si no retornar invalido
 * tipo 1:
 * -crear funcion que recorra S dentro de L
 * --iniciar contador
 * ---cada que dentro de L se encuentre el primer caracter dentro de S, reiniciar contador
 * ---Cada que S dentro de L, cont +1
 * --retornar valor cont
 * tipo 2:
 * -crear funcion que recorra S dentro de L (o usar la misma pero condicionar con un static)
 * --iniciar contador
 * --while (cant.combinaciones posibles)
 * ---crear un vector de punteros para almacenar las combinaciones posibles
 * ---cada que dentro de L se encuentre el primer caracter dentro de S, reiniciar contador
 * ---Cada que un vector de punteros derivado de S que coincida dentro de L, cont +1
 * --retornar valor cont
 * -si validaciones validas
 * -imprimir L y S
 * -imprimir contadores de las funciones
 */




/*
 * funcion encargada de crear los vectores para los ingresos del usuario
 * -L-->vector L
 * -S-->vector S
 * -TamS-->variable que sera utilizada para almacenar el tamaño del vector S
 */
int cargarLS(char *(L),char *(S),int *tamS)
{
	int lens;//
	char c;	//se crean las variables locales
	int i; //
	printf("ingrese el vector L\n");
	for (i=0;(i<50) && ((c=getchar())!='\n');i++)
	{
		if(c!='A'&&c!='G'&&c!='C'&&c!='T')											// if encargado de chequear que los valores ingresados por el
		{																		   // usuario sean los que plantea el problema
			printf("caracter ingresado invalido\ncaracteres validos: A G T C");	  // de lo contrario se resta 1 a la variable i (que controla el for)
			if (i>0)															 //	para que quede en bucle hasta que ingrese un \n
				i--;
		}else{					//
							   // else encargado de cargar el caracter cargado en el vector correspondiente
			L[i]=c;			  //
		}
	}
	if(strlen(L)<50)	// si el vector cargado por el usuario es menor a 50 caracteres
		L[i+1]='\0';   // se ingresa un \0 para terminar el vector
	printf("ingrese el vector S\n");
	char k;
	for (int j=0;(j<50) && ((k=getchar())!='\n');j++)									//
		{																			   // funcionamiento del for analogo hasta la linea del lens+=1
			if(k!='A'&&k!='G'&&k!='C'&&k!='T')										  //
			{
				printf("caracter ingresado invalido\ncaracteres validos: A G T C");
				if (j>0)
					j--;
			}else{

				S[j]=k;
				lens+=1;		// siempre que se cumpla la condicion de cargado se suma una unidad a la variable que contrala el tamaño de S
			}
		}
	if (lens<2)				// Si el tamaño de S es menor a 2 se retorna 1 y termina el programa dando un aviso
		return 1;		   //
	if (lens<strlen(L))
		S[lens+1]='\0'; // carga un \0 al final del vector
	*tamS=lens;		   // iguala Tams a lens para almacenar el tamaño de S
	return 0;		  // fin de la funcion
}
/*
 * funcion encargada de chekear la condision 1
 * Fa--> variable encargada de almacenar las repeticiones de caracteres
 * cont--> contador que se retorna al finalizar
 * -L-->vector L
 * -S-->vector S
 */
int Tipo1(char *L,char *S)
{
	int FA=0;		// se crean las variables
	int cont=0;	   //
	for (int i=0;L[i]!='\0';i++)					// for encargado de recorrer el vector L buscando coincidencias con S
	{											   // si encuentra coincidencias dentro de L y S adiciona una unidad a FA
		for (int j=0;S[j]!='\0';j++)			  //
		{									     // si FA consigue ser mayor que 2 significa que se cumple la condicion
			if(L[i]==S[j])						// por lo que se suma una unidad al contador
				FA+=1;						   //
			else							  // si no se encuentran coincidencias FA vuelve a 0
				FA=0;

		}
		if(FA>2)							//
		{								   // siempre que FA sea mayor que 2 se suma 1 a cont
			cont+=1;				      //
			FA=0;
		}
	}
	return cont; // retorna el total parejas semejantes y termina la funcion
}
/*
 * funcion encargada de chekear la condicion 2
 * jreserva --> variable almacenada para guardar el valor de j
 * cont-->contador que se retorna al final de la funcion
 * zaza-->vector de punteros utilizados para guardar todos los casos a revisar dentro del vector S
 * tamS--> tamaño de S
 * -L-->vector L
 * -S-->vector S
 */
int Tipo2(char *L,char *S,int *tamS)
{
	int jreserva;			//
	int cont=0;			   // se crean las variables y el vector de punteros
	char *zaza[*tamS];	  //
	int j=0;
	for (int i=0;i<*tamS-1;i++)					// en este for se guardan dentro del vector de punteros todos los casos
	{										   // que corresponden ser chekeados con L
		for(;j<*tamS-1;j++)			  		  //
		{								     // dentro del if se revisa en S si existen caracteres que sean repetidos en la cadena
			if(S[j]!=S[j+1])                //
				zaza[i][j]=S[j];		   //
			jreserva=j;					  //
		}
		zaza[i][jreserva+1]='\0';
		j++;
	}
	int FA=0;										// este for funciona de manera analoga al de su semejante en la
		for (int i=0;L[i]!='\0';i++)			   //
		{										  //
			for (int j=0;zaza[i][j]!='\0';j++)
			{
				if(L[i]==zaza[j][i])
					FA+=1;
				else
					FA=0;
			}
			if(FA>2)
			{
				cont+=1;
				FA=0;
			}
		}
	return cont;// se retorna el valor final del contador
}


/*
 * S--> vector S
 * L--> vector L
 * cont1 y cont2--> contadores que almacenan la cantidad de coincidencias
 */
int main()
{
	char S[50],L[50];		//
	int cont1,cont2;	   // cracion de variables
	cont1=cont2=0;		  //
	int tamS=0;			 //
	if ((cargarLS(L,S,&tamS))==1)
	{
		printf("valores ingresados invalidos\n");
		return 0; // terminacion de la funcion
	}
	printf("las cadenas ingresadas son:\nL:%s\tS:%s",L,S);
	cont1=Tipo1(L,S);
	printf("las concidencias encontradas son:\ntipo 1:%d",cont1);
	cont2=Tipo2(L,S,&tamS);
	printf("tipo 2:%d",cont2);
}
