htsim: htsim.o hikedatafsm.o 
	g++ -std=c++11 htsim.o hikedatafsm.o -std=c++11 -o htsim

htsim.o: htsim.cpp parser.hpp hikedatafsm.hpp
	g++ -std=c++11 -g -c htsim.cpp

hikedatafsm.o: hikedatafsm.cpp statemachine.hpp
	g++ -std=c++11 -g -c hikedatafsm.cpp

