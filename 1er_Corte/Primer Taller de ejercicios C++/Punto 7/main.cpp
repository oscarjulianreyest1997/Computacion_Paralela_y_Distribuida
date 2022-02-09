/* 
Fecha: 09 de febrero de 2022
Autor: Oscar Julian Reyes Torres
Materia: Computación Paralela y Distribuida
Tema: Ejecucion Septimo Punto Taller
*/


#include <iostream>
using namespace std;

// Creación de una función que evalue serie

double serialEvaluation(int b, double x, double y){
	int a;
	double serial = 0;
	for(a = 0; a <= b ; a++){
		serial += 1/(x+a*y);
	}
	return serial;
}


//Implementación de una aplicacion que evalue la serie dada
int main(int argc, char** argv) {
	int b = 0;
	double x = 0, y = 0, serial = 0;
	
	cout << "\t ---------- Calculador de Series ---------- \n" << endl;
	
	do{
		cout <<"Digite el valor (mayor que cero ) hasta donde desea realizar la sumatoria (limite superior)" << endl;
		cin >> b;
	}while(b < 0);
	
	do{
		cout <<"Digite el valor de x (mayor que cero)" << endl;
		cin >> x;
	}while(x < 0);
	
	do{
		cout <<"Digite el valor de y (mayor que cero)" << endl;
		cin >> y;
	}while(y < 0);
	
	serial = serialEvaluation(b, x, y);
	cout << "La serie hasta el limite superior " << b << " es igual a: " << serial << endl;
	
}


