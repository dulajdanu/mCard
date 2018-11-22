#include <iostream>
#include<math.h>

using namespace std;


int n = 0;
int val = 2048; // 2048 is used to get 1024
void guessNum(int a)
{
	while(val != a)
	{
		if(val > a)
		{
			val -= 1024/pow(2,n);
			cout << val << endl;
		}
		else
		{
			val += 1024 /pow(2,n);
			cout << val << endl;
		}
		n++;
	}
	
}

int pow(int a, int b)
{
	if(b==0)
		return 1;
	else
		return a*pow(a,b-1);
}


void check(int a)
{
	if(a >= 1 && a <= 1024)
	{
		guessNum(a);
	}
	else
	{
		cout << "Please enter a number between 1 and 1024" << endl;
	}

}



int main()
{
	
	int num ;
	cout << "Enter the number" << endl;
	cin >> num;
	check(num);
	
	
	return 0;
}
