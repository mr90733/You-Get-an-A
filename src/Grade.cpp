#include "Grade.hpp"

#include <sstream>

void Grade::addStudent(const std::string& FName, const std::string& LName)

{
    Student s(FName, LName);

    s.grades.resize(assignments.size(), 0);

    students.push_back(s);
}

void Grade::addAssignment(const std::string& name, int maxPoints)

{
    Assignment a(name, maxPoints);

    assignments.push_back(a);

    for (auto& s : students)

        {
        s.grades.push_back(0);
    }
}

void Grade::enterGrade(const std::string& studentName, const std::string& assignmentName, int grade) {

    for (auto& s : students) {

        if (s.firstName + " " + s.lastName == studentName) {

            for (size_t i = 0; i < assignments.size(); ++i) {

                if (assignments[i].name == assignmentName) {

                    if (grade < 0) grade = 0;

                    if (grade > assignments[i].maxPoints) grade = assignments[i].maxPoints;

                    s.grades[i] = grade;

                    return;
                }
            }
        }
    }
}

std::string Grade::report() const

{
    std::ostringstream oss;

    oss << "LastName,FirstName";

    for (const auto& a : assignments)

        {

        oss << "," << a.name;
    }
    oss << "\n";

    for (const auto& s : students) {

        oss << s.lastName << "," << s.firstName;

        for (const auto& g : s.grades) {

            oss << "," << g;
        }

        oss << "\n";
    }

    return oss.str();
}