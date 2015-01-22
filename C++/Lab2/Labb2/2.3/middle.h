#ifndef MIDDLE_H
#define MIDDLE_H
#include "date.h"
#include <math.h>
#include <string>
namespace lab2 {
class middle : public Date {
	protected:
		static const int daysPerWeek = 7; 
		static const int monthsPerYear = 12;
		static const int startYear = 1858;
		static const int endYear = 2558;
		
		int MJDG() const;
	
	public:
	
		std::string month_name()const;
		int week_day()const;
		std::string week_day_name()const;
		int days_this_month()const;
		int days_per_week()const;
		
		int months_per_year()const;

		void add_year(int n);

		void add_month(int n);
		virtual int JDN() const = 0;
		virtual bool isJulian() const;
		
		
		
		
};
}
#endif	
		
		



