#pragma once

#include "requirement_rule.hpp"
#include "teaching_period.hpp"

#include <set>
#include <string>

namespace course_planner {

class Unit {
public:
    Unit(std::string name, std::string code, int credits,
         std::string description, RequirementRulePtr corequisite,
         RequirementRulePtr prerequisite, RequirementRulePtr prohibition,
         std::set<TeachingPeriod> teaching_periods);

    Unit(const Unit&) = delete;
    Unit& operator=(const Unit&) = delete;
    Unit(Unit&&) = delete;
    Unit& operator=(Unit&&) = delete;

    [[nodiscard]] const std::string& name() const;
    [[nodiscard]] const std::string& code() const;
    [[nodiscard]] int credits() const;
    [[nodiscard]] const std::string& description() const;
    [[nodiscard]] const RequirementRulePtr& corequisite() const;
    [[nodiscard]] const RequirementRulePtr& prerequisite() const;
    [[nodiscard]] const RequirementRulePtr& prohibition() const;
    [[nodiscard]] const std::set<TeachingPeriod>& teaching_periods() const;

    void set_name(std::string name);
    void set_code(std::string code);
    void set_credits(int credits);
    void set_description(std::string description);
    void set_teaching_periods(std::set<TeachingPeriod> teaching_periods);

private:
    std::string name_;
    std::string code_;
    int credits_;
    std::string description_;
    RequirementRulePtr corequisite_;
    RequirementRulePtr prerequisite_;
    RequirementRulePtr prohibition_;
    std::set<TeachingPeriod> teaching_periods_;
};

}  // namespace course_planner
