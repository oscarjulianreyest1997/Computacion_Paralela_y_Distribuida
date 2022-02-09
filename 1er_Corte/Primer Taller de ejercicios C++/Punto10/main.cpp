/* 
Fecha: 09 de febrero de 2022
Autor: Oscar Julian Reyes Torres
Materia: Computaci�n Paralela y Distribuida
Tema: Ejecucion Decimo Punto Taller
*/

#include <iostream>
using namespace std;

//Funcion de busqueda de centros num�ricos
void searchCenters(int n){

/*Se declaran variables para suma de n�meros anteriores al centro y posteriores
al centro */ 
	int sumBefore = 0, sumAfter = -1, center = 1;

	do{
		for (int i = 1; i < center; i++){
		sumBefore += i;
		}
		for (int j = center+1; j <= center*2; j++){
			if(sumBefore == sumAfter){
				cout << "El numero " << center << " es un centro numerico" << endl;
				break;
			}else{
				sumAfter += j;
			}
		}
		center++;
		sumBefore=0;
		sumAfter=0;
	}while (center <=n);
}


//Se requiere la implementaci�n de una aplicaci�n que calcule los centros num�ricos entre 1 y n

int main(int argc, char** argv) {
	int n;
	cout << "\t --------CALCULADORA DE NUMEROS CENTROS -------- \n" << endl;
	do{
		cout << "Digite un numero mayor que 1" << endl;
		cin >> n;
	}while(n<1);
	searchCenters(n);	
}




