#include "OperationsExpert.hpp"

using namespace std;
using namespace pandemic;


Player& OperationsExpert::build(){
   
    board.add_discover_station(this->city);
    return *this;
}