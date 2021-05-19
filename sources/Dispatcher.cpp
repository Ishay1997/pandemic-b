#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Player &Dispatcher::fly_direct(const City &city)
{
    if (this->city == city)
    {
        throw std::invalid_argument{"you already in this city"};
    }

    if (board.if_discover_station(this->city))
    {
        this->city = city;
    }
    else
    {
        auto v = Player::fly_direct(city);
    }

    return *this;
}