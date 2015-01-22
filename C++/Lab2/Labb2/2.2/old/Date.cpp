#include "Date.h"


//#include<string>

		int Date::mod_julian_day(const int year,const int month,const int day) const {
			struct tm currentTime;
			struct tm someYear;
			double seconds;
			
			currentTime.tm_hour = 0;   
			currentTime.tm_min = 0; 
			currentTime.tm_sec = 0;
	  		currentTime.tm_year = year;
			currentTime.tm_mon = month; 
			currentTime.tm_mday = day;

			someYear.tm_hour = 0;   
			someYear.tm_min = 0; 
			someYear.tm_sec = 0;
	  		someYear.tm_year = 0;
			someYear.tm_mon = 0; 
			someYear.tm_mday = 0;

			seconds = difftime(mktime(&currentTime), mktime(&someYear));
			
			int c1 = 44;
			double c2 = 365.2425 * 41 + c1;
			double daysSince1900 = seconds /(3600*24);
			int modJulDay = static_cast<int>((c2 + daysSince1900));
			return modJulDay;
		}
		
		int Date::year() const { return ar; }
		int Date::month() const { return manad; }
		int Date::day() const { return dag; }
		
		//Returtyper på operatorer?
		void Date::operator +=(int daysToAdd){
			if(day() + daysToAdd < days_this_month() || day() + daysToAdd > 0) {
			dag = day() + daysToAdd;
			} else{
				int restdagar = fmod(daysToAdd, daysPerYearRatio());
				ar = year() + ((daysToAdd - restdagar)/daysPerYearRatio());
				int currentDay = day();
				restdagar = restdagar * (daysToAdd/abs(daysToAdd));
					//Mindre än 365 dagar att addera
				while(abs(restdagar) > 0) {
				if(restdagar > 0) {
					if(currentDay + restdagar <= days_this_month()) {
					currentDay = currentDay + restdagar;
					restdagar = 0;
					} else{
						int daysTilNextMonth = days_this_month() - currentDay;
						restdagar = restdagar - daysTilNextMonth;
						manad = month() + 1;
						currentDay = 1; //Kan möjligtvis vara den sista i varje månad oxo om d klagar
						if(month() > months_per_year()) {
							ar = year() + 1;
							manad = 1;
						}
					}
				} else if(restdagar < 0) {
					if(currentDay + restdagar > 0) {
					currentDay = currentDay + restdagar;
					restdagar = 0;
					} else{
						restdagar = restdagar - currentDay;
						manad = month() - 1;
						
						if(month() < 1) {
							ar = year() - 1;
							manad = months_per_year();
						}
						currentDay = days_this_month(); //Kan möjligtvis vara den sista i varje månad oxo om d klagar
					}

				}
				}
				dag = currentDay;
			}
		}
	     void Date::operator -=(int daysToAdd){
	    std::cout << "Entered -=" << std::endl;
			dag += -daysToAdd;
	    }

		
		int Date::operator-(const Date &otherDate) {
			std::cout << "Entered -" << std::endl;
			int diff = 0;
			int d1 = mod_julian_day(year(), month(), day());
			std::cout << "Our day counter is " << d1 << std::endl;
			int d2 = mod_julian_day(otherDate.year(), otherDate.month(), otherDate.day());
			std::cout << "Next day counter is " << d2 << std::endl;
			diff = d1 - d2;
			return diff;
		}
		bool Date::operator== (const Date &otherDate) const {
			bool equal = false;
			// är datumen samma?
			int daysSinceJulianDay1 = mod_julian_day(year(), month(), day());
			int daysSinceJulianDay2 = mod_julian_day(otherDate.year(), otherDate.month(), otherDate.day());
			if(daysSinceJulianDay1 == daysSinceJulianDay2) equal = true;
			return equal;
		}
	
		bool Date::operator!= (const Date &otherDate) const {
		// är datumen olika?
			bool notequal = false;
			if(!(*this == otherDate)) notequal = true;
			return notequal;
			}
		
		//Date objekt?
		bool Date::operator< (const Date &otherDate) const {
			// är datumet mindre än rvaluet?
			bool less = false;
			
			int daysSinceJulianDay1 = mod_julian_day(year(), month(), day());
			int daysSinceJulianDay2 = mod_julian_day(otherDate.year(), otherDate.month(), otherDate.day());
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
			int daysSinceJulianDay1 = mod_julian_day(year(), month(), day());
			int daysSinceJulianDay2 = mod_julian_day(otherDate.year(), otherDate.month(), otherDate.day());
			if(daysSinceJulianDay1 > daysSinceJulianDay2) greater = true;
			return greater;				
		}
	
std::ostream & operator<<(std::ostream & os, const Date & someDate) {
		std::cout << "Now printing" << std::endl;
		std::string someYear = std::to_string(someDate.year()); //Inga ental pga datumbegränsning
		std::string someMonth = std::to_string(someDate.month());
		std::string someDay = std::to_string(someDate.day());
		if(someDate.month() < 10) {
			someMonth = "0" + someMonth;
		} 
		if(someDate.day() < 10) {
			someDay = "0" + someDay;
		}
		os << someYear << "-" << someMonth << "-" << someDay << "\n";
		return os;
		} 

