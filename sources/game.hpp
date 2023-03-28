#include <string>
#include "player.hpp"
namespace ariel {
    class Game {
        
        public:
            Game(Player, Player);
            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
        private:
            Player p1;
            Player p2;
            
    };
}