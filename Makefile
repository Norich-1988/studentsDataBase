# Определяем компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++2a -Wall -Wextra

# Библиотеки, необходимые для GoogleTest
GTEST_LIBS = -lgtest -lgtest_main -pthread

# Цель по умолчанию: собрать всё
all: main_app run_tests

# Правило для сборки основной программы
main_app: main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

# Правило для сборки тестов
run_tests: tests.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@ $(GTEST_LIBS)

# Правило для очистки
clean:
	rm -f main_app run_tests