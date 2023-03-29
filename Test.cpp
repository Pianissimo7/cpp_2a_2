#include "doctest.h"
#include "game.hpp"

using namespace ariel;

TEST_CASE("making players") {
    
    CHECK_NOTHROW(Player p1("Alice"));
    CHECK_NOTHROW(Player p2("Bob"));
}

TEST_CASE("making a game") {
    
    Player p1("Alice");
    Player p2("Bob");

    CHECK_NOTHROW(Game game(p1,p2));
}
TEST_CASE("game functions") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    
    SUBCASE("printing the last turn before any turn was played should return an error") {
        CHECK_THROWS(game.printLastTurn());
    }
    
    SUBCASE("make sure both players start out with 27 cards each") {
        CHECK(p1.stacksize() == 27);
        CHECK(p2.stacksize() == 27);
    }

    SUBCASE("make sure no player has won cards before a turn was played") {
        CHECK(p1.cardesTaken() == 0);
        CHECK(p2.cardesTaken() == 0);
    }
    SUBCASE("make sure the stack size is updating after every turn") {
        for (int i=0;i<5;i++) {
            
            CHECK_NOTHROW(game.playTurn());
            CHECK(p1.stacksize() <= 27 - (i + 1));
            CHECK(p2.stacksize() <= 27 - (i + 1));
        }
    }
    CHECK_NOTHROW(game.printLastTurn());

    SUBCASE("make sure play all works") {
        CHECK_NOTHROW(game.playAll());
        SUBCASE("make sure after play all was called that one player ran out of cards") {
            bool atleast_one_player_out_of_cards = p1.stacksize() == 0 || p2.stacksize() == 0;
            CHECK(atleast_one_player_out_of_cards == true);
        }
    }
    
    SUBCASE("print functions should not throw errors") {
        CHECK_NOTHROW(game.printWiner()); 
        CHECK_NOTHROW(game.printLog());
        CHECK_NOTHROW(game.printStats());
    }
}
