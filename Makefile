# Variables
CXX = g++
CXXFLAGS = -g -std=c++20 -Wall

# Targets
all:

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<


