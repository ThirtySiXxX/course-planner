import java.util.List;
public class AllOfRule implements RequirementRule {
    private List<RequirementRule> rules;

    public AllOfRule(List<RequirementRule> rules) {
        this.rules = rules;
    }

    @Override
    public boolean isSatisfied(Student student) {
        for (RequirementRule rule : rules) {
            if (!rule.isSatisfied(student)) {
                return false;
            }
        }
        return true;
    }
}
