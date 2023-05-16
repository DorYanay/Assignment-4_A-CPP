#include "Character.hpp"
#include "SmartTeam.hpp"
#include <vector>

SmartTeam::SmartTeam(Character *leader) : leader(leader) {}
void SmartTeam::add(Character *member) {}
void SmartTeam::attack(SmartTeam *other) {}
int SmartTeam::stillAlive() { return 0; }
void SmartTeam::print() {}
SmartTeam::~SmartTeam() {}