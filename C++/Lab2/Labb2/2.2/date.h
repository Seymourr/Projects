#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<string>
#include<vector>
#include <time.h>
#include <stdexcept>
#include <type_traits>
#include <math.h>

namespace lab2{
class Date {
	protected:
		//void recursiveAdd(int daysToAdd);
		mutable int ar =0; //Year of the calendar
		mutable int manad = 0; //Month of the calendar
		mutable int dag = 0; //Current day in the calendar
	public:	

		virtual int mod_julian_day() const = 0;
		int year() const;
		int month() const;
		int day() const;
		
		//Returtyper på operatorer?
		Date& operator +=(int daysToAdd) ;
	    Date& operator -=(int daysToAdd) ;

		int operator-(const Date &otherDate) const;
		bool operator== (const Date &otherDate) const;
	
		bool operator!= (const Date &otherDate) const;
		
		//Date objekt?
		bool operator< (const Date &otherDate) const;
		
			//Date objekt?
		bool operator<= (const Date &otherDate) const;
			//Date objekt?
		bool operator>= (const Date &otherDate) const;
		
		Date & operator=(const Date & otherDate) ;
		
			//Date objekt?
		bool operator> (const Date &otherDate) const;
		virtual std::string week_day_name() const= 0; //Julian is behind gregorian
		virtual std::string month_name() const= 0;	
		virtual int week_day() const = 0;
		virtual int days_this_month() const= 0;
		virtual int days_per_week() const= 0;
		virtual int months_per_year() const= 0;	
		virtual void add_year(int n = 1) = 0;
		virtual void add_month(int n = 1) = 0;
		virtual Date& operator ++() = 0;
		virtual Date& operator--() = 0;
		virtual double daysPerYearRatio() const = 0;
		virtual bool leap_year() const= 0;
		virtual void reset()  = 0;
};	
std::ostream & operator<<(std::ostream & os, const Date & someDate); 
}
#endif

