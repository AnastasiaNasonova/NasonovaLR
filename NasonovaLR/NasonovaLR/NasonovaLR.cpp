// NasonovaLR.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

struct Pipe
{
    int id;
    int d;
    int l;
    bool r;
};

struct CS 
{
    int id;
    string name;
    int numA;
    int numW;
};


void PrintePipe(Pipe& p)
{
    cout << "Pipe ID number: " << p.id << "  Diameter: " << p.d << " mm " << " Lenght: " << p.l << " km\n";
    cout << "Pipe under repair: " << p.r;
}

Pipe AddPipe()
{
    Pipe p;
    p.id = 0;
    cout << "Enter the diameter ";
    cin >> p.d;
    cout << "Enter the lenght ";
    cin >> p.l;
    cout << "Is the pipe being repaired ? ";
    cin >> p.r;
    return p;
}

CS AddCS()
{
    CS c;
    c.id = 0;
    cout << "Name of the Compressor Station";
    cin >> c.name;
    cout << "Number of workshops";
    cin >> c.numA;
    cout << "Number of workshops in olperation";
    cin >> c.numW;
    return c;
}

int main()
{
    int menu;
    Pipe p;
    CS c;
    cout << " 1. Add a pipe\n 2. Add Compressor Station\n 3. Viewing all objects\n 0. Exit\n";
    cin >> menu;
    switch (menu)
    {
    case 0: 
        return 0;
    case 1:
        p = AddPipe();
    case 2:
        c = AddCS();
    case 3:
        PrintePipe(p);
    default: 
        break;
    }
    
      

}



