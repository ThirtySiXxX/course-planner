#pragma once

#include <string>
#include <unordered_set>

namespace course_planner {

class Unit;

class Student {
public:
    Student(std::string name, int id,
            std::unordered_set<const Unit*> completed_units = {});

    [[nodiscard]] bool has_completed(const Unit& unit) const;

    [[nodiscard]] const std::string& name() const;
    [[nodiscard]] int id() const;
    [[nodiscard]] const std::unordered_set<const Unit*>& completed_units() const;

    void set_name(std::string name);
    void set_id(int id);

private:
    std::string name_;
    int id_;
    std::unordered_set<const Unit*> completed_units_;
};

}  // namespace course_planner
