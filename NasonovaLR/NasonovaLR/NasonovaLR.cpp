// NasonovaLR.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

struct Pipe
{
    int id;
    int d;
    int l;
};


void PrintePipe(Pipe& p)
{
    std::cout << "Pipe ID number: " << p.id << "  Diameter: " << p.d << " mm " << " Lenght: " << p.l << " km ";
}

Pipe AddPipe()
{
    Pipe p;
    p.id = 0;
    std::cout << "Enter the diameter ";
    std::cin >> p.d;
    std::cout << "Enter the lenght ";
    std::cin >> p.l;
    return p;
}

int main()
{
    Pipe p = AddPipe();
    PrintePipe(p);
}



