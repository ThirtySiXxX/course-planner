#pragma once

#include "requirement_rule.hpp"

namespace course_planner {

class Unit;

class HasCompletedUnitRule final : public RequirementRule {
public:
    explicit HasCompletedUnitRule(const Unit& unit);

    [[nodiscard]] bool is_satisfied(const Student& student) const override;

private:
    const Unit* unit_;
};

}  // namespace course_planner
