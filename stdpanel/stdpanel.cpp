#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include "stdpanel.h"

#define CANT_AVES 10
#define CANT_PIEDRAS 5

using namespace std;

void cargarObstaculos(char tablero[][MAXIMO], int tamanio_obstaculos[], bool tipo, int filas, int columnas);
bool disponible(char tablero[][MAXIMO], int x, int filas);

void cargarTablero(char tablero[][MAXIMO], int filas, int columnas){
	
	srand(time(NULL));
	
	int aves[CANT_AVES];
	for(int i=0; i < CANT_AVES; i++) aves[i]=1;
	int piedras[CANT_PIEDRAS] = {3,3,2,2,1};
	
	
	// Se inicializa el tablero con caracteres vacios en todas las posiciones
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			tablero[i][j] = ' ';
		}
	}
	
	cargarObstaculos(tablero, aves, 0, filas, columnas);
	cargarObstaculos(tablero, piedras, 1, filas, columnas);
	
}

void cargarObstaculos(char tablero[][MAXIMO], int tamanio_obstaculos[], bool tipo, int filas, int columnas){
	
	// CONVENCION VALORES variable tipo (booleana):
	// 0- Ave
	// 1- Piedra
	
	bool listo;
	int i,j,inicio,fin;
	
	char simbolo_obstaculo = (tipo) ? 'X' : '^';
	int cantidad_obstaculos = (tipo) ? CANT_PIEDRAS : CANT_AVES;
	
	
	for(int x=0;x<cantidad_obstaculos;x++)
	{
		listo=false;
		
		do //do-while para intentar colocar obstaculo a partir de una posicion x e y aleatorias en el tablero
		{
			
			i = (tipo) ? 9:(rand()%3); // si el obstaculo es un ave, toma cualquier valor entre entre 0 y 2 en la matriz. en cualquier otro caso toma valor 9 (suelo).
			j = rand()%columnas; // posicion j aleatoria, el obstaculo puede estar en cualquier posicion de j
			
			
			if (not tipo){ // si es un ave...
				if (tablero[i][j]==' '){ // posicion disponible
					tablero[i][j] = simbolo_obstaculo;
					listo = true;
				}
			}
			
			else if(disponible(tablero, j, filas)){
				// Defino el final de las posiciones a chequear para saber si puedo
				// introducir el obstaculo en el rango necesario.
				
				inicio = 9-tamanio_obstaculos[x]+1;
				fin = 9;
				for(int y=inicio; y<=fin; y++){
					tablero[y][j]=simbolo_obstaculo;
				}
				
				listo = true;
				
			}
			
		}
		while(!listo); // Si no se pudo colocar el obstaculo en la posicion aleatoria generada, se vuelve a intentar con un nuevo par i e j.
	}
	
}
	
bool disponible(char tablero[][MAXIMO], int j, int filas){
	
	bool previa_disponible = (j>0) ? tablero[filas-1][j-1] == ' ' : false; // hay piedra en la posicion previa? si j==0, no puede haber una piedra alli (enunciado)
	bool siguiente_disponible = (j<19) ? tablero[filas-1][j+1] == ' ' : false; // hay piedra en la posicion siguiente? si j==19, no puede haber una piedra alli (enunciado)
	bool actual_disponible = tablero[filas-1][j] == ' ';
	
	return actual_disponible and previa_disponible and siguiente_disponible;
	
}
