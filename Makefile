CXX = g++
CXXFLAGS = -std=c++17 -Wall -O3
LIBS = -lcurl

SRC = src/main.cpp src/DataFetcher.cpp src/Backtester.cpp src/Strategy.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = backtester

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -Iinclude -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)
