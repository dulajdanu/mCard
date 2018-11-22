#include<iostream>
#include<ctime>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include <unistd.h>

using namespace std;

enum eDir{STOP = 0, LEFT = 1, UPLEFT = 2,DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};
class cBall //creating class for the ball
{

    private:
        int x,y; // x and y used to position ball on screen
        int originalX,originalY;
        eDir direction;
    public:
        cBall(int posX,int posY) // this is the constructor
        {
            originalX = posX;
            originalY = posY;
            x = posX ;
            y = posY;
            direction = STOP;
        }

        void Reset()
        {
            x = originalX;
            y = originalY;
            direction = STOP;
        }

        void changeDirection(eDir d) // this function ios used to change the direction of the ball
        {
            direction = d;
        }

        void randomDirection() // this is used to change the direction randomly
        {
            direction = (eDir)((rand()%6) + 1);

        }

        inline int getX() // this is used to get the current x position of ball
        {
            return x;
        }

         inline int getY() // this is used to get the current y position of ball
        {
            return y;
        }

         inline eDir getDirection() // this is used to get the current direction of ball
        {
            return direction;
        }

        void Move() // this function used for moving ball
        {
            switch(direction)
            {
                case STOP:
                    break;
                case LEFT:
                    {
                        x--;
                        break;
                    }
                case RIGHT:
                    {
                        x++;
                        break;
                    }
                case UPLEFT:
                    {
                        x--;
                        y--;
                        break;
                    }
                case UPRIGHT:
                    {
                        x++;
                        y--;
                        break;
                    }
                case DOWNLEFT:
                    {
                        x--;
                        y++;
                        break;
                    }
                case DOWNRIGHT:
                    {
                        x++;
                        y++;
                        break; // here the coordinate plane is different y values increase when going down and x increase when going right
                    }
                default:
                    break;
            }
        }

        friend ostream & operator << (ostream & o , cBall c)
        {
            o << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]" ;
            return o;
        }
};

class cPlayer // this is the player class of the game
{
private:
    int x,y;
    int originalX,originalY;
public:
    cPlayer()
    {
        x = y = 0;
    }
    cPlayer(int posX,int posY) : cPlayer()
    {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
    }

    inline void Reset()
    {
        x = originalX;
        y= originalY;
    }
    inline int getX()
    {
        return x;
    }
    inline int getY()
    {
        return y;
    }
    inline void moveUp(){y--;}
    inline void moveDown(){y++ ;}

     friend ostream & operator << (ostream & o , cPlayer c)
        {
            o << "Player [" << c.x << "," << c.y << "]" ;
            return o;
        }

};


class cGameManager // this class is used to manage the player and the ball class
{
private:
    int width,height;
    int score1,score2; // scores of players
    char up1,up2,down1,down2; // keys to move the players
    bool quit;

    cBall * ball; // declaring pointers for the two classes
    cPlayer *player1;
    cPlayer *player2;

public:
    cGameManager(int w,int h)
    {
        srand(time(NULL)); // get current time in unix time stamp
        quit = false;
        up1 = 'w';up2 = 'i'; // initializing up keys for the 2 players
        down1 = 's' ; down2 = 'k' ;// initializing down keys for the 2 players
        score1 = score2 = 0;
        width = w;
        height = h;
        ball = new cBall(w/2,h/2);
        player1 = new cPlayer(1,h/2 - 3);
        player2 = new cPlayer(w-2,h/2- 3);

    }
    ~cGameManager() // this is the deconstructor this is used to free memory
    {
        delete ball;
        delete player1;
        delete player2;
    }

    void scoreUp(cPlayer *player)
    {
         if(player == player1)
            score1++;
         else if(player == player2)
            score2++;

         ball->Reset();
         player1->Reset();
         player2->Reset();
    }

    void Draw()
    {
        system("cls"); // clear the console screen
        for(int i = 0 ; i < width + 3 ; i++)
        {
            cout << '\xB2';
        }
        cout << endl;

        for(int i= 0 ; i < height; i++)
        {
            for(int j = 0 ; j < width ; j++)
            {
                int ballX = ball->getX();
                int ballY = ball->getY();
                int player1x = player1->getX();
                int player2x = player2->getX();
                int player1y = player1->getY();
                int player2y = player2->getY();

                if(j==0)
                    cout << '\xB2'; // printing the wall by a special character by using the ascill hex values of that character

                if(j== width/2 -1)
                        cout << '|';

                if(ballX == j && ballY == i)
                        cout << '\xE8'; //printing the ball
                else if(player1x == j && player1y == i )
                    cout << '\xDB'; //player1 //special character is used for player

                else if(player2x == j && player2y == i )
                    cout << '\xDB'; //player2

                else if(player1x == j && player1y  + 1== i )
                    cout << '\xDB'; //player1 //special character is used for player
                else if(player2x == j && player2y + 1== i )
                    cout << '\xDB'; //player1 //special character is used for player

                else
                    cout << " ";

                if(j==width -1) //printing the wall
                    cout << '\xB2';

            }
            cout << endl;
        }

       for(int i = 0 ; i < width + 3 ; i++)
        {
            cout << '\xB2';
        }
        cout << endl;

        cout << "Score 1 "<<score1 << " Score 2 " << score2 << endl;


    }
    void input() // this function is used to get inputs from player
    {
        ball->Move();
        //int ballx = ball->getX();
        //int bally  = ball->getY();
        //int player1x = player1->getX();
        //int player2x = player2->getX();
        int player1y = player1->getY();
        int player2y = player2->getY();

        if(_kbhit()) //this is function which is used to check whether button is pressed .. if a button is pressed this will return non zero
        {
            char currentKey = _getch();
            if(currentKey == up1)
            {
                if(player1y>0) //checking whether the player is in the corner if he is in the corner he cant move up
                {
                    player1->moveUp();
                }
            }
            if(currentKey == up2)
            {
                if(player2y>0)
                {
                    player2->moveUp();
                }
            }
            if(currentKey == down1)
            {
                if(player1y+2 < height) // if the player is in the bottom it cant move
                {
                    player1->moveDown();
                }
            }
            if(currentKey == down2)
            {
                if(player2y+2 < height) // if the player is in the bottom it cant move
                {
                    player2->moveDown();
                }
            }

            if(ball->getDirection() == STOP)
            {
                ball->randomDirection(); //if the ball is stopped we randomise the direction of the ball
            }
            if(currentKey == 'q')
                quit = true;
        }
    }

    void logicOfGame()
    {
        int ballX = ball->getX();
        int ballY = ball->getY();
        int player1x = player1->getX();
        int player2x = player2->getX();
        int player1y = player1->getY();
        int player2y = player2->getY();

        for(int i = 0 ; i < 2  ; i++) // the length of the player is 2
        {
            //player 1 collision
            if(ballX == player1x + 1)
            {
                if(ballY ==player1y + i) // if the right part of the player is hit
                {
                    ball->changeDirection((eDir)((rand()%3) + 4)); // we give random right direction for the ball when the right part of the player is hit
                }
            }


        }

        for(int i = 0 ; i < 2  ; i++) // the length of the player is 2
        {
            //player 2 collision
            if(ballX == player2x - 1)
            {
                if(ballY == player2y + i) // if the right part of the player is hit
                {
                    ball->changeDirection((eDir)((rand()%3) + 1)); // we give random left direction for the ball when the left part of the player is hit
                }
            }


        }
        //top wall
        if(ballY == height - 1)
            ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT );

        if(ballY == 0)
            ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT );

        //if the rightplayer unable to hit the ball marks given for leftplayer
        if(ballX == width -1 )
            scoreUp(player1);
        //if the lefttplayer unable to hit the ball marks given for rightplayer
        if(ballX == 0)
            scoreUp(player2);


    }

    void run() // function used to run the game
    {
        //Draw();
        while(!quit)
        {
            Sleep(120);
            Draw();
            input();
            logicOfGame();

            //usleep(120);
        }
    }



};
int main()
{
    //srand(time(0)); // this is used to create true random values
    cGameManager c(40,20);

   c.run();
   //c.DrawPlayers();
    system("pause");

    return 0;
}


