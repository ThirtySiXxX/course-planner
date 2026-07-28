import java.util.Set;
public class Unit {
    private String name;
    private String code;
    private int credits;
    private String description;
    private RequirementRule corequisite;  //meantime or before
    private RequirementRule prerequisite; //before
    private RequirementRule prohibition;  //cannot take if completed
    private Set<TeachingPeriod> teachingPeriod;
    

    public Unit(String name, String code, int credits, String description, 
        RequirementRule corequisite, RequirementRule prerequisite, RequirementRule prohibition,
        Set<TeachingPeriod> teachingPeriod) 
    {
        this.name = name;
        this.code = code;
        this.credits = credits;
        this.description = description;
        this.corequisite = corequisite;
        this.prerequisite = prerequisite;
        this.prohibition = prohibition;
        this.teachingPeriod = teachingPeriod;
    }


    //getters
    public String getName() {
        return name;
    }

    public String getCode() {
        return code;
    }

    public int getCredits() {
        return credits;
    }

    public String getDescription() {
        return description;
    }

    public RequirementRule getCorequisite() {
        return corequisite;
    }

    public  RequirementRule getPrerequisite() {
        return prerequisite;
    }

    public RequirementRule getProhibition() {
        return prohibition;
    }

    public Set<TeachingPeriod> getTeachingPeriod() {
        return teachingPeriod;
    }



    //setters
    public void setName(String name) {
        this.name = name;
    }

    public void setCode(String code){
        this.code = code;
    }

    public void setCredits(int credits) {
        this.credits = credits;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setTeachingPeriod(Set<TeachingPeriod> teachingPeriod) {
        this.teachingPeriod = teachingPeriod;
    }


}