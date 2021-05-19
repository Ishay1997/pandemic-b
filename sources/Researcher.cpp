#include "Researcher.hpp"

using namespace std;
namespace pandemic
{
    const int n = 5;

    Player &Researcher::discover_cure(const Color &color)
    {
        if (!checkIfThereAre(this->cards, color, n))
        {
            throw std::invalid_argument{"have less then 5 cards in this color"};
        }
        int count = 0;
        
        for (auto city_card=cards.begin();count<n&&city_card!=cards.end();)
        {
            if (citiesColers.at(*city_card) == color)
            {
                count++;
                city_card=cards.erase(city_card);
            }
            else{
                city_card++;
            }
        }
        board.add_cure_discover(color);
        return *this;
    }
} 