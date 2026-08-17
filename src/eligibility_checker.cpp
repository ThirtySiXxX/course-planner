#include "eligibility_checker.hpp"

#include "planned_unit.hpp"
#include "student.hpp"
#include "unit.hpp"

namespace course_planner {

bool EligibilityChecker::can_take(const Student& student,
                                  const Unit& target_unit,
                                  TeachingPeriod teaching_period) const {
    const auto& prerequisite = target_unit.prerequisite();
    const auto& corequisite = target_unit.corequisite();
    const auto& prohibition = target_unit.prohibition();

    const bool prerequisite_satisfied =
        !prerequisite || prerequisite->is_satisfied(student);
    const bool corequisite_satisfied =
        !corequisite || corequisite->is_satisfied(student);
    const bool prohibition_satisfied =
        !prohibition || !prohibition->is_satisfied(student);
    const bool is_offered =
        target_unit.teaching_periods().count(teaching_period) != 0;

    return prerequisite_satisfied && corequisite_satisfied &&
           prohibition_satisfied && is_offered;
}

bool EligibilityChecker::can_place(const Student& student,
                                   const PlannedUnit& planned_unit) const {
    if (planned_unit.is_forced()) {
        return true;
    }

    return can_take(student, planned_unit.unit(),
                    planned_unit.teaching_period());
}

}  // namespace course_planner
