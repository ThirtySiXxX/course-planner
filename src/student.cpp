#include "student.hpp"

#include "unit.hpp"

#include <utility>

namespace course_planner {

Student::Student(std::string name, int id,
                 std::unordered_set<const Unit*> completed_units)
    : name_(std::move(name)),
      id_(id),
      completed_units_(std::move(completed_units)) {}

bool Student::has_completed(const Unit& unit) const {
    return completed_units_.count(&unit) != 0;
}

const std::string& Student::name() const {
    return name_;
}

int Student::id() const {
    return id_;
}

const std::unordered_set<const Unit*>& Student::completed_units() const {
    return completed_units_;
}

void Student::set_name(std::string name) {
    name_ = std::move(name);
}

void Student::set_id(int id) {
    id_ = id;
}

}  // namespace course_planner
