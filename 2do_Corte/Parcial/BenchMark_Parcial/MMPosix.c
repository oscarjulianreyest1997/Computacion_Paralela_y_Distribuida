/*Fecha: 20/04/2022
* Autor: Oscar Juián Reyes Torres
* Asignatura: Computación Paralela y Distribuida.
* Tema: Implementacion libreria Poxis.
* Descripción: Aplicación para la multiplicación de matrices
  wcon el algoritmo clásico (filas x columnas) usando
  variables globales. Además, utilizando las siguientes funciones:
    1. Creación de variables de doble puntero para matrices.
    2. Reserva de memoria para matrices de doble puntero
    3. Matriz de inicio
    4. Función para el producto de la matriz:
      4.1.1 La matriz A se divide y esas porciones
            será enviado a un hilo individual
      4.1.2 El tamaño de la matriz se enviará en el
         ejecución.
    5. Tamaño de la matriz siempre al cuadrado (NxN)
    6. Imprimir matriz con doble puntero.
*/

/*Interfaces*/
#include "modulo.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <omp.h>


/*  @breif main(): Main function
*/
int main(int argc, char* argv[]){

    double **Ma,**Mb,**Mc;
    //struct arg_struct args;

    if (argc!=3){
        printf("./MMPosix <matrix size> <# of threads>\n");
        return -1;
    }

    /*Init of global variables*/
    int N           = atof(argv[1]);    /* Matrix's size.*/
    int nthreads    = atof(argv[2]);    /* Number of threads.*/
    
    /*It is validated that the number of threads entered is less than or equal to the 
      number of cores detected by the operating system*/
	if(nthreads > omp_get_max_threads()){
		printf("El número de hilos debe ser <= %d \n",omp_get_max_threads());
		return -1;
	}


    /*The thread array is created*/
	pthread_t *hilosExec;
	/*Memory reservation for threads*/
	hilosExec = (pthread_t *)malloc(nthreads*sizeof(pthread_t));
	
	/*argument vector is created to be passed to the threads*/
	struct arg_struct argThreads[nthreads];

    /*Memory creation and reserce for each matrix*/
    Ma = memReserve(N); 
    Mb = memReserve(N);
    Mc = memReserve(N);
    initMatrix_DoublePointers (Ma, Mb, Mc, N);

    /*Matrices are printed if N is less than 4*/
    if (N<4){
        printf("Matriz A\n");
        printMatrix_DoublePointers (Ma, N);
        printf("Matriz B\n");
        printMatrix_DoublePointers (Mb, N);
    }
    sampleStart();

    /*Thread creation process*/
    for (int i = 0; i < nthreads; ++i){
        /*Argument assignment to struct*/
        argThreads[i].iDThread = i;
		argThreads[i].n = N;
		argThreads[i].NThreads = nthreads;
		argThreads[i].Ma = Ma;
		argThreads[i].Mb = Mb;
		argThreads[i].Mc = Mc;
        /*creation of thread*/
        pthread_create(&hilosExec[i],NULL,&multMM,(void *)&argThreads[i]);
    }
    /*function waits for the thread specified by thread to terminate*/
    for (int i = 0; i < nthreads; ++i){
        pthread_join(hilosExec[i],NULL);
    }
    sampleEnd();
    free(hilosExec);
    
    /*Matrices are printed if N is less than 4*/
    if (N<4){
        printf("Matriz C\n");
        printMatrix_DoublePointers (Mc, N);
    }

    return 0;
}