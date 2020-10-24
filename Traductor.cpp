#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
const char *nombre_archivo = "traductor.txt";

struct Traductor{
	string palabra;
	string Npalabra;
	string traduccion;
	string funcionalidad;
};

void ingresar();
void abrir();

main(){
	int opcion;
	
	while(true){
		cout<<"1 - Agregar"<<endl;
		cout<<"2 - Leer"<<endl;
		cout<<"3 - Modificar"<<endl;
		cout<<"4 - Eliminar"<<endl;
		cout<<"Ingrese una opcion: ";
		cin>>opcion;
		
		system("cls");
		switch(opcion){
			case 1:
				{
					ingresar();
					break;
				}
			case 2:
				{
					abrir();
					break;
				}
		}
	}
	return 0;
}

void abrir (){
	ifstream archivo;
	archivo.open(nombre_archivo, ios::app); 
	string fila;
	
	if(archivo.fail()){
		cout<<"No es posible abrir el archivo"<<endl;
		exit(1);
	}else{
		do{
			getline(archivo, fila);
			cout<<fila<<endl;
		}while(archivo.eof()==false);
		
	}
	archivo.close();
}

void ingresar(){
	ofstream guardar;
	guardar.open(nombre_archivo, ios::app); 

	char s;
	Traductor traductor;
	
	if(guardar.fail()){
		cout<<"No es posible abrir el archivo"<<endl;
		exit(1);
	}else{
		do{
			cout<<"Ingrese palabra: ";
			cin>>traductor.palabra;
			cout<<"Ingrese traduccion: ";
			cin>>traductor.traduccion;
			cout<<"Ingrese funcionalidad: ";
			cin.ignore();
			getline(cin, traductor.funcionalidad);
			
			guardar<<traductor.palabra<<", "<<traductor.traduccion<<", "<<traductor.funcionalidad<<endl;
			
			cout<<"Desea agregar mas datos (s/n)";
			cin>>s;
			system("cls");
		}while(s=='s');
	}
	
	guardar.close();
	//abrir();
}
