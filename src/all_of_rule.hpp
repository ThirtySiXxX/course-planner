#pragma once

#include "requirement_rule.hpp"

#include <vector>

namespace course_planner {

class AllOfRule final : public RequirementRule {
public:
    explicit AllOfRule(std::vector<RequirementRulePtr> rules);

    [[nodiscard]] bool is_satisfied(const Student& student) const override;

private:
    std::vector<RequirementRulePtr> rules_;
};

}  // namespace course_planner
