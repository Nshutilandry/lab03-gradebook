#include "printing.h"
#include "grading.h"
#include "utilities.h"
#include "constants.h"
#include <iostream>

int main() {
    std::array<std::string, STUDENT_COUNT> names;
    std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT> scores;

    populateSampleData(names, scores);

    printRoster(names);

    std::cout << "\n--- Gradebook Summary ---\n";
    printHeader();
    for (std::size_t i = 0; i < STUDENT_COUNT; ++i) {
        printStudentRow(names, scores, static_cast<int>(i));
    }

    printAssignmentSummary(scores);
    printHistogram(scores, names);

    return 0;
}"
