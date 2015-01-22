#include "gregorian.h"
#include "middle.h"

class Gregorian : public middle {
	public:

		  Gregorian() {
		  	std::cout << "Creating gregorian object" << std::endl;
			time_t mytime;
    		k_time(&mytime);
   			struct tm *currentTime = gmtime(&mytime);
			ar = (*currentTime).tm_year + 1900;
			manad = (*currentTime).tm_mon + 1;
			dag = (*currentTime).tm_mday;
		}
		
		  Gregorian(Date & otherDate) {
			ar = otherDate.year();
			manad = otherDate.month();
			dag = otherDate.day();		  
		  	}
			
			Gregorian(Date * otherDate) {
			ar = (*otherDate).year();
			manad = (*otherDate).month();
			dag = (*otherDate).day();		  
		  	}
		  	
		Gregorian(int year, int month, int day) { 
			if((leap_year()) && (month == 2) && (day == 29)) {
				ar = year;
				manad = month;
				dag = day;
				
			} else if((year < startYear || year > endYear) || (month < 1 || month > 12) || (day < 1 || day > monthlengths[month - 1])) {
				throw std::out_of_range("Out of bounds");
			} else {
			
			ar = year;
			manad = month;
			dag = day;
			}
		}

		virtual bool leap_year() {
			bool isLeapYear = false;

			if((year() % 4 == 0)) {
				if(year() % 100) { //Sekelskifte
					if(year() % 400) {
						isLeapYear = true;
					}					
				} else {
					isLeapYear = true;
				}
			}

			return isLeapYear;
		}
		virtual double daysPerYearRatio() {
				return 365.2425;
			}
			
		virtual Date& operator ++(){
			if(day() + 1 > days_this_month()) { //Är vi på sista dagen i nån månad?
				add_month(1);
				dag = 1;
			} else {
				dag = day() + 1;
			}
		return *this;
		}
		
		virtual Date& operator--(){
			if(day() - 1 < 1) { //Är vi på första dagen i nån månad?
				add_month(-1);
				dag = days_this_month();			
			} else {
				dag = day() - 1;
			}
		}
			
		virtual Gregorian operator++(int) {
			Gregorian before = *this;
			++(*this);
			return before;
		}
		
		virtual Gregorian operator--(int) {
			Gregorian before = *this;
			--(*this);
			return before;
		}	

};
