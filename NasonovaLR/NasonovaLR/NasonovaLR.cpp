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
    string r;
};

struct CS; {

}


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

int main()
{

    Pipe p = AddPipe();
    PrintePipe(p);
}



