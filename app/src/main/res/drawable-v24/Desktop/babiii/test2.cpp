#include <iostream>



using namespace std;

void drawFSquare(int length, int height,char shape)
{
	int n,m;
	for(n=0;n < height ; n++)
	{
		for(m=0;m < length ; m++)
		{
			cout << shape ;
		}
		cout << endl;
	
	}
}

void drawUSquare(int length, int height,char shape)
{
	int n,m;
	for(n=0;n < height ; n++)
	{
		for(m=0;m < length ; m++)
		{
			if((n>0 && n < height-1) && (m>=1  && m <= length-2))
			{
				cout << ' ';
			}
			else
			{
			cout << shape ;
			}
		}
		cout << endl;
	
	}
}
void drawTraingle(int length, int height,char shape)
{
	int n ,m;
	for(n=0;n < height ; n++)
	{
		for(m=0;m <= n ; m++)
		{
			cout << shape ;
		}
		cout << endl;
	
	}
	
}




int main()
{
	char choice;
	int length,height;
	char shape;
	cout << "Enter your choice" << endl;
	cout << "Enter 1 for square" << endl;
	cout << "Enter 2 for Traingle" << endl;
	cin  >> choice;
	if(choice=='1')
	{
		cout << "Enter '/U/' for unfilled and '/F'/ for filled" << endl;
		cin >> choice;
		if(choice == 'U'  || choice == 'u')
		{
			cout << "Enter the dimensions" << endl;
			cout << "Enter length : " ;
			cin  >> length ;
			cout << "Enter Height : " ;
			cin  >> height ;
			cout << "Enter the character you want in the shape" << endl;
			cin >> shape;
			drawUSquare(length,height,shape);
			
		}
		else if(choice == 'F'  || choice == 'f')
		{
			cout << "Enter the dimensions" << endl;
			cout << "Enter length : " ;
			cin  >> length ;
			cout << "Enter Height : " ;
			cin  >> height ;
			cout << "Enter the character you want in the shape" << endl;
			cin >> shape;
			drawFSquare(length,height,shape);
			
		}
		else
		{
			cout << "Please give correct answer" << endl;
		}
	}
	if(choice == '2')
	{
			cout << "Enter the dimensions" << endl;
			cout << "Enter length : " ;
			cin  >> length ;
			cout << "Enter Height : " ;
			cin  >> height;
			cout << "Enter the character you want in the shape" << endl;
			cin >> shape;
			drawTraingle(length,height,shape);
	}
	return 0;
}
