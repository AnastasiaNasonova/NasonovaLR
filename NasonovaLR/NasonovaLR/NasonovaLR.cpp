// NasonovaLR.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct Pipe
{
    int id;
    int d;
    float l;
    bool r;
};

struct CS 
{
    int id;
    string name;
    int numW, numA;
};

int GetInt()
{
    while (1)
    {
        int number;
        cin >> number;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Enter a variable int ";
        }
        else
        {
            return number;
        }
    }
}
float GetFloat()
{
    while (1)
    {
        float number;
        cin >> number;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Enter a variable float ";
        }
        else
        {
            return number;
        }
    }
}
bool GetBool()
{
    while (1)
    {
        bool number;
        cin >> number;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << " Enter 1 or 0 ";
        }
        else
        {
            return number;
        }
    }
}


void PrintPipe( const Pipe& p)
{
    if (p.id > 0) {
        cout << "Pipe " << endl << endl;
        cout << "Pipe ID number: " << p.id << "  Diameter: " << p.d << " mm " << " Lenght: " << p.l << " km\n";
        cout << "Pipe under repair: " << p.r << endl << endl; \
    }
    else cout << "No data pipe" << endl;
}


void PrintCS( const CS& c)
{
    if (c.id > 0) {
        cout << "Compressor Station " << endl << endl;
        cout << "CS ID number: " << c.id << " Name of the Compressor Station: " << c.name << " Number of workshops: " << c.numA << " Number of workshops in olperation: " << c.numW;
    }
    else cout << "No data CS" << endl;
}

Pipe AddPipe()
{
    Pipe p;
    p.id = 1;
    cout << "Enter the diameter from 500 to 1428: ";
    p.d = GetInt();

   
    while (p.d < 500 || p.d > 1428) {
        cout << "This diameter is not suitable, enter another one ";
        cin >> p.d;
    }
    cout << "Enter the lenght ";
    p.l = GetFloat();
    while (p.l < 10 || p.l > 1000) {
        cout << "The length should be from 10 to 1000 km, enter a lenght: ";
        p.l = GetFloat();
    }
    p.r = 0;
      
    return p;
}
CS AddCS()
{
    CS c;
    c.id = 1;
    cout << "Name of the Compressor Station ";
    cin >> ws;
    getline(cin, c.name);
    cout << "Number of workshops ";
    c.numA = GetInt();
    while (c.numA > 20 || c.numA < 0) {
        cout << "Workshops should be at least 1, but less then 20, enter a number of workshops ";
        c.numA = GetInt();
    }
    cout << "Number of workshops in olperation ";
    c.numW = GetInt();
    while (c.numW > c.numA) {
        cout << "The number of workstation must not exceed the number of all station " << endl << "Enter another number ";
        c.numW = GetInt();
    };
    return c;
}

void RedactPipe(Pipe& p) 
{
        if (p.id > 0) {
        cout << "Enter the state of the pipe (1 - under repair; 0 - not under repair)";
        p.r = GetBool();

        }
    else cout << "No pipe data available"; //данных о трубе нет
}
void RedactCS(CS& c) {

    if (c.id > 0) {
        cout << "How many workshops are in operation? ";
        c.numW = GetInt();

        while (c.numW > c.numA) {
            cout << "The number of workstation must not exceed the number of all station " << endl << "Enter another number";
            c.numW = GetInt();
        };
        while (c.numW < 0) {
            cout << "The number of workstation must not exceed the number of all station " << endl << "Enter another number";
            c.numW = GetInt();
        };
    }
    else cout << "No CS data available";
}

void Save( const Pipe& p, const CS& c)
{
    ofstream f;
    f.open("save.txt", ios_base::out);

    if (f.good())
    {
        if (p.id > 0)
        {
            f << "pipe" << endl << p.id << endl << p.l << endl << p.d << endl << p.r << endl;
        }

        if (c.id > 0)
        {
            f << "station" << endl << c.id << endl << c.name << endl << c.numA << endl << c.numW << endl;
            
        }
        f.close();
        cout << "Saved";

    }
    else cout << "No pipe or station";

}

void Load(Pipe& p, CS& c)
{
    ifstream f;
    f.open("save.txt", ios::in);
    if (f.good())
    {      
            while (!f.eof())
            {
                string str;
                f >> str;
                //cout << str;
                if (str == "pipe")
                {
                    f >> p.id;
                    f >> p.d;
                    f >> p.l;
                    f >> p.r;  
                }
              
                if (str == "station")
                {
                    f >> c.id;
                    f.ignore(256, '\n');
                    string(c.name);
                    getline(f, c.name);
                    f >> c.numA;
                    f >> c.numW;
                }              
            
            }
            cout << "Loaded";
    }
}

int main()
{
    int menu;

    Pipe p = {};
    CS c = {};
    
    for (;;) {
    cout << "\n 1. Add a pipe\n 2. Add Compressor Station\n 3. Viewing all objects\n 4. Redact Pipe\n 5. Redact CS\n 6. Save\n 7. Load\n 0. Exit\n";
    
    menu = GetInt();
    
        switch (menu)
        {
        case 0:
            return 0;
        case 1:
        {
            p = AddPipe();
            break;
        }
        case 2:
        {
            c = AddCS();
            break;
        }
        case 3:
        {
            PrintPipe(p);
            PrintCS(c);
            break;
        }
        case 4:
        {
            RedactPipe(p);
            break;
        }
        case 5:
        {
            RedactCS(c);
            break;
        }
        case 6:
        {
            Save(p, c);
            break;
        }
        case 7:
        {
            Load(p, c);
            break;
        }
        default:
            cout << "There is no such number in the menu, enter another number";
            break;
        }
    }
      

}





