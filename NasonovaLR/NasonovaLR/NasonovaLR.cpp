// NasonovaLR.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

struct Pipe
{
    int id;
    int d;
};

int main()
{
    Pipe p;
    p.id = 0;
    std::cout << "Enter the diameter ";
    std::cin >> p.d;
    std::cout << "Pipe number: " << p.id << "Diameter: " << p.d;
}

