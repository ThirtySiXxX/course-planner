#include "all_of_rule.hpp"

#include "student.hpp"

#include <utility>

namespace course_planner {

AllOfRule::AllOfRule(std::vector<RequirementRulePtr> rules)
    : rules_(std::move(rules)) {}

bool AllOfRule::is_satisfied(const Student& student) const {
    for (const auto& rule : rules_) {
        if (!rule->is_satisfied(student)) {
            return false;
        }
    }
    return true;
}

}  // namespace course_planner
