public class EligibilityChecker {
    public boolean canTake (Student student,Unit targetUnit, TeachingPeriod teachingPeriod) {
        boolean prerequisiteSatisfied = targetUnit.getPrerequisite() == null || targetUnit.getPrerequisite().isSatisfied(student);
        boolean corequisiteSatisfied = targetUnit.getCorequisite() == null || targetUnit.getCorequisite().isSatisfied(student);
        boolean prohibitionSatisfied = targetUnit.getProhibition() == null || !targetUnit.getProhibition().isSatisfied(student);
        return  
                prerequisiteSatisfied 
                && corequisiteSatisfied 
                && prohibitionSatisfied 
                && targetUnit.getTeachingPeriod().contains(teachingPeriod);
    }

    public boolean canPlace(
    Student student,
    PlannedUnit plannedUnit
) {
    if (plannedUnit.isForced()) {
        return true;
    }

    return canTake(
        student,
        plannedUnit.getUnit(),
        plannedUnit.getTeachingPeriod()
    );
}
}
