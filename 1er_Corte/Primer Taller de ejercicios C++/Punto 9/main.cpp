/* 
Fecha: 09 de febrero de 2022
Autor: Oscar Julian Reyes Torres
Materia: Computación Paralela y Distribuida
Tema: Ejecucion Noveno Punto Taller
*/

#include <iostream>
using namespace std;

//Función para imprimir triangulo
void printtriangle (int numfilas){
	int i, j, k, z, espacios;
	
	espacios = numfilas-1;
	
	for(i = 1; i <=numfilas; i++){
		for(j = 0; j < espacios; j++){
			cout << " ";
		}
		for(k = i; k <=(i*2)-1; k++){
			cout << k%10;
		}
		for(z = (i*2)-1; z > i; z--){
			cout << (z-1)%10;
		}
		cout << endl;
		espacios--;
	}
	
}


// Se requiere implementar una aplicación que genere la secuencia de digitos mostrados
int main(int argc, char** argv) {
	int numfilas;
	do{
	cout<<"Digite el numero de filas de la piramide, entre 11 y 20" << endl;
	cin>>numfilas;
	}while(numfilas < 11 || numfilas > 20);
	
	printtriangle(numfilas);
	return 0;
}
