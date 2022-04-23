//
// Created by Amanda Yu on 4/17/22.
//

#ifndef MAIN_CPP_RANDOM_H
#define MAIN_CPP_RANDOM_H

#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <random>
using std::unordered_map;
using std::string;
using namespace std;
using namespace sf;

class Random
{
    // one instance of the x variable, and all instances SHARE this variable
    // static variables/functions exist for the lifetime of your program
    static mt19937 random;

public:
    // one and only one of this function
    static int Int(int min, int max);
    static float Float(float min, float max);
};


#endif //MAIN_CPP_RANDOM_H
