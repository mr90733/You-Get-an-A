#include <catch2/catch_test_macros.hpp>

#include <catch2/benchmark/catch_benchmark.hpp>

#include "../src/Grade.hpp"

TEST_CASE("Add student and assignments correctly")

{
    Grade gb;

    gb.addStudent("Ricardo", "Mottet");

    gb.addAssignment("Quiz", 100);

    gb.addAssignment("Lab", 50);

    std::string result = gb.report();

    REQUIRE(result.find("Mottet,Ricardo") != std::string::npos);

    REQUIRE(result.find("Quiz") != std::string::npos);

    REQUIRE(result.find("Lab") != std::string::npos);

}

TEST_CASE("Stores grades correctly")

{
    Grade gb;

    gb.addStudent("Ricardo", "Mottet");

    gb.addAssignment("Quiz", 100);

    gb.enterGrade("Ricardo Mottet", "Quiz", 90);

    std::string result = gb.report();

    REQUIRE(result.find("90") != std::string::npos);
}

TEST_CASE("invalid grades")

{
    Grade gb;

    gb.addStudent("Ricardo", "Mottet");

    gb.addAssignment("Exam", 100);

    gb.enterGrade("Ricardo Mottet", "Exam", 101);

    std::string result = gb.report();

    REQUIRE(result.find("100") != std::string::npos);

    gb.enterGrade("Ricardo Mottet", "Exam", -1);
    result = gb.report();

    REQUIRE(result.find("0") != std::string::npos);
}