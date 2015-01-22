#ifndef JULIAN_H
#define JULIAN_H
#include "middle.h"

namespace lab2{
class Julian : public middle {

	protected:
		void setToday(int mjd);
		int JDN() const;
		
		void reset() ;
		bool leap_year() const;
	public:
		Julian();
		Julian(int year, int month, int day);
		Julian(const Date& otherDate);
		Julian(const Julian& otherDate);
		Julian(const Date* otherDate);
		

		double daysPerYearRatio() const;	
		Date& operator ++();		
		Date& operator--();
		Julian operator++(int);		
		Julian operator--(int);
		bool isJulian() const;
		int mod_julian_day() const;
		
};
}
#endif
