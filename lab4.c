/*Escuela Colombiana de ingenieria
En este programa se desarrolla el problema planteado por el profesor en la guia de laboratorio #4 en donde dadas dos matrices en formato .csv se realizan ciertas operaciones indicadas por el ususario ingresadas como argumento del programa.
Autor: Sergio Fernando Quiroga Guio
Materia: ALSE-2
version 1.0
Septiembre 2020
*/

#include <stdio.h>                                     //inclusion de librerias a usar
#include <string.h>
#include <stdlib.h>
#define MIN_ARG 4
#define MAX_ARG 6
#define MAX_FILE_SIZE 100
#define MAX 100
#define MAX_COL 10
#define MAX_FIL 10

void mostrar_ayuda();
void mostrar_version();
void suma_mat(float Matriz_A[MAX][MAX],float Matriz_B[MAX][MAX],float Matriz_C[MAX][MAX],int fa,int ca,int fb,int cb);
void rest_mat(float Matriz_A[MAX][MAX],float Matriz_B[MAX][MAX],float Matriz_C[MAX][MAX],int fa,int ca,int fb,int cb);
void paso_a_matriz(char buffer[MAX],float matriz[MAX][MAX],long int tam,int* fil,int* col);
void ciclo1 (char cad2[MAX], float matriz1[MAX][MAX],int longc2, int* col);
void ciclo2 (char cad2[MAX], float matriz[MAX][MAX],int longc2,int fil);
void cambio_a_matriz(char* argv[MAX],char buffer1[MAX],char buffer2[MAX],int fil[MAX],int col[MAX]);





void main (int argc, char *argv[MAX])
{
	int bandera_1 = 0;                                    //bandera utilizada para validar si el numero de argumentos es correcto
	char buffer1[MAX];
	char buffer2[MAX];
	//long tam_matriz_a = 0, tam_matriz_b = 0;
    //FILE *matr_a;
    //FILE *matr_b;
	float Matriz_A[MAX_COL][MAX_FIL], Matriz_B[MAX_COL][MAX_FIL], Matriz_C[MAX_COL][MAX_FIL], Matriz_D[MAX_COL][MAX_FIL];
	int fa= 0,ca=0, fb=0, cb=0, i=0, j=0, k=0, bandera=0;
	int fil[MAX],col[MAX];
	
	if (argc != MIN_ARG && argc != MAX_ARG)             //valida si el numero de argumentos es correcto o no
	{
		printf("\n¡¡¡Error!!! Se requieren como minimo cuatro argumentos y como maximo seis argumentos, intente nuevamente.\n\n");
		bandera_1 = 1;              
		//si el numero de argumentos es incorrecto cambia el valor de la bandera por 1
	}                                                   
	if (bandera_1 == 0)                                   //si el valor de la bandera no cambio, realiza el resto del programa
	{
		if (strcmp(argv[1],"--help") == 0 )
		    mostrar_ayuda();
		else
		{
		    if (strcmp(argv[1],"-v") == 0)
		        mostrar_version();
		    else
		    {
				if ((strcmp(argv[1],"-r") == 0)/*||(strcmp(argv[1],"-a"))*/)
				{
				printf("HSHDUWHSUWHS");
				cambio_a_matriz(argv,buffer1,buffer2,fil,col);
				}
					else
					{
				    if (strcmp(argv[4],"-w") == 0)
	                      {
	                      printf("guardar nuevo");
	                      }
				    //else
				    //printf("\nError en la eleccion de la operacion, el argumento ingresado no hace parte de las opciones.\n\n");	 
				    }
			}
		}
				//fclose(matr_a);
			    //fclose(matr_b);
    }
}

void mostrar_ayuda()
{
	printf("\nLas opciones para seleccionar una funcion son:\n");
	printf("\t-v (Muestra la version, autores y fecha)\n\t-t (Indica la transpuesta de las matrices)\n\t-a (Realiza la suma de las dos matrices)\n\t-r (Resta las dos matrices)\n\t-w (El resultado de la operación se guarda en un archivo con formato  .CSV\n\t    Se debe  agregar  ruta y  nombre  de  donde  se  guardará  el archivo)\n\n");
}

void mostrar_version()
{
	printf("\n\tVersion: 1.0\n\tAutor: Sergio Quiroga\n\tFecha de desarrollo: Septiembre 2020\n\n");
}



void cambio_a_matriz(char* argv[MAX],char buffer1[MAX],char buffer2[MAX],int fil[MAX],int col[MAX])
{
	        long int tam_matriz_a =0, tam_matriz_b=0;
	        FILE *matr_a;
	        FILE *matr_b;
	        float ma1[MAX][MAX],ma2[MAX][MAX],ma3[MAX][MAX];
            matr_a=fopen(argv[2],"r");
            matr_b=fopen(argv[3],"r");
			//printf("NEJNDUEHDUEDUJEIDJWIJDIWJDIWJD");
            fseek(matr_a,0,SEEK_END);
            tam_matriz_a=ftell(matr_a);
            rewind(matr_a);
            fseek(matr_b,0,SEEK_END);
            tam_matriz_b=ftell(matr_b);
            rewind(matr_b);
            fread(buffer1, 1, tam_matriz_a, matr_a);
            fread(buffer2, 1, tam_matriz_b, matr_b);
            strcat(buffer1,"\0");
            strcat(buffer2,"\0");
            paso_a_matriz(buffer1,ma1,tam_matriz_a,&fil[0],&col[0]);
            paso_a_matriz(buffer2,ma2,tam_matriz_b,&fil[1],&col[1]);
			//if (strcmp(argv[1],"-a") == 0)
         	//    {
         	//    	suma_mat(ma1,ma2,ma3,fil[0],col[0],fil[1],col[1]);
         	//    }
         	//    else
         	//    {
         	//    	 if (strcmp(argv[1],"-r") == 0)
         	//    	 {
         	//    		rest_mat(ma1,ma2,ma3,fil[0],col[0],fil[1],col[1]);	
         	//    	 }
			//		 else
			//		 {
			//			 if (strcmp(argv[1],"-t") == 0)
			//			 {
	        //             //mostrar_transpuesta();
			//			 }
			//		 }
			//	}
}				


void paso_a_matriz(char buffer[MAX],float matriz[MAX][MAX],long int tam,int* fil,int* col)
{
	int cont=0,i=1,j=0,longc1=0,longc2=0,longi1=0, longi=0,cont_fil=0,cont_col=0,longitot=0;
	char *dir_simb1=0,*dir_simb2=0,*dir_simb3=0,*dir_simb4=0,*dir_1=0,*dir_2=0, *dir_3=0, *dir_4=0;
	char cad1[MAX],cad2[MAX],numero1[MAX], numero[MAX];
	float matriz1[MAX][MAX];
	
	dir_1=buffer;
	dir_simb1=strchr(buffer,'\n');
	longc1=dir_simb1-buffer;
	strncpy(cad1,buffer,longc1);
	ciclo1(cad1,matriz,longc1,col);
			
	 while(longitot<tam-longc1)
	{
		dir_2=buffer+longc1+1;
		dir_simb2=strchr(dir_2,'\n');
		longc2=dir_simb2-dir_2;
		strncpy(cad2,dir_2,longc2);
		longitot=longc1;
		longc1=longc1+1+longc2;
		ciclo2(cad2,matriz,longc2,i);
		*fil=i+1;
		i++;
	}

}

void ciclo1 (char cad2[MAX], float matriz1[MAX][MAX],int longc2, int* col)
{
	int cont=0,longi=0,j=0;
	char *dir_4=0,*dir_simb4=0;
	char numero[MAX];
	while(cont<longc2)
	{			
		dir_4=cad2+longi;
		dir_simb4=strchr(dir_4,';');
		longi=dir_simb4-cad2;
		strncpy(numero,dir_4,longi);
		matriz1[0][j]=atof(numero);
		j++;
		longi=longi+1;
		cont=longi;
	}
	*col=j;
}

void ciclo2 (char cad2[MAX], float matriz[MAX][MAX],int longc2,int fil)
{
	int cont=0,longi=0,j=0;
	char *dir_4=0,*dir_simb4=0;
	char numero[MAX];
	while(cont<longc2)
	{			
		dir_4=cad2+longi;
		dir_simb4=strchr(dir_4,';');
		longi=dir_simb4-cad2;
		strncpy(numero,dir_4,longi);
		matriz[fil][j]=atof(numero);
		j++;
		longi=longi+1;
		cont=longi;
	}
	
}

void suma_mat(float Matriz_A[MAX][MAX],float Matriz_B[MAX][MAX],float Matriz_C[MAX][MAX],int fa,int ca,int fb,int cb)
{
	int i=0, j=0;
	for(i=0;i<fa;i++)
	{
		for(j=0;j<ca;j++)
		{
			Matriz_C[i][j]=Matriz_A[i][j]+Matriz_B[i][j];
		}
	}
	printf("\n\n\tEl resultado de la suma de la matriz A con la matriz B es\n\n");
	for(i=0;i<fa;i++)
	{
		for(j=0;j<ca;j++)
		{
			printf("%.3f\t",Matriz_C[i][j]);
		}
			printf("\n");
	}
}

void rest_mat(float Matriz_A[MAX][MAX],float Matriz_B[MAX][MAX],float Matriz_C[MAX][MAX],int fa,int ca,int fb,int cb)
{
	int i=0, j=0;
	for(i=0;i<fa;i++)
	{
		for(j=0;j<ca;j++)
		{
			Matriz_C[i][j]=Matriz_A[i][j]-Matriz_B[i][j];
		}
	}
	printf("\n\n\tEl resultado de la resta de la matriz A con la matriz B es\n\n");
	for(i=0;i<fa;i++)
	{
		for(j=0;j<ca;j++)
		{
	    	printf("%.3f\t",Matriz_C[i][j]);
		}
		printf("\n");
	}
}