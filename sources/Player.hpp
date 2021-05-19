#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>

namespace pandemic {

    class Player {

        protected:
            Board& board;
            std::set<City> cards;
            City city; 
            std::string player_role;
            
        public:
            Player(Board& board,const City &city, std::string PlayerRole = "Player"): board(board), city(city), player_role(PlayerRole){}

            virtual Player& drive(const City &city);
            virtual Player& fly_direct(const City &city);
            virtual Player& fly_charter(const City &city);
            virtual Player& fly_shuttle(const City &city);
            virtual Player& build();
            virtual Player& discover_cure(const Color &color);
            virtual Player& treat(const City &city);//virtual
            virtual std::string role(){return player_role;}
            virtual Player& take_card(const City &city);
            virtual void remove_cards();
            virtual void arrive(){};//virtual
            static bool checkIfThereAre(const std::set<City> &ca, const Color &color, int num);
    };

}
