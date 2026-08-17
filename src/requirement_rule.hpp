#pragma once

#include <memory>

namespace course_planner {

class Student;

class RequirementRule {
public:
    virtual ~RequirementRule() = default;
    [[nodiscard]] virtual bool is_satisfied(const Student& student) const = 0;
};

using RequirementRulePtr = std::shared_ptr<const RequirementRule>;

}  // namespace course_planner
