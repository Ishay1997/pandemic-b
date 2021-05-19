#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Researcher: public Player {

        public:
            Researcher(Board& b,const City &color): Player(b, color, "Researcher") {}
            Player& discover_cure(const Color &color) ;
    };

}