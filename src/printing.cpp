#include "printing.h"
#include "constants.h"
#include "grading.h"
#include "utilities.h"
#include <iostream>
#include <iomanip>

// Returns true if student's average is below 70 or if any single assignment score is below 50
bool isAtRisk(
    const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores,
    int studentIndex
) {
    if (calculateStudentAverage(scores[studentIndex]) < 70.0) {
        return true;
    }

    for (std::size_t i = 0; i < ASSIGNMENT_COUNT; ++i) {
        if (scores[studentIndex][i] < 50.0) {
            return true;
        }
    }

    return false;
}

void printHeader() {
    std::cout << std::left << std::setw(15) << "Name";
    for (std::size_t i = 0; i < ASSIGNMENT_COUNT; ++i) {
        std::cout << std::right << std::setw(10) << ("A" + std::to_string(i + 1));
    }
    std::cout << std::right << std::setw(10) << "Average" 
              << std::setw(8) << "Grade" 
              << std::setw(10) << "Status" << "\n";
    std::cout << std::string(15 + (ASSIGNMENT_COUNT * 10) + 28, '-') << "\n";
}

void printStudentRow(
    const std::array<std::string, STUDENT_COUNT>& names,
    const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores,
    int studentIndex
) {
    std::cout << std::left << std::setw(15) << names[studentIndex];
    for (std::size_t j = 0; j < ASSIGNMENT_COUNT; ++j) {
        std::cout << std::right << std::setw(10) << std::fixed << std::setprecision(1) << scores[studentIndex][j];
    }
    
    double avg = calculateStudentAverage(scores[studentIndex]);
    char grade = getLetterGrade(avg);
    std::string status = isAtRisk(scores, studentIndex) ? "AT RISK" : "OK";

    std::cout << std::right << std::setw(10) << std::fixed << std::setprecision(1) << avg
              << std::setw(8) << grade 
              << std::setw(10) << status << "\n";
}

void printHistogram(
    const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores,
    const std::array<std::string, STUDENT_COUNT>& names
) {
    std::cout << "\n--- Grade Distribution ---\n";
    for (std::size_t i = 0; i < STUDENT_COUNT; ++i) {
        double avg = calculateStudentAverage(scores[i]);
        std::cout << std::left << std::setw(15) << names[i] << " | ";
        int stars = static_cast<int>(avg / 10);
        for (int s = 0; s < stars; ++s) {
            std::cout << "*";
        }
        std::cout << " (" << std::fixed << std::setprecision(1) << avg << ")\n";
    }
}

void printAssignmentSummary(
    const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores
) {
    std::cout << "\n--- Assignment Averages ---\n";
    for (std::size_t j = 0; j < ASSIGNMENT_COUNT; ++j) {
        double total = 0.0;
        for (std::size_t i = 0; i < STUDENT_COUNT; ++i) {
            total += scores[i][j];
        }
        double avg = total / STUDENT_COUNT;
        std::cout << "Assignment " << (j + 1) << ": " << std::fixed << std::setprecision(1) << avg << "\n";
    }
}

void printRoster(
    const std::array<std::string, STUDENT_COUNT>& names
) {
    std::cout << "\n--- Class Roster ---\n";
    for (std::size_t i = 0; i < STUDENT_COUNT; ++i) {
        std::cout << (i + 1) << ". " << names[i] << "\n";
    }
}
