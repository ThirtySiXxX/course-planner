#pragma once

#include "teaching_period.hpp"

namespace course_planner {

class PlannedUnit;
class Student;
class Unit;

class EligibilityChecker {
public:
    [[nodiscard]] bool can_take(const Student& student, const Unit& target_unit,
                                TeachingPeriod teaching_period) const;
    [[nodiscard]] bool can_place(const Student& student,
                                 const PlannedUnit& planned_unit) const;
};

}  // namespace course_planner
