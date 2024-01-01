#include "Settlement.h"

ostream & operator<<(ostream &os,Settlement &settlement) {
    os << settlement.name <<" "<<settlement.county<<" "<<settlement.population;
    return os;
}