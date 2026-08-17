#include "planned_unit.hpp"

#include "unit.hpp"

namespace course_planner {

PlannedUnit::PlannedUnit(const Unit& unit, TeachingPeriod teaching_period,
                         int year, bool force)
    : unit_(&unit),
      teaching_period_(teaching_period),
      year_(year),
      force_(force) {}

const Unit& PlannedUnit::unit() const {
    return *unit_;
}

TeachingPeriod PlannedUnit::teaching_period() const {
    return teaching_period_;
}

bool PlannedUnit::is_forced() const {
    return force_;
}

int PlannedUnit::year() const {
    return year_;
}

void PlannedUnit::set_unit(const Unit& unit) {
    unit_ = &unit;
}

void PlannedUnit::set_teaching_period(TeachingPeriod teaching_period) {
    teaching_period_ = teaching_period;
}

void PlannedUnit::set_force(bool force) {
    force_ = force;
}

void PlannedUnit::set_year(int year) {
    year_ = year;
}

}  // namespace course_planner
