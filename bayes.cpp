#include <iostream>
#include <math.h>
#include <stdio.h>
#include <random>

using namespace std;

//x_obs y y_obs corresponden a los arreglos dados por un archivo de datos


//Deben ingresar los dos arreglos para este caso

float likelihood(//Type y_obs, Type y_model)
{
	float suma =0;

	for (int i=0; i<y_obs;i++)
	{ 
		suma+=(pow((y_obs[i]-y_model[i]),2));
	}
	float chi=0.5*suma;
		
return chi;
}


float my_model(//Type x_obs, Type m, Type b)
{
	float value=x_obs*m + b;

return value;
}


int main()
{
iteraciones = 20000;
srand(time(NULL));
double random_num=rand();

double *m_walk= new double[iteraciones];
double *b_walk= new double[iteraciones];
double *l_walk= new double[iteraciones];

//double *m_prime= new double[iteraciones];
//double *b_prime= new double[iteraciones];



//double *y_init= new double[iteraciones];


	for(int i=0; i<iteraciones;i++)
	{
	m_walk[i]=rand();
	b_walk[i]=rand();
	}

float y_init = my_model(x_obs,m_walk[0],b_walk[0]);	
l_walk[i]=likelihood(y_obs,y_init);


	for(int i=0; i<iteraciones;i++)
	{
	float m_prime=normal_distribution(m_walk[i],0.1);
	float b_prime=normal_distribution(b_walk[i],0.1);

	y_init=my_model(x_obs,m_walk[i], b_walk[i]);
	float y_prime=my_model(x_obs,m_prime,b_prime);
		
	float l_prime=likelihood(y_obs,y_prime);
	float l_init=likelihood(y_obs, y_init);
	
	float alpha=l_prime/l_init;
		
		if(alpha>=1.0)
		{
			m_walk[i]=m_prime;
			b_walk[i]=b_prime;
			l_walk[i]=l_prime;
		}
	
		else 
		{
			beta=rand();		
			if(beta<=alpha){
				m_walk[i]=m_prime;
				b_walk[i]=b_prime;
				l_walk[i]=l_prime;	
			}
			else
			{
				m_walk[i]=m_walk[i];
				b_walk[i]=b_walk[i];
				l_walk[i]=l_walk[i];	

			}
		}
			
	}

// Deberia ir i+1 en la parte izquierda de los arreglos??



return 0;
}





























