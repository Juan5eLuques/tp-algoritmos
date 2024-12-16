#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <cstring>

#define CANT_AVES 10
#define CANT_PIEDRAS 5
#define MAXIMO 20

using namespace std;

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
long long recursiva4(long long n); //funcion recursiva para algoritmo 4
void simulacion1(); // algoritmo de simulacion de Mario y Luigi
void simulacion2();
void cargarObstaculos(char tablero[][MAXIMO], int tamanio_obstaculos[], bool tipo, int filas, int columnas);
bool disponible(char tablero[][MAXIMO], int x, int filas);
void cargarTablero(char tablero[][MAXIMO], int filas, int columnas);
bool numero_malasuerte(string n); // funcion iterativa de algoritmo 1
unsigned long long irecursiva=0; bool uno_2=false; bool malasuerte = false; //variables para la funcion recursiva de algoritmo 2
void numero_Ms_Recursivo(string &n); //funcion recursiva de algoritmo 2
int usuario_actual =-1;	//Subindice del usuario iniciado
char nombre_actual[11]; 	//Nombre sin cifrar del usuario
void cargar_datos(user arr_usuarios[100]);	//Carga los datos desde un archivo binario
void invertir(char cadena[37]);
void cifrado(char cadena[37]);	//Junto con invertir, son el proceso de encriptado
int buscar(char usuario[11],user arr_usuarios[100]);	//Retorna posicion del usuario dentro del array (-1 si no esta)
bool requisitos(char user[11]);	//Verifica que se cumplan requisitos de nombre de usuario
bool requisitos_contrasenia(char password[37]);	//Verifica requisitos de contrase�a
void crear_usuario(user arr_usuarios[100]);		//Crea un nuevo usuario
void nuevo_acceso(user arr_usuarios[100],int i);	//acttualiza las variables de fecha por las del momento del incio de sesion
void iniciar_sesion(user arr_usuarios[100]);		//Inicia sesion al usuario y actualiza su ultimo acceso
void guardar_datos(user arr_usuarios[100]);		//Sobrescribe el archivo con los datos actuales.


int main(int argc, char *argv[]) {
	bool ok=false;
	int numacceso;
	string stralg1 = "Se pide un numero 'n', luego en la funcion va recorriendo el numero hasta encontrar la combinacion 13, si la encuentra retorna true y muestra el mensaje que ese numero es de mala suerte, sino retorna false y muestra el mensaje que ese numero no es de mala suerte";
	string stralg2 = "Se pide un numero 'n', luego en la funcion va recorriendo el numero, si encuentra un uno, y el numero siguiente es un 3, entonces corta la funcion y n es de mala suerte, sino pregunta si quedan valores por analizar, si quedan valores se llama a la funcion otra vez, y sino n no es de mala suerte";
	string stralg3 = "Se pide un numero 'n', luego entra al bucle (si n es distinto de 1) y con 2 auxiliares (aux es para ir sumando los valores previos a aux2, cuando se lo alcanza a aux2, este se incrementa en 1 y aux vuelve a valer 1, todo esto si aux2 no es igual a n) va preguntando, si aux es menor a aux2 (aca se suma 2 veces el valor de aux) y si aux es igual aux2(se suma 1 vez el valor de aux y si aux2 es menor a n se incrementa, sino termina el bucle). Luego de esto muestra el numero espiral de n y termina el programa";
	string stralg4 = "Se pide un numero 'n', luego entra a la funcion 'recursiva', ahi pregunta, si n es igual a 1 , retorna 1, sino se suman 2 veces los valores previos a n y una vez el valor de n, luego retorna la suma m�s la funcion 'recursiva' pasandole como parametro n-1, cuando n sea iguala 1, retorna 1, se suman todos los valores y se devuelve esa suma a la funcion main, donde se mostrara el resultado";
	
	
	
	while(!ok){
	
	cout << "    Men� de acceso " << endl;
	cout << endl;
	cout << "===============================" << endl;
	cout << endl;
	cout << "1.- Registro" << endl;
	cout << "2.- Iniciar sesi�n" << endl;
	cout << "3.- Algoritmos Num�ricos" << endl;
	cout << "4.- Juego Super Mario Bros" << endl;
	cout << endl;
	cout << "9.- Salir de la aplicaci�n" << endl;
	cout << "    Ingrese una opci�n:"<< endl;
	cin >> numacceso;
	switch(numacceso){
	case 1:{
		user usuarios[100];
	
	cargar_datos(usuarios);
	char n; 
	do{
		cout << "Ingrese opcion deseada: " << endl;
		cout << "-----------------------" << endl;
		cout << "1 - crear usuario " << endl;
		cout << "9 - salir " << endl;
		cin >> n;
		cin.ignore();
		switch(n){
		case '1': crear_usuario(usuarios); break;
		case '9': cout << "saliendo..." << endl;
		break;
		default: break;
		}
		
	}while(n!='9');
	
	guardar_datos(usuarios);
	system("cls");
	}
		break;
	case 2:{
		user usuarios[100];
		cargar_datos(usuarios);
		char n; 
		do{
			cout << "Ingrese opcion deseada: " << endl;
			cout << "-----------------------" << endl;
			cout << "1 - iniciar sesion " << endl;
			cout << "9 - salir " << endl;
			cin >> n;
			cin.ignore();
			switch(n){
			case '1': iniciar_sesion(usuarios); break;
			case '9': cout << "saliendo..." << endl;
			break;
			default: break;
			}
			
		}while(n!='9');
		
		guardar_datos(usuarios);
		system("cls");
	}
		break;
	case 3:{
		bool ok2 = false;
		while(!ok2){
			
			system("cls");
		cout << "    Men� Algoritmos Num�ricos " << endl;
		cout << endl;
		cout << "===============================" << endl;
		cout << endl;
		cout << "1.- N�meros de la mala suerte (Soluci�n iterativa)" << endl;
		cout << "2.- N�meros de la mala suerte (Soluci�n recursiva)" << endl;
		cout << "3.- N�meros Espiral (Soluci�n iterativa)" << endl;
		cout << "4.- N�meros Espiral (Soluci�n recursiva)" << endl;
		cout << endl;
		cout << "9.- Volver al men� principal" << endl;
		int numaccesoalg;
		cout << endl;
		cout << "    Ingrese una opci�n:"<< endl;
		
		bool ok3;
		int numaccesosubpro;
		cin >> numaccesoalg;
		switch(numaccesoalg){
			
			
		case 1:{ ok3=false;
		while(!ok3){
			
			cout << "Algoritmo N�meros de la mala suerte (Soluci�n iterativa)" << endl;
			cout << "===========================" << endl;
			cout << "1.- Ver definici�n" << endl;
			cout << "2.- Ejecutar" << endl;
			cout << endl;
			cout << "9.- Volver al men� anterior" << endl;
			cout << endl;
			cout << "Ingrese una opci�n:" << endl;
			cin >> numaccesosubpro;
			if(numaccesosubpro==1) cout << stralg1 << endl;
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
			
			cout << "Algoritmo N�meros de la mala suerte (Soluci�n recursiva)" << endl;
			cout << "===========================" << endl;
			cout << "1.- Ver definici�n" << endl;
			cout << "2.- Ejecutar" << endl;
			cout << endl;
			cout << "9.- Volver al men� anterior" << endl;
			cout << endl;
			cout << "Ingrese una opci�n:" << endl;
			cin >> numaccesosubpro;
			if(numaccesosubpro==1) cout << stralg2 << endl;
			else if(numaccesosubpro==2) algoritmo2();
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
			cout << "Algoritmo N�meros Espiral (Soluci�n iterativa)" << endl;
			cout << "===========================" << endl;
			cout << "1.- Ver definici�n" << endl;
			cout << "2.- Ejecutar" << endl;
			cout << endl;
			cout << "9.- Volver al men� anterior" << endl;
			cout << endl;
			cout << "Ingrese una opci�n:" << endl;
			cin >> numaccesosubpro;
			if(numaccesosubpro==1) cout << stralg3 << endl;
			else if(numaccesosubpro==2) algoritmo3();
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
			cout << "Algoritmo N�meros Espiral (Soluci�n recursiva)" << endl;
			cout << "===========================" << endl;
			cout << "1.- Ver definici�n" << endl;
			cout << "2.- Ejecutar" << endl;
			cout << endl;
			cout << "9.- Volver al men� anterior" << endl;
			cout << endl;
			cout << "Ingrese una opci�n:" << endl;
			cin >> numaccesosubpro;
			if(numaccesosubpro==1) cout << stralg4 << endl;
			else if(numaccesosubpro==2) algoritmo4();
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
		cout << "Men� de Juego Super Mario Bros" << endl;
		cout << "==============================" << endl;
		cout << endl;
		cout << endl;
		cout << "1.- Simulaci�n de encuentro entre Mario y Luigi" << endl;
		cout << "2.- Simulaci�n de b�squeda de Princesa Peach" << endl;
		cout << endl;
		cout << "9.- Volver al men� anterior" << endl;
		cout << endl;
		cout << "Ingrese una opci�n:" << endl;
		int numaccesosmb;
		cin >> numaccesosmb;
		
		switch(numaccesosmb){
		case 1:{ok5=false;
		while(!ok5){
			cout << "Juego Super Mario Bros - Simulaci�n de encuentro entre Mario y Luigi" << endl;
			cout << "=====================================" << endl;
			cout << endl;
			cout << endl;
			cout << "1.- Ver instrucciones" << endl;
			cout << "2.- Jugar y simular" << endl;
			cout << endl;
			cout << "9.- Volver al men� anterior" << endl;
			cout << endl;
			cout << "Ingrese una opci�n:" << endl;
			int numaccesosmbpro;
			cin >> numaccesosmbpro;
			if(numaccesosmbpro==1);
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
			
			cout << "Juego Super Mario Bros - Simulaci�n X" << endl;
			cout << "=====================================" << endl;
			cout << endl;
			cout << endl;
			cout << "1.- Ver instrucciones" << endl;
			cout << "2.- Jugar y simular" << endl;
			cout << endl;
			cout << "9.- Volver al men� anterior" << endl;
			cout << endl;
			cout << "Ingrese una opci�n:" << endl;
			int numaccesosmbpro;
			cin >> numaccesosmbpro;
			if(numaccesosmbpro==1);
			else if(numaccesosmbpro==2);
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
	cout << "Intente nuevamente" << endl << endl;
	cout << "==================" << endl << endl;
	}
	
	
	
	}
	return 0;
}









void cargar_datos(user arr_usuarios[100]){
	ifstream archivo;
	archivo.open("Usuarios.bin");
	//Verifico apertura del archivo
	if(!archivo){
		cout << "Error de apertura del archivo Usuarios";
		return;
	}
	if(!archivo.eof()){
		archivo.read((char*)(arr_usuarios),sizeof(arr_usuarios[100]));
	}
}
	void invertir(char cadena[37]){
		int n = strlen(cadena);
		for(int i=0;i<n/2;i++){
			swap(cadena[i],cadena[n-1-i]);
		}
	}
		void cifrado(char cadena[37]){
			int n = strlen(cadena);
			for(int i=0;i<n;i++){
				if(cadena[i] >= 'A' and cadena[i] <= 'z'){
					cadena[i] += 3;
				}
			}
			invertir(cadena);
			for(int i= int(n/2);i<n;i++){
				cadena[i] -= 1;		
			}
		}
			int buscar(char usuario[11],user arr_usuarios[100]){
				int i=0;
				while(arr_usuarios[i].nombre_usuario[0] != 0){	//Busco hasta llegar al ultimo elemento
					if(strcmp(arr_usuarios[i].nombre_usuario,usuario)==0){
						return i;	//Retorno la posicion
					}
					i++;
				}
				return -1;	//Si no lo encuentra
			}
				bool requisitos_usuario(char user[100]){
					int n = strlen(user);
					if(n>=6 and n<=10){	//Primero verifico tama�o
						if(user[0]>='a' and user[0]<='z'){ //Verifico la minuscula inicial
							int dig=0;int may=0;
							for(int i=1;i<n;i++){	//Recorro string contando mayusculas y digitos
								if(isupper(user[i])){ may++;}
								if(isdigit(user[i])){ dig++;}
								
							}
							if(may>=2 and dig<=3){
								return true;
							}else{
								cout << "No cumple con la cantidad de mayusculas o digitos requerida" << endl;
							}
						}else{
							cout << "No cumple con la minuscula inicial" << endl;
						}
					}else{
						cout << "No cumple con el tama�o minimo o maximo" << endl;
					}
					return false;
				}	
					bool requisitos_contrasenia(char password[100]){
						int n = strlen(password);
						if(n>=6 and n<=32){	//verifico tama�o
							bool may=false,min=false,num=false;
							for(int i=0;i<n;i++){	//Recorro string y verifico requisitos
								if(isupper(password[i])){may=true;}
								if(islower(password[i])){min=true;}
								if(isdigit(password[i])){num=true;}
								//Para caracteres de puntuacion
								if(ispunct(password[i]) or (password[i]>='�' and password[i]<='�') or isspace(password[i])){
									return false;
								}
							}
							if(may and min and num){
								return true;
							}
						}
						return false;
					}
						void crear_usuario(user arr_usuarios[100]){
							char usuario_2[100], usuario[11];
							
							cout << endl << "Ingrese a continuacion su nombre de usuario respetando las siguientes normas: " << endl;
							cout << "-----------------------------------------------------------------------------" << endl;
							cout << "-Entre 6 y 10 caracteres" << endl;
							cout << "-Comenzar con una letra minuscula" << endl;
							cout << "-Tener minimo 2 mayusculas" << endl;
							cout << "-Maximo 3 digitos" << endl << endl;
							//Leo nombre de usuario verificando que cumpla requisitos o no este repetido
							bool reintentar;
							do{
								reintentar = false;
								cin.getline(usuario_2,100);
								
								if(!requisitos_usuario(usuario_2)){
									cout << "Por favor, intente de nuevo!" << endl << endl;
									reintentar = true;
								}else{
									strcpy(usuario,usuario_2);	//Paso los datos a una variable con el formato del struct
									cifrado(usuario);
									if(buscar(usuario,arr_usuarios)!=-1){	//Busco al usuario cifrado, ya que se guardan cifrados
										cout << "Nombre de usuario ya registrado, vuelva a intentar!" << endl;
										reintentar = true;
									}
								}
							}while(reintentar);
							//Ahora lo mismo pero con la contrase�a
							char password[100];	//Utilizo 100 para aceptado en beecrowd
							cout << endl << "Nombre de usuario valido. Ahora Ingrese su contrase�a respetando las siguientes normas: " << endl;
							cout << "-Entre 6 y 32 caracteres" << endl;
							cout << "-Al menos una mayuscula, minuscula y digito" << endl;
							cout << "-Ningun caracter de puntuacion, con acento o espacios" << endl;
							do{
								reintentar = false;
								cin.getline(password,100);
								if(!requisitos_contrasenia(password)){
									cout << "Requisitos incumplidos, intente de nuevo!" << endl;
									reintentar = true;
								}
							}while(reintentar);
							// convierto password a char[37] para adaptarlo al formato en el struct
							char contrasenia[37];
							strcpy(contrasenia,password);
							//pido reingreso
							cout << "Contrase�a valida. Por favor Reingrese la contrase�a para confirmar: " << endl;
							cin.getline(password,100);
							//Cierro la funcion si la contrase�a no coincide
							if(strcmp(contrasenia,password) != 0){
								cout << "Las contrase�as no coinciden. Volviendo al menu..." << endl;
								return;
							}
							cout << "Contrase�a confirmada. Registrando usuario..." << endl;
							//Encripto contrasenia para guardado, usuario ya se cifro antes
							cifrado(contrasenia);
							//Guardamos en struct
							int i=0;
							while(arr_usuarios[i].nombre_usuario[0] != 0){	//Busco la primera posicion vacia
								i++;
							}
							//Relleno con los datos
							strcpy(arr_usuarios[i].nombre_usuario,usuario);
							strcpy(arr_usuarios[i].clave,contrasenia);
							cout << "Usuario registrado exitosamente!" << endl;
							cout << "Iniciando proceso de inicio de sesion...";
							iniciar_sesion(arr_usuarios);
						}
							void nuevo_acceso(user arr_usuarios[100],int i){
								time_t t = time(nullptr);
								tm *tiempo = localtime(&t);
								
								arr_usuarios[i].ultimo_acceso.dia = tiempo->tm_mday;
								arr_usuarios[i].ultimo_acceso.mes = tiempo->tm_mon + 1;
								arr_usuarios[i].ultimo_acceso.anio = tiempo->tm_year + 1900;
							}
								void iniciar_sesion(user arr_usuarios[100]){
									char usuario_2[100], usuario[11],contrasenia_2[100],contrasenia[37],usuario_3[11];
									int intentos=0;
									do{
										cout << endl << "Ingrese su nombre de Usuario: " << endl;
										cin.getline(usuario_2,100);
										//primero verifico que el usuario ingresado cumpla requisitos
										if(requisitos_usuario(usuario_2)){
											//Ahora lo cifro y procedo a buscarlo en la base de datos
											strcpy(usuario,usuario_2);
											strcpy(usuario_3,usuario_2);
											cifrado(usuario);
											int i = buscar(usuario,arr_usuarios);
											if(i !=-1){
												//Si buscar usuario me retorno un indice, es decir que lo encontro, verifico contrasenia
												cout << endl << "Ahora ingrese la contrase�a: " << endl;
												bool salir=false;
												do{
													cin.getline(contrasenia_2,100);
													if(requisitos_contrasenia(contrasenia_2)){	//Verifico requisitos de clave
														strcpy(contrasenia,contrasenia_2);
														cifrado(contrasenia);	//Cifro y busco la contrase�a para compararlas
														if(strcmp(arr_usuarios[i].clave,contrasenia)==0){
															usuario_actual = i;
															salir = true; break;	//Guardo el indice del usuario iniciado para acceder a sus datos cuando quiera y corto el while;
														}else{
															cout << "Contrase�a incorrecta, ";
														}
													}else{
														cout << "Contrase�a no cumple requisitos, ";
													}
													cout << "Vuelva a ingresarla:" << endl;
													intentos++;
												}while(intentos<3);
												if(salir){break;}else{
													cout << endl << "Le quedan 0 intentos!!" << endl; break;
												}
											}else{
												cout << "Nombre de usuario no encontrado" << endl;
											}
										}else{
											cout << "Nombre de usuario no cumple con los requisitos" << endl;
										}
										
										cout << endl << "Le quedan " << (2-intentos) << " intentos!!" << endl;
										intentos++;
									}while(intentos<3);
									//Si no inicio ningun usuario, se quedo sin intentos
									if(usuario_actual== -1){	
										cout << "Ya no le quedan mas intentos.Por razones de seguridad se finaliza la ejecucion de iniciar sesion" << endl << endl;
									}else{
										int j = usuario_actual;
										strcpy(nombre_actual,usuario_3);
										cout << endl << "Inicio de sesion exitoso, Bienvenido " << usuario_3 << "!" << endl;
										cout << "-----------------------------------------------" << endl;
										if(arr_usuarios[j].ultimo_acceso.dia == 0){	//Primera vez accediendo
											cout << "Parece que es la primera vez que accedes a tu cuenta!!" << endl << endl;
											nuevo_acceso(arr_usuarios,j);
										}else{
											cout << "Parece que la ultima vez que accediste a tu cuenta fue el " << arr_usuarios[j].ultimo_acceso.dia;
											cout << "/" << arr_usuarios[j].ultimo_acceso.mes << "/" << arr_usuarios[j].ultimo_acceso.anio << endl << endl;
											nuevo_acceso(arr_usuarios,j);
										}
									}
								}
									void guardar_datos(user arr_usuarios[100]){
										ofstream archivo;
										archivo.open("Usuarios.bin");
										//Verifico apertura del archivo
										if(!archivo){
											cout << "Error de apertura del archivo Usuarios";
											return;
										}
										archivo.write((char*)(arr_usuarios),sizeof(arr_usuarios[100]));
									}

void algoritmo1(){
	string n; cin >> n;
	if(numero_malasuerte(n)){
	cout << n << " es de Mala Suerte" << endl;
	}
	else{
	cout << n << " NO es de Mala Suerte" << endl;
	}
}
	bool numero_malasuerte(string n){
		bool uno = false;
		unsigned long long i=0;
		//leo el numero como string y lo recorro hasta el final o hasta leer el 13
		while(i<n.size()){	
			if (n[i] == '1'){
				uno = true;
			}
			else{
				if(uno and n[i]=='3'){
					return true;
				}
				else{
					uno = false;
				}
			}
			i++;	//avanzo en el string
		}
		return false;
	}
		
		
void algoritmo2(){
		string n; cin >> n;
		numero_Ms_Recursivo(n);
	}
		
	void numero_Ms_Recursivo(string &n){
		//Verificacion de numero
		if(n[irecursiva]=='1'){
			uno_2=true;
		}else{
			if(uno_2 and n[irecursiva]=='3'){
				malasuerte = true;
			}else{
				uno_2 = false;
			}
		}
		//Corto la funcion si llegue al numero
		if(malasuerte){
			cout << n << " es de Mala Suerte" << endl;
			irecursiva=0;uno_2=false;malasuerte=false;	//Reseteo
			return;
		}else{	//Vuelvo a invocar si todavia queda numero por mirar, en caso de no corto
			if(irecursiva<n.size()){
				irecursiva++;
				numero_Ms_Recursivo(n);
			}else{
				cout << n << " NO es de Mala Suerte" << endl;
				irecursiva=0;uno_2=false;malasuerte=false;	//Reseteo
				return;
			}
		}
	}
		

void algoritmo3(){
	long long n,aux=1,aux2=2,suma=1;
	cin >> n;
	if(n!=1){
		bool ok=false;
		while(!ok){//hasta que aux no sea igual a n no para
			if(aux<aux2){
				suma+=aux*2;
				aux++;
			}
			if(aux==aux2){
				suma+=aux;
				if(aux2<n){
					aux2++;//incrementa el tope
					aux=1;//reseteo aux
				}
			}
			if(aux==n) ok=true;
		}
	}
	cout << suma << endl;	
}
	
	void algoritmo4(){
		long long n;
		cin >> n;
		long long suma=recursiva4(n);
		cout << suma << endl;
	}
		
		long long recursiva4(long long n){
			if(n==1) return 1;
			else{
				long long aux=n-1,suma=n;
				while(aux!=0){
					suma+=aux*2;
					aux--;
				}
				return suma + recursiva4(n-1);
			}
		}
			
			void cargarTablero(char tablero[][MAXIMO], int filas, int columnas){
				
				srand(time(NULL));
				
				int aves[CANT_AVES];
				for(int i=0; i < CANT_AVES; i++) aves[i]=1;
				int piedras[CANT_PIEDRAS] = {3,3,2,2,1};
				
				
				for(int i=0;i<filas;i++){
					for(int j=0;j<columnas;j++){
						tablero[i][j] = ' ';
					}
				}
				
				cargarObstaculos(tablero, aves, 0, filas, columnas);
				cargarObstaculos(tablero, piedras, 1, filas, columnas);
				
			}
				
				void cargarObstaculos(char tablero[][MAXIMO], int tamanio_obstaculos[], bool tipo, int filas, int columnas){
					
					bool listo;
					int i,j,inicio,fin;
					
					char simbolo_obstaculo = (tipo) ? 'X' : '^';
					int cantidad_obstaculos = (tipo) ? CANT_PIEDRAS : CANT_AVES;
					
					
					for(int x=0;x<cantidad_obstaculos;x++)
					{
						listo=false;
						
						do 
						{
							
							i = (tipo) ? 9:(rand()%3); 
							j = rand()%columnas; 
							
							
							if (not tipo){ 
								if (tablero[i][j]==' '){ 
									tablero[i][j] = simbolo_obstaculo;
									listo = true;
								}
							}
							
							else if(disponible(tablero, j, filas)){
								
								
								inicio = 9-tamanio_obstaculos[x]+1;
								fin = 9;
								for(int y=inicio; y<=fin; y++){
									tablero[y][j]=simbolo_obstaculo;
								}
								
								listo = true;
								
							}
							
						}
						while(!listo); 
					}
					
				}
					
					bool disponible(char tablero[][MAXIMO], int j, int filas){
						
						bool previa_disponible = (j>0) ? tablero[filas-1][j-1] == ' ' : false;
						bool siguiente_disponible = (j<19) ? tablero[filas-1][j+1] == ' ' : false; 
						bool actual_disponible = tablero[filas-1][j] == ' ';
						
						return actual_disponible and previa_disponible and siguiente_disponible;
						
					}
						
						void simulacion1(){
							char tablero[10][20];
							char tablerosimulacion[10][20];
							
							for(int i=0;i<10;i++){
								for(int j=0;j<20;j++){
										tablero[i][j]=' ';
								}
							}
							cargarTablero(tablerosimulacion,10,20);
							bool ok=false;
							int aves=0,rocas=0;
							while(!ok){
							int a,b;
							for(int i=0;i<10;i++){
								for(int j=0;j<20;j++){
									cout << tablero[i][j] <<" ";
									}
								cout << endl;
								}
							cout << endl;
							
							cout << "Ingrese una cordenada en Y: ";
							cin >> a;
							if(a==99){
								ok=true;
								for(int i=0;i<10;i++){
									for(int j=0;j<20;j++){
										if(tablerosimulacion[i][j]!='^' and tablerosimulacion[i][j]!='X'){
											if(i==9) tablero[i][j]='_';
											else tablero[i][j]='.';
										}
										if(tablerosimulacion[i][j]=='^'){
											tablero[i][j]='^';
										}
										if(tablerosimulacion[i][j]=='X'){
											tablero[i][j]='X';
										}
									}
								}
							}
							else{
							cout << endl <<"Ingrese una cordenada en X: ";
							cin >> b;
							
							if(tablerosimulacion[a][b]=='^'){
								cout << endl << "Acierto" << endl;
								tablero[a][b]='^';
								++aves;
							}
							if(tablerosimulacion[a][b]=='X'){
								cout << endl << "Acierto" << endl;
								tablero[a][b]='X';
								++rocas;
							}
							if(tablerosimulacion[a][b]!='^' and tablerosimulacion[a][b]!='X' and a<9){
								cout << endl << "Aire" << endl;
								tablero[a][b]='.';
							}
							if(tablerosimulacion[a][b]!='^' and tablerosimulacion[a][b]!='X' and a==9){
								cout << endl << "Tierra" << endl;;
								tablero[a][b]='_';
							}
							if(aves==10 and rocas==11){
								ok=true;
								for(int i=0;i<10;i++){
									for(int j=0;j<20;j++){
										if(tablerosimulacion[i][j]!='^' and tablerosimulacion[i][j]!='X'){
										if(i==9) tablero[i][j]='_';
										else tablero[i][j]='.';
										}
									}
								}
							}
							
							}
							}
							for(int i=0;i<10;i++){
								for(int j=0;j<20;j++){
									cout << tablero[i][j] <<" ";
								}
								cout << endl;
							}
							cout << endl;
							
						}
							
					
							