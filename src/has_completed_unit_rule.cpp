#include "has_completed_unit_rule.hpp"

#include "student.hpp"
#include "unit.hpp"

namespace course_planner {

HasCompletedUnitRule::HasCompletedUnitRule(const Unit& unit) : unit_(&unit) {}

bool HasCompletedUnitRule::is_satisfied(const Student& student) const {
    return student.has_completed(*unit_);
}

}  // namespace course_planner
