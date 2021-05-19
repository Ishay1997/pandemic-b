#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

Player &Scientist::discover_cure(const Color &color)
{
    if (!board.if_discover_station(this->city))
    {
        throw std::invalid_argument{"doesn't have discover cure in this city."};
    }
    int num = this->n;
    for (City i : this->cards)
    {
        if (citiesColers.at(i) == color)
        {
            num--;
        }
    }
    if (num > 0){
        throw std::invalid_argument{"can't have cards for this action "};
    }
    int count = 1;
    for (auto it = cards.begin(); it != cards.end(); count++)
    {
        if (count == n)
        {
            break;
        }
        if (citiesColers.at(*it) == color)
        {
            it = cards.erase(it);
        }
        else
        {
            ++it;
        }
    }
    board.add_cure_discover(color);
    return *this;
}
