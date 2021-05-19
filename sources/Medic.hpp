#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Medic: public Player {

        public:
            Medic(Board& board,const City &color): Player(board, color, "Medic") {}
            Player& treat(const City &city) override;
            void arrive() override;
    };
    
}