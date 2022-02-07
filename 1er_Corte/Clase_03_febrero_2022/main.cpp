/* 
Fecha: 03 de febrero de 2022
Autor: Oscar Julian Reyes Torres
Materia: Computación Paralela y Distribuida
Tema: Construcción del primer Benchmark
Benchmark: Aplicación de juguete que permite evaluar rendimiento
		   de un aspecto en específico de la computadora
*/

#include <iostream>
#include <vector>
#include <random>


using namespace std;

/*Funcion Multipicación Matrices
	Se requiere multiplicar llas dos matrices: Adicionalmente 
	Los ingeniero deben verificar y Validar que realmente
	se cumpla el algoritmo de multiplicación

*/
vector<vector<double>> MultiMatriz(vector<vector<double>> Ma, 
								   vector<vector<double>> Mb){
	int i,j,k;
	vector<vector<double>> Mresultado(Ma.size(),vector<double>(Ma.size(),0));
	
	for(i=0;i<Ma.size();++i){
		for(j=0;j<Ma.size();++j){
			for(k=0;k<Ma.size();++k){
				Mresultado[i][j]+=Ma[i][k]*Mb[k][j];
			}
		}
	}
	return Mresultado;
	

}

// Función Inicialización: Se requiere inicializar las matrices con numeros aleatorios

	vector<vector<double>> InicializacionMatriz(vector<vector<double>> M){
	int i,j;
	float limInf = 0.001, limSup = 9.999;
	vector<vector<double>> Minicializada(M.size(), vector<double> (M.size(),0));
	random_device rd; //Se usa para inicializar la semila
	mt19937 gen(rd());
	uniform_real_distribution<> dis(limInf,limSup);

	for(i=0; i<M.size();++i){
		for(j=0; j<M.size();++j){			
	Minicializada[i][j] = dis(gen);
		}
	}
	
	return Minicializada;
		
	}

//Se crea la función oara imprimir matrices
void ImprimirMatriz(vector<vector<double>> M){
	int i,j;
	for(i=0; i<M.size();++i){
		for(j=0; j<M.size();++j){			
		cout << M[i][j] << " \t";
		}
		cout << "\n";
	}	
	
}

/* Se requiere implementar una aplicación que multiplique dos matrices.
   El algoritmo a usar sera el clásico (filas por columnas) */

int main(int argc, char** argv) {
	
	int i,j,k;
	int N = atoi(argv[1]);
	
	//Se usa la clase vector para crear las matrices.
	//Las matrices deben ser de doblre precisión
	
	vector<vector<double>> M1(N, vector<double> (N,0));
	vector<vector<double>> M2(N, vector<double> (N,0));
	vector<vector<double>> MR(N, vector<double> (N,0));

	
	M1 = InicializacionMatriz(M1);
	M2 = InicializacionMatriz(M2);
	

			
	
	//Se imprime M1
	cout << "Se imprime M1" << "\n";	
	ImprimirMatriz(M1);
	cout << "\n \n \n";
	
	//Se imprime M2	
	cout << "Se imprime M2" << "\n";
	ImprimirMatriz(M2);
	cout << "\n \n \n";
	
	
	
	//Se hace la multiplicación
	MR = MultiMatriz(M1,M2);
	//Se imprime MR	
	cout << "Se imprime MR" << "\n";
	ImprimirMatriz(MR);
	cout << "\n \n \n";
	
	
	
	return 0;
}
