#include <iostream>
#include <math.h>
using namespace std;


int main() 
{

//Valores iniciales calculados 

int dt=0.5;
float nu=0.001;

//dx y dy dados en cm

int dx=1;
int dy=1;

//Otras que usare como arreglos Tforw es el de adelante y T es el actual

float Tforw[5000]={};
float partedx[100]={};
float partedy[100]={};
float T[5000]={};
float advx;
float advy;
float advt;

for(int k=0;k<2500;k+=dt)
{
	for(int i=1;i<100;i++)
	{
		for(int j=1;j<100;j++)
		{

		// Ajuste de condiciones iniciales
		if(advx>=20.0 && advx<=40.0 && advy>=50.0 && advy<=70.0)
		{
			T[i][j]=100.0;
		}
		else {	T[i][j]=50.0;	}
		
		partedx=(T[i+1][j]-2.0*T[i][j]+T[i-1][j])/pow(dx,2);
		partedy=(T[i][j+1]-2.0*T[i][j]+T[i][j-1])/pow(dy,2);


		Tforw[i][j]=(nu*partedx + nu*partedy)*dt+T[i][j];

		T[i][j]=Tforw[i][j];
		advx+=dx;
		advy+=dy;
		advt+=dt;

		cout<<advx<<","<<advy<<","<<advt<<"\n";

		}
	}
}




//Condiciones iniciales 
//Se tiene un cuadrito de 20x20 en la posicion 50 en y y 20 en x, asumiento que la posicion del cuadradito se toma para su borde izquierdo y el borde superior en estos puntos, y considerando que sus bordes son los que estan a 100, debe ser como esta en el condicional.


	




















return 0;
}







