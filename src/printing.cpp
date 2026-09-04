#include "printing.h"
#include "stats.h" // Needed for studentAverage()
#include<array>
#include<string>
#include<iomanip>
#include"constants.h"
#include"grading.h"
#include"utilities.h"


bool isAtRisk(
    const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores,
    int studentIndex
) {
    if ( studentAverage(scores, studentIndex) < 70.0 ) {
        return true;
    }

    for ( auto i{0}; i < ASSIGNMENT_COUNT; i++ ) {
        if ( scores[studentIndex][i] < 50.0 ) {
            return true;
        }
    }

    return false;
}

bool hasPerfectScore(
    const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores,
    int studentIndex
) {
    for ( auto i{0}; i < ASSIGNMENT_COUNT; i++ ) {
        if ( scores[studentIndex][i] == 100.0 ) {
            return true;
        }
    }

    return false;
}
