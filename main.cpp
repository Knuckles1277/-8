#include <iostream>
#include "everything_but_main.h"

using namespace std;

int main()
{
    int t;
    int timer=6;
    int digger_i=4;
    int digger_j=7;
    int map[10][15]={
    {2,2,2,2,2,2,2,3,2,2,2,2,2,2,2},
    {2,1,1,2,2,2,2,0,2,2,2,2,1,1,2},
    {2,1,1,2,2,2,2,0,2,2,2,2,1,1,2},
    {2,2,2,2,2,2,2,0,2,2,2,2,2,2,2},
    {3,0,0,0,0,0,0,9,0,0,0,0,0,0,3},
    {2,2,2,2,2,2,2,0,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,0,2,2,2,2,2,2,2},
    {2,1,1,2,2,2,2,0,2,2,2,2,1,1,2},
    {2,1,1,2,2,2,2,0,2,2,2,2,1,1,2},
    {2,2,2,2,2,2,2,3,2,2,2,2,2,2,2}
    };
    cout << "\t\t\t\t\tDIGGER" << endl;
    cout << "\tWould you like to read the instructions? Type 1 if so or 0 if not. ";
    cin >> t;
    if (t) show_instructions();
    while (true)
    {
        show_map(map);
        show_menu(map, digger_i, digger_j, &timer);
        cin >> t;
        switch(t)
        {
            case 0:
                if(endstep(map, digger_i, digger_j, &timer)) return 0;
                break;
            case 1:
                if (map[digger_i][digger_j-1]<3&&(digger_i>=0)&&(digger_j-1>=0)&&(digger_i<10)&&(digger_j-1<15))
                {
                    map[digger_i][digger_j]=0;
                    map[digger_i][digger_j-1]=9;
                    digger_j--;
                    if(endstep(map, digger_i, digger_j, &timer)) return 0;
                    break;
                }
                else
                {
                    cout << "\tSuch command number isn't available.";
                    break;
                }
            case 2:
                if (map[digger_i][digger_j+1]<3&&(digger_i>=0)&&(digger_j+1>=0)&&(digger_i<10)&&(digger_j+1<15))
                {
                    map[digger_i][digger_j]=0;
                    map[digger_i][digger_j+1]=9;
                    digger_j++;
                    if(endstep(map, digger_i, digger_j, &timer)) return 0;
                    break;
                }
                else
                {
                    cout << "\tSuch command number isn't available.";
                    break;
                }
            case 3:
                if (map[digger_i-1][digger_j]<3&&(digger_i-1>=0)&&(digger_j>=0)&&(digger_i-1<10)&&(digger_j<15))
                {
                    map[digger_i][digger_j]=0;
                    map[digger_i-1][digger_j]=9;
                    digger_i--;
                    if(endstep(map, digger_i, digger_j, &timer)) return 0;
                    break;
                }
                else
                {
                    cout << "\tSuch command number isn't available.";
                    break;
                }
            case 4:
                if (map[digger_i+1][digger_j]<3&&(digger_i+1>=0)&&(digger_j>=0)&&(digger_i+1<10)&&(digger_j<15))
                {
                    map[digger_i][digger_j]=0;
                    map[digger_i+1][digger_j]=9;
                    digger_i++;
                    if(endstep(map, digger_i, digger_j, &timer)) return 0;
                    break;
                }
                else
                {
                    cout << "\tSuch command number isn't available.";
                    break;
                }
            case 5:
                if (map[digger_i][digger_j-1]%3==0&&map[digger_i][digger_j-1]!=0&&(digger_i>=0)&&(digger_j-1>=0)&&(digger_i<10)&&(digger_j-1<15)&&timer==6)
                {
                    map[digger_i][digger_j-1]=0;
                    timer=0;
                    if(endstep(map, digger_i, digger_j, &timer)) return 0;
                    break;
                }
                else
                {
                    cout << "\tSuch command number isn't available.";
                    break;
                }
                break;
            case 6:
                if (map[digger_i][digger_j+1]%3==0&&map[digger_i][digger_j+1]!=0&&(digger_i>=0)&&(digger_j+1>=0)&&(digger_i<10)&&(digger_j+1<15)&&timer==6)
                {
                    map[digger_i][digger_j+1]=0;
                    timer=0;
                    if(endstep(map, digger_i, digger_j, &timer)) return 0;
                    break;
                }
                else
                {
                    cout << "\tSuch command number isn't available.";
                    break;
                }
                break;
            case 7:
                if (map[digger_i-1][digger_j]%3==0&&map[digger_i-1][digger_j]!=0&&(digger_i-1>=0)&&(digger_j>=0)&&(digger_i-1<10)&&(digger_j<15)&&timer==6)
                {
                    map[digger_i-1][digger_j]=0;
                    timer=0;
                    if(endstep(map, digger_i, digger_j, &timer)) return 0;
                    break;
                }
                else
                {
                    cout << "\tSuch command number isn't available.";
                    break;
                }
                break;
            case 8:
                if (map[digger_i+1][digger_j]%3==0&&map[digger_i+1][digger_j]!=0&&(digger_i+1>=0)&&(digger_j>=0)&&(digger_i+1<10)&&(digger_j<15)&&timer==6)
                {
                    map[digger_i+1][digger_j]=0;
                    timer=0;
                    if(endstep(map, digger_i, digger_j, &timer)) return 0;
                    break;
                }
                else
                {
                    cout << "\tSuch command number isn't available.";
                    break;
                }
                break;
            default:
            cout << "\tSuch command number isn't available.";
        }
    }
}
