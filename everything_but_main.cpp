#include <iostream>
#include "everything_but_main.h"

using namespace std;

void show_instructions()
{
    cout << "\tIn this game you control a machine called digger. It is marked" << endl;
    cout << "\ton the map as number 9. It can move through corridors (number " << endl;
    cout << "\t0 on the map) or dig tunnels though dirt (number 2). Your goal " << endl;
    cout << "\tis to either collect all emeralds (number 1, they can be" << endl;
    cout << "\tdug out by coming to the same square) or kill all monsters" << endl;
    cout << "\twho try to destroy your digger (num. 3,6, etc). If they come" << endl;
    cout << "\tto the same square as your digger, you will lose. However, you" << endl;
    cout << "\tcan fight monsters which kills them once in 5 turns. Good luck!" << endl;
}

void show_map(int map[10][15])
{
    for (int i=0; i<10; i++)
    {
        cout << "\n_____________________________________________"<< endl;
        for (int j=0; j<15; j++)
        {
            cout << "|" << map[i][j] << "|";
        }
    }
    cout << endl;
}

void show_menu(int map[10][15], int digger_i, int digger_j, int *timer)
{
    cout << "\n\tList of available options:" << endl;
    cout << "\t0. Do nothing" << endl;
    if (map[digger_i][digger_j-1]<3&&(digger_i>=0)&&(digger_j-1>=0)&&(digger_i<10)&&(digger_j-1<15)) cout << "\t1. Move left" << endl;
    if (map[digger_i][digger_j+1]<3&&(digger_i>=0)&&(digger_j+1>=0)&&(digger_i<10)&&(digger_j+1<15)) cout << "\t2. Move right" << endl;
    if (map[digger_i-1][digger_j]<3&&(digger_i-1>=0)&&(digger_j>=0)&&(digger_i-1<10)&&(digger_j<15)) cout << "\t3. Move up" << endl;
    if (map[digger_i+1][digger_j]<3&&(digger_i+1>=0)&&(digger_j>=0)&&(digger_i+1<10)&&(digger_j<15)) cout << "\t4. Move down" << endl;
    if (map[digger_i][digger_j-1]%3==0&&map[digger_i][digger_j-1]!=0&&(digger_i>=0)&&(digger_j-1>=0)&&(digger_i<10)&&(digger_j-1<15)&&*timer==6) cout << "\t5. Fight a monster to the left" << endl;
    if (map[digger_i][digger_j+1]%3==0&&map[digger_i][digger_j+1]!=0&&(digger_i>=0)&&(digger_j+1>=0)&&(digger_i<10)&&(digger_j+1<15)&&*timer==6) cout << "\t6. Fight a monster to the right" << endl;
    if (map[digger_i-1][digger_j]%3==0&&map[digger_i-1][digger_j]!=0&&(digger_i-1>=0)&&(digger_j>=0)&&(digger_i-1<10)&&(digger_j<15)&&*timer==6) cout << "\t7. Fight a monster above" << endl;
    if (map[digger_i+1][digger_j]%3==0&&map[digger_i+1][digger_j]!=0&&(digger_i+1>=0)&&(digger_j>=0)&&(digger_i+1<10)&&(digger_j<15)&&*timer==6) cout << "\t8. Fight a monster below" << endl;
    cout << "\tType the corresponding option number: ";
}

bool endstep(int map[10][15], int digger_i, int digger_j, int *timer)
{
    bool emerald=true;
    bool monster=true;
    bool win=false;
    if (*timer<6) *timer=*timer+1;
    cout << *timer << endl;

    for (int i=0; i<10; i++)
    {
        for (int j=0; j<15; j++)
            if (map[i][j]%3==0&&map[i][j]!=0)
            {
                if (i<digger_i&&map[i][j]%11!=0&&map[i+1][j]%3==0)
                {
                    map[i+1][j]=(map[i+1][j]+map[i][j])*11;
                    map[i][j]=0;
                }
                if (i>digger_i&&map[i][j]%11!=0&&map[i-1][j]%3==0)
                {
                    map[i-1][j]=(map[i-1][j]+map[i][j])*11;
                    map[i][j]=0;
                }
                if (j<digger_j&&map[i][j]%11!=0&&map[i][j+1]%3==0)
                {
                    map[i][j+1]=(map[i][j+1]+map[i][j])*11;
                    map[i][j]=0;
                }
                if (j>digger_j&&map[i][j]%11!=0&&map[i][j-1]%3==0)
                {
                    map[i][j-1]=(map[i][j-1]+map[i][j])*11;
                    map[i][j]=0;
                }
            }
    }

    for (int i=0; i<10; i++)
    {
        for (int j=0; j<15; j++)
            if (map[i][j]%11==0) map[i][j]=map[i][j]/11;
    }


    if (map[digger_i][digger_j]>9)
    {
        show_map(map);
        cout << "\n\tOh no! Monsters broke your digger!" << endl;
        return true;
    }

    for (int i=0; i<10; i++)
    {
        for (int j=0; j<15; j++)
            if (map[i][j]==1) emerald=false;
    }

    for (int i=0; i<10; i++)
    {
        for (int j=0; j<15; j++)
            if (map[i][j]%3==0&&map[i][j]!=0&&map[i][j]!=9) monster=false;
    }

    win=emerald+monster;
    if (!win) return false;
    show_map(map);
    cout << "\n\tCongratulations! You won!" << endl;
    return true;
}
