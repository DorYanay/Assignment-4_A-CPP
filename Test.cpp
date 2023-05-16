#include "doctest.h"
#include <cmath>
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"

TEST_CASE("Constructors")
{
    CHECK(OldNinja("sushi", Point(0, 0)));
    CHECK(YoungNinja("Yogi", Point(1, 1)));
    CHECK(TrainedNinja("Shmulik", Point(2, 2)));
    CHECK(Cowboy("Mike", Point(3, 3)));
    CHECK(Ninja("Young", Point(4, 4), 100, 25));
}
TEST_CASE("creating characters")
{
    Point a(32.3, 44), b(1.3, 3.5);
    CHECK_NOTHROW(Cowboy *tom = new Cowboy("tom", a));
    CHECK_NOTHROW(OldNinja *sushi = new OldNinja("sushi", b));
    CHECK_NOTHROW(YoungNinja *Yogi = new YoungNinja("Yogi", Point(1, 1)));
    CHECK_NOTHROW(TrainedNinja("Shmulik", Point(2, 2)));
    CHECK_NOTHROW(Ninja("Young", Point(4, 4), 100, 25));
}
TEST_CASE("Characters functions")
{
    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy *tom = new Cowboy("tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    YoungNinja *su = new YoungNinja("su", b);
    TrainedNinja *shi = new TrainedNinja("shi", b);
    CHECK_NOTHROW(tom->shoot(sushi));
    CHECK_NOTHROW(sushi->slash(tom));
    CHECK_NOTHROW(sushi->move(tom));
    CHECK_NOTHROW(tom->shoot(su));
    CHECK_NOTHROW(tom->shoot(shi));
    CHECK_NOTHROW(sushi->slash(su));
    CHECK_NOTHROW(sushi->move(shi));
    CHECK_NOTHROW(sushi->slash(shi));
    CHECK_NOTHROW(sushi->move(su));
    CHECK_NOTHROW(su->slash(tom));
    CHECK_NOTHROW(su->move(tom));
    CHECK_NOTHROW(shi->slash(tom));
    CHECK_NOTHROW(shi->move(tom));
    CHECK(tom->isAlive());
    sushi->move(shi);
    CHECK(sushi->getLocation());
    CHECK_NOTHROW(sushi->hit(10));
    CHECK(tom->hasboolets());
    CHECK_NOTHROW(sushi->slash(tom));
    CHECK_NOTHROW(tom->reload());
}
TEST_CASE("distance between points")
{
    Point a(32.3, 44), b(1.3, 3.5);
    CHECK(a.distance(b) == b.distance(a));
    Point c(0, 0), d(0, 0), g(1, 1);
    CHECK(c.distance(d) == 0);
    CHECK(d.distance(c) == 0);
    CHECK(c.distance(c) == 0);
    CHECK(c.distance(g) == sqrt(2));
    double dist1 = a.distance(b);
    Point::moveTowards(a, b, 1);
    CHECK(a.distance(b) != dist1);
}
TEST_CASE("distance between characters")
{

    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy *tom = new Cowboy("tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    YoungNinja *su = new YoungNinja("su", b);
    TrainedNinja *shi = new TrainedNinja("shi", b);
    CHECK(sushi->distance(*su) == 0);
    CHECK(sushi->distance(*tom) != 0);
}
TEST_CASE("check Team functions")
{
    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy *tom = new Cowboy("tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    YoungNinja *su = new YoungNinja("su", b);
    TrainedNinja *shi = new TrainedNinja("shi", b);
    Cowboy *tim = new Cowboy("tim", a);
    OldNinja *tam = new OldNinja("tam", b);
    YoungNinja *tuu = new YoungNinja("tuu", b);
    TrainedNinja *taa = new TrainedNinja("taa", b);
    YoungNinja *tpp = new YoungNinja("tpp", b);
    TrainedNinja *tcc = new TrainedNinja("tcc", b);
    YoungNinja *cpp = new YoungNinja("cpp", b);
    TrainedNinja *caa = new TrainedNinja("caa", b);
    CHECK_NOTHROW(Team teamA(tom));
    Team teamA(tom);
    CHECK_NOTHROW(teamA.add(sushi));
    CHECK_NOTHROW(Team2 teamB(su));
    Team2 teamB(su);
    CHECK_THROWS(teamB.add(tom));
    CHECK_THROWS(teamB.add(su));
    CHECK(teamA.stillAlive());
    CHECK_NOTHROW(teamA.print());
    CHECK_NOTHROW(teamB.print());
    CHECK_NOTHROW(teamA.attack(&teamB));
    teamA.add(sushi);
    teamA.add(shi);
    teamA.add(tim);
    teamA.add(tam);
    teamA.add(tuu);
    teamA.add(taa);
    teamA.add(tpp);
    teamA.add(tcc);
    teamA.add(cpp);
    CHECK_THROWS(teamA.add(caa));
    while (teamB.stillAlive())
    {
        teamA.attack(&teamB);
    }
    CHECK_EQ(teamB.stillAlive(), 0);
}