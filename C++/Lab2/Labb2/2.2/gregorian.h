#ifndef GREGORIAN_H
#define GREGORIAN_H
#include "middle.h"
namespace lab2 {
class Gregorian : public middle {
	protected: 
			int JDN() const;
			int mod_julian_day() const;
			double daysPerYearRatio() const;
			bool leap_year() const;
			void reset() ;
	public:


		Gregorian(); 
		
		Gregorian(const Date & otherDate);
			
		Gregorian(const Date * otherDate);
		  	
		Gregorian(int year, int month, int day);
	
		
		Gregorian operator++(int);
		
		Gregorian operator--(int); 
		
		Date& operator ++();
		
		Date& operator--();
			

	
		
		

};
}
#endif
