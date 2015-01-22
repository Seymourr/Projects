#include "gregorian.h"
#include "middle.h"
#include "kattistime.h"
namespace lab2{
		  Gregorian::Gregorian() {
			time_t mytime;
    		k_time(&mytime);
   			struct tm *currentTime = gmtime(&mytime);
			ar = (*currentTime).tm_year + 1900;
			manad = (*currentTime).tm_mon + 1;
			dag = (*currentTime).tm_mday;
		}
		
		  Gregorian::Gregorian(const Date & otherDate) {
		  	reset();
		  	int daysSince = otherDate.mod_julian_day();
		 	operator+=(daysSince);			  
		  	}
			
			Gregorian::Gregorian(const Date * otherDate) {
			if(!otherDate) 
			{
				throw std::out_of_range("Out of bounds");
			}
			reset();
		  	int daysSince = (*otherDate).mod_julian_day();
		  	operator+=(daysSince);				  
		  	}
		  	
		Gregorian::Gregorian(int year, int month, int day) {
			ar = year;
			manad = month;
			dag = day;
			if(year < startYear || year > endYear || month < 1 || month > 12 || day < 1 || day > days_this_month()) {
				throw std::out_of_range("Out of bounds");
			} 
			
		}

		bool Gregorian::leap_year() const{
			bool isLeapYear = false;
			if(year() % 4 == 0) {
				isLeapYear = true;
				if(year() % 100 == 0 && year() % 400 != 0) {
				isLeapYear = false;
				}
			
			}
			return isLeapYear;
		}
		double Gregorian::daysPerYearRatio() const{
				return 365.2425;
			}
		
		Date& Gregorian::operator ++(){
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
		
		Date& Gregorian::operator--(){
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
			//Kontrollera ++ operationerna
		Gregorian Gregorian::operator++(int) {
			Gregorian before = *this;
			++(*this);
			return before;
		}
		
		Gregorian Gregorian::operator--(int) {
			Gregorian before = *this;
			--(*this);
			return before;
		}
		
		void Gregorian::reset() {
		dag = 17;
		manad = 11;
		ar = 1858;
		}
		

		int Gregorian::JDN() const {
			int day = dag;
			int month = manad;
			int year = ar;

			int a = floor((14-month)/12);
			int y = year + 4800 - a;
			int m = month + 12*a -3;
			int JDN = day + floor((153*m + 2)/5) + 365*y + floor(y/4) - floor(y/100) + floor(y/400)- 32045;
			return JDN;
		
		}
		int Gregorian::mod_julian_day() const{
		
    		
			int MJD = floor(JDN() - 2400000.5);
    		return MJD;
    		
		}
}

