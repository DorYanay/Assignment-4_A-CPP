#include "Character.hpp"
#include "Team2.hpp"
#include <vector>

Team2::Team2(Character *leader) : leader(leader) {}
void Team2::add(Character *member) {}
void Team2::attack(Team2 *other) {}
int Team2::stillAlive() { return 0; }
void Team2::print() {}
Team2::~Team2() {}