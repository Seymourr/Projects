#include "gregorian.h"
#include "julian.h"
#include "calendar.h"
#include "kattistime.h"
using namespace lab2;

int main() {
	time_t mytime;
    time(&mytime);
    set_k_time(mytime);
	Calendar<Julian> cal;
	cal.add_event("hej");
	cal.add_event("hejdå");
	cal.remove_event("hej");
	cal.add_event("hej");
	Calendar<Gregorian> cal2;
	cal = cal2;
	Calendar<Julian> cal3= cal2;

	std::cout << cal2 << std::endl;
	return 0;
}