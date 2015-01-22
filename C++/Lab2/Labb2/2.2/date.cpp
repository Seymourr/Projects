#include "date.h"


//#include<string>
namespace lab2 {
		
		int Date::year() const { return ar; }
		int Date::month() const { return manad; }
		int Date::day() const { return dag; }
		//Returtyper på operatorer?
		
		
		Date& Date::operator +=(int daysToAdd){
		if(daysToAdd < 0){
			(*this)-=(daysToAdd/-1);
		} else {
			while(daysToAdd > 0) {
				operator++();
				daysToAdd = daysToAdd - 1;
			}
		}
		return *this;
		}
		
			
			
			
	     Date& Date::operator -=(int daysToRemove){
	     if(daysToRemove < 0){
	    	 (*this)+=(daysToRemove/-1);
	     } else {
	     	while(daysToRemove > 0) {
	     		--(*this);
	     	daysToRemove = daysToRemove - 1;
	     }
	     }
	     return *this;
	     }
	    		
		Date & Date::operator=(const Date & otherDate) {
		if(*this == otherDate) {
			return *this;
		}
		reset();
		int daysSince = otherDate.mod_julian_day();
		operator+=(daysSince);	
		return *this;
		}

		
		int Date::operator-(const Date &otherDate) const {
			int diff = 0;
			int d1 = mod_julian_day();
			int d2 = otherDate.mod_julian_day();
			diff = d1 - d2;
			return diff;
		}
		bool Date::operator== (const Date &otherDate) const {
			bool equal = false;
			// är datumen samma?
			int daysSinceJulianDay1 = mod_julian_day();
			int daysSinceJulianDay2 = otherDate.mod_julian_day();
			if(daysSinceJulianDay1 == daysSinceJulianDay2) equal = true;
			return equal;
		}
	
		bool Date::operator!= (const Date &otherDate) const {
		// är datumen olika?
			bool notequal = false;
			if(!((*this) == otherDate)) notequal = true;
			return notequal;
			}
		
		//Date objekt?
		bool Date::operator< (const Date &otherDate) const {
			// är datumet mindre än rvaluet?
			bool less = false;
			
			int daysSinceJulianDay1 = mod_julian_day();
			int daysSinceJulianDay2 = otherDate.mod_julian_day();
			if(daysSinceJulianDay1 < daysSinceJulianDay2) less = true;
			return less;	
		}
		
			//Date objekt?
		bool Date::operator<= (const Date &otherDate) const {
			// är datumet mindre eller lika med rvaluet
			bool notless = false;
			if(!(*this > otherDate)) notless = true;
			return notless;
		}
			//Date objekt?
		bool Date::operator>= (const Date &otherDate) const {
			// är datumet större lika med rvalue?
			bool greaterOrEqual = false;
			if(!(*this < otherDate)) greaterOrEqual = true;
			return greaterOrEqual;
		}
		
			//Date objekt?
		bool Date::operator> (const Date &otherDate) const {
			// är lvalue större än rvalue?
			bool greater = false;
			int daysSinceJulianDay1 = mod_julian_day();
			int daysSinceJulianDay2 = otherDate.mod_julian_day();
			if(daysSinceJulianDay1 > daysSinceJulianDay2) greater = true;
			return greater;				
		}
		std::ostream & operator<<(std::ostream & os, const Date & someDate){
		std::string someYear = std::to_string(someDate.year()); //Inga ental pga datumbegränsning
		std::string someMonth = std::to_string(someDate.month());
		std::string someDay = std::to_string(someDate.day());
		if(someDate.month() < 10) {
			someMonth = "0" + someMonth;
		} 
		if(someDate.day() < 10) {
			someDay = "0" + someDay;
		}
		os << someYear << "-" << someMonth << "-" << someDay;
		return os;
		}
}

