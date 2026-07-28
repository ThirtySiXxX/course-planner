import java.util.List;
public class AnyOfRule implements RequirementRule {
    private List<RequirementRule> rules;

    public AnyOfRule(List<RequirementRule> rules) {
        this.rules = rules;
    }

    @Override
    public boolean isSatisfied(Student student) {
        for (RequirementRule rule : rules) {
            if (rule.isSatisfied(student)) {
                return true;
            }
        }
        return false;
    }
    
}
