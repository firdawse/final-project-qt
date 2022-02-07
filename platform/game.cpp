#include "game.h"
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

Game::Game()
{

}
bool Game::LOSE()
{
    bool lose=true;

    for (auto i = 0; i < 4; i++)
    {
        for (auto j = 0; j <4; j++)
        {

            if (gridboard[i][j] == 0)
            {
                lose = false;
            }
        }
    }

    for (auto i = 0; i < 4 - 1; i++)
    {
        for (auto j = 0; j < 4 - 1; j++)
        {
            if (gridboard[i][j]== gridboard[i][j+1]&& gridboard[i][j]!=0)
            {
                lose = false;
            }
            else if (gridboard[j][i]== gridboard[j+1][i]&& gridboard[j][i]!=0)
            {
                lose = false;
            }
        }
    }
    return lose;
}

bool Game::WIN()
{
    for (auto i = 0; i <4; i++)
    {
        for (int j = 0; j <4; ++j)
        {

            if (gridboard[i][j]==2048)
            {
                return true;
            }

        }
    }
    return false;
}
void Game::AddRandom()
{
    vector<int> choice = { 4, 2, 4, 4, 2, 2, 2, 2 , 4,2 };
    //srand(time(0));
    int temp = rand() % choice.size()  ;
    int p1 = rand() % 4;
    int p2 = rand() % 4;
    while (gridboard[p1][p2] != 0)
    {
        p1 = rand() % 4;
        p2 = rand() % 4;
    }
    gridboard[p1][p2] = choice[temp];
    condition = false;
}

void Game::Up()
{
    for (auto i = 0; i <4; i++)
    { for (auto count= 0; count <3; count++){
            for (auto j = 0; j <4 - 1; j++)
            {
                if (gridboard[j][i] == 0)
                {
                    if(gridboard[j+1][i] != 0){condition = true;}
                    auto temp = gridboard[j][i];
                    gridboard[j][i] = gridboard[j + 1][i];
                    gridboard[j + 1][i] = temp;

                }
            }}
        for (auto j = 0; j < 4 - 1; j++)
        {
            if (gridboard[j][i] == gridboard[j + 1][i])
            {   if(gridboard[j][i] != 0){condition = true;}
                gridboard[j][i] = gridboard[j][i] * 2;
                score = gridboard[j][i] + score;
                gridboard[j + 1][i] = 0;
            }
        }
        for (auto count= 0; count <3; count++){
            for (auto j = 0; j < 4 - 1; j++)
            {
                if (gridboard[j][i] == 0)
                {
                    auto temp = gridboard[j][i];
                    gridboard[j][i] = gridboard[j + 1][i];
                    gridboard[j + 1][i] = temp;
                }
            }}
    }
    if(!WIN() && !LOSE())
    {
        if(condition){
                    AddRandom();
                    condition = false;}
    }
}

void Game::Down()
{
    for (auto i = 0; i < 4; i++)
    {   for (auto count= 0; count <4; count++){
            for (auto j = 4 - 1; j >0; j--)
            {
                if (gridboard[j][i] == 0)
                {   if(gridboard[j][i] != 0){condition = true;}
                    auto temp = gridboard[j][i];
                    gridboard[j][i] = gridboard[j - 1][i];
                    gridboard[j - 1][i] = temp;
                }
            }
        }
        for (auto j =4 - 1; j>0; j--)
        {
            if (gridboard[j][i] == gridboard[j - 1][i])
            {
                gridboard[j][i] = gridboard[j][i] * 2;
                score = gridboard[j][i] + score;
                gridboard[j - 1][i] = 0;
            }
        }
        for (auto count= 0; count <4; count++){
            for (auto j =4 - 1; j >0; j--)
             {
                if (gridboard[j][i] == 0)
                {   if(gridboard[j][i] != 0){condition = true;}
                    auto temp = gridboard[j][i];
                    gridboard[j][i] = gridboard[j - 1][i];
                    gridboard[j - 1][i] = temp;
                }
            }
        }
    }
    if(!WIN() && !LOSE())
    {
        if(condition){
                    this->AddRandom();
                    condition = false;}
    }
}

void Game::Left()
{
    for (auto j= 0; j <4; j++)
    {    for (auto count= 0; count <4; count++){
            for (auto i = 0; i <4 - 1; i++)
            {
                if (gridboard[j][i] == 0)
                {   if(gridboard[j][i+1] != 0){condition = true;}
                    auto temp = gridboard[j][i];
                    gridboard[j][i] = gridboard[j][i + 1];
                    gridboard[j][i + 1] = temp;
                }
            }}
        for (auto i = 0; i <4 - 1; i++)
        {
            if (gridboard[j][i]== gridboard[j][i+1])
            {
                gridboard[j][i] = gridboard[j][i] * 2;
                score = gridboard[j][i] + score;
                gridboard[j][i + 1] = 0;
            }
        }
        for (auto count= 0; count <4; count++){
            for (auto i = 0; i <4 - 1; i++)
            {
                // 0 2 0 2 -> 2 2 0 0
                if (gridboard[j][i] == 0)
                {   if(gridboard[j][i] != 0){condition = true;}
                    auto temp = gridboard[j][i];
                    gridboard[j][i] = gridboard[j][i + 1];
                    gridboard[j][i + 1] = temp;
                }
            }}
    }
    if(!WIN() && !LOSE())
    {
        if(condition){
                    this->AddRandom();
                    condition = false;}
    }
}
void Game::Right()
{
    for (auto j = 0; j < 4; j++)
    {   for (auto count= 0; count <4; count++){
            for (auto i =4 - 1; i>0; i--)
            {
                if (gridboard[j][i] == 0)
                {   if(gridboard[j][i] != 0){condition = true;}
                    auto temp = gridboard[j][i];
                    gridboard[j][i] = gridboard[j][i - 1];
                    gridboard[j][i - 1] = temp;
                }
            }}
        for (auto i =4 - 1; i >0; i--)
        {
            if (gridboard[j][i] == gridboard[j][i - 1])
            {
                gridboard[j][i] = gridboard[j][i] * 2;
                score = gridboard[j][i] + score;
                gridboard[j][i - 1] = 0;
            }
        }
        for (auto count= 0; count <4; count++){
            for (auto i = 4 - 1; i > 0; i--)
            {
                if (gridboard[j][i] == 0)
                {   if(gridboard[j][i] != 0){condition = true;}
                    auto temp = gridboard[j][i];
                    gridboard[j][i] = gridboard[j][i - 1];
                    gridboard[j][i - 1] = temp;
                }
            }}
    }
    if(!WIN() && !LOSE())
    {     if(condition){
            this->AddRandom();
            condition = false;
        }
    }
}
void Game::Restart()
{
    this->score = 0;
    for (auto i = 0; i < 4; i++)
    {
        for (auto j = 0; j < 4; j++)
        {
            gridboard[i][j] =0;
        }
    }
    this->AddRandom();
}
