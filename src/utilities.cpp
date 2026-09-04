#include "utilities.h"

void populateSampleData(
    std::array<std::string, STUDENT_COUNT>& names,
    std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores
) {
    names = {"Alice", "Bob", "Charlie", "Diana", "Ethan"};
    scores = {{
        {85.5, 90.0, 78.0, 92.5},
        {70.0, 65.5, 80.0, 72.0},
        {98.0, 95.0, 100.0, 91.0},
        {60.0, 72.5, 68.0, 75.0},
        {88.0, 84.0, 89.5, 90.0}
    }};
}
