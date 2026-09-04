#ifndef UTILITIES_H
#define UTILITIES_H

#include <array>
#include <string>
#include "constants.h"

void populateSampleData(
    std::array<std::string, STUDENT_COUNT>& names,
    std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores
);

#endif
