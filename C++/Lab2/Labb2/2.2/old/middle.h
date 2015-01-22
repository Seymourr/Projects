#ifndef MIDDLE_H
#define MIDDLE_H
#include "Date.h"
#include <math.h>
#include <string>

class middle : public Date {
	protected:
		static const int daysPerWeek = 7; 
		static const int monthsPerYear = 12;
		static const int startYear = 1858;
		static const int endYear = 2558;
		const std::vector<std::string> weeknames = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
		
		const std::vector<std::string> monthnames = {"january", "february", "march", "april", "may", "june", "july", "august", "october", "november", "december"};
		const std::vector<int> monthlengths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

		
	
	public:
		std::string week_day_name();
		std::string month_name();
		int week_day();
		int days_this_month();
		int days_per_week();
		
		int months_per_year();

		void add_year(int n);

		void add_month(int n);
		
		
		
		
		virtual bool leap_year();
		virtual double daysPerYearRatio() const;
};

#endif	
		
		



