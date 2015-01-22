%.out: %.cpp
	/info/DD2387/labs/cxxtest/cxxtestgen.py --error-printer -o simple_testrunner.cpp $*.cpp
	g++ -o simple_test.out -I /info/DD2387/labs/cxxtest/ simple_testrunner.cpp count_if_followed_by.o
	
	

