#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;

const int n = 5;

Player &GeneSplicer::discover_cure(const Color &color)
{
    
    if (!board.if_discover_station(this->city))
    {
        throw std::invalid_argument{"doesn't have discover station in the city"};
    }
    if (this->cards.size() < n)
    {
        throw std::invalid_argument{"have less then 5 cards"};
    }
    int i=0;
    auto point=cards.begin();
    while (i<n)
    {
        point=this->cards.erase(point);
        i++;
    }
    board.add_cure_discover(color);
    return *this;
}
    