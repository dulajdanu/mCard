#include<iostream>

using namespace std;

int add(int a,int b)
{
	return a+b;
	
}

int sub(int a,int b)
{
	return a-b;
}

int mul(int a,int b)
{
	return a*b;	
}

float div(int a,int b)
{
	return (float(a/b));
}

int power(int a,int b)
{
	if(b==0)
		return 1;
	else
		return a*power(a,b-1);	
}

int factorial(int a)
{
	if(a==1)
		return 1;
	else
		return a*factorial(a-1);	
}


int main()


{
	int a,b ;
	while(1==1)
	{
	
		cout << "Please enter your choice" << endl;
		cout << "Enter 1 for Addition " << endl;
		cout << "Enter 2 for Subtraction " << endl;
		cout << "Enter 3 for Multiplication " << endl;
		cout << "Enter 4 for Division " << endl;
		cout << "Enter 5 for Power " << endl;
		cout << "Enter 6 for Factorial " << endl;
		cout << "Enter \'e\' or \'E\' to exit" << endl;
	
		char choice ;
	
		cin >> choice;
		
		if (choice == 'e' || choice == 'E')
		{
			
		cout << "Bye" << endl;
			break;
		}
		switch(choice)
		{
			case '1':
				{
					cout << "Enter the two numbers to add" << endl;
					cin >> a >> b ;
					cout << add(a,b) << endl;
					break;	
				}
			case '2':
				{
					cout << "Enter the two numbers to subtract" << endl;
					cin >> a >> b ;
					cout <<sub(a,b) << endl;
					break;
				}
			case '3':
				{
					cout << "Enter the two numbers to multiply" << endl;
					cin >> a >> b ;
					cout << mul(a,b)<< endl;
					break;
				}
			case '4':
				{
					cout << "Enter the two numbers to Divide" << endl;
					cin >> a >> b ;
					 cout << div(a,b) << endl;
					break;
				}		
			case '5':
				{
					cout << "Enter the number number and its power" << endl;
					cin >> a >> b ;
					cout << power(a,b) << endl;
					break;	
				}
			case '6':
				{
					cout << "Enter  the number" << endl;
					cin >> a ;
					cout << factorial(a) << endl;
					break;	
				}
			default:
				{
					cout << "Enter the correct choice";
				}		
		}
		
	}
	return 0;
	
	
	
	
	
	
	
	
	
	
	
}
