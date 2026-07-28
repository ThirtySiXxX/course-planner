public class HasCompletedUnitRule implements RequirementRule {
    private Unit unit;

    public HasCompletedUnitRule(Unit unit) {
        this.unit = unit;
    }

    @Override
    public boolean isSatisfied(Student student) {
        return student.hasCompleted(unit);
    }
}