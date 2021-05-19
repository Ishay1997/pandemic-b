#include "Board.hpp"

using namespace std;
using namespace pandemic;

int& Board::operator[](const City &city) {
    return this->diseas_level[city];
}

bool Board::is_clean() {
     for (auto i = diseas_level.begin(); i != diseas_level.end(); ++i)
    {
      if (i->second != 0)
      {
        return false;
      }
    }
    return true;
  }

bool Board::is_connected(const City &city1,const City &city2) {
    return (connections_cities.at(city1).find(city2)!=connections_cities.at(city1).end());
}

void Board::remove_cures() {
    diseas_discoverd.clear();
}

void Board::remove_stations()
  {
      research_stations.clear(); 
  }

  void Board::discover_cure(const Color &color)
  {
    diseas_discoverd.insert(color);
  }

void Board::add_discover_station(const City &city)
  {
    research_stations.insert(city);
  }

  bool Board::if_discover_station(const City &city)
  {
    return (research_stations.find(city)!=research_stations.end());
  }
  void Board::add_level_disease(const City &city)
  {
    diseas_level.at(city)++;
  }
  void Board::reduce_level_disease(const City &city)
  {
    diseas_level.at(city)--;
  }
  void Board::zero_level_disease(const City &city)
  {
    diseas_level.at(city) = 0;
  }
  int Board::level_of_disease(const City &city)
  {
    return (diseas_level.at(city));
  }
  void Board::add_cure_discover(const Color &color)
  {
    diseas_discoverd.insert(color);
  }
   bool Board::if_cure_discover(const Color &color)
  {
    return ((diseas_discoverd.find(color)!=diseas_discoverd.end()));
  }
  
std::ostream& pandemic::operator<<(std::ostream& out, const Board& board) {
  return out;
}


std::map<City, std::set<City>> Board::connections_cities {
    { Algiers, {Madrid, Paris, Istanbul, Cairo } },
    { Atlanta, {Chicago, Miami, Washington } },
    { Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi } },
    { Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong } },
    { Beijing, {Shanghai, Seoul } },
    { Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires } },
    { BuenosAires, {Bogota, SaoPaulo } },
    { Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh } },
    { Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta } },
    { Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal } },
    { Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata } },
    { Essen, {London, Paris, Milan, StPetersburg } },
    { HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila } },
    { HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei } },
    { Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow } },
    { Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney } },
    { Johannesburg, {Kinshasa, Khartoum } },
    { Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi } },
    { Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg } },
    { Kinshasa, {Lagos, Khartoum, Johannesburg } },
    { Kolkata, {Delhi, Chennai, Bangkok, HongKong } },
    { Lagos, {SaoPaulo, Khartoum, Kinshasa } },
    { Lima, {MexicoCity, Bogota, Santiago } },
    { London, {NewYork, Madrid, Essen, Paris } },
    { LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney } },
    { Madrid, {London, NewYork, Paris, SaoPaulo, Algiers } },
    { Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong } },
    { MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota } },
    { Miami, {Atlanta, MexicoCity, Washington, Bogota } },
    { Milan, {Essen, Paris, Istanbul } },
    { Montreal, {Chicago, Washington, NewYork } },
    { Moscow, {StPetersburg, Istanbul, Tehran } },
    { Mumbai, {Karachi, Delhi, Chennai } },
    { NewYork, {Montreal, Washington, London, Madrid } },
    { Osaka, {Taipei, Tokyo } },
    { Paris, {Algiers, Essen, Madrid, Milan, London } },
    { Riyadh, {Baghdad, Cairo, Karachi } },
    { SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila } },
    { Santiago, {Lima } },
    { SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid } },
    { Seoul, {Beijing, Shanghai, Tokyo } },
    { Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo } },
    { StPetersburg, {Essen, Istanbul, Moscow } },
    { Sydney, {Jakarta, Manila, LosAngeles } },
    { Taipei, {Shanghai, HongKong, Osaka, Manila } },
    { Tehran, {Baghdad, Moscow, Karachi, Delhi } },
    { Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco } },
    { Washington, {Atlanta, NewYork, Montreal, Miami } }
};