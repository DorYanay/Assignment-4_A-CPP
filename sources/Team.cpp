#include "Character.hpp"
#include "Team.hpp"
#include <vector>

Team::Team(Character *leader) : leader(leader) {}
void Team::add(Character *member) {}
void Team::attack(Team *other) {}
int Team::stillAlive() { return 0; }
void Team::print() {}
Team::~Team() {}