#ifndef FUNCIONES-TP_H
#define FUNCIONES-TP_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <cstring>
#include <windows.h>  // Necesario para la función Sleep en Windows

#define CANT_AVES 10
#define CANT_PIEDRAS 5
#define MAXIMO 20



using namespace std;
const int FILAS = 10;
const int COLUMNAS = 20;

struct Personaje {
	int posicionX;               // Posición en X
	int posicionY;               // Posición en Y
	bool miraHaciaDerecha;       // Dirección del movimiento
	int contadorDeMovimientos;   // Contador de movimientos realizados
	bool saltando;               // Indica si el personaje está saltando
};

struct fecha{
	int dia=0;
	int mes;
	int anio;
};

struct user{
	char nombre_usuario[11]={0};
	char clave[37];
	fecha ultimo_acceso;
};


void algoritmo1(); // algoritmo de Numeros de mala suerte (iterativa)
void algoritmo2(); // algoritmo de Numeros de mala suerte (recursiva)
void algoritmo3(); // algoritmo de Numeros Espiral (iterativa)
void algoritmo4(); // algoritmo de Numeros Espiral (recursiva)
long long recursiva4(long long n);
void simulacion1(); // algoritmo de simulacion de Mario y Luigi
void simulacion2();
void cargarObstaculos(char tablero[][MAXIMO], int tamanio_obstaculos[], bool tipo, int filas, int columnas);
bool disponible(char tablero[][MAXIMO], int x, int filas);
void cargarTablero(char tablero[][MAXIMO], int filas, int columnas);
bool numero_malasuerte(string n); // funcion iterativa de algoritmo 1
void numero_Ms_Recursivo(string &n); //funcion recursiva de algoritmo 2
void cargar_datos(user arr_usuarios[100]);	//Carga los datos desde un archivo binario
void invertir(char cadena[37]);
void cifrado(char cadena[37]);	//Junto con invertir, son el proceso de encriptado
int buscar(char usuario[11],user arr_usuarios[100]);	//Retorna posicion del usuario dentro del array (-1 si no esta)
bool requisitos(char user[11]);	//Verifica que se cumplan requisitos de nombre de usuario
bool requisitos_contrasenia(char password[37]);	//Verifica requisitos de contraseña
void crear_usuario(user arr_usuarios[100]);		//Crea un nuevo usuario
void nuevo_acceso(user arr_usuarios[100],int i);	//acttualiza las variables de fecha por las del momento del incio de sesion
void iniciar_sesion(user arr_usuarios[100]);		//Inicia sesion al usuario y actualiza su ultimo acceso
void guardar_datos(user arr_usuarios[100]);		//Sobrescribe el archivo con los datos actuales.
void mostrar_usuario(char usuario[12]);
void ejecutarSimulacion(char mundo[][20]);

#endif
