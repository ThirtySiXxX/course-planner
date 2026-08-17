#include "any_of_rule.hpp"

#include "student.hpp"

#include <utility>

namespace course_planner {

AnyOfRule::AnyOfRule(std::vector<RequirementRulePtr> rules)
    : rules_(std::move(rules)) {}

bool AnyOfRule::is_satisfied(const Student& student) const {
    for (const auto& rule : rules_) {
        if (rule->is_satisfied(student)) {
            return true;
        }
    }
    return false;
}

}  // namespace course_planner
