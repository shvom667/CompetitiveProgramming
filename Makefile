# Variables
CXX = g++
CXXFLAGS = -std=c++20 -Wall

# Targets
all:

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<


