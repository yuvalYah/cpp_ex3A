#include "NumberWithUnits.hpp"
using namespace std;

namespace ariel
{   
           
void NumberWithUnits::read_units(ifstream& x){}
///frinde        
bool operator<(const NumberWithUnits& c1, const NumberWithUnits& c2){return true;}
bool operator<=(const NumberWithUnits& c1, const NumberWithUnits& c2){return true;}
bool operator>(const NumberWithUnits& c1, const NumberWithUnits& c2){return true;}
bool operator>=(const NumberWithUnits& c1, const NumberWithUnits& c2){return true;}
bool operator==(const NumberWithUnits& c1, const NumberWithUnits& c2){return true;}
bool operator!=(const NumberWithUnits& c1, const NumberWithUnits& c2){return true;}
NumberWithUnits operator*( const double x , const NumberWithUnits& c1/*, const double x*/){return NumberWithUnits(2, "km");}

ostream& operator<< (ostream& os, const NumberWithUnits& c){return os<<"";}
istream& operator>> (istream& is, NumberWithUnits& c){return is ;}

    
}
