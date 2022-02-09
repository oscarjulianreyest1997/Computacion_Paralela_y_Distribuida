/* 
Fecha: 09 de febrero de 2022
Autor: Oscar Julian Reyes Torres
Materia: Computaci�n Paralela y Distribuida
Tema: Ejecucion Sexto Punto Taller
*/

#include <iostream>
using namespace std;

/*
Funci�n sumar los m�ltiplos de 5 entre un n�mero a 
y un n�mero b 
 */

int sumMultiplos(int a, int b){
	int i=0, sum =0;
	for(i = a; i <= b; i++){
		if(i%5 == 0){
			sum +=i;
		}
	}
	
	return sum;
}

/*
Se requiere implementar un programa que sume los 
n�meros multiplos de 5 de dos n�meros mayores a 0
*/

int main(int argc, char **argv) {
	cout <<"\t ----------- Calculadora de la suma de los multiplos de 5 entre dos numeros ----------- \n"<< "\n";
	int num1 = 0, num2 = 0, sum = 0;
	
	do{
		cout <<"Ingrese el primer numero mayor a 0"<< endl;
		cin >> num1;
	}while(num1 < 0);
	
	do{
	cout <<"Ingrese el segundo numero mayor a 0"<< endl;
		cin >> num2;
	}while(num2 < 0);
	
	if(num1 < num2){
		sum = sumMultiplos(num1, num2);
		cout << "\n Suma de los multiplos de 5 entre " << num1 << " y " << num2 << " es igual a: " << sum << endl;
	}else{
		sum = sumMultiplos(num2,num1);
		cout << "\n Suma de los multiplos de 5 entre " << num2 << " y " << num1 << " es igual a: " << sum << endl;
	}
		
}


	


