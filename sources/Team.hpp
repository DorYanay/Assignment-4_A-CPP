#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Ninja.hpp"
#include "Cowboy.hpp"
namespace ariel
{
};
class Team
{
    Character *leader;
    vector<Character *> team;

public:
    Team(Character *leader);
    void add(Character *);
    void attack(Team *);
    int stillAlive();
    void print();
    ~Team();
};
