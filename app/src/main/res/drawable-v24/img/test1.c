
// Sample code to perform I/O:
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int checkVowel(char val);
int main(){
	char numPlate[10];
    //printf("Enter the number plate:");
    scanf("%[^/n]s",numPlate);
    int i;
    int condition1 = 0; // this is used to check the numbers
    int condition2 = 0; // this is used to check the letters
    for(i=0;numPlate[i] != '\0';i++)
    {
        if(i == 2)
            continue;
        if(isdigit(numPlate[i]))
        {
            if((numPlate[i] + numPlate[i+1]) %2 == 0)
            {
                condition1 = 1;
                break;
            }
        }
        else if (isalpha(numPlate[i]))
        {
            condition2 = checkVowel(numPlate[i]);
        }
    }
    
    if (condition1 == 0 && condition2 == 0)
    {
        printf("valid");
    }
    else
    {
        printf("invalid");
    }
}

int checkVowel(char val)
{
    int num;
    switch(val)
    {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        {
            num = 1;
            break;
        }
        default:
        {
            num = 0;
        }
        
    }
    return num;
}


