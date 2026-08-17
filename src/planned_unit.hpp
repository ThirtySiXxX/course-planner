#pragma once

#include "teaching_period.hpp"

namespace course_planner {

class Unit;

class PlannedUnit {
public:
    PlannedUnit(const Unit& unit, TeachingPeriod teaching_period, int year,
                bool force);

    [[nodiscard]] const Unit& unit() const;
    [[nodiscard]] TeachingPeriod teaching_period() const;
    [[nodiscard]] bool is_forced() const;
    [[nodiscard]] int year() const;

    void set_unit(const Unit& unit);
    void set_teaching_period(TeachingPeriod teaching_period);
    void set_force(bool force);
    void set_year(int year);

private:
    const Unit* unit_;
    TeachingPeriod teaching_period_;
    int year_;
    bool force_;
};

}  // namespace course_planner
