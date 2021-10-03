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
    int id, numA;
    string name;
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
    p.id = 1;
    cout << "Enter the diameter ";
    cin >> p.d;
    cout << "Enter the lenght ";
    cin >> p.l;
    p.r = 0;
    //cout << "Is the pipe being repaired ? ";
    //cin >> p.r;
    return p;
}

CS AddCS()
{
    CS c;
    c.id = 1;
    cout << "Name of the Compressor Station";
    cin >> c.name;
    cout << "Number of workshops";
    cin >> c.numA;
    cout << "Number of workshops in olperation";
    cin >> c.numW;
    return c;
}

Pipe RedactPipe(Pipe& p) {
    int k;
    if (p.id == 1) {
        cout << "Enter the state of the pipe (1 - under repair; 0 - not under repair)";
        cin >> p.r;
    }
    else cout << "No pipe data available"; //данных о трубе нет
    return p;
}

int main()
{
    int menu;

    Pipe p = {};
    CS c = {};
    cout << " 1. Add a pipe\n 2. Add Compressor Station\n 3. Viewing all objects\n 4. Redact Pipe\n 0. Exit\n";
    cin >> menu;
    switch (menu)
    {
    case 0: 
        return 0;
    case 1:
        p = AddPipe();
        break;
    case 2:
        c = AddCS();
        break;
    case 3:
        PrintePipe(p);
        break;
    case 4:
        RedactPipe(p);
        break;
    default: 
        break;
    }
    
      

}



