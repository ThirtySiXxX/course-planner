#include "unit.hpp"

#include <utility>

namespace course_planner {

Unit::Unit(std::string name, std::string code, int credits,
           std::string description, RequirementRulePtr corequisite,
           RequirementRulePtr prerequisite, RequirementRulePtr prohibition,
           std::set<TeachingPeriod> teaching_periods)
    : name_(std::move(name)),
      code_(std::move(code)),
      credits_(credits),
      description_(std::move(description)),
      corequisite_(std::move(corequisite)),
      prerequisite_(std::move(prerequisite)),
      prohibition_(std::move(prohibition)),
      teaching_periods_(std::move(teaching_periods)) {}

const std::string& Unit::name() const {
    return name_;
}

const std::string& Unit::code() const {
    return code_;
}

int Unit::credits() const {
    return credits_;
}

const std::string& Unit::description() const {
    return description_;
}

const RequirementRulePtr& Unit::corequisite() const {
    return corequisite_;
}

const RequirementRulePtr& Unit::prerequisite() const {
    return prerequisite_;
}

const RequirementRulePtr& Unit::prohibition() const {
    return prohibition_;
}

const std::set<TeachingPeriod>& Unit::teaching_periods() const {
    return teaching_periods_;
}

void Unit::set_name(std::string name) {
    name_ = std::move(name);
}

void Unit::set_code(std::string code) {
    code_ = std::move(code);
}

void Unit::set_credits(int credits) {
    credits_ = credits;
}

void Unit::set_description(std::string description) {
    description_ = std::move(description);
}

void Unit::set_teaching_periods(std::set<TeachingPeriod> teaching_periods) {
    teaching_periods_ = std::move(teaching_periods);
}

}  // namespace course_planner
