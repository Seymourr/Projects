#include "julian.h"
#include "middle.h"
#include "kattistime.h"

		Julian::Julian() {
		std::cout << "Creating Jul object" << std::endl;
			time_t mytime;
    		k_time(&mytime);
   			struct tm *currentTime = gmtime(&mytime);
			ar = (*currentTime).tm_year + 1900;
			manad = (*currentTime).tm_mon + 1;
			dag = (*currentTime).tm_mday;

			int dagarSedanJulian = mod_julian_day(ar, manad, dag);
			int restdagar = fmod(dagarSedanJulian, 365.25);
			int tot_ar = (dagarSedanJulian - restdagar) / 365.25;
			ar = 1858 + tot_ar;
			
			int currentMonth = 0;
			for(int i = 1; i <= 12; ++i) {
				currentMonth = i;
				int newMonthlength = monthlengths[i - 1];
				if(leap_year() && i == 2) {
					newMonthlength += 1;			
				}
				if(restdagar - newMonthlength <= 0) {
				 break;
				} else {
					//fortsätt till nästa månad
					restdagar -= newMonthlength;
				}
			}
			
			manad = currentMonth;
			dag = restdagar;
		}
		
		Julian::Julian(Date& otherDate) {
			ar = otherDate.year();
			manad = otherDate.month();
			dag = otherDate.day();		  
		  	}
		  	
		Julian::Julian(Date* otherDate) {
			ar = (*otherDate).year();
			manad = (*otherDate).month();
			dag = (*otherDate).day();		  
		  	}
		  	
		Julian::Julian(int year, int month, int day) { 
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


		bool Julian::leap_year() {
			bool isLeapYear = false;

			if(year() % 4 == 0) {
				isLeapYear = true;
			}
			return isLeapYear;
		}

		double Julian::daysPerYearRatio() const {
			return 365.25;
		}
		
		
		Date& Date::operator ++(){
			if(day() + 1 > days_this_month()) { //Är vi på sista dagen i nån månad?
				add_month(1);
				dag = 1;
			} else {
				dag = day() + 1;
			}
		return *this;
		}
		
		Date& Date::operator--(){
			if(day() - 1 < 1) { //Är vi på första dagen i nån månad?
				add_month(-1);
				dag = days_this_month();			
			} else {
				dag = day() - 1;
			}
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



