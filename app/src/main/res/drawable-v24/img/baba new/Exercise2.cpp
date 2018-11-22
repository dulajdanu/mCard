
#include<iostream>
#include<math.h>
using namespace std;

int input() {
	int c;
	cin >> c;
	return c;
	
}

int xcord() {
	int xvalue;
	cout << "Enter the x cordinate of the center or the top left corner of the shape : ";
	cin >> xvalue;
	return xvalue;
}
int ycord() {
	int yvalue;
	cout << "Enter the x cordinate of the center or the top left corner of the shape : ";
	cin >> yvalue;
	return yvalue;
}
char fillineswith() {
	char b;
	cout << "Enter the character you want to fill in with : ";
	cin >> b;
	if (!(isalpha(b))) {
		cout << "Entered character is not a alphabetical letter Try again ";
		return fillineswith();
	}
	return b;
}
char optionlist() {
	char x;
	cout << "Enter the shape you want : \n";
	cout << "(S)-Square\n(C)-Circle\n(R)-Rectangle\n(Q)-Quit\n";
	cin >> x;
	x = toupper(x);
	return x;
}



int main() {
	bool logicaldraw[300][400];
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 400; j++)
			logicaldraw[i][j] = { false };
	}
	char option,filledcharacter,viewtheshape;
	int xcordianteofthedrawing, ycordinateofthedrawing;
	option=optionlist();
	switch (option) {
	case 'S':
		int side;
		cout << "Enter the length of the square : ";
		side = input();
		xcordianteofthedrawing = xcord();
		ycordinateofthedrawing = ycord();
		
		filledcharacter = fillineswith();
		for (int j = ycordinateofthedrawing; j < ycordinateofthedrawing+side; j++)
		{
			for (int i = xcordianteofthedrawing;i < xcordianteofthedrawing + side; i++) {
				logicaldraw[j][i] = true;
			}
		}
		
		cout << "Do you want to view the shape <Y/N> : ";
		cin >> viewtheshape;
		viewtheshape=toupper(viewtheshape);
		switch (viewtheshape) {
		case 'Y':
			for (int j = 0; j < 300; j++)
			{
				for (int i = 0; i < 400; i++) {
					if (logicaldraw[j][i] == true)
						cout << filledcharacter;
					else
						cout << " ";
				}
				cout << endl;
			}
			break;
		case'N': 
			return main();
		}
		
		break;
	case 'C':
		int rad;
		cout << "Enter the rad of the circle : ";
		rad=input();
		xcordianteofthedrawing = xcord();
		ycordinateofthedrawing = ycord();
		
		filledcharacter = fillineswith();
		for (int j = 0; j < 400; j++)
		{
			for (int i = 0; i < 300 ; i++) {
				
				if (pow((xcordianteofthedrawing - i), 2) + pow((ycordinateofthedrawing - j), 2) <= pow(rad, 2)) {
					logicaldraw[j][i] = true;
					
				}
			}
		}
		
		cout << "Do you want to view the shape <Y/N> : ";
		cin >> viewtheshape;
		viewtheshape = toupper(viewtheshape);
		switch (viewtheshape) {
		case 'Y':
			for (int j = 0; j < 300; j++)
			{//prints the shape
				for (int i = 0; i < 400; i++) {
					if (logicaldraw[j][i] == true)
						cout << filledcharacter;
					else
						cout << " ";
				}
				cout << endl;
			}
			break;
		case 'N':
			return main();
		}
		break;
	case 'R':
		int length,width;
		cout << "Enter the length of the rectangle : ";
		length=input();
		cout << "Enter the width of the rectangle : ";
		width=input();//
		xcordianteofthedrawing = xcord();
		ycordinateofthedrawing = ycord();
		filledcharacter = fillineswith();
		for (int j = ycordinateofthedrawing; j < ycordinateofthedrawing + length; j++)
		{
			for (int i = xcordianteofthedrawing; i < xcordianteofthedrawing + width; i++) {
				logicaldraw[j][i] = true;
			}
		}
		cout << "Do you want to view the shape <Y/N> : ";
		cin >> viewtheshape;
		viewtheshape = toupper(viewtheshape);
		switch (viewtheshape) {
		case 'Y':
			for (int j = 0; j < 300; j++)
			{//prints the shape
				for (int i = 0; i < 400; i++) {
					if (logicaldraw[j][i] == true)
						cout << filledcharacter;
					else
						cout << " ";
				}
				cout << endl;
			}
			break;
		case'N':
			return main();
		}
		break;
	case 'Q':
		return 0;
	}
	system("pause");
}
