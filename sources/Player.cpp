#include "Player.hpp"

using namespace std;
using namespace pandemic;
const int n = 5;

Player &Player::take_card(const City &city)
{
    cards.insert(city);
    return *this;
}

Player &Player::drive(const City &city)
{
    if (!Board::is_connected(this->city, city))
    {
        throw std::invalid_argument{"this cities are not connected" };
    }
    this->city = city;
    arrive();
    return *this;
}
Player &Player::build()
{

    if (board.if_discover_station(this->city))
    {
        return *this;
    }
    if (cards.find(this->city) == cards.end())
    {
        throw std::invalid_argument{"doesn't have this city  card"};
    }
    board.add_discover_station(this->city);
    this->cards.erase(this->city);

    return *this;
}


Player &Player::discover_cure(const Color &color)
{ 
    if (!board.if_discover_station(this->city))
    {
        throw std::invalid_argument{"in this city there is no discover station"};
    }
    
        if (!checkIfThereAre(this->cards, color, n))
        {
            throw std::invalid_argument{"have less then 5 cards in this color"};
        }
        int count = 0;

        for (auto city_card = cards.begin(); count < n && city_card != cards.end();)
        {
            if (citiesColers.at(*city_card) == color)
            {
                count++;
                city_card = cards.erase(city_card);
            }
            else
            {
                city_card++;
            }
        }
        board.add_cure_discover(color);
        return *this;
   
}

Player &Player::fly_direct(const City &city)
{
    if (cards.find(city) == cards.end())
    {
        throw std::invalid_argument{"you don't have this city  card" };
    }
    cards.erase(city);
    this->city = city;
    arrive();
    return *this;
}

Player &Player::fly_charter(const City &city)
{
    if (cards.find(this->city) == cards.end())
    {
        throw std::invalid_argument{"you don't have this city  card" };
    }
    cards.erase(this->city);
    this->city = city;
    arrive();
    return *this;
}

Player &Player::fly_shuttle(const City &city)
{
    if (this->city == city)
    {
        throw std::invalid_argument{"already in this city."};
    }
    if (board.if_discover_station(this->city) && board.if_discover_station(city))
    {
        this->city = city;
        arrive();
        return *this;
    }
    throw std::invalid_argument{"there is no discover satation in the city you in or in the city you want to fly"};
}



Player &Player::treat(const City &city)
{

        if (board.level_of_disease(city) == 0)
        {
            throw std::invalid_argument{"disease level is 0"};
        }
        if (board.if_cure_discover(citiesColers.at(city)))
        {
            board.zero_level_disease(city);
        }
        else
        {
            board.reduce_level_disease(city); 
        }
        return *this;
}
    void Player::remove_cards(){
        this->cards.clear();
    }
bool Player::checkIfThereAre(const std::set<City> &ca,const Color &color, int num)
{
    for (City i : ca)
    {
        if (citiesColers.at(i) == color)
        {
            num--;
        }
        if (num == 0)
        {
            return true;
        }
    }
    return false;
 }