#include "all_of_rule.hpp"
#include "any_of_rule.hpp"
#include "eligibility_checker.hpp"
#include "has_completed_unit_rule.hpp"
#include "planned_unit.hpp"
#include "student.hpp"
#include "teaching_period.hpp"
#include "unit.hpp"

#include <cassert>
#include <memory>
#include <unordered_set>
#include <vector>

int main() {
    using course_planner::AllOfRule;
    using course_planner::AnyOfRule;
    using course_planner::EligibilityChecker;
    using course_planner::HasCompletedUnitRule;
    using course_planner::PlannedUnit;
    using course_planner::RequirementRulePtr;
    using course_planner::Student;
    using course_planner::TeachingPeriod;
    using course_planner::Unit;

    Unit first_unit("First unit", "FIT1001", 6, "", nullptr, nullptr,
                    nullptr, {TeachingPeriod::semester_1});
    Unit second_unit("Second unit", "FIT1002", 6, "", nullptr, nullptr,
                     nullptr, {TeachingPeriod::semester_1});

    Student student("Bob", 12345,
                    std::unordered_set<const Unit*>{&first_unit});

    RequirementRulePtr completed_first =
        std::make_shared<HasCompletedUnitRule>(first_unit);
    RequirementRulePtr completed_second =
        std::make_shared<HasCompletedUnitRule>(second_unit);
    RequirementRulePtr either_completed = std::make_shared<AnyOfRule>(
        std::vector<RequirementRulePtr>{completed_first, completed_second});
    RequirementRulePtr both_completed = std::make_shared<AllOfRule>(
        std::vector<RequirementRulePtr>{completed_first, completed_second});

    Unit eligible_unit("Eligible", "FIT2001", 6, "", nullptr,
                       either_completed, nullptr,
                       {TeachingPeriod::semester_2});
    Unit missing_prerequisite("Missing prerequisite", "FIT2002", 6, "",
                              nullptr, both_completed, nullptr,
                              {TeachingPeriod::semester_2});
    Unit prohibited_unit("Prohibited", "FIT2003", 6, "", nullptr, nullptr,
                         completed_first, {TeachingPeriod::semester_2});

    const EligibilityChecker checker;

    assert(checker.can_take(student, eligible_unit,
                            TeachingPeriod::semester_2));
    assert(!checker.can_take(student, eligible_unit,
                             TeachingPeriod::semester_1));
    assert(!checker.can_take(student, missing_prerequisite,
                             TeachingPeriod::semester_2));
    assert(!checker.can_take(student, prohibited_unit,
                             TeachingPeriod::semester_2));

    const PlannedUnit normal_plan(prohibited_unit,
                                  TeachingPeriod::semester_2, 2026, false);
    const PlannedUnit forced_plan(prohibited_unit,
                                  TeachingPeriod::semester_2, 2026, true);
    assert(!checker.can_place(student, normal_plan));
    assert(checker.can_place(student, forced_plan));
}
