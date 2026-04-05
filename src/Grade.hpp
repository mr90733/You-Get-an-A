#pragma once

#include <string>

#include <utility>

#include <vector>

class Assignment

{

public:

    std::string name;

    int maxPoints;

    Assignment(std::string  n, int max) : name(std::move(n)), maxPoints(max) {}
};

class Student

{

public:

    std::string firstName;

    std::string lastName;

    std::vector<int> grades;

    Student(std::string  fn, std::string  ln)

        : firstName(std::move(fn)), lastName(std::move(ln)) {}
};

class Grade

{

private:

    std::vector<Student> students;

    std::vector<Assignment> assignments;

public:

    void addStudent(const std::string& FName, const std::string& LName);

    void addAssignment(const std::string& name, int maxPoints);

    void enterGrade(const std::string& studentName, const std::string& assignmentName, int grade);

    [[nodiscard]] std::string report() const;
};