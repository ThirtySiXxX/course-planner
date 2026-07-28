import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Main {
    public static void main(String[] args) {

        HashSet<Unit> completedUnits = new HashSet<>();
        Unit FIT1001 = new Unit("Introduction to Programming", "FIT1001", 6, "Learn the basics of programming.", null, null, null, Set.of(TeachingPeriod.SEMESTER_1));
        Unit FIT1002 = new Unit("Data Structures", "FIT1002", 6, "Learn about data structures.", null, null, null, Set.of(TeachingPeriod.SEMESTER_1));
        Unit FIT1003 = new Unit("Algorithms", "FIT1003", 6, "Learn about algorithms.", null, null, null, Set.of(TeachingPeriod.SEMESTER_2));

        completedUnits.add(FIT1003);
        Student Bob = new Student("Bob", 12345, completedUnits);

        // Create a requirement rule for FIT2001
        RequirementRule CompletedFIT1001 = new HasCompletedUnitRule(FIT1001);
        RequirementRule CompletedFIT1002 = new HasCompletedUnitRule(FIT1002);
        RequirementRule CompletedFIT1003 = new HasCompletedUnitRule(FIT1003);
        RequirementRule FIT2001PrerequisiteRule = new AnyOfRule(List.of(new AllOfRule(List.of(CompletedFIT1001, CompletedFIT1002)), CompletedFIT1003));

        Unit FIT2001 = new Unit("Advanced Programming", "FIT2001", 6, "Learn advanced programming concepts.", null, FIT2001PrerequisiteRule, null, Set.of(TeachingPeriod.SEMESTER_2, TeachingPeriod.SUMMER));
        EligibilityChecker checkEligibility = new EligibilityChecker();
        boolean canTakeFIT2001 = checkEligibility.canTake(Bob, FIT2001, TeachingPeriod.SEMESTER_2);
        System.out.println("Can the student take FIT2001? " + canTakeFIT2001);
    }
}