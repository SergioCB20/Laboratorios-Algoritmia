#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//Hecho por Sergio Chumbimuni Bustamante

void cargaBin(int N,int cromo[],int num){
	int i,res;
	for(i=0;i<N;i++)cromo[i]=0;
	i=0;
	while(num>0){
		res = num%2;
		num = num/2;
		cromo[i] = res;
		i++;
	}
}

void resetearSemana(int semana[][]){
	for(i=0;i<6;i++)
	for(int j=0;j<24;j++)
	semana[i][j] = 0;
}

int main(){
	
	ifstream archDatos("20221_Lab1_2.txt",ios::in);
	char horarios[15][11],cadena[6],c;
	int datosHorarios[15][8];//creditos,dia teoria, inicio, final, dia practica, inicio, final, indicador semana.
	int i=0,l,semana[6][24];
	
	while(true){
		archDatos >> cadena;
		if(archDatos.eof())break;
		strcpy(horarios[i],cadena);
		archDatos>>datosHorarios[i][0]>>c>>cadena;
		strcat(horarios[i],"-");
		strcat(horarios[i],cadena);
		archDatos>>datosHorarios[i][1]>>datosHorarios[i][2]>>datosHorarios[i][3]>>datosHorarios[i][4];
		archDatos>>datosHorarios[i][5]>>datosHorarios[i][6]>>datosHorarios[i][7];
		i++;
	}
	
	cout<<"Ingrese el numero de creditos maximo que se puede matricular:"<<endl;
	cin>>l;
	
	int cantCred;
	
	for(i=0;i<15;i++)
	  cantCred = 0;
	  resetearSemana(semana);
	  llenarSemana(semana,datosHorario[i]);
	
	
	return 0;
}
