#include "grading.h"

double calculateStudentAverage(
    const std::array<double, ASSIGNMENT_COUNT>& scores
) {
    double sum = 0.0;
    for (double score : scores) {
        sum += score;
    }
    return sum / ASSIGNMENT_COUNT;
}

char getLetterGrade(double average) {
    if (average >= 90.0) return 'A';
    if (average >= 80.0) return 'B';
    if (average >= 70.0) return 'C';
    if (average >= 60.0) return 'D';
    return 'F';
}
