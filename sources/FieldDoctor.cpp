#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;


Player& FieldDoctor::treat(const City &city){
        if ((!Board::is_connected(this->city, city)) && this->city != city)
        {  
            throw std::invalid_argument{"this city doesn't connect to current city"};
        }
        if (board.level_of_disease(city) == 0)
        {
            throw std::invalid_argument{"the disease level is 0"};
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
