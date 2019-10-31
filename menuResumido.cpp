# include "iostream"
# include "conio.h"
# include "fstream"
# include <stdio.h>
# include <string.h>
# include <time.h>
# include <dos.h>
# include <stdlib.h>
#include <cstdlib>
#include <windows.h>
#include "sstream"
using namespace std;
void clientes();
void derechos();
void menu();
void loge();
void ingresolog();
void acceso();
char apellido[10];
string nombre;
int codigo;
struct login
{
  	char auxcontr[10];
  	char auxnombre[10],auxiuser[10],auxapellidos[10],auxdpi[10];
  	string nombre,dpi,user,contr,iuser,icontr,auxicontr;
  	string apellidos,por,auxcodigo,auxuser,codigo,aux;
  	
  
};	
login login;
int main()
{
	acceso();
	ingresolog();
	system("pause");
	return 0;
}
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
void acceso(){
	
	ofstream gcliente;
	ofstream log;
    gcliente.open("Clientes.txt",ios::in);
    time_t tiempo = time(0);
    char output[128];
  	int opcion;
  	while(opcion!=3)
  	{
  		system("cls");
  		int i;
  		system("Color A");
  		cout<<endl;
  		printf("%s\n",output);
        for(i=1;i<81;i++){
        	gotoxy(i,1);
          	printf("%c",219);
      		gotoxy(i,25);
          	printf("%c",219);
        }
        for(i=1;i<25;i++){
        	gotoxy(1,i);
          	printf("%c",219);
      		gotoxy(80,i);
          	printf("%c",219);
        }
  		gotoxy(26,10);
  		cout<<"<><><><><><><><><><><><><><><><><><>"<<endl;
  		gotoxy(26,11);
  		cout<<"<>                               <>"<<endl;
  		gotoxy(26,12);
  		cout<<"<>	      1..Acceso             <>"<<endl;
  		gotoxy(26,13);
  		cout<<"<>	      2..Creacion           <>"<<endl;
  		gotoxy(26,14);
  		cout<<"<>	      3..Salir              <>"<<endl;
  		gotoxy(26,15);
  		cout<<"<>	                            <>"<<endl;
  		gotoxy(26,16);
  		cout<<"<><><><><><><><><><><><><><><><><><>"<<endl;
        gcliente.close();
  
  		gotoxy(27,17);
  		cin>>opcion;
  		switch(opcion){
  			case 1:{
  				loge();
  	    	break;
  			}
  			case 2:{
  				ingresolog();
  				break;
  			}
	        case 3:{
	        	system("cls");
	        	exit(0);
	          break;
	        }

  		}
  	}
}
void menu()
{
  	int opcion;
  	while (opcion !=7)
  	{
  		system("cls");
  		time_t tiempo = time(0);
    	struct tm *tlocal = localtime(&tiempo);
    	char output[128];
    	strftime(output,128,"%d/%m/%y %H:%M",tlocal);
      	system("Color c");
      	int i;
        gotoxy(2,2);
      	cout<<nombre<<" "<<apellido<<endl;
      	codigo;
        gotoxy(2,3);
        printf("%s\n",output);
  		cout<<endl<<endl<<endl;
      	gotoxy(15,7);
      	for(i=0;i<50;i++)
        {
        	printf("%c",175);
      	}
      	gotoxy(15,20);
      	for(i=0;i<50;i++)
        {
        printf("%c",174);
        }
        for(i=1;i<81;i++){
            gotoxy(i,1);
            printf("%c",219);
            gotoxy(i,25);
            printf("%c",219);
        }
        for(i=1;i<25;i++){
            gotoxy(1,i);
            printf("%c",219);
            gotoxy(80,i);
            printf("%c",219);
        }
        gotoxy(33,8);
        cout<<"MENU PRINCIPAL"<<endl;
        gotoxy(30,10);
      	cout<<"1....Clientes"<<endl;
        gotoxy(30,11);
      	cout<<"2.....Derechos de autor"<<endl;
        gotoxy(30,13);
        cout<<"3....Salir"<<endl;
        gotoxy(34,14);
      	cout<<"Ingrese Opcion"<<endl;
        gotoxy(34,15);
  		cin>>opcion;
  		switch(opcion){
  			case 1:{
  				clientes();
  				break;
  			}
  			case 2:{
  				derechos();
  				break;
  			}
  		}
  	}
}
void clientes()
{
	system("cls");
  	ofstream log;
  	string auxuser, linea,linea2,linea3,linea4,linea5,linea6,linea7;
	int res=0;
  	ifstream consultac;
	consultac.open("Clientes.txt",ios::in); //abriendo archivo
    system("Color F");
    gotoxy(30,5);
    cout<<"Creacion de Usuarios"<<endl;
    cout<<endl<<endl;
    bool repetido=false;
    string codigo;
    log.open("Login.txt",ios::app);
    cout<<endl<<endl;
    cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    system("Color E");printf("NOTA: el Codigo y el Usuario No se podran modificar en un futuro");
    cout<<endl<<endl;
    cout<<"                   Ingrese Usuario (Nick).......: ";cin>>login.auxuser;
    
    
	if(consultac.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	while(getline(consultac,linea))
	{
		if(linea.find(login.auxuser) != string::npos)
		{
			system("cls");
        	gotoxy(20,10);
        	system("Color E");printf("Lo sentimos, Codigo o Usuario ya en Uso");
        	log.close();	
			res = 1;
		}
		
	}
	if (res==0){
		cout<<"                   Usuario Disponible...........: "<<login.auxuser<<endl;
		cout<<"                   Ingrese Nombre...............: ";cin>>login.nombre;
      	cout<<"                   Ingrese Apellido.............: ";cin>>login.apellidos;
      	cout<<"                   Ingrese Pass.................: ";cin>>login.contr;
      	cout<<endl<<endl;
      	cout<<"                            Guardado Correctamente"<<endl;
      	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
		log <<login.auxuser<<endl;
		log <<login.nombre<<endl;
		log <<login.apellidos<<endl;
		log <<login.contr<<endl;
		log.close();
        consultac.close();
        
	}
	system("pause");

	}	
    

void loge()
{
  	system("cls");
	int res=0;
  	ofstream log;
    log.close();
    system("Color F");
    log.open("Login.txt",ios::app);
  	bool si=false;
    gotoxy(26,11);
  	cout<<"Ingrese Usuario....: ";
  	cin>>login.iuser;
    gotoxy(26,12);
    cout<<"Ingrese Contrasena.: ";
  	cin>>login.icontr;
  	ifstream consultal;
	string texto;
	consultal.open("Login.txt",ios::in); //abriendo archivo
	if(consultal.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
  	while(!consultal.eof())
  	{
  		
  	while(getline(consultal,login.user))
	{
		if(login.user.find(login.auxuser) != string::npos)
		{
			cout<<login.user<<endl;
			getline(consultal,login.nombre);
			cout<<login.nombre<<endl;
			getline(consultal,login.apellidos);
			cout<<login.apellidos<<endl;
			getline(consultal,login.contr);
			cout<<login.contr<<endl;
			
			int result = strcmp(login.user.c_str(), login.iuser.c_str());
  			int result2 = strcmp(login.contr.c_str(), login.icontr.c_str());
  		if (result==0&&result2==0)
  	  	{
  	    	system("cls");
        	system("Color F");
        	gotoxy(28,12);
  	    	cout<<"Bienvenido "<<login.nombre<<" "<<login.apellidos<<"!!"<<endl;
        	getch();
  	    	menu();
  	  	}else {
      	system("cls");
      	system("Color C");
      	gotoxy(26,12);
      	cout<<"Usuario o contraseña incorrecto "<<endl;
  		getch();
  		}
			
			
			res = 1;
		}
	}
	if (res==0){
		cout<<login.auxuser<<"no encontrado..."<<endl;
	}
	
  		
  }
  	consultal.close();
    log.close();
}

void ingresolog()
{
  	system("cls");
  	ofstream log;
  	string auxuser, linea,linea2,linea3,linea4,linea5,linea6,linea7;
	int res=0;
  	ifstream consultal;
	consultal.open("Login.txt",ios::in); //abriendo archivo
	log.open("Login.txt",ios::in); //abriendo archivo
  	log.close();
    system("Color E");
    gotoxy(30,5);
    cout<<"Creacion de Usuarios"<<endl;
    cout<<endl<<endl;
    bool repetido=false;
    string codigo;
    log.open("Login.txt",ios::app);
    cout<<endl<<endl;
    cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    system("Color E");printf("NOTA: el Codigo y el Usuario No se podran modificar en un futuro");
    cout<<endl<<endl;
    cout<<"                   Ingrese Usuario (Nick).......: ";cin>>login.auxuser;
    
    
	if(consultal.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	while(getline(consultal,linea))
	{
		if(linea.find(login.auxuser) != string::npos)
		{
			system("cls");
        	gotoxy(20,10);
        	system("Color E");printf("Lo sentimos, Codigo o Usuario ya en Uso");
        	log.close();	
			res = 1;
		}
		
	}
	if (res==0){
		cout<<"                   Usuario Disponible...........: "<<login.auxuser<<endl;
		cout<<"                   Ingrese Nombre...............: ";cin>>login.nombre;
      	cout<<"                   Ingrese Apellido.............: ";cin>>login.apellidos;
      	cout<<"                   Ingrese Pass.................: ";cin>>login.contr;
      	cout<<endl<<endl;
      	cout<<"                            Guardado Correctamente"<<endl;
      	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
		log <<login.auxuser<<endl;
		log <<login.nombre<<endl;
		log <<login.apellidos<<endl;
		log <<login.contr<<endl;
		log.close();
        consultal.close();
        
	}
	system("pause");
}
void derechos()
{
    system("cls");
    cout<<""<<endl;
    cout<<""<<endl;
    getch();
} 

 
