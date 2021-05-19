#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class GeneSplicer: public Player {

        public:
            GeneSplicer(Board& board,const City &color): Player(board, color, "GeneSplicer") {}
            Player& discover_cure(const Color &color) ;
    };
    
}