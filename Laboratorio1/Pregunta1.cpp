#include <iostream>
#include <math.h>

//Hecho por Sergio Chumbimuni Bustamante

using namespace std;

void cargaBin(int N,int cromo[],int num){
	int i,res;
	for(i=0;i<N;i++)cromo[i]=0;
	i=0;
	while(num>0){
		res = num%2;
		num = num/2;
		cromo[i]=res;
		i++;
	}
}

int main(){
	
	int p = 50000, n = 9,iteraciones; //50000 dolares de presupuesto y 9 canales de publicidad
	double canales[n][3] = {{30000,1.2,2000},
	                     {14000,2.8,3000},
					 {18000,1.4,1200},
					 {9000,2.5,400},
					 {15000,1.3,700},
					 {10000,2,800},
					 {21000,1.2,1300},
					 {15000,2.5,1000},
					 {20000,1.1,200}};
	char nombres[n][50] ={{'T','V'},
	{'Y','O','U','T','U','B','E'},
	{'R','A','D','I','O'},
	{'E','M','A','I','L'},
	{'D','I','A','R','I','O'},
	{'F','B'},
	{'A','N','U','N','C','I','O','S'},
	{'G','O','O','G','L','E','_','A','D','S'},
	{'E','V','E','N','T','O','S'}};
	int ingresoVentas[n],cromo[n],ingresoTParcial,ingresoMaximo=0,inversionT,inversionMax,iMax;
	//Ingreso de datos
    
    
    //Calculando los ingresos de ventas
    for(int i=0;i<n;i++)
    	ingresoVentas[i] = canales[i][0] * canales[i][1];
    	
    //Resto del programa
    
    iteraciones = pow(2,n);
	
	for(int i=1;i<iteraciones;i++){
		ingresoTParcial = 0;
		inversionT = 0;
		cargaBin(n,cromo,i);
		for(int j=0;j<n;j++){
			if(cromo[j]==1){
				ingresoTParcial +=ingresoVentas[j];
				inversionT += canales[j][0];
			}
		}
		if(inversionT<p && ingresoTParcial>ingresoMaximo){
			ingresoMaximo = ingresoTParcial;
			inversionMax = inversionT;
			iMax = i;
		}
	}
	cout<<"El maximo ingreso por ventas es de "<<ingresoMaximo <<" dolares "
	<<"con una inversion total en publicidad de "<<inversionMax<<" dolares."<<endl<<endl;
	cout<<"Los canales de publicidad que se deben de elegir para obtener el mximo ingreso total son:"<<endl<<endl;
	cargaBin(n,cromo,iMax);
	for(int i=0;i<n;i++){
		if(cromo[i]==1){
			cout<<"Canal "<<i+1<<" - "<<nombres[i]<<", ingreso = "<<ingresoVentas[i]
			<<" dolares con una inversion publicitaria de "<<canales[i][0]<<" dolares."<<endl;
		}
	}
	cout<<endl;
	//Parte D
	int recordacionT, recordacionMax =0;
	
	for(int i=1;i<iteraciones;i++){
		ingresoTParcial = 0;
		inversionT = 0;
		recordacionT = 0;
		cargaBin(n,cromo,i);
		for(int j=0;j<n;j++){
			if(cromo[j]==1){
				recordacionT += canales[j][2];
				ingresoTParcial +=ingresoVentas[j];
				inversionT += canales[j][0];
			}
		}
		if(inversionT<=p && recordacionT>recordacionMax){
			recordacionMax = recordacionT;
			ingresoMaximo = ingresoTParcial;
			inversionMax = inversionT;
			iMax = i;
		}
	}
	cout<<"El nivel maximo de recordacion de marca es de "<<recordacionMax<<" con una inversion total en publicidad de "
	<<inversionMax<<" dolares y un ingreso de "<<ingresoMaximo<<endl<<endl;
	cout<<"Los canales de publicidad que se deben de elegir para obtener el maximo nivel de recordacion de marca son:"<<endl<<endl;
	cargaBin(n,cromo,iMax);
	for(int i=0;i<n;i++){
		if(cromo[i]==1){
			cout<<"Canal "<<i+1<<" - "<<nombres[i]<<", recordacion de marca = "<<canales[i][2]<<", ingreso = "<<ingresoVentas[i]
			<<" dolares con una inversion publicitaria de "<<canales[i][0]<<" dolares."<<endl;
		}
	}
	return 0;
}
