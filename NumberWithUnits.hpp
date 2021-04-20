#pragma once

#include <iostream>
#include <map>

namespace ariel
{
    class NumberWithUnits
    {
        int _len;
        std::string _type;
        std::map<std::string,int> units;
        public:
            NumberWithUnits( int len = 0 , std::string type = ""):_len(len){
                // if(!units[type]) throw std::string("the type illigal!! ");
                // else _type = type;
            }
            
            static void read_units(std::ifstream& x );
            const NumberWithUnits operator+ (const NumberWithUnits& c1) const{
                return c1;
            }
            NumberWithUnits& operator+=(const NumberWithUnits& c1){
                return *this;
            }
             NumberWithUnits operator+ (){
                return NumberWithUnits(2, "km");
            }
            //friend const NumberWithUnits operator+ (const NumberWithUnits& c1, const NumberWithUnits& c2);
            const NumberWithUnits operator- (const NumberWithUnits& c1) const {
                return NumberWithUnits(2, "km");
            }
            NumberWithUnits operator-= (const NumberWithUnits& c1){
                return c1;
            }
            NumberWithUnits operator- (){
                return NumberWithUnits(2, "km");
            }

            friend bool operator<(const NumberWithUnits& c1, const NumberWithUnits& c2);
            friend bool operator<=(const NumberWithUnits& c1, const NumberWithUnits& c2);
            friend bool operator>(const NumberWithUnits& c1, const NumberWithUnits& c2);
            friend bool operator>=(const NumberWithUnits& c1, const NumberWithUnits& c2);
            friend bool operator==(const NumberWithUnits& c1, const NumberWithUnits& c2);
            friend bool operator!=(const NumberWithUnits& c1, const NumberWithUnits& c2);
            friend bool operator<(const NumberWithUnits& c1, const NumberWithUnits& c2);
            NumberWithUnits& operator++() {
               return *this;

            }
            NumberWithUnits& operator++(int) {
               return *this;

            }
            NumberWithUnits& operator--() {
                return *this;
            }
            NumberWithUnits& operator--(int) {
                return *this;
            }
            friend NumberWithUnits operator*( const double x , const NumberWithUnits& c1/*, const double x*/);

            friend std::ostream& operator<< (std::ostream& os, const NumberWithUnits& c);
            friend std::istream& operator>> (std::istream& is, NumberWithUnits& c);









    };
}
