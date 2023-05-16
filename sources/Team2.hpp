#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "Team.hpp"

class Team2 : public Team
{
    Character *leader;
    vector<Character *> team;

public:
    Team2(Character *leader);
    void add(Character *);
    void attack(Team2 *);
    int stillAlive();
    void print();
    ~Team2();
};
