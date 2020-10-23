#include <iostream>
#include <fstream>

using namespace std;
const char *nombre_archivo = "traductor.txt";

struct Traductor{
	string palabra;
	string traduccion;
	string funcionalidad;
};

void ingresar();

main(){
	ingresar();
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
	ofstream archivo;
	archivo.open(nombre_archivo, ios::app); 

	char s;
	Traductor traductor;
	
	if(archivo.fail()){
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
			
			archivo<<traductor.palabra<<", "<<traductor.traduccion<<", "<<traductor.funcionalidad<<endl;
			
			cout<<"Desea agregar mas datos (s/n)";
			cin>>s;
			system("cls");
		}while(s=='s');
	}
	
	archivo.close();
	//abrir();
}
