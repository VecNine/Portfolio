#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
using namespace std;

class cPlayer
{
public:
    int x, y;
    cPlayer(int GroundLevel = 5, int WidthLevel = 20)
    {
        x = WidthLevel / 2;
        y = GroundLevel-1;
    }
};

class cLevel
{
private:
    cPlayer* player;
    int ChanceOfBlock[28] = { 0 };
    bool GravitationOn = true;
    bool TouchingBlock = false;
    bool quit = false;
public:
    int GroundLevel;
    int WidthLevel;
   
    cLevel(int h = 5, int w = 20)
    {
        GroundLevel = h;
        WidthLevel = w;
        player = new cPlayer(GroundLevel, 0);
    }
    void Chance()
    {
        for (int i = 1; i < WidthLevel; i++)
        {
            if (rand() % 3 == 1)
            {
                ChanceOfBlock[i] = 1;
            }
            else
            {
                ChanceOfBlock[i] = 0;
            }
        }
    }
    void Draw()
    {
        system("cls");
        
        for (int i = 0; i <= GroundLevel; i++)
        {
            for (int j = 0; j < WidthLevel; j++)
            {

                if (GroundLevel == i)
                {
                    cout << "#";
                }
                else
                {
                    if (i==GroundLevel - 3||i == GroundLevel - 2 || i == GroundLevel - 1)
                    {
                        
                        if (ChanceOfBlock[j]==1)
                        {
                            cout << "X";
                            if (player->x == j && player->y == i)
                            {
                                GravitationOn = false;
                                TouchingBlock = true;
                                
                            }
                        }
                        else
                        {
                            if (player-> x == j && player->y == i)
                            {
                                cout << "V";
                                GravitationOn = true;
                            }
                            else
                            {
                                cout << " ";
                            }
                        }
                    }
                    else
                    {
                        if (player->x == j && player->y == i)
                        {
                            cout << "V";
                            GravitationOn = true;
                            
                        }
                        else 
                        {
                            cout << " ";
                        }
                    }

                }
            }
            cout << endl;
        }
    }
    void Input()
    {
           if (_kbhit())
           {
              char CurrentInput = _getch();

              if (CurrentInput == 'a')
              {
                   if (TouchingBlock == true)
                   {
                       player->x++;
                       TouchingBlock = false;
                   }
                   else 
                   {
                       player->x--;
                   }    
              }
              if (CurrentInput == 'd')
              {
                 if (TouchingBlock == true)
                 {
                     player->x--;
                     TouchingBlock = false;
                 }
                 else 
                 {
                     player->x++;
                 }
              }
              if (CurrentInput == 'w')
              {
                  player->y--;
              }
              if (CurrentInput == 'q')
              {
                  quit = true;
              }
           }
    }
    void Run()
    {
        Chance();
        while (!quit)
        {
            Draw();
            Input();
            Gravitation();
        }
    }
    void Gravitation()
    {
        if (player->y != GroundLevel-1 && rand() % 3 == 1 && GravitationOn == true)
        { 
            player->y++;
        }
        if (GravitationOn == false)
        {
            player->y--;
        }
    }
};

int main()
{
    srand(time(NULL));
    cLevel level(8, 24);
    level.Run();

    return 0;
}

