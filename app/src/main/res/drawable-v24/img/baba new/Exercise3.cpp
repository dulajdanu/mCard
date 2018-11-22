#include<iostream>
#include<cstdlib>
using namespace std;
int select_Col() {
	int a;
	cout << "Enter a valid value for the column u want to sort : ";
	cin >> a;
	if (a < 1 || a>4) {
		cout << "Entered value is incorrect try again \n";
		return select_Col();
	}
	else
		return a;
}
char selectorder() {
	char b;
	cout << "Enter the selection Ascending or Descending :";
	cin >> b;
	switch (b) {
	case'A':
	case'a':
		return 'A';
	case'D':
	case'd':
		return 'D';
	default:
		cout << "wrong selection ";
		return selectorder();
		break;
	}
}
int main() {
	int array1[10][4], array2[10][4];
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 3; j++) {
			if (j == 0) 
				array1[i][j] = i + 1;
			else
			{
				array1[i][j] = rand() % 101 - 50;

			}
		}
	}
	
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 3; j++) {
			array2[i][j] = array1[i][j];
		}
	}
	int column = select_Col();
	
	column -= 1;
	char sortingOrder=selectorder();
	
	
	
	

	if (sortingOrder == 'D')
	{
		int tempory[4];

		for (int i = 0; i <= 9; i++) {

			for (int j = 0; j <= 8; j++) {
				if (array2[j][column] <array2[j + 1][column]) {
					for (int x = 0; x <= 3; x++)
						tempory[x] = array2[j][x];
					for (int x = 0; x <= 3; x++)
						array2[j][x] = array2[j + 1][x];
					for (int x = 0; x <= 3; x++)
						array2[j + 1][x] = tempory[x];

				}

			}


		}
		
	}
		 
	else {

		int tempory[4];

		for (int i = 9; i >= 0; i--) {

			for (int j = 9; j >= 1; j--) {
				if (array2[j][column] <array2[j - 1][column]) {
					for (int x = 0; x <= 3; x++)
						tempory[x] = array2[j][x];
					for (int x = 0; x <= 3; x++)
						array2[j][x] = array2[j - 1][x];
					for (int x = 0; x <= 3; x++)
						array2[j - 1][x] = tempory[x];

				}

			}


		}
		 }
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 3; j++) {
			cout << array1[i][j] << "\t";
		}
		cout << "\t\t\t";
		for (int p = 0; p <= 3; p++)
			cout << array2[i][p]<<"\t";
		cout << endl;
	}
	

	system("pause");
	system("cls");
	return 0;
}
