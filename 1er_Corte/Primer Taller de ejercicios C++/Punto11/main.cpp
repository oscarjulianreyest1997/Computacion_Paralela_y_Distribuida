/* 
Fecha: 09 de febrero de 2022
Autor: Oscar Julian Reyes Torres
Materia: Computación Paralela y Distribuida
Tema: Ejecucion Undecimo Punto Taller
*/

#include <stdio.h>  
#include <iostream>
#include <string>

using namespace std;

/*
Se requiereelaborar una aplicacion que calcule el importe a pagar para el caso de
una bicicleta, un moto, un vehiculo particular y un camion con un menú
*/

main(int argc, char** argv) {
	
	int opcion, km,tm,importe;
	
	std::string menu= std::string("\t ---------- SELECCIONE TIPO DE VEHICULO ---------- \n")+
				 std::string(" 1. Bicicleta \n")+
				 std::string(" 2. Moto \n")+
				 std::string(" 3. Coche \n")+
				 std::string(" 4. Camion \n")+
				 std::string(" 5. Salir \n");
	cout<<menu;
	cin>>opcion;
	
	while(opcion>5 || opcion<0){
		cout<<"\n La opcion seleccionada no existe \n\n: "<<menu;
		cin>>opcion;
	}
	
	switch(opcion) {
	   case 1  :
	      importe=100;
	      break; 
	   case 2  :
	   case 3  :
	   	  cout<<"Digite la cantidad de Kilometros: ";
	   	  cin>>km;
	   	  importe=30*km;
	      break; 
	    case 4:
	   	  cout<<"Digite la cantidad de Kilometros: ";
	   	  cin>>km;
		  cout<<"Digite la cantidad de Toneladas: ";
	   	  cin>>tm;	    	
	      importe= 30 * km + 25 * tm;
	      break;
	    case 5:
	      return 0;
	    	
	}
	cout<<" \n El importe total a pagar es: $"<<importe<<"\n";

}
