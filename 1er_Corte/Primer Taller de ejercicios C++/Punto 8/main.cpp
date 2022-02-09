/* 
Fecha: 09 de febrero de 2022
Autor: Oscar Julian Reyes Torres
Materia: Computación Paralela y Distribuida
Tema: Ejecucion Octavo Punto Taller
*/

#include <iostream>
using namespace std;

// Función suma de fecha 
int sumFecha(int x, int y, int z){
	int sum = 0;
	sum = x + y + z;
	
return sum;
}


//Función para calcular número de tarot
int numTarot(int suma, int x){
	int num = 0;
	if(x == 1){
		while(suma/10 > 0){
			num += suma%10;
			if(suma%10 == 0){
				num += suma / 10;
			}
			suma /= 10;
		}
	}else{
		num += suma/10;
		num += suma%10;
	}
	
return num;
}


/*
Implementación de un programa que calcule el numero de tarot
*/

int main(int argc, char** argv) {
	int day, month, year, sum, tarot;
	cout <<"\t ------------------------ CALCULADORA DE NUMERO DE TAROT ------------------------ \n" << endl;
	
	do{
		cout << "Ingresa la fecha de nacimiento separada por espacios, por ejemplo: 10 12 2001" << endl;
		cin >> day >> month >> year;
	}while(day <= 0 || day > 31|| month <= 0 || month > 12 || year < 1900 || year > 2022);
	
	sum = sumFecha(day, month, year);
	
	tarot = numTarot(sum, 1);
	if(tarot > 9){
		tarot = numTarot(tarot, 0);
	}
	printf("Su numero de Tarot es: %d ", tarot);
	
}


