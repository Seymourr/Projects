#ifndef CALENDAR_H
#define CALENDAR_H

#include <vector>
#include <string>
#include <algorithm>
#include <ostream>


namespace lab2 {
template<typename T>
class Calendar {
	public:
	struct Handelse {
		std::string event;
		T date;
	};
	
	std::vector<Handelse> cal;
	T currentTime;
	
	Calendar();
	
	template<typename S>
	Calendar(const Calendar<S> & otherCal);
	
	Calendar(const Calendar & otherCal);
	
	template<typename S>
	Calendar<T>& operator=(const Calendar<S> & otherCal);
		
	Calendar<T>& operator=(const Calendar & otherCal);
	bool set_date(int year, int month, int day);
	bool add_event(std::string text, int d, int m, int y);
	bool add_event(std::string text, int d, int m);
	bool add_event(std::string text, int d);
	bool add_event(std::string text);
	
	
	bool remove_event(std::string text, int d, int m, int y);
	bool remove_event(std::string text, int d, int m);
	bool remove_event(std::string text, int d);
	bool remove_event(std::string text);

	};

template<typename T>
	Calendar<T>::Calendar() {

	}

template<typename T>
template<typename S>
	Calendar<T>::Calendar(const Calendar<S> & otherCal) {
		//cal.erase(cal.begin(), cal.end());
		cal.clear();
		for(int i = 0; i < otherCal.cal.size(); ++i){
		Handelse newObject;
		newObject.event = otherCal.cal[i].event;
		newObject.date = otherCal.cal[i].date;
		cal.push_back(newObject);
			
		}
		currentTime = otherCal.currentTime;
		
	}

template<typename T>
	Calendar<T>::Calendar(const Calendar<T> & otherCal) {
		cal = otherCal.cal;
		currentTime = otherCal.currentTime;
	}

template<typename T>
template<typename S>
	Calendar<T>& Calendar<T>::operator=(const Calendar<S> & otherCal) {
		//cal.erase(cal.begin(), cal.end());
		cal.clear();
		for(int i = 0; i < otherCal.cal.size(); ++i){
		Handelse newObject;
		newObject.event = otherCal.cal[i].event;
		newObject.date = otherCal.cal[i].date;
		cal.push_back(newObject);
		}
		currentTime = otherCal.currentTime;
		return *this;
	}
	

template<typename T>
	Calendar<T>& Calendar<T>::operator=(const Calendar<T> & otherCal) {
		cal = otherCal.cal;
		currentTime = otherCal.currentTime;
		return *this;
	}
	
template<typename T>
	bool Calendar<T>::set_date(int year, int month, int day) {
		bool valid = true;
		try{
			currentTime = T(year, month, day);
		}catch(std::out_of_range& oor) {
			valid = false;
		}
		return valid;
	}

template<typename T>	
	bool Calendar<T>::add_event(std::string text, int day, int month, int year) {
		bool valid = true;
		try{
			T date =  T(year, month, day);
			
			for(int i = 0; i < cal.size(); ++i) {
				if(cal[i].event == text) {
					if(cal[i].date.year() == year && cal[i].date.month() == month && cal[i].date.day() == day) {
					valid = false;
					} 
				}
			}
		
			if(valid) {
				Handelse newObject;
				newObject.event = text;
				newObject.date = date;
					
				if(cal.empty()) {
					cal.push_back(newObject);
				} else {
					bool inserted = false;
					for(int i = 0; i < cal.size(); ++i) {
						if(newObject.date < cal[i].date) {
						//Time to insert now..
						inserted = true;
						cal.insert(cal.begin() + i, newObject);
						break;
						}
					}
					if(!inserted) {
					cal.push_back(newObject);
					}
					
		
				}
			}
		}catch(std::out_of_range& oor) {
			valid = false;
		}
		return valid;
	}

template<typename T>
	bool Calendar<T>::add_event(std::string text, int day, int month) {
	return add_event(text, day, month, currentTime.year());
	}
template<typename T>	
	bool Calendar<T>::add_event(std::string text, int day) {
	return add_event(text, day, currentTime.month(), currentTime.year());
	}
template<typename T>	
	bool Calendar<T>::add_event(std::string text) {
	return add_event(text, currentTime.day(), currentTime.month(), currentTime.year());
	}
	
template<typename T>
	bool Calendar<T>::remove_event(std::string text, int day, int month, int year) {
		bool exist = false;
		try{
		for(int i = 0; i < cal.size(); ++i) {
			if(cal[i].date.year() == year && cal[i].date.month() == month && cal[i].date.day() == day && cal[i].event == text) {
					exist = true;
					cal.erase(cal.begin() + i);
					break;
				}
		
		}
		} catch(std::out_of_range& oor) {
			exist = false;
		}
		
		return exist;
	}
template<typename T>	
	bool Calendar<T>::remove_event(std::string text, int day, int month) {
	return remove_event(text, day, month, currentTime.year());
	}
template<typename T>	
	bool Calendar<T>::remove_event(std::string text, int day) {
	return remove_event(text, day, currentTime.month(), currentTime.year());
	}
template<typename T>	
	bool Calendar<T>::remove_event(std::string text) {
	return remove_event(text, currentTime.day(), currentTime.month(), currentTime.year());
	}

template<typename T>
		std::ostream & operator<<(std::ostream & os, const Calendar<T> & someDate){
		for(int i = 0; i < someDate.cal.size(); ++i) {
		if(someDate.currentTime < someDate.cal[i].date) {
				os << someDate.cal[i].date << " : " << someDate.cal[i].event << std::endl;
				}
		}
		return os;
		}
}
#endif
