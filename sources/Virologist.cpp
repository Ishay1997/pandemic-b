#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

Player &Virologist::treat(const City &city)
{
    if (this->city != city)
    {

        if (cards.find(city) == cards.end())
        {
            throw std::invalid_argument{"you don't have this city card "};
        }
    }
    else
    {
        if (board.level_of_disease(city) == 0)
        {
            throw std::invalid_argument{"the disease level is 0"};
        }
        if (board.if_cure_discover(citiesColers.at(city)))
        {
            board.zero_level_disease(city);
            return *this;
        }
    }

    cards.erase(city);
    board.reduce_level_disease(city);
    return *this;
}
