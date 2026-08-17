#include "all_of_rule.hpp"
#include "any_of_rule.hpp"
#include "eligibility_checker.hpp"
#include "has_completed_unit_rule.hpp"
#include "student.hpp"
#include "teaching_period.hpp"
#include "unit.hpp"

#include <iostream>
#include <memory>
#include <unordered_set>
#include <utility>
#include <vector>

int main() {
    using course_planner::AllOfRule;
    using course_planner::AnyOfRule;
    using course_planner::EligibilityChecker;
    using course_planner::HasCompletedUnitRule;
    using course_planner::RequirementRulePtr;
    using course_planner::Student;
    using course_planner::TeachingPeriod;
    using course_planner::Unit;

    Unit fit1001(
        "Introduction to Programming", "FIT1001", 6,
        "Learn the basics of programming.", nullptr, nullptr, nullptr,
        {TeachingPeriod::semester_1});
    Unit fit1002(
        "Data Structures", "FIT1002", 6, "Learn about data structures.",
        nullptr, nullptr, nullptr, {TeachingPeriod::semester_1});
    Unit fit1003(
        "Algorithms", "FIT1003", 6, "Learn about algorithms.", nullptr,
        nullptr, nullptr, {TeachingPeriod::semester_2});

    Student bob("Bob", 12345, std::unordered_set<const Unit*>{&fit1003});

    RequirementRulePtr completed_fit1001 =
        std::make_shared<HasCompletedUnitRule>(fit1001);
    RequirementRulePtr completed_fit1002 =
        std::make_shared<HasCompletedUnitRule>(fit1002);
    RequirementRulePtr completed_fit1003 =
        std::make_shared<HasCompletedUnitRule>(fit1003);

    RequirementRulePtr fit2001_prerequisite = std::make_shared<AnyOfRule>(
        std::vector<RequirementRulePtr>{
            std::make_shared<AllOfRule>(
                std::vector<RequirementRulePtr>{completed_fit1001,
                                                completed_fit1002}),
            completed_fit1003});

    Unit fit2001(
        "Advanced Programming", "FIT2001", 6,
        "Learn advanced programming concepts.", nullptr,
        std::move(fit2001_prerequisite), nullptr,
        {TeachingPeriod::semester_2, TeachingPeriod::summer});

    const EligibilityChecker eligibility_checker;
    const bool can_take_fit2001 = eligibility_checker.can_take(
        bob, fit2001, TeachingPeriod::semester_2);

    std::cout << std::boolalpha
              << "Can the student take FIT2001? " << can_take_fit2001 << '\n';
}
