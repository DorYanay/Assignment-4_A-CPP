#pragma once
#include <iostream>
#include <string>
#include "Character.hpp"

class Ninja : public Character
{
    int speed;

public:
    Ninja(string name, const Point &location, int hitpoints, int speed);
    void move(const Character *);
    void slash(Character *);
};

class YoungNinja : public Ninja
{

public:
    YoungNinja(string name, const Point &location)
        : Ninja(name, location, 100, 14) {}
};

class TrainedNinja : public Ninja
{

public:
    TrainedNinja(string name, const Point &location)
        : Ninja(name, location, 120, 12) {}
};

class OldNinja : public Ninja
{

public:
    OldNinja(string name, const Point &location)
        : Ninja(name, location, 150, 8) {}
};
