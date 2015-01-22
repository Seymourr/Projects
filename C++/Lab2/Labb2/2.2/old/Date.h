#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<string>
#include<vector>
#include <time.h>
#include <stdexcept>
#include <type_traits>
#include <math.h>

class Date {
	protected:
		int ar =0; //Year of the calendar
		int manad = 0; //Month of the calendar
		int dag = 0; //Current day in the calendar
	public:	
		int mod_julian_day(const int year,const int month,const int day) const;
		
		int year() const;
		int month() const;
		int day() const;
		
		//Returtyper på operatorer?
		void operator +=(int daysToAdd);
	    void operator -=(int daysToAdd);

		
		int operator-(const Date &otherDate);
		bool operator== (const Date &otherDate) const;
	
		bool operator!= (const Date &otherDate) const;
		
		//Date objekt?
		bool operator< (const Date &otherDate) const;
		
			//Date objekt?
		bool operator<= (const Date &otherDate) const;
			//Date objekt?
		bool operator>= (const Date &otherDate) const;
		
			//Date objekt?
		bool operator> (const Date &otherDate) const;
		virtual std::string week_day_name() = 0; //Julian is behind gregorian
		virtual std::string month_name() = 0;	
		virtual int week_day() = 0;
		virtual int days_this_month() = 0;
		virtual int days_per_week() = 0;
		virtual int months_per_year() = 0;	
		virtual void add_year(int n = 1) = 0;
		virtual void add_month(int n = 1) = 0;
		virtual Date& operator ++() = 0;
		virtual Date& operator--() = 0;
		virtual double daysPerYearRatio() const;
};
std::ostream & operator<<(std::ostream & os, const Date & someDate); 

#endif

