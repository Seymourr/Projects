#include "date.h"
#include "middle.h"
#include <math.h>
#include <string>
#include "kattistime.h"
namespace lab2{

		const int daysPerWeek = 7; 
		const int monthsPerYear = 12;
		const int startYear = 1858;
		const int endYear = 2558;
		static std::vector<std::string> weeknames = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
		
		static std::vector<std::string> monthnames = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november","december"};
		static std::vector<int> monthlengths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};
	

		std::string middle::month_name()const {
		return monthnames[month() -1];
		}
		
		
		
		int middle::week_day()const {
			int day = (JDN() % 7)+ 1;
		return day;
		}
		
		std::string middle::week_day_name() const{
		int day = week_day();
		return weeknames[day - 1];
		}
		
		//Individuellt för varje typ av kalender (Specialfall februari)
		int middle::days_this_month()const{
			if(month() == 2 && leap_year()) {
				return monthlengths[month() - 1] + 1;
			} else {
				return monthlengths[month() -1];
			}
		}
		
		
		int middle::days_per_week() const{
			return daysPerWeek;
		}
		
		int middle::months_per_year() const{
			return monthsPerYear;
		}

		void middle::add_year(int n){
			if(n == 0) {
			return;
			}
			if(year() + n > endYear || year() + n < startYear) {
				throw std::out_of_range("Out of bounds");
			}
		
			if(month() == 2 && day() == 29) {
				ar = year() + n;
				if(leap_year()) {
					//Do nothing
				} else {
					dag = 28;
				}
			} else {
			ar = ar + n;
			}
		}
	
	
		
		void middle::add_month(int n) {
		if(n == 0) {
		return;
		}
		if(abs(n) > 1) {
			for(int i = 0; i < abs(n); ++i) {
				add_month(n/abs(n));
				
			}
			return;
		
		}
		
		int thisMonthLength = days_this_month();
		int thisMonth = manad;
		int nextMonth = manad + n;
		int lengthNextMonth;
		
		if(nextMonth <= 0) {
			nextMonth = 12;
			manad = nextMonth;
			lengthNextMonth = days_this_month();
			add_year(-1);
		} else if(nextMonth > 12) {
			nextMonth = 1;
			manad = nextMonth;
			lengthNextMonth = days_this_month();		
			add_year(1);
		} else {
		 manad = nextMonth;
		 lengthNextMonth = days_this_month();
		 manad = thisMonth;
		}
		
		if(day() > lengthNextMonth) {

			//"plussa på 30"
			if(n > 0) {
				int daysToAdd = 30;
				//speciallfall!
				if(month() == 1 && day() == 31) {
					if(leap_year()) {
					 manad = 3;
					 dag = 1;
					} else {
					 manad = 3;
					 dag = 2;
					}
				} else if(month() == 1 && day() == 30) {
			
					if(leap_year()) {
					 manad = 2;
					 dag = 29;
					} else {
					
					 manad = 3;
					 dag = 1;
					}
				} else {
				
				daysToAdd = daysToAdd - (thisMonthLength - day()) - 1; 
				dag = 1 + daysToAdd;
				manad = nextMonth;
				}
			} else {
				int daysToRemove = 30;
				if(month() == 3 && day() == 30) {
					if(leap_year()) {
						dag = 29;
						manad = 2;
					} else {
						dag = 28; 
						manad = 2;
					}
				} else {
				daysToRemove = daysToRemove - day()+ 1;
				dag = 1;
				if(daysToRemove > 1) {
					dag = lengthNextMonth - daysToRemove + 1; 
						manad = nextMonth;
				} 
			
				
				}
				
			}
			
	} else {
		manad = nextMonth;
	}
	}
	
	
			
		int middle::MJDG()const {
			time_t mytime;
    		k_time(&mytime);
    		
    		
   			struct tm *currentTime = gmtime(&mytime);
			int year = (*currentTime).tm_year + 1900;
			int month = (*currentTime).tm_mon + 1;
			int day = (*currentTime).tm_mday;
		
			int a = floor((14-month)/12);
			int y = year + 4800 - a;
			int m = month + 12*a -3;
			int JDN = day + floor((153*m + 2)/5) + 365*y + floor(y/4) - floor(y/100) + floor(y/400)- 32045;
			int MJD = floor(JDN - 2400000.5);
    		return MJD;
		
		}	
			
		bool middle::isJulian() const{
			return false;
		}
		
		//SKROTA!

}

		
		
		
		
		



