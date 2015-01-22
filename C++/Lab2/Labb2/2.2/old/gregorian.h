#include "middle.h"
namespace lab2 {
class Gregorian : public middle {
	public:

		Gregorian() {};
		Gregorian(int year, int month, int day) {};
		Gregorian(Date &){};
		Gregorian(Date*){};
		virtual bool leap_year() {};
		virtual double daysPerYearRatio() {};		
		virtual Date& operator ++(){};	
		virtual Date& operator--(){};		
		virtual Gregorian operator++(int) {};	
		virtual Gregorian operator--(int) {};	

};
}

