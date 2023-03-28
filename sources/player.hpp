#pragma once
#include <string>
namespace ariel {
    class Player {
        
        public:
            Player(std::string);
            int stacksize();
            int cardesTaken();
        private:
            std::string name;
            int stack_size;
    };
}