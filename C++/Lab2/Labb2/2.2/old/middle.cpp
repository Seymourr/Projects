
#include "middle.h"
#include "Date.h"
#include <math.h>
#include <string>
		const int daysPerWeek = 7; 
		const int monthsPerYear = 12;
		const int startYear = 1858;
		const int endYear = 2558;
		const std::vector<std::string> weeknames = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
		
		const std::vector<std::string> monthnames = {"january", "february", "march", "april", "may", "june", "july", "august", "october", "november", "december"};
		const std::vector<int> monthlengths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};
	
	
	
		std::string middle::week_day_name() {
			int daysSinceJulianDay = mod_julian_day(year(), month(), day());
			std::string weekdayname = weeknames[daysSinceJulianDay % 7];
		return weekdayname;
		}

		std::string middle::month_name() {
		return monthnames[month() -1];
		}
		
		int middle::week_day(){
			int daysSinceJulianDay = mod_julian_day(year(), month(), day()) % 7;
		return daysSinceJulianDay + 1;
		}
		
		
		//Individuellt för varje typ av kalender (Specialfall februari)
		int middle::days_this_month(){
			if(month() == 2 && leap_year()) {
				return monthlengths[month() - 1] + 1;
			} else {
				return monthlengths[month() -1];
			}
		}
		
		
		int middle::days_per_week(){
			return daysPerWeek;
		}
		
		int middle::months_per_year(){
			return monthsPerYear;
		}

		void middle::add_year(int n){
			if(month() == 2 && day() == 29) {
				//specialcase
				if(ar + n > endYear || ar + n < startYear) {
					throw std::out_of_range("Out of bounds");
				}
				ar = ar + n;
				if(leap_year()) {
				//Do nothing.
				}else{
					dag = 28;
				}

			} else {
				if(n > 0) { //Positivt?
					if(n > 1) {
						for(int i = 0; i < n; ++i) {
							add_year(1);
						}
					} else {
						if(ar + 1 > endYear) {
							throw std::out_of_range("Out of bounds");
						}
						ar = ar + 1;
					}
				} else if(n < 0) { //Negativt?
					if(n < -1) {
						for(int i = 0; i < abs(n); ++i) {
							add_year(-1);
						}
					} else {
							if(ar - 1 < startYear) {
							throw std::out_of_range("Out of bounds");
						}
						ar = ar -1;
					}
				} else {
					//dont add any year
				}
			}
	}

		void middle::add_month(int n) {
		if(abs(n) > 1) {
			for(int i = 0; i < abs(n); ++i) {
				add_month(n/abs(n));
			}
		}
		//kolla om borderline
		int nextMonth = month() + n;
		if(nextMonth <= 0 && n != 0) {
			nextMonth = 12;
			add_year(-1);
		} else if(nextMonth > 12) {
			nextMonth = 1;
			add_year(1);
		} 
		int lengthNextMonth = monthlengths[nextMonth - 1];
		if(nextMonth == 2 && leap_year()) {
			lengthNextMonth = lengthNextMonth + 1;
		}
		
		if(day() > lengthNextMonth) {
		//Plussa på 30 eller ta bort 30
		 dag += 30; 
		} else {
			manad = nextMonth;
		}
	}


		
		
		
		
		



