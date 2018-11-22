#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void hoursPrint(int hours);
void timeOut(int hours,int minutes);


int main()
{

    int hours;
    int minutes;
    scanf("%d%d",&hours,&minutes);
    if((hours >= 0 && hours <=12) && (minutes >= 0 && minutes <= 60))
    {
        timeOut(hours,minutes);
    }

    return 0;

}

void hoursPrint(int hours)
{

    switch(hours)
    {

    case 1:
        {
        printf("%s"," one ");
        break;
        }
    case 2:
        {
        printf("%s"," two ");
        break;
        }
    case 3:
        {
        printf("%s"," three ");
        break;
        }
    case 4:
         {
        printf("%s"," four ");
        break;
        }
    case 5:
 {
        printf("%s"," five ");
        break;
        }
    case 6:
        {
        printf("%s"," six ");
        break;
        }
    case 7:
         {
        printf("%s"," seven");
        break;
        }
    case 8:
 {
        printf("%s"," eight ");
        break;
        }

    case 9:
 {
        printf("%s"," nine  ");
        break;
        }
    case 10:
        {
        printf("%s"," ten ");
        break;
        }
    case 11:
        {
        printf("%s"," eleven ");
        break;
        }
    case 12:
        {
        printf("%s"," twelve ");
        break;
        }
    }

}




void timeOut(int hours,int minutes)
{
    if(minutes == 0 && hours != 0)
    {
        switch(hours)
        {

        case 1:
            {
            printf("one o' clock");
            break;
            }
        case 2:
            {
            printf("two o' clock");
            break;
            }
        case 3:
            {
            printf("three o' clock");
            break;
            }
        case 4:
            {
            printf("four o' clock");
            break;
            }
        case 5:
            {
            printf("five o' clock");
            break;
            }
        case 6:
            {
            printf("six o' clock");
            break;
            }
        case 7:
            {
            printf("seven o' clock");
            break;
            }
        case 8:
            {
            printf("eight o' clock");
            break;
            }
        case 9:
            {
            printf("nine o' clock");
            break;
            }
        case 10:
            {
            printf("ten o' clock");
            break;
            }
        case 11:
            {
            printf("eleven o' clock");
            break;
            }
        case 12:
            {
            printf("twelve o' clock");
            break;
            }

        }
    }

    else if(minutes < 30 && minutes > 0)
    {

        switch(minutes)
        {
        case 1:
            {
            printf("one minute past ");
            hoursPrint(hours);
            break;
            }
        case 2:
            {
              printf("two minutes past");
              hoursPrint(hours);
            break;
            }

        case 3:
            {
            printf("three minutes past");
            hoursPrint(hours);
            break;
            }
        case 4:
            {
                printf("four minutes past");
                 hoursPrint(hours);
                break;

            }

        case 5:
            {
                printf("five minutes past");
                 hoursPrint(hours);
            break;
            }
        case 6:
            {
            printf("six minutes past");
             hoursPrint(hours);
            break;
            }
        case 7:
            {
            printf("seven minutes past ");
             hoursPrint(hours);
            break;
            }
        case 8:
            {
            printf("eight minutes past");
             hoursPrint(hours);
            break;
            }
        case 9:
            {
            printf("nine minutes past");
            hoursPrint(hours);
            break;
            }
        case 10:
            {
            printf("ten minutes past");
             hoursPrint(hours);
            break;
            }
        case 11:
            {
            printf("eleven minutes past");
             hoursPrint(hours);
            break;
            }
        case 12:
            {
            printf("twelve minutes past");
             hoursPrint(hours);
            break;
            }

        case 13:
            {
            printf("thirteen minutes past");
             hoursPrint(hours);
            break;
            }

        case 14:
            {
            printf("fourteen minutes past");
             hoursPrint(hours);
            break;
            }
        case 15:
            {
            printf("fifteen minutes past");
             hoursPrint(hours);
            break;
            }
        case 16:
            {
            printf("sixteen minutes past");
             hoursPrint(hours);
            break;
            }
        case 17:
            {
            printf("seventeen minutes past");
             hoursPrint(hours);
            break;
            }
        case 18:
            {
            printf("eighteen minutes past");
             hoursPrint(hours);
            break;
            }
        case 19:
            {
            printf("nineteen minutes past");
             hoursPrint(hours);
            break;
            }
        case 20:
            {
            printf("twenty minutes past");
             hoursPrint(hours);
            break;
            }
        case 21:
            {
            printf("twenty one minutes past");
             hoursPrint(hours);
            break;
            }
        case 22:
            {
            printf("twenty two minutes past");
             hoursPrint(hours);
            break;
            }
        case 23:
            {
            printf("twenty three minutes past");
             hoursPrint(hours);
            break;
            }
        case 24:
            {
            printf("twenty four minutes past");
             hoursPrint(hours);
            break;
            }
        case 25:
            {
            printf("twenty five minutes past");
             hoursPrint(hours);
            break;
            }
        case 26:
            {
            printf("twenty six minutes past");
             hoursPrint(hours);
            break;
            }
        case 27:
            {
            printf("twenty seven minutes past");
             hoursPrint(hours);
            break;
            }
        case 28:
            {
            printf("twenty eight minutes past");
             hoursPrint(hours);
            break;
            }
        case 29:
            {
            printf("twenty nine minutes past");
             hoursPrint(hours);
            break;
            }

        }
    }

    else if (minutes == 30)

    {
        printf("half past");
        hoursPrint(hours);
    }

    else if(minutes > 30 )
    {
          switch(minutes)
        {
        case 31:
            {
            printf("twenty  nine minutes to");
            hoursPrint(hours + 1);
            break;
            }
        case 32:
            {
              printf("twenty eight minutes to");
              hoursPrint(hours+1);
            break;
            }

        case 33:
            {
            printf("twenty seven minutes to");
            hoursPrint(hours+1);
            break;
            }
        case 34:
            {
                printf("twenty six minutes to");
                 hoursPrint(hours+1);
                break;

            }

        case 35:
            {
                printf("twenty five minutes to");
                 hoursPrint(hours + 1);
            break;
            }
        case 36:
            {
            printf("twenty four minutes to");
             hoursPrint(hours + 1);
            break;
            }
        case 37:
            {
            printf("twenty three minutes to");
             hoursPrint(hours + 1);
            break;
            }
        case 38:
            {
            printf("twenty two minutes to");
             hoursPrint(hours+1);
            break;
            }
        case 39:
            {
            printf("twenty one minutes to");
            hoursPrint(hours+1);
            break;
            }
        case 40:
            {
            printf("twenty minutes to");
             hoursPrint(hours+1);
            break;
            }
        case 41:
            {
            printf("nineteen minutes to");
             hoursPrint(hours+1);
            break;
            }
        case 42:
            {
            printf("eighteen minutes to");
             hoursPrint(hours+1);
            break;
            }

        case 43:
            {
            printf("seventeen minutes to");
             hoursPrint(hours+ 1);
            break;
            }

        case 44:
            {
            printf("sixteen minutes to");
             hoursPrint(hours+1);
            break;
            }
        case 45:
            {
            printf("quarter to");
             hoursPrint(hours+1);
            break;
            }
        case 46:
            {
            printf("fourteen minutes to");
             hoursPrint(hours+1);
            break;
            }
        case 47:
            {
            printf("thirteen minutes to");
             hoursPrint(hours+1);
            break;
            }
        case 48:
            {
            printf("twelve minutes to");
             hoursPrint(hours+1);
            break;
            }
        case 49:
            {
            printf("eleven minutes to");
             hoursPrint(hours+1);
            break;
            }
        case 50:
            {
            printf("ten minutes to");
             hoursPrint(hours + 1);
            break;
            }
        case 51:
            {
            printf("nine minutes to");
             hoursPrint(hours+1);
            break;
            }
        case 52:
            {
            printf("eight minutes to");
             hoursPrint(hours + 1);
            break;
            }
        case 53:
            {
            printf("seven minutes to");
             hoursPrint(hours + 1);
            break;
            }
        case 54:
            {
            printf("six minutes to");
             hoursPrint(hours + 1);
            break;
            }
        case 55:
            {
            printf("five minutes to");
             hoursPrint(hours+1);
            break;
            }
        case 56:
            {
            printf("four minutes to");
             hoursPrint(hours+1);
            break;
            }
        case 57:
            {
            printf("three minutes to");
             hoursPrint(hours+1);
            break;
            }
        case 58:
            {
            printf("two minutes to");
             hoursPrint(hours+1);
            break;
            }
        case 59:
            {
            printf("one minute to");
             hoursPrint(hours+1);
            break;
            }

        }
    }
}

