#pragma once

#include "requirement_rule.hpp"

#include <vector>

namespace course_planner {

class AnyOfRule final : public RequirementRule {
public:
    explicit AnyOfRule(std::vector<RequirementRulePtr> rules);

    [[nodiscard]] bool is_satisfied(const Student& student) const override;

private:
    std::vector<RequirementRulePtr> rules_;
};

}  // namespace course_planner
