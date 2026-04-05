#include <iostream>

#include <string>

#include "src/Grade.hpp"

int main()

{
    Grade gb;

    std::string choice;

    do {
        std::string first, last;

        std::cout << "Name of the stundent: ";

        std::getline(std::cin, first);

        std::cout << "Last name of the student: ";

        std::getline(std::cin, last);

        gb.addStudent(first, last);

        do {
            std::string assignName;

            int maxPoints, grade;

            std::cout << "Assignment name: ";

            std::getline(std::cin, assignName);

            std::cout << "Max grade: ";

            std::cin >> maxPoints;

            gb.addAssignment(assignName, maxPoints);

            std::cout << "Grade of the student: ";

            std::cin >> grade;

            gb.enterGrade(first + " " + last, assignName, grade);

            std::cout << "Add another assignment? (y/n): ";

            std::cin >> choice;

            std::cin.ignore();

        } while (choice == "y" || choice == "Y");

        std::cout << "Add student? (y/n): ";

        std::cin >> choice;

        std::cin.ignore();

    } while (choice == "y" || choice == "Y");

    std::cout << "\nReport\n";

    std::cout << gb.report();

    return 0;
}