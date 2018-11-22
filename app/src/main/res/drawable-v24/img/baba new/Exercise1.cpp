#include <iostream>     
#include<cmath>          
const float pi = 3.14159;            
int array[2500];                         
float s[2500];                 
float d[2500];  
using namespace std;


float signal(int i,float itvl)
{
	float f1 = (2.0*sin(2.0 * pi*array[i] * itvl)) + (0.75*sin(0.5*pi*array[i] * itvl)); 
	return f1;
}

float deri(int i,float itvl)
{
	float f2 = 	(2.0 * cos(2.0 * pi*array[i] * itvl) * 2.0 * pi*array[i]) + (0.75*cos(0.5*pi*array[i] * itvl)*0.5*pi*array[i]);
	return f2;   
}

int main()         
{
	int prd;    
	float itvl;  

	cout << "Enter the the total time period( 5,10,15,20 seconds):-";    
	cin >> prd;

	cout << "Enter the interval( 0.01,0.02,0.05):-";      
	cin >> itvl;
	if (prd > 0 && itvl > 0)           
	{	
		            
		int count = 0;
		for (int i = 0; i <= prd / itvl; i++)
		{
			array[i] = i;            

			s[i] =   signal(i,itvl);

			d[i] = deri(i,itvl);   
			count++;
			cout << endl;
		}
			for (int i = 0; i < count; i++)         
			{
				cout << i << " Signal " << s[i] << " : ";
				cout << "Derivative " << d[i] << endl;
			}
		
	}
	else
		cout << "ERROR!";

	system("PAUSE");                 
	return 0;

}
