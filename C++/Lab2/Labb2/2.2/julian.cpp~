#include "julian.h"
#include "middle.h"
#include "kattistime.h"
namespace lab2 {
		Julian::Julian() {
		time_t mytime;
    	k_time(&mytime);
   		struct tm *currentTime = gmtime(&mytime);
		ar = (*currentTime).tm_year + 1900;
		manad = (*currentTime).tm_mon + 1;
		dag = (*currentTime).tm_mday;
	
		int diff = ar - 1600;
  		diff = 10 + diff/100 - diff/400;
  		operator-=(diff);
		}
		
		Julian::Julian(const Date& otherDate) {
			reset();
			int daysSince = otherDate.mod_julian_day();
			operator+=(daysSince);	  
		  	}
		  	
		Julian::Julian(const Date* otherDate) {
		if(!otherDate) 
			{
				throw std::out_of_range("Out of bounds");
			}
			
		reset();
		int daysSince = (*otherDate).mod_julian_day();
			operator+=(daysSince);			  
		  	}
		  	
		  	
		Julian::Julian(int year, int month, int day) { 
			ar = year;
			manad = month;
			dag = day;
			if(year < startYear || year > endYear || month < 1 || month > 12 || day < 1 || day > days_this_month()) {
				throw std::out_of_range("Out of bounds");
			} 
		}

		
		bool Julian::leap_year() const {
			bool isLeapYear = false;

			if(year() % 4 == 0) {
				isLeapYear = true;
			}
			return isLeapYear;
		}

		double Julian::daysPerYearRatio() const {
			return 365.25;
		}
		
		



		// ÄNDRADE HÄR NERE
		Date& Julian::operator ++(){
			if(day() + 1 > days_this_month()) { //Är vi på sista dagen i nån månad?
				dag = 1;
				if(manad + 1 > monthsPerYear) {
					manad = 1;
					add_year(1);
				} else {
				 manad = manad + 1;
				}
			
			} else {
				dag = day() + 1;
				
			}
		return *this;
		}
		
		Date& Julian::operator--(){
			if(day() - 1 < 1) { //Är vi på första dagen i nån månad?
					if(manad - 1 < 1) {
						manad = 12;
						dag = days_this_month();
						add_year(-1);
					} else {
						manad = manad - 1;
						dag = days_this_month();
					}
					
				
			} else {
			dag = dag - 1;
			}
			return *this;
		}
		Julian Julian::operator++(int) {
			Julian before = *this;
			++(*this);
			return before;
		}
		
		Julian Julian::operator--(int) {
			Julian before = *this;
			--(*this);
			return before;
		}
		
		void Julian::reset() {
		dag = 5;
		manad = 11; 
		ar = 1858;
		}
		
		int Julian::JDN() const {
			int day = dag;
			int month = manad;
			int year = ar;

			int a = floor((14-month)/12);
			int y = year + 4800 - a;
			int m = month + 12*a -3;
			int JDN = day + floor((153*m + 2)/5) + 365*y + floor(y/4) - 32083;
			return JDN;
		}
		int Julian::mod_julian_day() const{
			int MJD = floor(JDN() - 2400000.5);
    		return MJD;
		}
		
	bool Julian::isJulian() const {
		return true;
	}

	
}

