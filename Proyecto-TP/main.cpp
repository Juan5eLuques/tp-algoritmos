#include <iostream>
#include <locale.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <cstring>
#include <windows.h>  // Necesario para la función Sleep en Windows

using namespace std;
#include "Funciones-TP.h"
extern int usuario_actual;	//Subindice del usuario iniciado
extern char nombre_actual[11]; 	//Nombre sin cifrar del usuario

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "spanish");
	
	bool ok=false;
	int numacceso;
	string stralg1 = "Se pide un numero 'n', luego en la funcion va recorriendo el numero hasta encontrar la combinacion 13, si la encuentra retorna true y muestra el mensaje que ese numero es de mala suerte, sino retorna false y muestra el mensaje que ese numero no es de mala suerte";;
	string stralg2 = "Se pide un numero 'n', luego en la funcion va recorriendo el numero, si encuentra un uno, y el numero siguiente es un 3, entonces corta la funcion y n es de mala suerte, sino pregunta si quedan valores por analizar, si quedan valores se llama a la funcion otra vez, y sino n no es de mala suerte";;
	string stralg3 = "Se pide un numero 'n', luego entra al bucle (si n es distinto de 1) y con 2 auxiliares (aux es para ir sumando los valores previos a aux2, cuando se lo alcanza a aux2, este se incrementa en 1 y aux vuelve a valer 1, todo esto si aux2 no es igual a n) va preguntando, si aux es menor a aux2 (aca se suma 2 veces el valor de aux) y si aux es igual aux2(se suma 1 vez el valor de aux y si aux2 es menor a n se incrementa, sino termina el bucle). Luego de esto muestra el numero espiral de n y termina el programa";
	string stralg4 = "Se pide un numero 'n', luego entra a la funcion 'recursiva', ahi pregunta, si n es igual a 1 , retorna 1, sino se suman 2 veces los valores previos a n y una vez el valor de n, luego retorna la suma más la funcion 'recursiva' pasandole como parametro n-1, cuando n sea iguala 1, retorna 1, se suman todos los valores y se devuelve esa suma a la funcion main, donde se mostrara el resultado";
	string inssim1 = "Super Mario Bros: Juegos y Simulaciones es un videojuego en el que Mario y Luigi deben rescatar a la Princesa Peach del Reino Champiñón, enfrentándose a obstáculos como aves y piedras. El juego se desarrolla en una matriz de 10x20, primero hay que encontrar las 11 aves y las 10 rocas o si lo deasea el usuario, al apretar 99 se veran todas las aves y rocas,luego comenzara la simulacion donde los personajes se mueven alternadamente, realizando acciones como caminar, girar, saltar o trepar. En la simulación de encuentro, ambos personajes comienzan en posiciones aleatorias y deben encontrarse en la misma celda, sorteando piedras en el camino. Al final, se cuenta el número de movimientos de cada uno para determinar al ganador.";
	
	
	while(!ok){
		
		system("cls");
		
		cout << "#######################################" << endl;
		cout << "#                                     #" << endl;
		cout << "#           Menú de acceso            #" << endl;
		cout << "#                                     #" << endl;
		cout << "      Usuario: ";
		if (usuario_actual == -1) {
			cout << "Invitado";
		} else {
			mostrar_usuario(nombre_actual);  // Aquí mostramos el nombre directamente
		}
		cout << "" << endl;
		
		cout << "#                                     #" << endl;
		cout << "#######################################" << endl;
		cout << endl;
		
		
		if (usuario_actual!= -1) {
			
		}
		else {
			cout << "1.- Registro" << endl;
			cout << "2.- Iniciar sesión" << endl;
		}
		cout << "3.- Algoritmos Numéricos" << endl;
		cout << "4.- Juego Super Mario Bros" << endl;
		cout << endl;
		cout << "9.- Salir de la aplicación" << endl;
		
		cout << "Ingrese una opción: ";
		cin >> numacceso;
		switch(numacceso){
		case 1:{
			user usuarios[100];
			
			cargar_datos(usuarios);
			system("cls");
			
			cin.ignore();
			crear_usuario(usuarios);
			
			guardar_datos(usuarios);
			system("cls");
		}
			break;
		case 2:{
			user usuarios[100];
			cargar_datos(usuarios);
			
			system("cls");
			cin.ignore();
			iniciar_sesion(usuarios);
			
			guardar_datos(usuarios);
			system("cls");
		}
			break;
		case 3:{
			bool ok2 = false;
			while(!ok2){
				
				system("cls");
				cout << "    Menú Algoritmos Numéricos " << endl;
				cout << endl;
				cout << "===============================" << endl;
				cout << endl;
				cout << "1.- Números de la mala suerte (Solución iterativa)" << endl;
				cout << "2.- Números de la mala suerte (Solución recursiva)" << endl;
				cout << "3.- Números Espiral (Solución iterativa)" << endl;
				cout << "4.- Números Espiral (Solución recursiva)" << endl;
				cout << endl;
				cout << "9.- Volver al menú principal" << endl;
				int numaccesoalg;
				cout << endl;
				cout << "    Ingrese una opción:"<< endl;
				
				bool ok3;
				int numaccesosubpro;
				cin >> numaccesoalg;
				switch(numaccesoalg){
					
					
				case 1:{ ok3=false;
				while(!ok3){
					system("cls");
					cout << "Algoritmo Números de la mala suerte (Solución iterativa)" << endl;
					cout << "===========================" << endl;
					cout << "1.- Ver definición" << endl;
					cout << "2.- Ejecutar" << endl;
					cout << endl;
					cout << "9.- Volver al menú anterior" << endl;
					cout << endl;
					cout << "Ingrese una opción:" << endl;
					cin >> numaccesosubpro;
					if(numaccesosubpro==1) {cout << stralg1 << endl; system("pause");} 
					else if(numaccesosubpro==2) algoritmo1();
					else if(numaccesosubpro==9){
						system("cls");
						ok3=true;
					}
					else cout << "Intente nuevamente" << endl;
					cout << endl;
				}
				system("cls");
				break;
				}
				
				case 2:{ ok3=false;
				while(!ok3){
					system("cls");
					cout << "Algoritmo Números de la mala suerte (Solución recursiva)" << endl;
					cout << "===========================" << endl;
					cout << "1.- Ver definición" << endl;
					cout << "2.- Ejecutar" << endl;
					cout << endl;
					cout << "9.- Volver al menú anterior" << endl;
					cout << endl;
					cout << "Ingrese una opción:" << endl;
					cin >> numaccesosubpro;
					if(numaccesosubpro==1){cout << stralg2 << endl; system("pause");} 
					else if(numaccesosubpro==2) {algoritmo2(); system("pause");}
					else if(numaccesosubpro==9){
						system("cls");
						ok3=true;
					}
					else cout << "Intente nuevamente" << endl;
					cout << endl;
				}
				system("cls");
				break;
				}
				
				
				case 3:{ ok3=false;
				while(!ok3){
					system("cls");
					cout << "Algoritmo Números Espiral (Solución iterativa)" << endl;
					cout << "===========================" << endl;
					cout << "1.- Ver definición" << endl;
					cout << "2.- Ejecutar" << endl;
					cout << endl;
					cout << "9.- Volver al menú anterior" << endl;
					cout << endl;
					cout << "Ingrese una opción:" << endl;
					cin >> numaccesosubpro;
					if(numaccesosubpro==1) {cout << stralg3 << endl; system("pause");}
					else if(numaccesosubpro==2) { algoritmo3(); system("pause");}
					else if(numaccesosubpro==9){
						system("cls");
						ok3=true;
					}
					else cout << "Intente nuevamente" << endl;
					cout << endl;
					
				}
				system("cls");
				break;
				}
				
				
				case 4:{ ok3=false;
				while(!ok3){
					system("cls");
					cout << "Algoritmo Números Espiral (Solución recursiva)" << endl;
					cout << "===========================" << endl;
					cout << "1.- Ver definición" << endl;
					cout << "2.- Ejecutar" << endl;
					cout << endl;
					cout << "9.- Volver al menú anterior" << endl;
					cout << endl;
					cout << "Ingrese una opción:" << endl;
					cin >> numaccesosubpro;
					if(numaccesosubpro==1) {cout << stralg4 << endl;system("pause");} 
					else if(numaccesosubpro==2) {algoritmo4();system("pause");} 
					else if(numaccesosubpro==9){
						system("cls");
						ok3=true;
					}
					else cout << "Intente nuevamente" << endl;
					cout << endl;
				}
				system("cls");
				break;
				}
				
				case 9: system("cls");
				ok2=true;
				}
			}
			break;
		}
			
			
			
		case 4:{bool ok4=false;
		bool ok5=false;
		while(!ok4){
			system("cls");
			cout << "Menú de Juego Super Mario Bros" << endl;
			cout << "==============================" << endl;
			cout << endl;
			cout << endl;
			cout << "1.- Simulación de encuentro entre Mario y Luigi" << endl;
			cout << "2.- Simulación de búsqueda de Princesa Peach" << endl;
			cout << endl;
			cout << "9.- Volver al menú anterior" << endl;
			cout << endl;
			cout << "Ingrese una opción:" << endl;
			int numaccesosmb;
			cin >> numaccesosmb;
			
			switch(numaccesosmb){
			case 1:{ok5=false;
			while(!ok5){
				system("cls");
				cout << "Juego Super Mario Bros - Simulación de encuentro entre Mario y Luigi" << endl;
				cout << "=====================================" << endl;
				cout << endl;
				cout << endl;
				cout << "1.- Ver instrucciones" << endl;
				cout << "2.- Jugar y simular" << endl;
				cout << endl;
				cout << "9.- Volver al menú anterior" << endl;
				cout << endl;
				cout << "Ingrese una opción:" << endl;
				int numaccesosmbpro;
				cin >> numaccesosmbpro;
				if(numaccesosmbpro==1){cout << inssim1 << endl;system("pause");}
				else if(numaccesosmbpro==2) simulacion1();
				else if(numaccesosmbpro==9){
					system("cls");
					ok5=true;
				}
			}
			system("cls");
			break;
			}
			
			case 2:{ok5=false;
			while(!ok5){
				system("cls");
				cout << "Juego Super Mario Bros - Simulación de búsqueda de Princesa Peach" << endl;
				cout << "=====================================" << endl;
				cout << endl;
				cout << endl;
				cout << "1.- Ver instrucciones" << endl;
				cout << "2.- Jugar y simular" << endl;
				cout << endl;
				cout << "9.- Volver al menú anterior" << endl;
				cout << endl;
				cout << "Ingrese una opción:" << endl;
				int numaccesosmbpro;
				cin >> numaccesosmbpro;
				if(numaccesosmbpro==1){cout << "En construccion..." << endl;system("pause");}
				else if(numaccesosmbpro==2){cout << "En construccion..." << endl;system("pause");}
				else if(numaccesosmbpro==9){
					system("cls");
					ok5=true;
				}
			}
			system("cls");
			break;
			}
			
			case 9: system("cls");
			ok4=true;
			}
		}
		break;
			}
		case 9: ok=true;
		break;
		default:system("cls");
		cout << "Intente nuevamente" << endl;
		}
		
		
		
	}
	return 0;
}


