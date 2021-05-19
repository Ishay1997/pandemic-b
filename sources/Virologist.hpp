#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Virologist: public Player {

        public:
            Virologist(Board& board, const City &color): Player(board, color, "Virologist") {}
            Player& treat(const City &c) override;
    };

}