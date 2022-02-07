/* 
Fecha: 01 de febrero de 2022
Autor: Oscar Julian Reyes Torres
Materia: Computación Paralela y Distribuida
Tema: Presentación de tipo de datos disponibles en C++
*/


/* Se declaran las interfacez */
#include <iostream>
#define SIZEBITES(X) sizeof(X)*8 // Definición funcion lambda para calculo de bites
using namespace std;



int main() {
	cout << "========================================================================================="<< endl;
	cout << "|	Type 		|		Meaning		|      Bytes	|      bites	|" << endl;
	cout << "========================================================================================="<< endl;
	cout << "|	bool		|	boolean			|	 "	<< sizeof(bool) << "	|	 "<<SIZEBITES(bool)<< "	|"<< endl;		
	cout << "|	char		|	Character		|	 "	<< sizeof(char) << "	|	 "<<SIZEBITES(char)<< "	|"<< endl;	
	cout << "|	wchar_t		|	Wide Character		|	 "	<< sizeof(wchar_t) << "	|	"<<SIZEBITES(wchar_t)<< "	|"<< endl;	
	cout << "|	char16_t	|	UniCode Character	|	 "	<< sizeof(char16_t) << "	|	"<<SIZEBITES(char16_t)<< "	|"<< endl;
	cout << "|	char32_t	|	UniCode Character	|	 "	<< sizeof(char32_t) << "	|	"<<SIZEBITES(char32_t)<< "	|"<< endl;	
	cout << "|	short		|	Short Integer		|	 "	<< sizeof(short) << "	|	"<<SIZEBITES(short)<< "	|"<< endl;	
	cout << "|	int		|	Integer			|	 "	<< sizeof(int) << "	|	"<<SIZEBITES(int)<< "	|"<< endl;
	cout << "|	long		|	Long Integer		|	 "	<< sizeof(long) << "	|	"<<SIZEBITES(long)<< "	|"<< endl;		
	cout << "|	long long	|	Long Long Integer	|	 "	<< sizeof(long long) << "	|	"<<SIZEBITES(long long)<< "	|"<< endl;	
	cout << "|	float		|Single Precision Floating Point|	 "	<< sizeof(float) << "	|	"<<SIZEBITES(float)<< "	|"<< endl;
	cout << "|	double		|Double Precision Floating Point|	 "	<< sizeof(double) << "	|	"<<SIZEBITES(double)<< "	|"<< endl;
	cout << "|	long double	|Extend Precision Floating Point|	"	<< sizeof(long double) << "	|      "<<SIZEBITES(long double)<< "	|"<< endl;
	cout << "========================================================================================="<< endl;
					
	
	return 0;
}
