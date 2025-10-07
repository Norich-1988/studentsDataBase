# Makefile

CXX = g++
CXXFLAGS = -std=c++2a -Wall -Wextra -I.
GTEST_LIBS = -lgtest -lgtest_main -pthread

# Наши исходные файлы
SRCS = students.cpp main.cpp
TEST_SRCS = students.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

all: main_app run_tests

main_app: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

run_tests: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIBS)

# Правило для компиляции .cpp в .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o main_app run_tests