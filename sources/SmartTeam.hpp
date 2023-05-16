#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "Team.hpp"
#include "Team2.hpp"
class SmartTeam : public Team
{
    Character *leader;
    vector<Character *> team;

public:
    SmartTeam(Character *leader);
    void add(Character *);
    void attack(SmartTeam *);
    int stillAlive();
    void print();
    ~SmartTeam();
};
