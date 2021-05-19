#include "Medic.hpp"

using namespace std;
using namespace pandemic;


Player& Medic::treat(const City &city) {
   	if (this->city != city)
		{
			throw std::invalid_argument{" you are not in the city you want to treat  "};
		}
		if (board.level_of_disease(city)==0)
		{
			throw std::invalid_argument{"the disease level is 0"};
		}

    board.zero_level_disease(this->city);
    return *this;
}

void Medic::arrive() {
    if (board.if_cure_discover(citiesColers.at(this->city)))
		{
			board.zero_level_disease(this->city);
		}
}