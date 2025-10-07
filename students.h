#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

void addStudent(std::vector<Student>& database);
void displayStudents(const std::vector<Student>& database);
void removeStudent(std::vector<Student>& database);