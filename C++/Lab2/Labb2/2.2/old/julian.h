#ifndef JULIAN_H
#define JULIAN_H
#include "middle.h"
#include "kattistime.h"

class Julian : public middle {
	public:
		Julian();

		Julian(int year, int month, int day);
		Julian(Date& otherDate);
		Julian(Date* otherDate);
		bool leap_year();

		double daysPerYearRatio() const;	
		Date& operator ++();		
		Date& operator--();
		Julian operator++(int);		
		Julian operator--(int);


};

#endif
