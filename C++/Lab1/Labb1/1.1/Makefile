# Change these
cxxtestpath = /info/cprog11/cxxtest/
testcode    = testfall.cpp

testcode.cpp: $(testcode)
	python $(cxxtestpath)cxxtestgen.py --error-printer -o testcode.cpp $(testcode)

runtest0%: testcode.cpp
	g++ -std=c++11 -I $(cxxtestpath) -o runtest0$* testcode.cpp Matrix0$*.o

owntest: testcode.cpp
	g++ -std=c++11 JVector.cpp Matrix.cpp -c
	g++ -std=c++11 -I $(cxxtestpath) -o runtest0 testcode.cpp Matrix.o
clean:
	touch runtest01 testcode.cpp
	rm runtest0* testcode.cpp

