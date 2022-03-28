/************************************************************
* Fecha: 15 de marzo de 2022.
* Autor: Oscar Reyes
* Materia : Computación Paralela y Distribuida
* Tema: Implementación Posix (Library).
* Programa Principal para multiplicar 2 matrices sin 
* variables GLOBALES.
* Se requiere que el diseño sea modular.
* El modulo implementará las funeciones para 
* cálculo del producto de la matrix:
* 1. Creación de variables doble puntero para matrices principal GLOBAL
* 2. Función Reserva de Memoria para las matrices de doble puntero
* 3. Función de Inicialización de las matrices.
* 4. Función para el producto de matrices:
	Sea dividide la matriz A por porciones, a ser enviadas a cada hilo
	--> El número de hilos será enviada al ejecutar
	--> La dimensión de la matriz será enviada al ejecutar
* 5. La dimensión de la matriz siempre será cuadrada (NxN)
* 6. Se necesita función para impresión de matrices (doble puntero).	
************************************************************/

#include "modulo.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

/*Se declaran las variables globales para todo el programa*/
int N, Nthreads;
double **Ma, **Mb, **Mc;

/* Función a ser enviada a cada hilo, que realiza la multiplicaciòn de matrices.
 * La matrz A, se divide por porciones, en función de la dimensión y del número
 * de hilos que requiere el usuario.
 *
 * -Nota: La función será de tipo void, la cual regtornará un warning potencial de riesgo.
 * 	  Pensar en eso, para mejorarla*/ 

//arg.id, arg.N, arg.thread
void *multMM(void *arg){
	// arg: tiene el ID del hilo
	int i, j, k, idTh;
	int porcionSize, iniFila, finFila;
	double suma; // --- auxiliar para suma parcial
	
	//El arg es de tipo puntero vacio, y se castea a puntero entero 
	idTh = *(int *)(arg);
	//Se determina el tamaño de la porción de la matriz A a ser enviada a cada hilo
	porcionSize = N/Nthreads;
	//Se iguala el inicio de fila, segun el Id del Hilo
	iniFila = idTh*porcionSize;
	//Se pasa el fin de la fia, según el Id del Hilo
	finFila = (idTh+1)*porcionSize;
	
	for(i = iniFila;i < finFila; ++i){
		for(j = 0; j < N; ++j){
			suma = 0.0;
			for(k = 0; k < N; ++k){
				suma += Ma[i][k]*Mb[k][j];
			}
			Mc[i][j]=suma;
		}
	}
}


int main(int argc, char* argv[]){
	
	if(argc != 3){
		printf("./Exe N<dimMatriz> Nth<numHilos>");
		return -1;
	}
	
	//Se capturan las variables size y número de hilos*/
	N	 = atof(argv[1]);
	Nthreads = atof(argv[1]);
	
	
	//Se crea el pool de hilos
	pthread_t *hilosExec;
	//Se reserva memoria para los hilos
	hilosExec = (pthread_t *)malloc(Nthreads*sizeof(pthread_t));
	
	//Creación y reserva de Mem para cada Matriz
	Ma = ReservaMEM(N);
	Mb = ReservaMEM(N);
	Mc = ReservaMEM(N);
	
	//Se inicializan las matrices 
	IniciarMatriz(Ma,Mb,Mc,N);
	
	if(N < 4){
	  printf("Matriz A: \n");
	  printMatriz(Ma,N);
	  printf("Matriz B: \n");
	  printMatriz(Mb,N);
	 
	}
	
	//Se reparte la operación matematica a cada hilo
	//función pthread_create(&tinfo[tnum].thread_id, &attr, &thread_start, &tinfo[tnum]);
	void sampleStart();
	
	for(int i = 0; i < Nthreads; ++i){
		int *IDThread;
		IDThread = (int *)malloc(sizeof(int));
		*IDThread = i;
	pthread_create(&hilosExec[i], NULL, multMM , (void *) IDThread);
				
	}
	//Espero a que todos los hilos terminen 
	for(int i = 0; i < Nthreads; ++i){
		pthread_join(hilosExec[i],NULL);
	}
	
	void sampleEnd();
	free(hilosExec);	
	
	
	if(N < 4){
	  printf("Matriz C: \n");
	  printMatriz(Mc,N);
	}
		
	return 0;
}



















