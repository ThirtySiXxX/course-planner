# FIT Course Planner

An unofficial course-planning tool for Monash University Faculty of Information
Technology students. The long-term goal is to turn a student's degree
requirements, completed units, preferred units, and scheduling constraints into
a valid study plan that can be checked and adjusted semester by semester.

> **Project status:** early C++17 domain-model prototype. The repository can
> evaluate a small set of hard-coded unit rules, but it does not yet download
> the FIT unit catalogue, calculate full degree progress, or generate a complete
> study plan.

## Terminology

Monash uses **course** for a degree program and **unit** for an individual
subject such as `FIT1008`. This project follows that terminology.

## Intended user workflow

1. Select a degree, major, minor, or manually enter the requirements that must
   be completed.
2. Enter units already completed, including recognised equivalent units where
   applicable.
3. Add preferences such as target graduation date, normal semester workload,
   preferred electives, and unavailable teaching periods.
4. Lock a unit to a specific year and teaching period when the student wants to
   take it at that time.
5. Generate a proposed plan from the remaining degree requirements and unit
   rules.
6. Manually add, remove, or move units while receiving immediate validation and
   explanations.

The planner should always show which compulsory requirements and credit points
remain after every automatic or manual change.

## Planning rules

The generated plan must account for:

- **Prerequisites:** must normally be completed before the target unit.
- **Corequisites:** may be completed earlier or scheduled in the same teaching
  period as the target unit.
- **Prohibitions:** prevent incompatible or equivalent units from being taken
  together.
- **Teaching availability:** a unit can only be scheduled when it is offered for
  the relevant year, semester, campus, and delivery mode.
- **Degree requirements:** compulsory units, majors, minors, elective groups,
  level requirements, and total credit points must be satisfied.
- **Study load:** each teaching period must remain within the configured credit
  point or unit limit.
- **Locked units:** locking fixes a unit's requested position; it does not bypass
  prerequisites, corequisites, prohibitions, or availability rules. The planner
  must arrange supporting units around it or explain why the lock is infeasible.

Manual planning uses the same validation rules. An invalid manual placement may
be displayed as a draft, but it must be clearly marked with the exact reason it
cannot be taken.

## Explainable eligibility

Eligibility checking should eventually return structured reasons instead of
only `true` or `false`. For example:

```text
FIT2004 cannot be placed in 2027 Semester 1:
- prerequisite FIT1008 has not been completed or scheduled earlier
- FIT2004 is not offered in Semester 1 for the selected campus
```

This explanation model will be shared by automatic planning, manual planning,
and the "Can I take this unit?" feature.

## Current implementation

The current prototype provides:

- C++17 models for students, units, teaching periods, and planned units.
- Composable `AllOfRule`, `AnyOfRule`, and `HasCompletedUnitRule` requirement
  rules.
- Basic prerequisite, corequisite, prohibition, and teaching-period checks.
- A small executable example and automated eligibility tests.
- A CMake build configuration.

Important prototype limitations:

- Unit data is hard-coded; no Monash catalogue importer exists yet.
- Completed units are currently matched by in-memory object identity rather than
  a persistent unit-code identifier.
- Corequisites do not yet inspect other units in the same planned semester.
- Degree, major, minor, elective, and credit-point requirements are not modelled.
- Locked placement is not yet implemented with its final constraint semantics.
- There is no automatic constraint solver, persistent storage, or user
  interface.

## Development roadmap

### 1. Correct the domain model

- Use unit codes as stable identifiers.
- Add year-specific teaching offerings and delivery details.
- Represent prerequisite, corequisite, prohibition, credit-point, and permission
  rules as structured expressions.
- Replace boolean-only checks with structured validation results.
- Separate a locked schedule position from any explicit administrative override.

### 2. Build the data layer

- Import FIT unit catalogue and offering data from an authorised source.
- Store source dates and retain historical yearly snapshots.
- Detect catalogue changes and allow manual corrections.

### 3. Model degree progress

- Represent courses, majors, minors, compulsory units, elective groups, and
  credit-point rules.
- Match completed units against requirements without double-counting credits.
- Report satisfied and outstanding graduation requirements.

### 4. Implement automatic planning

- Generate candidate semester plans using a constraint-solving approach.
- Treat academic rules and locked positions as hard constraints.
- Optimise soft preferences such as balanced workload, preferred electives, and
  target completion time.
- Return an explanation when no feasible plan exists.

### 5. Add the interactive application

- Student profile and completed-unit entry.
- Automatic plan generation.
- Manual semester editing and unit locking.
- Real-time eligibility and degree-progress feedback.
- Import, export, and saved plan support.

## Build and run

Requirements: CMake 3.16 or newer and a C++17 compiler.

```sh
cmake -S . -B build
cmake --build build
./build/course_planner
```

## Test

```sh
ctest --test-dir build --output-on-failure
```

## Naming convention

- Files, functions, and variables use `lower_snake_case`.
- Types use `PascalCase`.
- Private data members use a trailing underscore.
- Project types live in the `course_planner` namespace.

## Data disclaimer

This is an unofficial planning project and is not affiliated with Monash
University. Unit offerings and academic rules can change. Production versions
must show the source and effective date of imported data, and students should
verify important enrolment decisions against official university information.
