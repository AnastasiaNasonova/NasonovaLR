// NasonovaLR.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

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
    cout << "Pipe " << endl << endl;
    cout << "Pipe ID number: " << p.id << "  Diameter: " << p.d << " mm " << " Lenght: " << p.l << " km\n";
    cout << "Pipe under repair: " << p.r << endl << endl;
}

void PrinteCS(CS& c)
{
    cout << "Compressor Station " << endl << endl;
    cout << "CS ID number: "<< c.id << " Name of the Compressor Station: " << c.name << " Number of workshops: " << c.numA << " Number of workshops in olperation: " << c.numW;
}

Pipe AddPipe()
{
    Pipe p;
    p.id = 1;
    cout << "Enter the diameter ";
    cin >> p.d;
    while (p.d > 500) {
        cout << "The diameter is too large, enter another one ";
        cin >> p.d;
    }
    cout << "Enter the lenght ";
    cin >> p.l;
    while (p.l < 50 && p.l > 200) {
        cout << "The length should be from 50 to 200 km, enter a lenght: ";
        cin >> p.l;
    }
    p.r = 0;
    //cout << "Is the pipe being repaired ? ";
    //cin >> p.r;
    return p;
}

CS AddCS()
{
    CS c;
    c.id = 1;
    cout << "Name of the Compressor Station ";
    cin >> c.name;
    cout << "Number of workshops ";
    cin >> c.numA;
    cout << "Number of workshops in olperation ";
    cin >> c.numW;
    while (c.numW > c.numA) {
        cout << "The number of workstation must not exceed the number of all station " << endl << "Enter another number ";
        cin >> c.numW;
    };
    return c;
}

Pipe RedactPipe(Pipe& p) {
    if (p.id == 1) {
        cout << "Enter the state of the pipe (1 - under repair; 0 - not under repair)";
        cin >> p.r;
    }
    else cout << "No pipe data available"; //данных о трубе нет
    return p;
}
CS RedactCS(CS& c) {

    if (c.id == 1) {
        cout << "How many workshops are in operation? ";
        cin >> c.numW;
        while (c.numW > c.numA) {
            cout << "The number of workstation must not exceed the number of all station " << endl << "Enter another number";
            cin >> c.numW;
        };
    }
    else cout << "No CS data available";
    return c;
}

int main()
{
    int menu;

    Pipe p = {};
    CS c = {};
    for (;;) {
    cout << "\n 1. Add a pipe\n 2. Add Compressor Station\n 3. Viewing all objects\n 4. Redact Pipe\n 5. Redact CS\n 0. Exit\n";
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
            PrinteCS(c);
            break;
        case 4:
            RedactPipe(p);
            break;
        case 5:
            RedactCS(c);
            break;
        default:
            break;
        }
    }
      

}



