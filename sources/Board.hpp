#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>
#include <unordered_map>

namespace pandemic
{
    class Board
    {
    private:
        static std::map<City, std::set<City>> connections_cities;
        std::set<Color> diseas_discoverd; 
        std::set<City>research_stations;
        std::map<City, int>  diseas_level;
     

    public:
        Board() {}
        int &operator[](const City &city);
        bool is_clean();
        void remove_cures();
        void remove_stations();
        friend std::ostream &operator<<(std::ostream &out, const Board &board);

        void discover_cure(const Color &color);
        void add_discover_station(const City &city);
        bool if_discover_station(const City &city);
        void add_level_disease(const City &city);
        void reduce_level_disease(const City &city);
        void zero_level_disease(const City &city);
        int level_of_disease(const City &city);
        void add_cure_discover(const Color &color);
        bool if_cure_discover(const Color &color);
        static bool is_connected(const City &city1 ,const City &city2);
 
    };
} // namespace pandemic
