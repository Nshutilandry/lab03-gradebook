#ifndef GRADING_H
#define GRADING_H

#include <array>
#include "constants.h"

double calculateStudentAverage(
    const std::array<double, ASSIGNMENT_COUNT>& scores
);

char getLetterGrade(double average);

#endif
